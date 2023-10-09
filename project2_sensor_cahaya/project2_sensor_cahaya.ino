#define BUZZER 2

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);  //Input dari sensor cahaya (LDR)
  pinMode(LED_BUILTIN, OUTPUT); //Output duntuk LED pin 13 (LED)
  pinMode(BUZZER, OUTPUT);  //Output sound dari pin 2 (BUZZER MODULE)

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

void loop() {
  int sensor_value = analogRead(A5);
  if(sensor_value < 110)
  {
    ledBlink(500);
    soundAlert(500, 1000);
  }


}
