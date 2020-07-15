
/*
 * Nachfolgend die Visualisierung des Displays in Unterprogrammen
 */



void Display_boot() {

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  //u8x8.begin();
  u8x8.clearDisplay();
  drawFirstLine();
  u8x8.drawString(0,2,"starte Display");
  for(int i = 0; i <= 14; i++)  {
    u8x8.drawString(i,3,".");
  delay(50);
  }
  
  u8x8.setPowerSave(0);
}

void drawFirstLine() {
  u8x8.drawString(0,0,"HTW - SmartDoor");
}

void doorOpenDisp() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"TUER OFFEN!");
  u8x8.drawString(0,2,"Bitte Tuer");
  u8x8.drawString(0,3,"schliessen!");
}

void doorLocked() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"TUER VERRIEGELT!");
}

void wipeDisp() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"ZURUECKSETZEN!");
  u8x8.drawString(0,1,"10 Sekunden");
  u8x8.drawString(0,2,"halten zum");
  u8x8.drawString(0,3,"loeschen!");
}

void wipedDisp() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"ZURUECKSETZEN!");
  u8x8.drawString(0,1,"Speicher");
  u8x8.drawString(0,2,"erfolgreich");
  u8x8.drawString(0,3,"geloescht!");
}

void wipecanceled() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"ZURUECKSETZEN!");
  u8x8.drawString(0,2,"Loeschvorgang");
  u8x8.drawString(0,3,"abgebrochen");
}

void masterdef() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"ZURUECKSETZEN!");
  u8x8.drawString(0,1,"keine MasterCard");
  u8x8.drawString(0,2,"Bitte Scanne");
  u8x8.drawString(0,3,"neue Mastercard");
}

void masterdefined() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"ZURUECKSETZEN!");
  u8x8.drawString(0,1,"MasterCard");
  u8x8.drawString(0,2,"erfolgreich");
  u8x8.drawString(0,3,"erstellt!");
}

void error() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"-SYSTEMFEHLER!-");
  u8x8.drawString(0,1,"Bitte");
  u8x8.drawString(0,2,"ueberpruefe");
  u8x8.drawString(0,3,"Verbindungen!");
}

void doorOpen() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"-ACHTUNG!-");
  u8x8.drawString(0,1,"Tuer offen!!");
  u8x8.drawString(0,2,"Bitte Tuer");
  u8x8.drawString(0,3,"schliessen");
}

void reading_card() {
  u8x8.clearDisplay();
  drawFirstLine();
  u8x8.drawString(0,2,"lese Karte");
  for(int i = 10; i <= 15; i++)  {
    u8x8.drawString(i,2,".");
    delay(100);
  }
}

void progMode() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"Karte loeschen/");
  u8x8.drawString(0,2,"hinzufuegen:");
  u8x8.drawString(0,3,"EXIT:scan MASTER");
}

void exitProgMode() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,2,"verlasse den");
  u8x8.drawString(0,3,"Programmiermodus");
}

void addCard() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"Karte wird");
  u8x8.drawString(0,2,"hinzugefuegt");
  for(int i = 0; i <= 14; i++)  {
    u8x8.drawString(i,3,".");
    delay(100);
  }
}

void cardAdded() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"Karte");
  u8x8.drawString(0,2,"erfolgreich");
  u8x8.drawString(0,3,"hinzugefuegt!");
}

void cardNotAdded() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"FEHLER!!!");
  u8x8.drawString(0,2,"Karte nicht");
  u8x8.drawString(0,3,"hinzugefuegt!");
}

void remCard() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"Karte wird");
  u8x8.drawString(0,2,"geloescht");
  for(int i = 0; i <= 14; i++)  {
    u8x8.drawString(i,3,".");
    delay(100);
  }
}

void cardRem() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"Karte");
  u8x8.drawString(0,2,"erfolgreich");
  u8x8.drawString(0,3,"geloescht!");
}

void cardNotRem() {
  u8x8.clearDisplay();
  u8x8.drawString(0,0,"Programmiermodus");
  u8x8.drawString(0,1,"FEHLER!!!");
  u8x8.drawString(0,2,"Karte nicht");
  u8x8.drawString(0,3,"geloescht!");
}

void scanCard() {
  u8x8.clearDisplay();
  drawFirstLine();
  u8x8.drawString(0,1,"BEREIT");
  u8x8.drawString(0,2,"Bitte Karte");
  u8x8.drawString(0,3,"scannen!");
}

void access() {
  u8x8.clearDisplay();
  drawFirstLine();
  u8x8.drawString(0,1,"WILKOMMEN!");
  u8x8.drawString(0,2,"Tuer wird");
  u8x8.drawString(0,3,"entsperrt!");
}

void noAccess() {
  u8x8.clearDisplay();
  drawFirstLine();
  u8x8.drawString(0,1,"SORRY!");
  u8x8.drawString(0,2,"kein Zugriff!");
  u8x8.drawString(0,3,"Karte unbekannt!");
}
