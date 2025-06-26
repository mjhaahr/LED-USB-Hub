/**
 *****************************************************************************
 *
 * @file        RGB_USB_HUB.c
 *
 * @module      RGB USB Hub Module (HUB)
 *
 * @brief       Handles the operating logic for the RGB USB Hub
 *
 * @author      Matthew Haahr
 *****************************************************************************
 */
// ------------------------------------------------------------------------ //
// Includes
// ------------------------------------------------------------------------ //
#include "RGB_USB_HUB.h"
#include <stdbool.h>

// ------------------------------------------------------------------------ //
// Private Macros/Defines
// ------------------------------------------------------------------------ //
#define LED_UPDATE_RATE		10
#define DEBOUNCE_LENGTH		12

#define NUM_LEDS			3
#define LED_OFFSET			20

// MAYBE TODO: Improve update rate (currently 100Hz)
// ------------------------------------------------------------------------ //
// Private Typedefs
// ------------------------------------------------------------------------ //
// Color Data
typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} HUB_Color_s;

// LED Container
typedef struct {
	__IO uint32_t* redCCR;		// CCRx Register For the Red Channel
	__IO uint32_t* greenCCR;    // CCRx Register For the Green Channel
	__IO uint32_t* blueCCR;		// CCRx Register For the Blue Channel
} HUB_LED_s;

// RGB USB Hub Module Context
typedef struct {
	bool init;			// Init flag (cleared once init is finished)

	uint8_t tickCount;	// LED Update Tick Counting
	uint8_t wheelPos;	// The position through the color wheel

	HUB_LED_s* leds[NUM_LEDS];			// LED Array (allows looping through)
	TIM_HandleTypeDef* tims[NUM_LEDS];	// Timer Array (allows looping through)
} HUB_HubContext_s;

// ------------------------------------------------------------------------ //
// Private Method Declarations
// Private Methods:
// ------------------------------------------------------------------------ //
/**
 * Calculates the color of the LEDs (using the current wheel position)
 * Applies the new color
 */
static void HUB_UpdateLEDs(void);

/**
 * Updates the given LED to the provided color
 * @param HUB_LED_s* led - The LED to change
 * @param HUB_Color_s color - The color to set
 */
static void HUB_UpdateLED(HUB_LED_s* led, HUB_Color_s color);

/**
 * Calculates a color given a position around a color wheel
 * @param uint8_t pos - Position
 * @return HUB_Color_s - The new color
 */
static HUB_Color_s HUB_ColorWheel(uint8_t pos);

// ------------------------------------------------------------------------ //
// Static Context and Data Initializations
// ------------------------------------------------------------------------ //
static HUB_LED_s usb1;
static HUB_LED_s usb2;
static HUB_LED_s usb3;

static HUB_HubContext_s hubContext = {.init = false};

// ------------------------------------------------------------------------ //
// Public Method Definitions
// Public Methods:
// ------------------------------------------------------------------------ //
/**
 * Initializes the RGB USB Hub  Module
 * @param TIM_HandleTypeDef* htim1 - HAL Timer Handle 1
 * @param TIM_HandleTypeDef* htim2 - HAL Timer Handle 2
 * @param TIM_HandleTypeDef* htim3 - HAL Timer Handle 3
 * @param PCD_HandleTypeDef* hpcd_USB_FS - HAL USB Handle
 */
void HUB_Init(TIM_HandleTypeDef* htim1, TIM_HandleTypeDef* htim2, TIM_HandleTypeDef* htim3, PCD_HandleTypeDef* hpcd_USB_FS) {
	// Set Power LED (ignore USB LED for now)
	HAL_GPIO_WritePin(LED_PWR_GPIO_Port, LED_PWR_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_USB_GPIO_Port, LED_USB_Pin, GPIO_PIN_SET);

	// Setup LEDs
	usb1.redCCR   = htim1->Instance->CCR3;
	usb1.greenCCR = htim1->Instance->CCR2;
	usb1.blueCCR  = htim1->Instance->CCR1;

	usb2.redCCR   = htim3->Instance->CCR3;
	usb2.greenCCR = htim3->Instance->CCR2;
	usb2.blueCCR  = htim3->Instance->CCR1;

	usb3.redCCR   = htim2->Instance->CCR1;
	usb3.greenCCR = htim2->Instance->CCR3;
	usb3.blueCCR  = htim2->Instance->CCR2;

	hubContext.tims[0] = htim1;
	hubContext.tims[1] = htim2;
	hubContext.tims[2] = htim3;

	// LEDs are "backwards" to allow colors to from left to right
	hubContext.leds[0] = &usb3;
	hubContext.leds[1] = &usb2;
	hubContext.leds[2] = &usb1;


	// Initialize the LEDs
	hubContext.wheelPos = 0;
	HUB_UpdateLEDs();

	// Start All Timers
	for (uint8_t i = 0u; i < NUM_LEDS; i++) {
		HAL_TIM_PWM_Start(hubContext.tims[i], TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(hubContext.tims[i], TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(hubContext.tims[i], TIM_CHANNEL_3);
	}

	// Start code
	hubContext.tickCount = 0;
	hubContext.init = true;
}

/**
 * Runs the main task of the RGB USB Hub Module
 */
void HUB_Task(void) {
	// Exit early if not initialized
	if (!hubContext.init) {
		return;
	}

	// TODO: Handle interval
	if (hubContext.tickCount++ >= LED_UPDATE_RATE) {
		HUB_UpdateLEDs();
		hubContext.tickCount = 0;
	}

	// TODO: Handle Button(s)
	// TODO: Handle Status LEDs (If USB on, disable
}

// ------------------------------------------------------------------------ //
// Private Method Definitions
// Private Methods:
// ------------------------------------------------------------------------ //
/**
 * Calculates the color of the LEDs (using the current wheel position)
 * Applies the new color
 */
static void HUB_UpdateLEDs(void) {
	uint8_t pos = hubContext.wheelPos;
	for (uint8_t i = 0u; i < NUM_LEDS; i++) {
		// Get new color
		HUB_Color_s newColor = HUB_ColorWheel(pos);

		// Apply color to LED
		HUB_UpdateLED(hubContext.leds[i], newColor);

		// Add offset for next LED
		pos += LED_OFFSET;
	}

	// Increment (using overflow to wrap at end)
	hubContext.wheelPos++;
}

/**
 * Updates the given LED to the provided color
 * @param HUB_LED_s* led - The LED to change
 * @param HUB_Color_s color - The color to set
 */
static void HUB_UpdateLED(HUB_LED_s* led, HUB_Color_s color) {
	*led->redCCR   = color.red;
	*led->greenCCR = color.green;
	*led->blueCCR  = color.blue;
}

/**
 * Calculates a color given a position around a color wheel
 * @param uint8_t pos - Position
 * @return HUB_Color_s - The new color
 */
static HUB_Color_s HUB_ColorWheel(uint8_t pos) {
	HUB_Color_s color;

	if (pos < 85u) {
		color.red = 255u - (pos * 3u);
		color.green = pos * 3u;
		color.blue = 0u;
	} else if (pos < 170u) {
		color.red = 0u;
		color.green = 255u - (pos * 3u);
		color.blue = pos * 3u;
	} else {
		color.red = pos * 3u;
		color.green = 0u;
		color.blue = 255u - (pos * 3u);
	}

	return color;
}
