#define BUZZER 3
const int echo = 2;
const int trigger = 1;
const int thresholdDistance = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
}


void calculate_distance()
{
  float duration, distance;
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.0343 / 2;
  delay(100);
  if(distance < 150)
  {
    detected();
  }
  Serial.println(distance);
  

}
  
  


void ledBlink(int speed)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(speed);
  digitalWrite(LED_BUILTIN, LOW);
}

void soundAlert(int speed, int freq)
{
  tone(BUZZER, freq);
  delay(speed);
  noTone(BUZZER);
}


void detected()
{
  soundAlert(500,1000);
  ledBlink(500);
}


void loop()
{
  calculate_distance();
}