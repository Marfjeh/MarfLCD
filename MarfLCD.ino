#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool startstring = false;
int charcount = 0;

void setup () {
  Serial.begin(9600); //init serial duh
  //init lcd, telling the lib that this is a 16x2 lcd.
  lcd.begin(16,2);
  lcd.home ();
  
  lcd.print("MarfLCD READY."); 
  lcd.setCursor(0,1);
  lcd.print ("Wait for input");
  lcd.setCursor(0,0);
  Serial.println("READY");
} 

void loop() {
  char serialData = 0;

  if (Serial.available() ){
    serialData = Serial.read();
    if ((serialData == '~') && (startstring == true)){
      startstring = false;
      lcd.clear();
      charcount = 0;
      lcd.setCursor(0,0);
    }

    if (startstring == true){
        lcd.print(serialData);
        charcount++;
        Serial.println("OK");
    }

    if (charcount == 16){
      lcd.setCursor(0,1);
    }
    
    if (charcount >= 33){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(serialData);
      charcount = 1;
      Serial.println("OVERFLOW");
    }
    
    if (serialData == '~'){
      startstring = false;
    } 
  }
}
