#define ENCODER 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = 0;
  value = digitalRead(ENCODER);
  Serial.print(value);
}
