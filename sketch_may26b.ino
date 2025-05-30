#define ToprakSensoru A0
#define SuMotoru A1
#define YesilLed 13
#define KirmiziLed 12
void setup() {
  pinMode(ToprakSensoru, INPUT);
  pinMode(SuMotoru, OUTPUT);
  pinMode(YesilLed, OUTPUT);
  pinMode(KirmiziLed, OUTPUT);
  digitalWrite(SuMotoru, HIGH);
  Serial.begin(9600);
}
void loop() {
  int sensorDegeri = analogRead(ToprakSensoru); // Sensör değerini oku
  Serial.print("Toprak Nem Degeri: ");
  Serial.println(sensorDegeri); // Sensör değerini Serial Monitör'e yazdır
  if (sensorDegeri > 700) {
    digitalWrite(SuMotoru, LOW);    // Motoru aç
    digitalWrite(YesilLed, LOW);    // Yeşil LED'i kapat
    digitalWrite(KirmiziLed, HIGH); // Kırmızı LED'i yak
  } else {
    digitalWrite(SuMotoru, HIGH);   // Motoru kapat
    digitalWrite(YesilLed, HIGH);   // Yeşil LED'i yak
    digitalWrite(KirmiziLed, LOW);  // Kırmızı LED'i kapat
  }
  delay(1000); // 1 saniye bekle
}
