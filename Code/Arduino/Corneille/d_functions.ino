void deplacements() {
  // le réveil va changer de direction de déplacement toutes les 1-3 s
  int randDelay = random(1000, 3000);
  // travaille à faire sur les vitesses après: la vitesse moyenne doit telle que seuilTension ne soit pas dépassé
  // pour ça il faut faire des tests
  randSpeed1 = random(150, 256);
  randSpeed2 = random(150, 256);
  analogWrite(moteur1, randSpeed1);
  analogWrite(moteur2, randSpeed2);
  delay(randDelay);
}

boolean pickUp() {
  float x=analogRead(0)/204.6;
  float y=analogRead(1)/204.6;
  float z=analogRead(2)/204.6;
  float moyenne = (x+y+z)/3;
  int chrono;
  /*lorsque la tension moyenne délivrée par les 3 axes dépasse 
   le "seuilTension" (il y a une accélération importante) et reste
   supérieure pendant "seuilTemps" (en ms) le réveil passe en mode "veille"*/
  if (moyenne > seuilTensionMoyenne) {
    if (chronoStartPickUp == false) {
      chrono = millis();
      chronoStartPickUp = true;
    }
    if (millis()-chrono > seuilTemps) {
      return true;
    }
  }
  if (moyenne < seuilTensionMoyenne and chronoStartPickUp == true) {
    chronoStartPickUp = false;
  }
  return false;
}

// vérifie si l'info envoyée sur la carte par BT commencent par "999" (la clé) et rend ce qu'il y a après (ou null sinon)
void lireInfosBT() {
  String dataString[17];
  int dataInt[17];
  if (BTSerie.available()) {
    int i = 0;
    while (BTSerie.available()) {
      char c = BTSerie.read();
      if (c == ',') {
        dataInt[i] = dataString[i].toInt();
        i++;
      } else {
        dataString[i] = dataString[i] + c;
      }
    }
  }
  if (dataString[0] == "999") {
    for (int i=0; i<=15; i++) {
      infosBT[i] = dataInt[i+1];
    }
    DateTime_t now;
    initialiserHorloge(now, infosBT[0], infosBT[1], infosBT[2], infosBT[3], infosBT[4], infosBT[5], infosBT[6]);
  }
}

// vérifie s'il faut activer le réveil
boolean activation() {
  for (int i=0; i<=1; i++) {
    if (infosHorloge[i]!=infosBT[i+7]) {
      return false;
    }
  }
  for (int i=9; i<=15; i++) {
    if (infosHorloge[2]==infosBT[i]) {
      return true;
    }
  }
  return false;
}

// vérifie si Corneille est sur son socle
boolean surSocle() {
  if (digitalRead(chargement)) {
    return true;
  } else {
    return false;
  }
}

