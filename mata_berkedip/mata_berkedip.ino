#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Posisi mata
int leftEyeX = 40, rightEyeX = 90, eyeY = 32;  
int eyeRadius = 25;  // Ukuran bola mata
int pupilRadius = 8; // Ukuran pupil

// Offset untuk gerakan mata
int targetOffsetX = 0, targetOffsetY = 0, moveSpeed = 5;
int offsetX = 0, offsetY = 0;

// Blinking & animation
bool isBlinking = false;
unsigned long lastBlinkTime = 0, moveTime = 0;

void setup() {
  Wire.begin(23, 22);  // SDA = 23, SCL = 22
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 tidak ditemukan!"));
  }
  display.clearDisplay();
}

void loop() {
  unsigned long currentTime = millis();

  // Animasi berkedip setiap 4 detik
  if (currentTime - lastBlinkTime > 4000 && !isBlinking) {
    isBlinking = true;
    lastBlinkTime = currentTime;
  } else if (currentTime - lastBlinkTime > 150 && isBlinking) {
    isBlinking = false;
  }

  // Gerakan mata acak setiap 2-3 detik
  if (currentTime - moveTime > random(1500, 3000) && !isBlinking) {
    targetOffsetX = random(-8, 9);
    targetOffsetY = random(-5, 6);
    moveTime = currentTime;
  }

  // Interpolasi gerakan pupil
  offsetX += (targetOffsetX - offsetX) / moveSpeed;
  offsetY += (targetOffsetY - offsetY) / moveSpeed;

  // Gambar mata
  display.clearDisplay();
  
  if (!isBlinking) {
    drawEye(leftEyeX, eyeY, eyeRadius, offsetX, offsetY);
    drawEye(rightEyeX, eyeY, eyeRadius, offsetX, offsetY);
  } else {
    drawBlink(leftEyeX, eyeY, eyeRadius);
    drawBlink(rightEyeX, eyeY, eyeRadius);
  }

  display.display();
  delay(30);
}

// Fungsi menggambar mata bulat dengan pupil
void drawEye(int x, int y, int r, int offsetX, int offsetY) {
  display.fillCircle(x, y, r, WHITE);  // Bola mata
  display.fillCircle(x + offsetX, y + offsetY, pupilRadius, BLACK);  // Pupil
  display.fillCircle(x + offsetX - 3, y + offsetY - 3, 3, WHITE);  // Refleksi cahaya
}

// Fungsi menggambar mata tertutup (berkedip)
void drawBlink(int x, int y, int r) {
  display.fillRoundRect(x - r, y - 2, 2 * r, 4, 2, WHITE); // Garis berkedip
}

