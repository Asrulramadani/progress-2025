#define IN1  13 // motor penggerak maju
#define IN2  12 // motor penggerak mundur
#define IN3  14 // motor penggerak mundur
#define IN4  27 // motor penggerak mundur

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void maju() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void mundur() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}


void belokKanan() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(200);
  remKemudi();
}

void belokKiri() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(200);
  remKemudi();
}

void remKemudi() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(100);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  belokKiri();
  // maju();
  delay(2000);
  // stop();
  delay(5000);
  belokKanan();
  // mundur();
  delay(2000);
  // stop();
  delay(5000);


}
