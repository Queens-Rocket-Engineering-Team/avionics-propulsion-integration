// haha oh SHIT (receiver edition)

#include "STM32_CAN.h"
#include <SoftwareSerial.h>

#define CAN_RX_PIN PB8
#define CAN_TX_PIN PB9
#define USB_RX_PIN PA10
#define USB_TX_PIN PA9

#define USB_BAUD 9600 // FUCK IT 9600 BOYSSS


// FUCK hardware serial periperhals we doin SOFTWARE
SoftwareSerial usb(USB_RX_PIN, USB_TX_PIN); 
// CANBUS trash wahooo
STM32_CAN canb( CAN1, ALT );    //CAN1 ALT is PB8+PB9
static CAN_message_t CAN_msg ;




void setup() {
  // setup canubs
  canb.begin(); //automatic retransmission can be done using arg "true"
  canb.setBaudRate(500000); //500kbps
  // setup usb serial
  usb.begin(USB_BAUD);
}//setup()

void loop() {
  // put your main code here, to run repeatedly:
  while (canb.read(CAN_msg)) {
    usb.print(F("CAN ID = "));
    usb.println(CAN_msg.id, BIN);
    usb.print("CAN PAYLOAD = ");
    usb.print(CAN_msg.buf[0], HEX);
    usb.print(CAN_msg.buf[1], HEX);
    usb.print(CAN_msg.buf[2], HEX);
    usb.print(CAN_msg.buf[3], HEX);
  }//while
  delay(250);
}//loop()
