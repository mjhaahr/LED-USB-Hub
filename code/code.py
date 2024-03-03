import board
import digitalio
import time
import supervisor
import adafruit_rgbled
import keypad

# Init LEDs
pwrLED = digitalio.DigitalInOut(board.PWR_LED)
pwrLED.direction = digitalio.Direction.OUTPUT
pwrLED.value = True

usbLED = digitalio.DigitalInOut(board.USB_LED)
usbLED.direction = digitalio.Direction.OUTPUT

L1 = adafruit_rgbled.RGBLED(board.L1R, board.L1G, board.L1B, True)
L2 = adafruit_rgbled.RGBLED(board.L2R, board.L2G, board.L2B, True)
L3 = adafruit_rgbled.RGBLED(board.L3R, board.L3G, board.L3B, True)

leds = [L1, L2, L3]

# Add Keypad
button = keypad.Keys((board.LED_EN,), value_when_pressed=False, pull=True)
buttonEvent = button.events.get()
# Get a first dangling event (from possibly holding down the button

def wheel(pos):
    # Input a value 0 to 255 to get a color value.
    # The colours are a transition r - g - b - back to r.
    if pos < 0 or pos > 255:
        return (0, 0, 0)
    if pos < 85:
        return (255 - pos * 3, pos * 3, 0)
    if pos < 170:
        pos -= 85
        return (0, 255 - pos * 3, pos * 3)
    pos -= 170
    return (pos * 3, 0, 255 - pos * 3)


pos = 0

print("Starting LEDs")

state = 0
# 0: All on, 1: All on dim, 2: Just Ports, 3: Just Ports dim
# 4: Status LEDs only, 5: All Off

while True:
    buttonEvent = button.events.get()
    if buttonEvent:
        if buttonEvent.pressed:
            state = (state + 1) % 6
            print(f"State: {state}")

    colors = []
    for i in range(len(leds)):
        wheelLoc = (pos + (i * 20)) % 256
        color = wheel(wheelLoc)
        colors.append(color)

    pos = (pos + 1) % 256

    usbStatus = supervisor.runtime.usb_connected

    if state == 0:
        # All on
        for led, color in zip(leds, colors):
            led.color = color

        usbLED.value = usbStatus
        pwrLED.value = True

    elif state == 1:
        # All on, dim
        for led, color in zip(leds, colors):
            led.color = tuple(i // 3 for i in color)

        usbLED.value = usbStatus
        pwrLED.value = True

    elif state == 2:
        # Ports only
        for led, color in zip(leds, colors):
            led.color = color

        usbLED.value = False
        pwrLED.value = False

    elif state == 3:
        # Ports only, dim
        for led, color in zip(leds, colors):
            led.color = tuple(i // 3 for i in color)

        usbLED.value = False
        pwrLED.value = False

    elif state == 4:
        # Status only
        for led in leds:
            led.color = (0, 0, 0)

        usbLED.value = usbStatus
        pwrLED.value = True

    else:
        # All off
        for led in leds:
            led.color = (0, 0, 0)

        usbLED.value = False
        pwrLED.value = False

    time.sleep(0.01)
