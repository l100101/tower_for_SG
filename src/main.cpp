#include <Arduino.h>
#include <TimerMs.h>
#include <EncButton.h>

#define SIGNAL_PIN 9
#define RECEIVE_PIN 10
TimerMs timer(0, 1);
// VirtualButton button(RECEIVE_PIN);
void setup()
{
  pinMode(SIGNAL_PIN, OUTPUT);
  pinMode(RECEIVE_PIN, INPUT);
  timer.setTime(300);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(RECEIVE_PIN) == HIGH)
  {
    timer.start();
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("signal received");
  }

  if (timer.tick())
  {
    digitalWrite(SIGNAL_PIN, HIGH);
    delay(10);
    Serial.println("signal sent");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(SIGNAL_PIN, LOW);
  }
}
