import board
import digitalio
import time
import supervisor
import adafruit_rgbled
#TODO: LED_EN
pwrLED = digitalio.DigitalInOut(board.PWR_LED)
pwrLED.direction = digitalio.Direction.OUTPUT
pwrLED.value = True

usbLED = digitalio.DigitalInOut(board.USB_LED)
usbLED.direction = digitalio.Direction.OUTPUT

button = digitalio.DigitalInOut(board.LED_EN)
button.direction = digitalio.Direction.INPUT

L1 = adafruit_rgbled.RGBLED(board.L1R, board.L1G, board.L1B, True)
L2 = adafruit_rgbled.RGBLED(board.L2R, board.L2G, board.L2B, True)
L3 = adafruit_rgbled.RGBLED(board.L3R, board.L3G, board.L3B, True)

leds = [L1, L2, L3]

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

print("Starting")

while(True):
    i = 0

    for i, led in enumerate(leds):
        wheelLoc = (pos + (i * 20)) % 256
        color = wheel(wheelLoc)
        led.color = color

    pos = (pos + 1) % 256

    usbLED.value = supervisor.runtime.usb_connected
    time.sleep(0.01)
