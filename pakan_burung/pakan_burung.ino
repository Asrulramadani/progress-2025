#include <ESP32Servo.h> // import library servo untuk esp32

// konfigurasi blynk
#define BLYNK_TEMPLATE_ID "TMPL6UrLhYNiv"
#define BLYNK_TEMPLATE_NAME "sistem pakan burung"
#define BLYNK_AUTH_TOKEN "w2yi-OBMLnzK-1C8txY2ha_oJJYRy3wu"

#include <BlynkSimpleEsp32.h> // import library blynk

Servo myServo;  // Buat objek servo

// inisialisasi variabel untuk menampung data dari blynk
int statusPakan;
int statusMinum;

#define SERVO_PIN 13  // definisi pin untuk servo
#define RELAY_PIN 15  // definisi pin untuk relay

#define WIFI_NAME "CV MEGA MANDIRI"
#define WIFI_PASSWORD "cv mega mandiri 01"


void setup() {
  myServo.attach(SERVO_PIN);  // Hubungkan servo ke pin ESP32
  pinMode(RELAY_PIN, OUTPUT); // setup mode pin untuk relay

  digitalWrite(RELAY_PIN, HIGH); // kondisi awal relay, logicnya terbalik. jika HIGH maka NO tidak aktif

  Serial.begin(9600); // setup serial monitor

  // koneksi ke wifi
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
 }

  Serial.print("WiFi connected");

  // konekasi ke blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_NAME, WIFI_PASSWORD);
  Serial.print("Blynk terkoneksi");

  }

// fungsi untuk menggerakkan servo sebanyak 2 step
void beriPakan() {
  myServo.write(90);
  delay(500);
  myServo.write(0);
  delay(500);
  myServo.write(90);
  delay(500);
  myServo.write(0);
}

// fungsi untuk mentrigger relay agar pompa bisa dinyalakan
void beriMinum() {
  digitalWrite(RELAY_PIN, LOW);
  delay(5000);
  digitalWrite(RELAY_PIN, HIGH);
}


void loop() {
  Blynk.run(); // menjalankan blynk

  // jika data dari blynk 1(aktif), makan jalankan fungsi beri pakan
  if(statusPakan == 1) {
    beriPakan();
    Blynk.virtualWrite(V0, 0); // mengubah data di blynk kembali ke 0(tidak aktif)
    statusPakan = 0;
    delay(2000);
  }

 // jika data dari blynk 1(aktif), makan jalankan fungsi beri minum
  if(statusMinum == 1) {
    beriMinum();
    Blynk.virtualWrite(V1, 0); // mengubah data di blynk kembali ke 0(tidak aktif)
    statusMinum = 0;
    delay(2000);
  }
}


// membaca data dari virtual pin 0 untuk mendapatkan data status pakan
BLYNK_WRITE(V0)
{
  statusPakan = param.asInt();
}

// membaca data dari virtual pin 0 untuk mendapatkan data status minum
BLYNK_WRITE(V1)
{
  statusMinum = param.asInt();
}
