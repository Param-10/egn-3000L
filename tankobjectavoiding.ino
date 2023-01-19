//defines the wires to the motors and the ultrasonic sensors.
int trigPin = 3;
int echoPin = 2;

int leftmotor4 =8;
int leftmotor5 = 9;
int rightmotor6 = 10;
int rightmotor7 = 11;

long duration, distance;
//defines the input and output to the motors. 
void setup()
{
  delay(random(500,2000));
  Serial.begin(9600);
  pinMode(leftmotor4, OUTPUT);
  pinMode(leftmotor5, OUTPUT);
  pinMode(rightmotor6, OUTPUT);
  pinMode(rightmotor7, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
//this is the main code of the robot, this will loop over and over to check the distance and the movement
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  delay(10);
//moves forward
  if (distance > 30)
  {
    digitalWrite(rightmotor7, HIGH);
    digitalWrite(rightmotor6, LOW);
    digitalWrite(leftmotor5, HIGH);
    digitalWrite(leftmotor4, LOW);

  }
  else if (distance < 30)
  {
   // Stop
    digitalWrite(rightmotor7, LOW);
    digitalWrite(rightmotor6, LOW);
    digitalWrite(leftmotor5, LOW);
    digitalWrite(leftmotor4, LOW);
    delay(500);
// Move Backwards
    digitalWrite(rightmotor7, LOW);
    digitalWrite(rightmotor6, HIGH);
    digitalWrite(leftmotor5, LOW);
    digitalWrite(leftmotor4, HIGH);
    delay(500);
// Stop
    digitalWrite(rightmotor7, LOW);
    digitalWrite(rightmotor6, LOW);
    digitalWrite(leftmotor5,LOW);
    digitalWrite(leftmotor4, LOW);
    delay(100);

    digitalWrite(rightmotor7, HIGH);
    digitalWrite(rightmotor6, LOW);
    digitalWrite(leftmotor4, LOW);
    digitalWrite(leftmotor5, LOW);
    delay(500);

    
  }
}
