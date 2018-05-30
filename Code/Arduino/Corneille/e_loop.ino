void loop() {
  if (!modeActif) {
    int chrono;
    if (chronoStartLoop == false) {
      int chrono = millis();
      chronoStartLoop = true;
    }
    if (millis()-chrono > 1000) { //lit l'heure toutes les secondes
      chronoStartLoop = false;
      lireInfosHorloge();
    }
    lireInfosBT();
    if (!surSocle()) {
      modeActif = activation();
    }
  } else {
    deplacements();
    tone(buzzer,2000,600000);
    if (pickUp()) {
      modeActif == false;
    }
  }
}
