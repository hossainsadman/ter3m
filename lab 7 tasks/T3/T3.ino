#define ENCODER 2
#define SPOKES_IN_ENCODER 20

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, INPUT);
  Serial.begin(9600);
}

// this function calculates the time it takes for the wheel to turn once
// the function returns the time in milliseconds

unsigned long timeOfOneRevolution() {
  int value = 0;
  int reads = 0;
  unsigned long timeStart = millis();

  do {
    value = digitalRead(ENCODER);
    do {
    } while (value == digitalRead(ENCODER));
    reads = reads + 1;
  } while (reads != 2*SPOKES_IN_ENCODER);

  unsigned long timeAfterOneRevolution = millis();
  return (timeAfterOneRevolution - timeStart);  
}
void loop() {
  // put your main code here, to run repeatedly:
  timeOfOneRevolution();
  int circumference = 2.5*3.14;
  int speedOfWheel = circumference / timeOfOneRevolution();
  Serial.print(speedOfWheel);
}
