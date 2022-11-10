/*
Author : Mohamad Nur Fitri bin Abd Halim
Title : Arduino Receiver LiFi Code
*/

const int selangmasa = 10;
int a[7];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(0) == LOW)
  {
    uint32_t startTime = millis();
    for (int i = 0; i < 7 && (millis() - startTime < 8 * 5 * selangmasa * 1000); i++)
    {
      while (digitalRead(0) == HIGH);
      delay(2 * selangmasa);
      a[i] = !digitalRead(0);
      delay(2 * selangmasa);
    }
    delay(4 * selangmasa);
    int m = decimal(a);
    char l = char(m);
    Serial.println(l);
  }
}

int decimal(int c[])
{
  int i, j = 0, decimal = 0, temp;
  for (i = 6; i >= 0; i--)
  {
    temp = c[i];
    for (int m = 0; m < j; m++)
      temp = temp * 2;
    decimal = decimal + temp;
    j++;
  }
  return decimal;
}
