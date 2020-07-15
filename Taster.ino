
// Unterprogramm zur Abfrage der Pins

void CheckStateInputPins() {

DoorLockedState = digitalRead(DoorLockedPin);
      Serial.print("Doorlock Reading is: ");
      Serial.println(DoorLockedState);

DoorUnlockedState = digitalRead(DoorUnlockedPin);
      Serial.print("DoorUnlock Reading is: ");
      Serial.println(DoorUnlockedState);
      
DoorState = digitalRead(DoorStatePin);
      Serial.print("Door Reading is: ");
      Serial.println(DoorState);
      if (DoorState == LOW) {
        Serial.println("Tür geschlossen");
      }
      else {
        Serial.println("Tür offen");
      
      }

}


//boolean DoorLockedState;
//boolean DoorUnlockedState;
