define symbolic constant ENCODER with a value 2             // digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the Arduino
define symbolic constant LED with a value 13                // we will use the built-in LED so that it flashes for every ON-OFF signal of encoder
define symbolic constant SPOKES_IN_ENCODER with a value 20  // the number of spokes in one encoder wheel
define symbolic constant MINUTE_IN_MILLIS with a value of 60000.0

int calculateMotorRPM() {
    declare variable value as an int and initialize to 0
    declare variable reads as an int and initialize to 0
    declare variable timeStart as an unsigned long and initialize to the system time in milliseconds

    do {
        read the signal from the encoder line 8 and store it in the variable value
        do {
        } while the variable value has not changed   // the spoke has not passed yet
        
        increment the variable reads by 1
        
    } while (reads is not equal to twice SPOKES_IN_ENCODER  // 20 spokes and 20 holes
    
    declare variable timeAfterOneRevolution as an unsigned long and initialize to the system time in milliseconds

    return (MINUTE_IN_MILLIS / (timeAfterOneRevolution - timeStart));
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ENCODER, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println(calculateMotorRPM());
}


Notes:

1. How to read the system time and assign it to a variable x: 

x = millis();


2. How to read a signal from the encoder line 8 and store it in a variable x:

x = digitalRead(ENCODER);
