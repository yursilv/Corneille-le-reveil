#include "DS1307.h"
#include <Wire.h>
int infosHorloge[3]; // 0 - min, 1 - heure, 2 - jour

/* Rétro-compatibilité avec Arduino 1.x et antérieur */
#if ARDUINO >= 100
#define Wire_write(x) Wire.write(x)
#define Wire_read() Wire.read()
#else
#define Wire_write(x) Wire.send(x)
#define Wire_read() Wire.receive()
#endif

/** Fonction de conversion BCD -> decimal */
byte bcd_to_decimal(byte bcd) {
  return (bcd / 16 * 10) + (bcd % 16);
}

/** Fonction de conversion decimal -> BCD */
byte decimal_to_bcd(byte decimal) {
  return (decimal / 10 * 16) + (decimal % 10);
}


/*
   Fonction récupérant l'heure et la date courante à partir du module RTC.
   Place les valeurs lues dans la structure passée en argument (par pointeur).
   N.B. Retourne 1 si le module RTC est arrêté (plus de batterie, horloge arrêtée manuellement, etc.), 0 le reste du temps.
*/
byte read_current_datetime(DateTime_t *datetime) {

  /* Début de la transaction I2C */
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire_write((byte) 0); // Lecture mémoire à l'adresse 0x00
  Wire.endTransmission(); // Fin de la transaction I2C

  /* Lit 7 octets depuis la mémoire du module RTC (le 6ème et le 7ème qui correspondent au mois et à l'année ne sont pas utilisés) */
  Wire.requestFrom(DS1307_ADDRESS, (byte) 7);
  byte raw_seconds = Wire_read();
  datetime->seconds = bcd_to_decimal(raw_seconds);
  datetime->minutes = bcd_to_decimal(Wire_read());
  byte raw_hours = Wire_read();
  if (raw_hours & 64) { // Format 12h
    datetime->hours = bcd_to_decimal(raw_hours & 31);
    datetime->is_pm = raw_hours & 32;
  } else { // Format 24h
    datetime->hours = bcd_to_decimal(raw_hours & 63);
    datetime->is_pm = 0;
  }
  datetime->day_of_week = bcd_to_decimal(Wire_read());
  datetime->days = bcd_to_decimal(Wire_read());
  datetime->months = bcd_to_decimal(Wire_read());
  datetime->year = bcd_to_decimal(Wire_read());

  /* Si le bit 7 des secondes == 1 : le module RTC est arrêté */
  return raw_seconds & 128;
}


/**
   Fonction ajustant l'heure et la date courante du module RTC à partir des informations fournies.
   N.B. Redémarre l'horloge du module RTC si nécessaire.
*/
void adjust_current_datetime(DateTime_t *datetime) {

  /* Début de la transaction I2C */
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire_write((byte) 0); // Ecriture mémoire à l'adresse 0x00
  Wire_write(decimal_to_bcd(datetime->seconds) & 127); // CH = 0
  Wire_write(decimal_to_bcd(datetime->minutes));
  Wire_write(decimal_to_bcd(datetime->hours) & 63); // Mode 24h
  Wire_write(decimal_to_bcd(datetime->day_of_week));
  Wire_write(decimal_to_bcd(datetime->days));
  Wire_write(decimal_to_bcd(datetime->months));
  Wire_write(decimal_to_bcd(datetime->year));
  Wire.endTransmission(); // Fin de transaction I2C
}

/* sert à synchroniser l'horloge avec la date et l'heure du téléphone */
void initialiserHorloge(DateTime_t now, int ss, int mm, int HH, int uu, int dd, int MM, int yy) {
  now.seconds = ss;
  now.minutes = mm;
  now.hours = HH;
  now.is_pm = 0;
  now.day_of_week = uu;
  now.days = dd;
  now.months = MM;
  now.year = yy;
  adjust_current_datetime(&now);
}

/* permet de lire l'heure courante et le jour courant */
void lireInfosHorloge() {
  DateTime_t now;
  read_current_datetime(&now);

  infosHorloge[0] = now.minutes;
  infosHorloge[1] = now.hours;
  infosHorloge[2] = now.day_of_week;
}
