import board
import digitalio

# TODO: add color methods, change to analog
# TODO: add LED for USB Data

class usbPort:
    def __init__(self, red, green, blue):
        self.red = digitalio.DigitalInOut(red)
        self.red.direction = digitalio.Direction.OUTPUT
        self.red.value = False

        self.green = digitalio.DigitalInOut(green)
        self.green.direction = digitalio.Direction.OUTPUT
        self.green.value = False

        self.blue = digitalio.DigitalInOut(blue)
        self.blue.direction = digitalio.Direction.OUTPUT
        self.blue.value = False


if (__name__ == "__main__"):
    port1 = usbPort(board.D0, board.D1, board.D3)
    port2 = usbPort(board.D4, board.D5, board.D6)
    port3 = usbPort(board.D7, board.D8, board.D9)
