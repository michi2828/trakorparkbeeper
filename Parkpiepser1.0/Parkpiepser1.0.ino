int piezo = 9;
int entfernung = 0;

unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
const long interval1 = 0; 
const long interval2 = 0;
const long interval3 = 0;


#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ultraschall Sensor
const int trigPin1 = 1;
const int echoPin1 = 2;
const int trigPin2 = 3;
const int echoPin2 = 4;
const int trigPin3 = 5;
const int echoPin3 = 6;

void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

}



void loop() {

    unsigned long currentMillis = millis();

    // Funktion 1
    if (currentMillis - previousMillis1 >= interval1) {
        previousMillis1 = currentMillis;
        function1();
    }

    // Funktion 2
    if (currentMillis - previousMillis2 >= interval2) {
        previousMillis2 = currentMillis;
        function2();
    }

    // Funktion 3
    if (currentMillis - previousMillis3 >=interval3) {
      previousMillis3 = currentMillis;
      function3();
    }





}

void function1()
{
digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);


  long duration = pulseIn(echoPin1, HIGH);
  long distance = duration * 0.034 / 2;
  
  if(entfernung >= 500 || entfernung <=0)
  {
  Serial.println("Kein Messwert");
  }
  else
  {
  Serial.print(entfernung);
  Serial.println(" cm");  
  }
  if(entfernung <= 80)
  {
  digitalWrite(piezo,LOW);  
  }
  delay(1000);
}



void function2 ()
 {
//blinkende lämpchen


digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);


  long duration = pulseIn(echoPin2, HIGH);
  long distance = duration * 0.034 / 2;
  
  if(entfernung >= 500 || entfernung <=0)
  {
  Serial.println("Kein Messwert");
  }
  else
  {
  Serial.print(entfernung);
  Serial.println(" cm");  
  }
  if(entfernung <= 80)
  {
  digitalWrite(piezo,LOW);  
  }
  delay(1000);


 }



void function3()
{
digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);


  long duration = pulseIn(echoPin3, HIGH);
  long distance = duration * 0.034 / 2;
  
  if(entfernung >= 500 || entfernung <=0)
  {
  Serial.println("Kein Messwert");
  }
  else
  {
  Serial.print(entfernung);
  Serial.println(" cm");  
  }
  if(entfernung <= 80)
  {
  digitalWrite(piezo,LOW);  
  }
  delay(1000);
}



