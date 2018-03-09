# arduinoAnalogsInToSerial

### Arduino code

The `analogsInToSerial.ino` program sends analog input values over the serial
port via a minimalistic message system prepending each channel value with a
`A0`, `A1`, ... `A5` message to allow any client to parse the incoming data flow.

### Pure data patch

The `analogsInFromSerial.pd` file shows how to parse the serial input
with pure data vanilla.
