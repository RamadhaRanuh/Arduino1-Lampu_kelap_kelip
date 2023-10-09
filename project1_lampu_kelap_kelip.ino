#define led_Red1 2
#define led_Yellow1 4
#define buttonSpeedUp 6

void setup() {
  Serial.begin(9600); //monitoring log input
  pinMode(buttonSpeedUp, INPUT);
  //default state = 1
  digitalWrite(buttonSpeedUp, HIGH);
  pinMode(led_Red1, OUTPUT);
  pinMode(led_Yellow1, OUTPUT);
  

}

void speedMode(int option)
{
  if(option == 1) //Mode Kencang
  {
    digitalWrite(led_Red1, HIGH); 
    delay(100);
    digitalWrite(led_Red1, LOW);
    digitalWrite(led_Yellow1, HIGH); 
    delay(100);
    digitalWrite(led_Yellow1, LOW);
  }

  else //Mode Lambat
  {
      digitalWrite(led_Red1, HIGH); 
      delay(500);
      digitalWrite(led_Red1, LOW);
      digitalWrite(led_Yellow1, HIGH); 
      delay(500);
      digitalWrite(led_Yellow1, LOW);
  }
}

void loop() {
  int isButtonSpeedPressed = digitalRead(buttonSpeedUp);

  if(isButtonSpeedPressed == 0) //Jika tombol di pencet
  {
    speedMode(1);
  }

  else
  {
    speedMode(0);
  }

}
