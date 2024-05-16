// Receiver code:

void setup() {
  delay(100);
  DDRD = DDRD & B11111101;  
  UCSR0B = UCSR0B | B00011000;  
  UCSR0C = UCSR0C | B00000110;
   UCSR0A |= (1 << U2X0);
  UBRR0 = 207;  
}

void loop() {
 
  
  while ((UCSR0A & B10000000) == 0);                 
  char data = UDR0;   
  Serial.print(data);
}
