// fait les règlages du BT
void setupBT() {
  String BTconnected = "";
  // vérifie si le module HC-06 est bien connecté
  String response = "";
  while (response != "ATOK") {
    BTconnected = BTSerie.write("AT");
    if (BTSerie.available()) {
      while (BTSerie.available()) {
        response = response + BTSerie.read();
      }
    }
    delay(100);
  }
  // met le baud rate à 9600
  BTSerie.write("AT+BAUD4");
  // initialise le nom et le mot de passe du BT
  BTSerie.write(nomBT);
  BTSerie.write(pinBT);
}

void setup() {
  Serial.begin(9600);
  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  pinMode(chargement, INPUT);
  setupBT();

  /* Initialise le port I2C */
  Wire.begin();
}
