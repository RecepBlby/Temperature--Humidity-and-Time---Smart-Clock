#include <DHT.h>                //nem sıcaklık 
#include <LiquidCrystal.h>      //LCD kütüphane
#include <DS3231.h>            //RTC kütüphane
#include <Wire.h>              //wire kütüphane

#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

DS3231   rtc(SDA,SCL);
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //LCD'nin pin değişkenleri
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);              //LCD'nin pin bağlantıları

void setup() {
 Serial.begin(115200);
 Wire.begin();
  lcd.begin(16, 2);     //LCD ekranı en-boy oranı                             
  rtc.begin();
  dht.begin();
}
void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();

  lcd.clear();                                //Başlamadan önce ekranı temizle 
  lcd.setCursor(0,0);                        //Ekranın ilk satır ilk sütunundan yaz
  lcd.print("SAAT=");
  lcd.print(rtc.getTimeStr());  
  delay(1000);  
                 
  lcd.setCursor(0,1);
  lcd.print("DAY=");
  lcd.print(rtc.getDOWStr());
  delay(3000);      
                          
  lcd.setCursor(0, 1);
  lcd.print("TARIH:");
  lcd.print(rtc.getDateStr());
  delay(3000);  
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SICAKLIK: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("NEM: %");
  lcd.print(hum);
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BALIBEY AILESI");
  delay(2000);
}
