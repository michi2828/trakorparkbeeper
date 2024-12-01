#include <NewPing.h>

#define MAX_DISTANCE 300

// Pins for each sensor
#define TRIG_PIN1 8
#define ECHO_PIN1 2
#define TRIG_PIN2 3
#define ECHO_PIN2 4
#define TRIG_PIN3 5
#define ECHO_PIN3 6
int beep = 0;
int beep1 = 0;
int beep2 = 0;
int beep3 = 0;
int nbcount = 0;
NewPing sonar1(TRIG_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIG_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIG_PIN3, ECHO_PIN3, MAX_DISTANCE);

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
const long interval = 1000;  // Delay between each ping in milliseconds

void setup() {
  Serial.begin(9600);

}

void loop() {
  unsigned long currentMillis = millis();

//if (beep1)






  // Sensor 1
 if (currentMillis - previousMillis1 >= interval) {
    previousMillis1 = currentMillis;
    unsigned int distance1 = sonar1.ping_cm();
    Serial.print("Sensor 1: ");
    if (distance1 == 0) {
      Serial.println("Außer Reichweite");
        beep1 = 0;
    } else {
      Serial.println("In Reichweite");
      beep1 = distance1;
    }
  }
  


  // Sensor 2
  if (currentMillis - previousMillis2 >= interval) {
    previousMillis2 = currentMillis;
    unsigned int distance2 = sonar2.ping_cm();
    Serial.print("Sensor 2: ");
    if (distance2 == 0) {
      Serial.println("Außer Reichweite");
         beep2 = 0;
    } else {
      Serial.println("In Reichweite");
      beep2 = distance2;
    }
  }



  // Sensor 3
  if (currentMillis - previousMillis3 >= interval) {
    previousMillis3 = currentMillis;
    unsigned int distance3 = sonar3.ping_cm();
    Serial.print("Sensor 3: ");
    if (distance3 == 0) {
      Serial.println("Außer Reichweite");
      beep3 = 0;
    } else {
      Serial.println("In Reichweite");
      beep3 = distance3;
    }
  }
}
