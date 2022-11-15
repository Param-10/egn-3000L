#include<Servo.h>
#include<AFMotor.h>
#define LEFT
#define echopin// echo pin
#define trigpin// Trigger pin
#define RIGHT
// this is to setup the motors
AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);
Servo mytank;//this is used to control a variety of motors
int posi =0;
long time;
void setup(){
Serial.begin(9600);
mytank.attach(10);
for(posi = 90; posi <= 180; posi += 1){ //to set the position to 90 degrees if the position is less than 180
mytank.write(posi);
delay(20);
}
for(posi = 180; posi >= 0; posi-= 1) { //to set the position to 180 if the position is greater than 0
mytank.write(posi);
delay(20);
}
for(posi = 0; posi<=90; posi += 1) { //to set the position to 0 if the position is less than 90
mytank.write(pos);
delay(20);
}
pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
}
void loop(){
unsigned int distance = read_cm();
int RightValue = digitalRead(RIGHT);
int LeftValue = digitalRead(LEFT);
Serial.print("R= ");
Serial.print(RightValue);
Serial.print(" L= ");
Serial.print(LeftValue);
Serial.print(" D= ");
Serial.println(distance);
//this is used to print the values on the LCD display
if((RightValue==1) && (distance>=10 && distance<=30)&&(LeftValue==1)){forward();}
else if((RightValue==0) && (LeftValue==1)){turnRight();}
else if((RightValue==1) && (LeftValue==0)){turnLeft();}
else if((RightValue==1) && (LeftValue==1)){stop();}
else if(distance > 5 && distance < 10){stop();}
else if(distance < 5){backward();}
//this part controls the motors to turn the robot after detecting the distance from the sensor.
}

void forword(){// the tank starts to go forward
Motor1.setSpeed(120);
Motor1.run(FORWARD);
Motor2.setSpeed(120);
Motor2.run(FORWARD);
Motor3.setSpeed(120);
Motor3.run(FORWARD);
Motor4.setSpeed(120);
Motor4.run(FORWARD);
}

void backword(){ // the tank starts to go backwards
Motor1.setSpeed(120);
Motor1.run(BACKWARD); 
Motor2.setSpeed(120);
Motor2.run(BACKWARD);
Motor3.setSpeed(120);
Motor3.run(BACKWARD); 
Motor4.setSpeed(120);
Motor4.run(BACKWARD); 
}

void turnRight(){ // turns the tank right
Motor1.setSpeed(200);
Motor1.run(FORWARD);
Motor2.setSpeed(200);
Motor2.run(FORWARD);
Motor3.setSpeed(100);
Motor3.run(BACKWARD);
Motor4.setSpeed(100);
Motor4.run(BACKWARD);
}

void turnLeft(){ // turns the tank to left
Motor1.setSpeed(100);
Motor1.run(BACKWARD);
Motor2.setSpeed(100);
Motor2.run(BACKWARD);
Motor3.setSpeed(200);
Motor3.run(FORWARD);
Motor4.setSpeed(200);
Motor4.run(FORWARD);
}

void stop(){ // stops the tank
Motor1.setSpeed(0);  
Motor1.run(RELEASE);
Motor2.setSpeed(0);
Motor2.run(RELEASE);
Motor3.setSpeed(0);
Motor3.run(RELEASE);
Motor4.setSpeed(0);
Motor4.run(RELEASE);  
}
