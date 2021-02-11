#define ENCODER 2
#define SPOKES_IN_ENCODER 20

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, INPUT);
  Serial.begin(9600);
}

void oneRevolution() {
  int value = 0;
  int reads = 0;

  do {
    value = digitalRead(ENCODER);
    do {
    } while (value == digitalRead(ENCODER));
    reads = reads + 1;
  } while (reads != 2*SPOKES_IN_ENCODER);
  
  Serial.print(reads);
  Serial.print("\n");
}
void loop() {
  // put your main code here, to run repeatedly:
  oneRevolution();
}
