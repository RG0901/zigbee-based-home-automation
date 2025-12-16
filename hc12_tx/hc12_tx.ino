#include <SoftwareSerial.h>

SoftwareSerial mySerial(A0, A1); //RX, TX

int buttonPin1 = 8;
int buttonPin2 = 9;
boolean onOff1 = 0;
boolean onOff2 = 0;
void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  mySerial.begin(9600);
}

void loop() {
 
  int buttonState1 = digitalRead(buttonPin1);//read button state
    int buttonState2 = digitalRead(buttonPin2);//read button state
  
  if(buttonState1 == 0){//if button is down
    mySerial.println(1111);//send unique code to the receiver to turn on. In this case 1111
    onOff1 = 1;//set boolean to 1
  }
  if(buttonState1 == 1 && onOff1 == 1){//Verifier to send off signal once
    mySerial.println(2222);//send unique code to the receiver to turn off. In this case 0000
  }
  delay(20);//delay little for better serial communication

  if(buttonState2 == 0){//if button is down
    mySerial.println(3333);//send unique code to the receiver to turn on. In this case 1111
    onOff2 = 1;//set boolean to 1
  }
  if(buttonState2 == 1 && onOff2 == 1){//Verifier to send off signal once
    mySerial.println(4444);//send unique code to the receiver to turn off. In this case 0000
  }
}
