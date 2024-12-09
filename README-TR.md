Proje Raporu: Arduino Robot El Kontrolü
1. Proje Başlığı:
•	Arduino Uno ile Robot El Kontrolü
2. Proje Amacı:
•	Bu projede, Arduino Uno kartı, bir joystick, iki servo motor bağlı el modeli, breadboard ve gerekli bağlantılar kullanılarak joystick hareketlerine bağlı olarak iki servo motor ile robot elin kontrol edilmesi amaçlanmıştır.
•	Joystick’in X ve Y eksenlerindeki hareketler, iki servo motorunun açısını ayarlamak için kullanılacaktır.
3. Gerekli Donanımlar:
•	1 x Arduino Uno kartı
•	1 x Joystick (analog) modülü
•	2 x Servo motor
•	1 x Robot El modeli
•	1 x Breadboard (Ekmek tahtası)
•	Birkaç Jumper kablo
•	1 x USB kablosu (Arduino'yu bilgisayarınıza bağlamak için)
4. Bağlantı Diyagramı:
•	Joystick Bağlantıları:
o	Joystick’in X ekseni (Vx) çıkışı: Arduino’nun A0 pinine bağlanır.
o	Joystick’in Y ekseni (Vy) çıkışı: Arduino’nun A1 pinine bağlanır.
o	Joystick’in VCC pini: Arduino'nun 5V pinine bağlanır.
o	Joystick’in GND pini: Arduino'nun GND pinine bağlanır.
•	Servo Motor Bağlantıları:
o	Servo 1 (X ekseni için): Pin 6'ya bağlanır.
o	Servo 2 (Y ekseni için): Pin 7'ye bağlanır.
o	Her iki servo motorunun GND pinleri: Arduino'nun GND pinine bağlanır.
o	Her iki servo motorunun VCC pinleri: Arduino’nun 5V pinine bağlanır.
•	Breadboard Bağlantıları:
o	Arduino kartı üzerinde 2 selvo motor ve joystick’i destekliyecek kadar 5V ve GND pini olmadığı için breadboard üzerinde bu pinler için hat çekilir ve selvo motorlardaki ve joystick’deki 5V ve GND bağlantıları breadboard üzerinden yapılır.
5. Yazılım:
•	Arduino IDE kullanarak, joystick'in X ve Y eksenlerindeki hareketleri okuyup, bunları iki servo motorunun açısını kontrol etmek için kullanacak bir program yazılmıştır.
Kod:
#include <Servo.h>  // Servo kütüphanesini dahil et

// Servo motorlarının pinleri
int servoPin1 = 6;  // İlk servo motoru X ekseni için
int servoPin2 = 7;  // İkinci servo motoru Y ekseni için

// Joystick'in analog pinleri
int joyX = A0;  // X ekseni
int joyY = A1;  // Y ekseni

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
  int xValue = analogRead(joyX);  // X ekseni (0-1023 arası)
  int yValue = analogRead(joyY);  // Y ekseni (0-1023 arası)
  
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
6. Yazılım Açıklamaları:
•	Servo Kütüphanesi: Servomotorları kontrol etmek için Arduino'nun Servo.h kütüphanesi kullanılmıştır.
•	Analog Okuma: Joystick'in X ve Y ekseninden gelen analog veriler analogRead() fonksiyonu ile okunmuştur.
•	Açı Dönüştürme: Joystick'ten gelen değerler, servo motorlarının hareket edebileceği 0-180 derece aralığına map() fonksiyonu ile dönüştürülmüştür.
•	Servo Motor Kontrolü: Servo motorlarının açıları servo.write() fonksiyonu ile ayarlanmıştır.
•	Serial Monitör: Kodda, joystick hareketlerinin ve servo açılarının izlenebilmesi için Serial.print() fonksiyonu ile seri monitörde bilgi gösterimi yapılmıştır.
7. Çalışma Prensibi:
•	Joystick'in X ve Y eksenleri, analog sinyaller olarak Arduino tarafından okunur.
•	X ekseni servo motorunun birinci açısını, Y ekseni ise ikinci servo motorunun açısını kontrol eder.
•	Joystick'in hareket ettirilmesiyle servo motorları farklı açılara gelir ve hareket eder.
•	Her iki servo motoru başlangıçta 90 derecede kalır, ancak joystick ile sağa, sola, yukarı veya aşağı hareket ettikçe bu açı değişir.
8. Sonuçlar ve Gözlemler:
•	Joystick hareketleri ile her iki servo motorunun açıları başarıyla kontrol edilmiştir.
•	Joystick’in X ekseni ile birinci servo motorunun hareketi, Y ekseni ile ise ikinci servo motorunun hareketi sağlanmıştır.
•	Proje, joystick ile servo motorları etkili bir şekilde kontrol edebilmek için temel bir uygulama olarak başarılı bir şekilde çalışmıştır.
9. Yapılabilecek Geliştirmeler:
•	Daha fazla servo motor ekleyerek her parmak ayrı ayrı kontrol edilebilir Joystickde bu projede kullanılmayan switch pini kontrol edilen selvo motorlar arasında geçiş yapabilir, bu geliştirme daha karmaşık hareketleri mümkün kılabilir.
10. Sonuç:
Bu proje, Arduino ile joystick ve servo motorlarını entegre ederek, kullanıcıların basit bir şekilde Robot elin fiziksel hareketlerini dijital bir ortamda kontrol etmelerini sağlamak için uygun bir çözüm sunmuştur. 

