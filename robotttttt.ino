// Pin Definitions
#define LEFT_SENSOR 3
#define RIGHT_SENSOR 2

#define LEFT_MOTOR_IN1 13
#define LEFT_MOTOR_IN2 12
#define RIGHT_MOTOR_IN3 11
#define RIGHT_MOTOR_IN4 10
#define EN_A  5
#define EN_B 6

#define MOTOR_SPEED 250

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN3, OUTPUT);
  pinMode(RIGHT_MOTOR_IN4, OUTPUT);

}
void loop() {
  // Read sensor values //
 digitalWrite(EN_A, HIGH);
 digitalWrite(EN_B, HIGH); 
digitalWrite(LEFT_MOTOR_IN1, HIGH);
digitalWrite(LEFT_MOTOR_IN2, HIGH);
digitalWrite(RIGHT_MOTOR_IN3, HIGH);
digitalWrite(RIGHT_MOTOR_IN4, HIGH);
delay(1000);
  
  bool leftDetected = digitalRead(LEFT_SENSOR);
  bool rightDetected = digitalRead(RIGHT_SENSOR);

  // Line-following logic
  if (leftDetected && rightDetected) {
    moveForward();
  } else if (leftDetected) {
    turnLeft();
  } else if (rightDetected) {
    turnRight();
  } else {
    stopMotors();
  }

  delay(100); // Stabilization delay */
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, HIGH);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, HIGH);
  digitalWrite(RIGHT_MOTOR_IN3, HIGH);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, LOW);
  digitalWrite(RIGHT_MOTOR_IN4, HIGH);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN3, LOW);
  digitalWrite(RIGHT_MOTOR_IN4, LOW);
}
