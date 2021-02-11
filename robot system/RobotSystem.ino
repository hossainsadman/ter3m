#define ENCODER 2
#define SPOKES_IN_ENCODER 20
#define PI 3.14
#define DIAMETER 6.5
#define CIR DIAMETER*PI/100

#define MOTOR_L 0.5
#define MOTOR_R 0.54
#define MOTOR_RATIO MOTOR_L/MOTOR_R

#define BOTH_MOTORS_PIN 5

int power = 0;
int powerChange = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(BOTH_MOTORS_PIN, OUTPUT);
}

int i = 0;

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(BOTH_MOTORS_PIN, power);
  power = power + powerChange;
  if (power == 50 || power == 255) {
    powerChange = -powerChange;
  }
  
  delay(50);
//  analogWrite(5, map(i, 0, 255, 60, 255));
}
