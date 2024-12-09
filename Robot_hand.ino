#include <Servo.h>  // Servo kütüphanesini dahil et

// Servo motorlarının pinleri
int servoPin1 = 6;  // İlk servo motoru X ekseni için
int servoPin2 = 7;  // İkinci servo motoru Y ekseni için

// Servo nesneleri oluştur
Servo servo1;
Servo servo2;

void setup() {
  // Servo motorlarını bağla
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  
  // Başlangıçta servo motorlarını 90 dereceye yerleştir
  servo1.write(90);
  servo2.write(90);
  
  // Serial monitörü başlat
  Serial.begin(9600);
}

void loop() {
  // Joystick'in X ve Y eksenlerinden gelen analog değerleri oku
  int xValue = analogRead(A0);  // X ekseni (0-1023 arası)
  int yValue = analogRead(A1);  // Y ekseni (0-1023 arası)
  
  // Joystick değerlerini 0-180 arası servo motor açılarına dönüştür
  int servo1Angle = map(xValue, 0, 1023, 0, 180);  // X ekseni için servo açısı
  int servo2Angle = map(yValue, 0, 1023, 0, 180);  // Y ekseni için servo açısı
// Servo motorlarının açılarını ayarla
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);

  // Serial monitörde joystick değerlerini ve servo açılarını göster
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" Servo1: ");
  Serial.print(servo1Angle);
  Serial.print(" Servo2: ");
  Serial.println(servo2Angle);

}
