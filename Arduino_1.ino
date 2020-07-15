/* Projekt 4 der Gebaeudeenergie- und -informationstechnik SS2020 @ HTW_Berlin
 *  Administrative responsible person: Herr Baumann email: baumann@htw-berlin.de
 *  Module: Analog- und Digitalelektronik G42
 *
 *  Members of this project: Siad El-Masri, Jens Heinel, Anton Knigge, Jonas Graw sowie ehemals 2 weitere...
 *  Date of Version: 6.15.2020
 *  Description: Servo Engine and RFID And Display- Module in a so far functional state.
 *  Both Sketches above are merged.
 *  
 *  Functional Description:
 *  
 *  There is the RFID Module - reading the 13Mhz RFID-Cards, which are then checked for verification.
 *  After approved RFID-Code was sensed, there is beginning Communication to the second Arduino via i2C
 *  By sending the information over i2C, the connected second 32u2 is then used to give create Output on
 *  the attached Display for us safety related lookup through 3 different microswitches.
 *  One is related the state of the door and two further ones which sense the position of the servo motor.
 *  
 *  We are not responsible in any way for damage in case of using this code, which you are intended to use as
 *  part of the GPL and it's underlying regulatories.
 * 
 *  
  */


  /* Pin Assignments:
   *  
   *  Output:
   *    Servo = digital 3
   *    Servo Vcc = 5V
   * 
   RST/Reset   RST          9            
   SPI SS      SDA(SS)(IRQ) 10          
   SPI MOSI    MOSI         11 / ICSP-4  
   SPI MISO    MISO         12 / ICSP-1 
   SPI SCK     SCK          13 / ICSP-3 
   *  
   */



// ####################################################################
// Inkludiere folgende Libraries --------------------------------------
// ####################################################################

#include <Arduino.h>

#include <EEPROM.h>                   // We are going to read and write PICC's UIDs from/to EEPROM
#include <SPI.h>                      // RC522 Module uses SPI protocol
#include <MFRC522.h>                  // Library for Mifare RC522 Devices
#include <U8x8lib.h>                  // Library for Display Device
#include <Servo.h>                    // Library for Servo-Motor

#define wipeB 3                       // Button pin for WipeMode

// Create MFRC522 instance.
#define SS_PIN 10
#define RST_PIN 9


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

MFRC522 mfrc522(SS_PIN, RST_PIN);     // eröffne Instanz RFID-Reader
Servo myservo;                        // create servo object to control a servo

// Variablen fuer RFID-Reader
bool programMode = false;             // initialize programming mode to false
uint8_t successRead;                  // Variable integer to keep if we have Successful Read from Reader
byte storedCard[4];                   // Stores an ID read from EEPROM
byte readCard[4];                     // Stores scanned ID read from RFID Module
byte masterCard[4];                   // Stores master card's ID read from EEPROM

// Initialisieren des Displaytreibers
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// Variablen fuer Programmablauf
boolean DoorLockedState;
boolean DoorUnlockedState;
boolean DoorState;

const int DoorLockedPin = 2;
const int DoorUnlockedPin = 4;
const int DoorStatePin = 7;

int ServoPin = 6;
int PositionClosed = 0;
int PositionOpened = 180;



void setup() {
  
  Serial.begin(9600);  // Initialize serial communications with PC
  SPI.begin();           // MFRC522 Hardware uses SPI protocol
  myservo.attach(ServoPin);  // attaches the servo on pin 6 to the servo object

  
  pinMode(DoorLockedPin, INPUT_PULLUP);   // Enable pin's pull up resistor
  pinMode(DoorUnlockedPin, INPUT_PULLUP);   // Enable pin's pull up resistor
  pinMode(DoorStatePin, INPUT_PULLUP);   // Enable pin's pull up resistor

  myservo.write(PositionClosed);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  CheckStateInputPins();

  
  u8x8.setFont(u8x8_font_chroma48medium8_r);  // Set Font for Display
  u8x8.begin();
  
  Display_boot();           //Unterprogramm Anzeige Starte Display
  delay(800);

// Abfrage nach geschlossener Tuer sonst HALT

  if (DoorState == HIGH) {
    doorOpen();
  }
  //  Bootsequenz RFID-Modul
  RFID_boot();
  
  
  
}


void loop() {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  RFID_loop();

}
