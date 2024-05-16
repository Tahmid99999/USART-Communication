//Sender Code
char arr[20] = "sopner padma setu";
int i = 0;

void setup() {
  DDRD = DDRD | B00000010;     
  UCSR0B = UCSR0B | B00011000; 
  UCSR0C = UCSR0C | B00000110;
  UCSR0A |= (1 << U2X0);
  UBRR0 = 207; 
}

void loop() {

  while ((UCSR0A & B00100000) == 0); 
  if (i < sizeof(arr))
    UDR0 = arr[i];
  i++;
  //UDR0 = 'A';   // Send the data 'A'
  //delay(10);  // Wait for 1 second
}
