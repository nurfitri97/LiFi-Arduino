/*
Author : Mohamad Nur Fitri bin Abd Halim
Title : Arduino Transimitter LIFI code
*/

int incomingByte = 0; // serial data that is receive from serial monitor
const int selangmasa=10; // Feel free to lower this value to increase the transmission speed. 
// You need to lower it on both receiver and transmitter
const int LED =13;	

void setup() 
{
  pinMode(LED, OUTPUT); 
  Serial.begin(9600); 
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read(); //read one character
    int a[10], i ;       
    for(i = 0; incomingByte > 0; i++)    
    {    
      a[i] = incomingByte%2;    
      incomingByte = incomingByte/2;  
    }    
  
    for(i = i-1; i >= 0; i--) // loop for 8 bit
    {   
      digitalWrite(LED, HIGH); // trigger Signal
   		delay(selangmasa);
   		digitalWrite(LED, a[i]); // bit signal either High or Low
    	delay(2 * selangmasa); 
    	digitalWrite(LED, LOW); // turn down the Led before next Bit
   		delay(2 * selangmasa);
    }    
  }  
}
