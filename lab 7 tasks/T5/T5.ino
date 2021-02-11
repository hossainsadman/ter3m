#define ENCODER 2
#define SPOKES_IN_ENCODER 20
#define PI 3.14
#define DIAMETER 6.5
#define CIR DIAMETER*PI/100
#define SPEED_MOTOR_1 0.5
#define SPEED_MOTOR_2 0.54
#define SPEED_RATIO_1_2 0.926

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

double averageSpeed() {
    int i = 0;
    unsigned long speedReadings = 0;
    for (i = 0; i < 10; i++) {
        speedReadings = speedReadings + timeOfOneRevolution();
    }
    return (CIR*10/speedReadings*1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(averageSpeed());
  Serial.print(" m/s\n");
}
