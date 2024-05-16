# UART Programming <a href ="https://sites.google.com/aust.edu/usartcommunication/home?authuser=0">Slide</a>
Data communication between two arduino.
*Date:05/02/2023*
# UART Programming.
### Ahsanullah University of Science and Technology(AUST.)
### CSE3216 - Microcontroller Based System Design Lab
### Contributor <kbd>↓</kbd><br/><br/>:octocat:

Student ID              |  Name
----------------------- | -------------
190204099               |  Tahmid Bin Rafique
190204111               |  Shovon Chowdhury
190204113               |  Mehedi Islam Remon
190204093               |  Md.Fardin Jaman Aranyak
190204103               |  Md. Nurul Yousuf Khan
----------------------------------------
Contact US: :mailbox_with_mail:

    |kfardin0@gmail.com
    
![Screenshot 2023-02-05 055647](https://user-images.githubusercontent.com/64925270/216795590-99ddffe8-dd67-4420-b82a-113c34acd7e1.png)


#### ABOUT: <br/>

*** UDR0, UCSR0A, UCSR0B, and UBRR0 are the AVR microcontroller's registers that are used for serial communication on the Arduino platform.

### UDR0 (USART Data Register 0) is a register that holds the data to be transmitted or the data received over serial communication. When sending data, you write the data to the UDR0 register. When receiving data, you read the data from the UDR0 register.

### UCSR0A (USART Control and Status Register A) is a register that holds the control and status bits for the USART (Universal Synchronous Asynchronous Receiver Transmitter) module. Some of the important bits in this register include RXC0 (Receive Complete), UDRE0 (USART Data Register Empty), and TXC0 (Transmit Complete).

### UCSR0B (USART Control and Status Register B) is a register that holds the control and status bits for the USART module. Some of the important bits in this register include RXEN0 (Receiver Enable), TXEN0 (Transmitter Enable), and RXCIE0 (Receive Complete Interrupt Enable).

### UBRR0 (USART Baud Rate Register) is a register that holds the baud rate value for serial communication. This value determines the speed of the serial communication, with higher values representing higher speeds. The baud rate can be calculated using the formula BAUD = F_CPU / (16 * (UBRR0 + 1)), where F_CPU is the clock frequency of the AVR microcontroller.***

### UART Register:
Register                |  Description
----------------------- | -------------
UDR                     |  USART Data Register
UCSR0A                  |  USART0 Control and Status Register A
UCSR0B                  |  USART0 Control and Status Register B
UCSR0C                  |  USART0 Control and Status Register C
UBRR                    |  Baud Rate Register
----------------------------------------

### UART Register Configuration:

### UCSR0A:
   

D7       |D6      |D5      |D4      |D3       |D2      |D1       |D0 
---------|--------|--------|--------|---------|--------|---------|--------
RXC0     |TXC0    |UDRE0   |FE0     |DOR0     |UPE0    |U2X0     |MPCM0
--------------------------------------------------------------------------

This bit is used to show the status of the received buffer.

### Bit 7 - RXC0 : USART Receive complete
1 : Unread data in the Receiver buffer

0 : Receive buffer is empty.

This bit us used to show the status of the transmitted buffer.
### Bit 6 - TXC0 : USART transmit complete

1 : No data present in the buffer register to transmit

0 : Transmit complete interrupt is executed.

This bit indicates whether Transmit data buffer ready to receive new data.

### Bit 5 - UDRE0 : USART Data Register empty
1 : Transmitter buffer is empty

0 : Transmitter is ready.
This bit us used to show the Frame error.
### Bit 4 - FE0 : Frame error
1 : Next character in the receiver buffer had error

0 : Writing to UCSR0A.
This bit us used to show the Receiver data over run occure.
### Bit 3 - DOR0 : Data over run
1 : Receiver buffer is full (Receiver data over run occure)

0 : Writing to UCSR0A.
This bit us used to show the parity error.
### Bit 2 - UPE0 : Parity Error
1 : Next character in the receiver buffer had a parity error

0 : Writing to UCSR0A.
This bit has effect for the Asynchronous operation. For Synchronous operation write this bit to 0.
### Bit 1 - U2X0: Double the USART transmission speed
1 :Reduces the divisor of the baud rate divider from 16 to 8 effectively doubling the transfer rate of Asynchronous communication

0 : Synchronous operation.
This bit enables the multiprocessor communication.
### Bit 0 - MPCM0: Multiprocessor communication mode
1 :All the incoming frames received by the USART Receiver that do not contain address information will be ignored.

0 : Writing to UCSR0A.



### UCSR0B

D7         |D6      |D5       |D4      |D3       |D2      |D1    |D0      
-----------|--------|---------|--------|---------|--------|------|---------
RXCIE0     |TXCIE0  |UDREIE0  |RXEN0   |TXEN0    |UCSZ20 |RXB80  |TXB80
--------------------------------------------------------------------------
This bit is used to show the status of the received interrupt.
### Bit 7 - RXCIE0: RX Complete Interrupt Enable
1 : A USART0 Receive Complete interrupt will be generated

0 : no interrupt.
This bit us used to show the status of the transmitted interrupt .
### Bit 6 - TXC0 : USART transmit complete
1 : A USART0 Transmit Complete interrupt will be generated

0 : no interrupt.

### Bit 5 - UDRIE0: USART Data Register Empty Interrupt Enable
1 : enables interrupt on the UDRE0 flag

0 : no interrupt.

### Bit 4 - RXEN0: Receiver Enable
1 : The Receiver will override normal port operation for the RxDn pin

0 : Receiver will flush the receive buffer invalidating the FEn, DORn and UPEn flags.

### Bit 3 - TXEN0: Transmitter Enable
1 : The Transmitter will override normal port operation for the TxDn pin

0 : the Transmitter will not become effective until ongoing and pending transmissions are completed

### Bit 2 - UCSZ02: Character Size
1 : number of data bits (character size) in a frame the Receiver and Transmitter use

0 :nil

### Bit 1 - RXB8n: Receive Data Bit 8
RXB8n is the ninth data bit of the received character when operating with serial frames with 9-data bits. Must be read before reading the low bits from UDR0.


### Bit 0 - TXB8n: Transmit Data Bit 8
TXB8n is the 9th data bit in the character to be transmitted when operating with serial frames with 9 data bits. Must be written before writing the low bits to UDR0.



### UCSR0C

D7       |D6      |D5      |D4      |D3       |D2      |D1       |D0      
---------|--------|--------|--------|---------|--------|---------|---------
URSEL0   |UMSEL0  |UPM10   |UPM00   |USBS0     |UCSZ10  |UCSZ00   |UCPOL0
----------------------------------------------------------------------------

---![Screenshot 2023-02-05 062042](https://user-images.githubusercontent.com/64925270/216795165-f429c221-87e5-4950-85ee-10c5cbfd5fca.png)
-


:point_right:***Arduino uno<br/>***

:point_right:***UART Module<br/>***

###Special thanks to Dr. Md. Raqibul Hasan:hearts: <a href ="https://www.aust.edu/cse/faculty_member/dr_md_raqibul_hasan">profile</a>
