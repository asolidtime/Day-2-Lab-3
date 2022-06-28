SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(AUTOMATIC);

#define LED D7
#define PR A5
// #define SERIALDEBUG

int minValue = 4095;
int maxValue = 0;
int reading;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PR, INPUT);
  pinMode(LED, OUTPUT);
  #ifdef SERIALDEBUG
    Serial.begin(115200);
  #endif
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  reading = analogRead(PR);
  maxValue = max(maxValue, reading);
  minValue = min(minValue, reading);
  analogWrite(LED, map(reading, minValue, maxValue, 0, 255));
  #ifdef SERIALDEBUG
    Serial.print("read ");
    Serial.print(reading);
    Serial.print(" min ");
    Serial.print(minValue);
    Serial.print(" max ");
    Serial.println(maxValue);
    delay(250ms);
  #endif
}