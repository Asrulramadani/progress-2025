#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long lastChangeTime = 0;
int currentFace = 0;  // 0 = happy, 1 = chongmat, 2 = angry

void drawHappyFace(int pupilOffsetX = 0, int pupilOffsetY = 0) {
  display.fillCircle(40, 32, 10, WHITE);
  display.fillCircle(40 + pupilOffsetX, 32 + pupilOffsetY, 4, BLACK);
  
  display.fillCircle(88, 32, 10, WHITE);
  display.fillCircle(88 + pupilOffsetX, 32 + pupilOffsetY, 4, BLACK);
  
  display.drawCircle(64, 48, 10, WHITE);
  display.fillRect(54, 38, 20, 10, BLACK); // senyum
}

void drawChongMatFace() {
  float angle = (millis() % 3600) / 3600.0 * 2 * PI;
  int orbitRadius = 3;
  
  display.fillCircle(40, 32, 10, WHITE);
  display.fillCircle(40 + orbitRadius * cos(angle), 32 + orbitRadius * sin(angle), 4, BLACK);
  
  display.fillCircle(88, 32, 10, WHITE);
  display.fillCircle(88 + orbitRadius * cos(angle), 32 + orbitRadius * sin(angle), 4, BLACK);
  
  display.drawLine(54, 48, 74, 48, WHITE); // mulut datar
}

void drawAngryFace() {
  display.drawLine(30, 22, 50, 32, WHITE);
  display.fillCircle(40, 38, 10, WHITE);
  display.fillCircle(40, 38, 5, BLACK);

  display.drawLine(78, 32, 98, 22, WHITE);
  display.fillCircle(88, 38, 10, WHITE);
  display.fillCircle(88, 38, 5, BLACK);

  display.drawCircle(64, 48, 10, WHITE);
  display.fillRect(54, 48, 20, 10, BLACK); // cemberut
}

void setup() {
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    while (1); // OLED tidak ditemukan
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  unsigned long now = millis();

  // Ganti ekspresi setiap 3 detik
  if (now - lastChangeTime > 3000) {
    currentFace = (currentFace + 1) % 3; // urut: 0→1→2→0...
    lastChangeTime = now;
  }

  display.clearDisplay();

  switch (currentFace) {
    case 0:
      drawHappyFace();
      break;
    case 1:
      drawChongMatFace();
      break;
    case 2:
      drawAngryFace();
      break;
  }

  display.display();
  delay(50);
}
