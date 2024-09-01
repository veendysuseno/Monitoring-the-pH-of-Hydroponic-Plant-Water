#include <LiquidCrystal_I2C.h>      //Library LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); //Alamat I2C
#define SensorpH A0                 //Sensor pH pada pin A0

float teganganPh7 = 2.73;   //Nilai kalibrasi
float teganganPh4 = 3.3;    //Nilai kalibrasi
float Po;

void setup() {
  lcd.init();       //Mulai LCD
  lcd.backlight();  //Nyalakan backlight
}

void loop() {
  int sensorValue = analogRead(SensorpH);         //Baca Sensor
  float voltage = sensorValue * (5.0 / 1023.0);   //Konversi menjadi nilai tegangan
  //Rumus mencari pH
  Po = 7.00 + ((teganganPh7 - voltage) / ((teganganPh4 - teganganPh7)/3));
  lcd.setCursor(0,0);
  lcd.print("Nilai pH = ");
  lcd.print(Po);                             //Tampilkan nilai pH
  delay(1000);
  lcd.clear();
}
