import board
import digitalio
import time
import storage
import usb_hid
import usb_midi

# Init LEDs
pwrLED = digitalio.DigitalInOut(board.PWR_LED)
pwrLED.direction = digitalio.Direction.OUTPUT
pwrLED.value = True

button = digitalio.DigitalInOut(board.LED_EN)
button.direction = digitalio.Direction.INPUT

# if LED_EN button is held during startup, storage drive is active
if not button.value:
    time.sleep(0.1)
    pwrLED.value = False
    time.sleep(0.1)
    pwrLED.value = True

else:
    storage.disable_usb_drive()
    usb_hid.disable()
    usb_midi.disable()
