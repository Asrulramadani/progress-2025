#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "CV MEGA MANDIRI";
const char* password = "cv mega mandiri 01";
#define LED_BUILTIN 2

WebServer server(80);

bool blinkStatus = false;  // Status apakah LED harus berkedip
unsigned long previousMillis = 0;
const long interval = 200; // Interval kedipan LED
bool ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print("Menghubungkan ke wifi.. ");
  }

  Serial.print("terhubung ke wifi");
  Serial.print("IP ESP32: ");
  Serial.print(WiFi.localIP());

  pinMode(LED_BUILTIN, OUTPUT);


  server.on("/led/on", HTTP_GET, []() {
    digitalWrite(LED_BUILTIN, HIGH);
    server.send(200, "text/plain", "LED ON");
  });

  server.on("/led/off", HTTP_GET, []() {
    digitalWrite(LED_BUILTIN, LOW);
    server.send(200, "text/plain", "LED OFF");
  });

  server.on("/led/status", HTTP_GET, []() {
    int state = digitalRead(LED_BUILTIN);
    server.send(200, "text/plain", state? "ON" : "OFF");
  });

  server.on("/led/blink", HTTP_GET, []() {
   blinkStatus = !blinkStatus;  // Toggle status blink
        server.send(200, "text/plain", blinkStatus ? "Blinking Started" : "Blinking Stopped");
    });
  });

  server.begin();


}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

    if (blinkStatus) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            ledState = !ledState;  // Toggle LED
            digitalWrite(LED_BUILTIN, ledState);
        }
    }
}
