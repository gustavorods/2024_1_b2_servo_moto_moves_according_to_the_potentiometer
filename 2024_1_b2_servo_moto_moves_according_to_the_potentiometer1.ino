#include <Servo.h>

const int pinServo[] = {2,3,4,5};
Servo servo[4];

const int pinPoten[] = {A0, A1, A2, A3};
int valorPoten[4];

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++) {
    servo[i].attach(pinServo[i]);
    servo[i].write(0);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    valorPoten[i] = analogRead(pinPoten[i]);
    if(i == 2) {
    	Serial.println(valorPoten[i]);
    }
  }
   
  
  valorPoten[0] = map(valorPoten[0], 0, 1023, 0, 180);
  valorPoten[1] = map(valorPoten[1], 0, 1023, 0, 90);
  valorPoten[2] = map(valorPoten[2], 0, 1023, 0, 120);
  valorPoten[3] = map(valorPoten[3], 0, 1023, 0, 90);

  servo[0].write(valorPoten[0]);
  servo[1].write(valorPoten[1]);
  servo[2].write(valorPoten[2]);
  servo[3].write(valorPoten[3]);
  
}
