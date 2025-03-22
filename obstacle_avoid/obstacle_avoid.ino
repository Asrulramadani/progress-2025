
#include <Arduino.h>
#include <ESP32Servo.h>

#define TRIG_PIN  12   // Pin Trig HC-SR04
#define ECHO_PIN  14  // Pin Echo HC-SR04
#define SERVO_PIN 13  // Pin untuk servo

// Motor Driver L298N
#define ENA  26    // PWM untuk Motor Kiri
#define IN1  27   // Arah Motor Kiri
#define IN2  33  

#define ENB  25    // PWM untuk Motor Kanan
#define IN3  32   // Arah Motor Kanan
#define IN4  34  

// PWM Setup
#define PWM_FREQ 1000  // Frekuensi PWM
#define PWM_RES  8     // Resolusi 8-bit (0-255)

Servo servo;
int distanceFront, distanceLeft, distanceRight;

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // servo.attach(SERVO_PIN);

  // Setup PWM untuk motor
  ledcAttach(ENA, PWM_FREQ, PWM_RES);
  ledcAttach(ENB, PWM_FREQ, PWM_RES);

  servo.attach(SERVO_PIN); 
  servo.write(90); // Sensor menghadap ke depan

    Serial.println("Mundur");
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);




}

void loop() {

}

// void loop() {
//   distanceFront = getDistance();
//   Serial.print("Depan: ");
//   Serial.println(distanceFront);

//   if (distanceFront > 30) {  
//     // Tidak ada rintangan, maju dengan kecepatan penuh
//     moveBackward(100);  // Kecepatan 200/255
//     servo.write(90);
//   } else {
//     // Ada rintangan, cek kiri & kanan
//     moveStop();
//     delay(500);
    
//     distanceLeft = checkDirection(160); // Baca ke kiri
//     distanceRight = checkDirection(20); // Baca ke kanan

//     Serial.print("Kiri: ");
//     Serial.print(distanceLeft);
//     Serial.print(" | Kanan: ");
//     Serial.println(distanceRight);
    
//     if (distanceLeft > 30 && distanceLeft > distanceRight) {
//       turnLeft(75);  // Belok kiri dengan kecepatan 150
//     } else if (distanceRight > 30) {
//       turnRight(75); // Belok kanan dengan kecepatan 150
//     } else {
//       // Semua sisi ada rintangan → Mundur → Putar balik
//       moveBackward(75);
//       delay(1000);
//       turnAround();
//     }
//   }
//   delay(100);
// }

// // Fungsi membaca jarak dengan sensor ultrasonik
// int getDistance() {
//   digitalWrite(TRIG_PIN, LOW);
//   delayMicroseconds(2);
//   digitalWrite(TRIG_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIG_PIN, LOW);
//   return pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;
// }

// // Fungsi untuk membaca jarak ke kiri atau kanan
// int checkDirection(int angle) {
//   servo.write(angle);
//   delay(500);
//   return getDistance();
// }

// // Gerakan motor dengan PWM
// void moveForward(int speed) {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   ledcWrite(ENA, speed);
//   ledcWrite(ENB, speed);
// }

// void moveBackward(int speed) {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   ledcWrite(ENA, speed);
//   ledcWrite(ENB, speed);
// }

// void turnLeft(int speed) {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   ledcWrite(ENA, speed);
//   ledcWrite(ENB, speed);
//   delay(500); // Belok sebentar
// }

// void turnRight(int speed) {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   ledcWrite(ENA, speed);
//   ledcWrite(ENB, speed);
//   delay(500); // Belok sebentar
// }

// void turnAround() {
//   // Motor kiri & kanan berputar berlawanan arah
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   ledcWrite(ENA, 100);
//   ledcWrite(ENB, 100);
//   delay(700); // Waktu yang cukup untuk putar balik
//   moveStop();
// }

// void moveStop() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
//   ledcWrite(ENA, 0);
//   ledcWrite(ENB, 0);
// }
