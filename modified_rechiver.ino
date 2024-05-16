uint8_t receive_buffer_tail = 15;
uint8_t receive_buffer_head = 0;
#define SS_MAX_RX_BUFF 20
uint8_t reveive_buffer[SS_MAX_RX_BUFF];

/*bool isListening() {
  return this == active_object;
}*/

char remon_read() {
  /*if (!isListening()) {
    return -1;
  }*/
  if (receive_buffer_head == receive_buffer_tail)
    return -1;

  uint8_t d = reveive_buffer[receive_buffer_head];
  //Serial.println(d);
  receive_buffer_head = (receive_buffer_head + 1) % SS_MAX_RX_BUFF;

  return d;
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //char c = remon_read();
  Serial.println(remon_read());
  //Serial.println("\n");
  //delay(1000);
}
