#include <SoftwareSerial.h>  //Software Serial Port  
#define RxD 10    //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define TxD 11    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);
String const nomBT = "projetJSY";
String const pinBT = "384653";

int randSpeed1;
int randSpeed2;
int moteur1 = 5; // sorite PWM 1 (pour le premier moteur)
int moteur2 = 6; // sorite PWM 2 (pour le deuxième moteur)
const float seuilTension = 2; // (en V) la valeur fournie sans accélération est normalement égale à 1.4 - 1.6 V;
const float seuilTemps = 200; // (en ms)
boolean modeActif = false;
// DdMmYyHhSs
String alarm = "";

void setup() {
  Serial.begin(9600);
  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  setupBT();
}

void loop() {
  updateAlarm();
  // si l'heure de réveil est définie
  if (alarm != "") {
    // si le réveil n'est pas sur le socle
    if (surSocle == false) {
      if (heure == alarm) {
        modeActif = true;
      }
      if (modeActif == true) {
        actif();
        z=analogRead(0)/204.6;
        /*lorsque la tension délivrée par l'axe z dépasse 
        le "seuilTension" (il y a une accélération importante) et reste
        supérieure pendant "seuilTemps" ms le réveil passe en mode "veille"*/
        if (z > seuilTension) {
          if (chronoStart == false) {
            chrono = millis();
            chronoStart = true;
          }
          if (millis()-chrono > seuilTemps) {
            modeActif = false;
          }
        }
        if (z < seuilTension and chronoStart == true) {
          chronoStart = false;
        }
      }
    }
  }
}

void actif() {
  // le réveil va changer de direction de déplacement toutes les 1-3 s
  randDelay = random(1000, 3000);
  // (travaille à faire sur les vitesses après: la vitesse moyenne ne doit pas être trop petite)
  randSpeed1 = random(150, 256);
  randSpeed2 = random(150, 256);
  analogWrite(moteur1, randSpeed1);
  analogWrite(moteur2, randSpeed2);
  delay(randDelay);
}

// fait les règlages du BT
void setupBT() {
  String BTconnected = "";
  // vérifie si le module HC-06 est bien connecté
  while (BTconnected != "ATOK") {
    BTconnected = BTSerie.write("AT");
    delay(100);
  }
  BTSerie.write("AT+BAUD4");
  // initialise le nom et le mot de passe du BT
  BTSerie.write("AT+NAME"+nomBT);
  BTSerie.write("AT+PIN"+pinBT);
}

// met à jour l'heure de réveil définie par l'utilisateur (à finir)
void updateAlarm() {
  char alarmChar;
  while (BTSerie.available()) {
    alarmChar = BTSerie.read();
    alarm = alarm + alarmChar;
  }
}
