

// Servo servo1;
#define relayPin 4
#define trigPin 2
#define echoPin 15

 long duration;
 float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // servo1.attach(servo1Pin);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void blink() {
 digitalWrite(relayPin, LOW);
 delay(50);
 digitalWrite(relayPin, HIGH);
 delay(50);
 digitalWrite(relayPin, LOW);
 delay(50);
 digitalWrite(relayPin, HIGH);
 delay(50);
}

void longg() {
  digitalWrite(relayPin, LOW);
  delay(1000);
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  Serial.print("jarak: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print('\n');

  if (distance <= 30) {
    longg();
  }else if(distance > 30 && distance <= 50) {
    blink();
  }else {
    digitalWrite(relayPin, HIGH);
  }

  // servo1.write(0);
  // digitalWrite(relayPin, LOW);
  // delay(2000);
  // servo1.write(180);
  // digitalWrite(relayPin, HIGH);
  delay(200);

}
