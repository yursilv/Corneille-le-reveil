/* tout ce qui concerne le BT */
#include <SoftwareSerial.h>
int RxD = 10;    //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
int TxD = 11;    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);
char nomBT[] = "AT+NAMEprojetJSY"; // write() ne prend pas en paramètre des String
char pinBT[] = "AT+PIN1234";

int randSpeed1;
int randSpeed2;
int moteur1 = 5; // sorite PWM 1 (pour le premier moteur)
int moteur2 = 6; // sorite PWM 2 (pour le deuxième moteur)
const float seuilTensionMoyenne = 2; // (en V) la valeur fournie sans accélération est normalement entre 1.4 et 1.6 V;
const float seuilTemps = 200; // (en ms)
boolean chronoStartLoop = false;
boolean chronoStartPickUp = false;
int chargement = 2;
boolean modeActif = false;
int buzzer = 7;

int infosBT[16];
/* 0-6 - infos pour synchroniser l'horloge; 7 - min; 8 - heure; 9-15 - jours de la semaine (0 ou le nombre correspondant) */
