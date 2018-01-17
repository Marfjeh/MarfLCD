# MarfLCD

Make a Arduino LCD status screen.

# Wiring
![diagram](https://hackster.imgix.net/uploads/image/file/97335/untitled.png)

# documentation

The firmware has some simple commands, at the start send `~~` at the beginning to start and clean the display.
Then you can start sending text plain in the serial console.

Sending: `Hello World`

This will print Hello world on the display.


Sending: `~Hello World`

This will also print Hello world on the display but it will clean the display first and then print the new text.
