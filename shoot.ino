#include <Servo.h>
int Speed;
Servo ESC;

void shootSetup(){
    ESC.attach(9, 1000, 2000);
    delay(1);
    ESC.write(10);
}

/**
  power is from 0 - 100
  */
void shoot(int power) {
    Speed = (power / 100) * 180;
    ESC.write(Speed);
    delay(2000);
    ESC.write(0);
}
