#define ENCODER 2                   // digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino
#define LED     13                  // just to have the built-in led flash for every on-off of the encoder
#define SPOKES_IN_ENCODER 20
#define ONE_MINUTE_MILLIS 60000.0

#define TRIALS 20
#define CIRCUMFERENCE_OF_WHEEL 0.195 // m

// in ms
unsigned timeOfOneRevolution() {
    int value = 0;
    int reads = 0;
    unsigned long timeStart = millis();

    do {
        value = digitalRead(ENCODER);
        do {
        } while (value == digitalRead(ENCODER));
        reads++;
    } while (reads != 2 * SPOKES_IN_ENCODER);   // one read through hole, one read through gap
    
    unsigned long timeAfterOneRevolution = millis();
    return timeAfterOneRevolution - timeStart;
}

// motor RMP from only one revolution read
double calculateMotorRPM() {
    return ONE_MINUTE_MILLIS / timeOfOneRevolution();
}

// motor RMP by averaging a number of trials
double calculateAverageMotorRPM() {
    double accumulated = 0.0;
    for (int trial = 1; trial <= TRIALS; trial++) {
        accumulated = accumulated + calculateMotorRMP();
    }
    return accumulated / TRIALS;
}

// speed from only one revolution read in m/s
double calculateSpeed() {
    return CIRCUMFERENCE_OF_WHEEL / (timeOfOneRevolution() / 1000.0);
}

// speed by averaging a number of trials in m/s
double calculateAverageSpeed() {
    double accumulated = 0.0;
    for (int trial = 1; trial <= TRIALS; trial++) {
        accumulated = accumulated + calculateSpeed();
    }
    return accumulated / TRIALS;
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ENCODER, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println(calculateAverageMotorRPM());
    Serial.println(calculateAverageSpeed());
}
