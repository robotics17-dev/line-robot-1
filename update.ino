// Define pin connections
#define IR_LEFT A0  // Left IR sensor (IR1)
#define IR_RIGHT A1 // Right IR sensor (IR2)

#define ENA 9       // Motor A enable pin
#define ENB 10      // Motor B enable pin
#define IN1 8       // Motor A input 1
#define IN2 7       // Motor A input 2
#define IN3 6       // Motor B input 1
#define IN4 5       // Motor B input 2

void setup() {
  // Set motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set IR sensor pins as input
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  // Start motors off
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
  int leftSensor = digitalRead(IR_LEFT);
  int rightSensor = digitalRead(IR_RIGHT);

  if (leftSensor == LOW && rightSensor == LOW) {
    // No obstacle detected - move forward
    moveForward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Obstacle on right - turn left
    turnLeft();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Obstacle on left - turn right
    turnRight();
  } else {
    // Obstacles on both sides - stop
    stopMotors();
  }
}

// Functions to control the motors
void moveForward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
