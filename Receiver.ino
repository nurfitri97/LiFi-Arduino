/*
Author : Mohamad Nur Fitri bin Abd Halim
Title : Arduino Receiver LiFi Code
*/

const int selangmasa=10;
int a[7];
unsigned long mili =millis();
int huruf=0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(1200);
}

void loop() 
{
  char ayat[100]={0};
  int j=0;
  if(digitalRead(0)==LOW)
  {
    for (int i=0;i<7;i++)
    {
      mili=millis();
      while((digitalRead(0)!=LOW)&&(i!=7))
      if  (millis()-mili>3*selangmasa) 
      {
        i=7;
        Serial.println(" ") ;
        //ni utk tunggu isyarat seterusnya
      }
      delay(2*selangmasa);
      a[i]=!digitalRead(0);
      delay(2*selangmasa);
     // Serial.println(a[i]);
      j++;
    }
    //delay(4*selangmasa); // nak skip enter
    int m=decimal(a);
   // Serial.println("nilai binari");
   // Serial.println(m);
    char l= char(m);
    //Serial.println("Simbol");
    Serial.print(l);
    //Serial.println("Simbol tamat ");
  }
}

/////////function definition untuk tukar array binary kepada integer 

int decimal(int c[])
{
 int i, j=0 , decimal=0, temp;
  for(i=6;i>=0;i--)
  {
    temp=c[i];
    for(int m=0;m<j;m++) temp=temp*2; //kuasakan sebanyak j kali, j ialah kedudukan digit dari kanan
    decimal=decimal +temp;
    j++;
  }
  
  return decimal;
  }
