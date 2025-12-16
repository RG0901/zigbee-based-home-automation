#include <SoftwareSerial.h>

SoftwareSerial mySerial(A0, A1); // RX, TX

int ledPin1 = A5;
int ledPin2 = A4;
int ledPin3 = 2;
int ledPin4 = 3;

int pir = 9;
int ldr = 8;
#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT11//#define DHTTYPE DHT21
    int s;               
DHT dht(DHTPIN, DHTTYPE);
#define USE_ARDUINO_INTERRUPTS true
// Include necessary libraries

void setup() {
   dht.begin();
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(ldr, INPUT);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
}

void loop() {
  Serial.println(dht.readTemperature());
    if((dht.readTemperature())>=35)
  digitalWrite(ledPin4, LOW);
  else
  digitalWrite(ledPin4, HIGH);
 
  
       if (digitalRead(ldr)==LOW && digitalRead(pir)==HIGH)
  {
digitalWrite(ledPin3, LOW);//turn LED on

  }

  else
  digitalWrite(ledPin3, HIGH);//turn LED on
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    if(input == 1111){//if on code is received
      digitalWrite(ledPin1, LOW);//turn LED on
    }
    if(input == 2222){//if off code is received
      digitalWrite(ledPin1, HIGH);//turn LED off
    }
      if(input == 3333){//if off code is received
      digitalWrite(ledPin2, LOW);//turn LED off
    }
      if(input == 4444){//if off code is received
      digitalWrite(ledPin2, HIGH);//turn LED off
    }
  }
  mySerial.flush();//clear the serial buffer for unwanted inputs     
  
  delay(20);//delay little for better serial communication
 
}
