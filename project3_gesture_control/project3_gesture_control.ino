#include <LiquidCrystal_I2C.h>

const int col = 16;
const int row = 2;

LiquidCrystal_I2C lcd(32, col, row);

byte love[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

int position = 0;
int direction = 1;

const char* msg = " Nata "; 

int msgLen = strlen(msg);

void setup() {
  lcd.init();
  lcd.backlight();
     
  lcd.createChar(0, love);
}

void loop() {
  lcd.clear();

  lcd.setCursor(position, direction);
  position+=1;
  
  direction ? direction = 0 : direction = 1;
  
  if(position < 0 || position >= col) {
    position = 0;
  }
 
  lcd.write(0);
  lcd.print(msg);
  lcd.write(0);
  
  delay(500);
}
