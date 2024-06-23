//Receiver code 
#include<SoftwareSerial.h>

SoftwareSerial mybt(2,3);
int m=0,n=0;

int enA = 5; // SPEED CONTROL
int enB = 6;
double minSpeed = 100;
double maxSpeed = 250;
double speed;
double rotatingSpeed;
double completeRotationSpeed;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  Serial.begin(9600);
  mybt.begin(9600);
}

void loop() {

  if(mybt.available() > 0) {  
    
    String data = mybt.readStringUntil(',');
    n = data.toInt();
    data = mybt.readStringUntil('\n');
    m = data.toInt();

    speed = min(maxSpeed, minSpeed + (maxSpeed - minSpeed) * ((abs(n)-100)/400));
    rotatingSpeed = max(speed * 0.5, speed * ((500 - abs(m))/500));
    
    if(n > 100){ //Front
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);

      if(m > 100) {  //left turn
        analogWrite(enA, rotatingSpeed);
        analogWrite(enB, speed);
      }
      else if(m < -100) {  //right turn
        analogWrite(enA, speed);
        analogWrite(enB, rotatingSpeed);
      }
      else{
        analogWrite(enA, speed);
        analogWrite(enB, speed);
      }

     }

    else if(n < -100) { //Back
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);

      if(m > 100) {  //left turn
        analogWrite(enA, rotatingSpeed);
        analogWrite(enB, speed);
      }
      else if(m < -100) {  //right turn
        analogWrite(enA, speed);
        analogWrite(enB, rotatingSpeed);
      }
      else{
        analogWrite(enA, speed);
        analogWrite(enB, speed);
      }

    }

    else if(m < -200) { //Right
      completeRotationSpeed = min(maxSpeed, minSpeed + (maxSpeed - minSpeed) * ((abs(m)-200)/300));
      analogWrite(enA, completeRotationSpeed);
      analogWrite(enB, completeRotationSpeed);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);

    }
    
    else if(m > 200) { //Left
      completeRotationSpeed = min(maxSpeed, minSpeed + (maxSpeed - minSpeed) * ((abs(m)-200)/300));
      analogWrite(enA, completeRotationSpeed);
      analogWrite(enB, completeRotationSpeed);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
    }

    else {
      analogWrite(enA, speed);
      analogWrite(enB, speed);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
  }
}
