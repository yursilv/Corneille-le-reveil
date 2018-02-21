# Cahier de suivi du projet de Saveria FRATI-PERALDI

* Semaine du 08/01/18

Je m’attèle à comprendre comment marche le chargement par induction.

Ci -joint mes notes: « Les chargeurs par induction sont aussi appelés chargeurs sans fil, du fait de leur fonctionnement reposant sur l’induction électromagnétique. Le système génère un signal électrique qui permet de de recharger (dans notre cas, les chargeurs sans fil à induction).
Plus en détails, la charge par induction consiste à générer de l’énergie qui transite via un champ électromagnétique sur une très courte distance afin d’être récupérée ensuite par les capteurs d’énergie du téléphone pour enfin être transmis à la batterie.
La norme Qi est conçue pour les appareils (smartphones, appareils photo et télécommandes) utilisant au maximum 5 watts de puissance ( après vérification, l’Arduino est compatible). La norme Qi est basée sur la transmission d’énergie sans fil sur une distance maximale de 40 mm.»

Il faut donc choisir quel type de batterie utiliser, nous choisissons Li-ion par défaut. Le principe du chargement est le suivant (ci-joint schéma) : schéma.pdf.
Attention, il faut impérativement que le chargeur intégré à ton socle soit équipé d'une protection contre les courts-circuits, car il est facile de court-circuiter des contacts "nus". Un fusible réarmable (polyswitch) fait l'affaire en général.

On prend la décision de commander :

-Bobines améliorées : https://fr.aliexpress.com/item/Universal-Sans-Fil-Alimentation-Bobine-Chargeur-Circuit-De-Charge-Module-Pour-Mobile-T-l-phones-R/32839115395.html?spm=a2g0w.search0104.3.174.bgpmpD&ws_ab_test=searchweb0_0%2Csearchweb201602_2_10152_10151_10065_10344_10068_10342_10343_10340_10341_10084_10083_10613_10305_10304_10615_10307_10614_10306_10302_10059_10314_10184_10534_100031_10604_10103_10142%2Csearchweb201603_25%2CppcSwitch_5&algo_expid=0b4ab953-2af3-422a-af06-a752f2554a33-26&algo_pvid=0b4ab953-2af3-422a-af06-a752f2554a33&priceBeautifyAB=0

-Sphère : https://fr.aliexpress.com/item/Transparent-clear-plastic-ball-hollow-sphere-store-window-wedding-favor-box-decoration-ornament-balls-candy-box/32609381016.html?spm=a2g0w.search0104.3.1.TxeFcx&ws_ab_test=searchweb0_0,searchweb201602_2_10152_10151_10065_10344_10068_10342_10343_10340_10341_10084_10083_10613_10305_10304_10615_10307_10614_10306_10302_10059_10314_10184_10534_100031_10604_10103_10142,searchweb201603_25,ppcSwitch_5&algo_expid=1d737cb7-43c2-4275-921f-578f4fbf76d3-0&algo_pvid=1d737cb7-43c2-4275-921f-578f4fbf76d3&priceBeautifyAB=0

Il va te falloir quelque chose capable de charger une batterie, par exemple un module à base de TP4056 pour gérer la charge une cellule LiPo (bien choisir la résistance qui définie l'intensité de charge en fonction de la batterie et de l'alim). 
En sortie on a une tension variant de 3.7 à 4.2V en fonction de la charge de la batterie, donc tu peux ajouter un convertisseur boost (module à base de MT3608 par exemple) à la suite pour amener la tension finale à 5V pour alimenter l'arduino.


* Semaine du 15/01/18
prototype en carton et premier test

* Semaine du 22/01/18
dem semaine apres mise en place du prototype en carton

* Semaine du 29/01/18
semaine de ski (neant)

* Semaine du 05/02/18

Sur papier, à retranscrire (fabrication du socle) réception des bobines à induction
il faut commandr une batterie rechargeable avec port micro usb

* Semaine du 12/02/18
pas darduino cette semaine, je navance pas sur le projet de mon coté

* Semaine du 19/02/18
Je mets à jour mon cahier d'avancement. On estime que le driver des moteurs actuel (L298N) est trop gros pour la structure, Yuri et moi en récupèrons un plus petit (L293D) que le précédent (environ 4 fois). J'essaie de faire le lien entre les deux pour pouvoir l'intégrer à notre structure. Il va peut-être falloir y ajouter un NAND. On a pas reçu la batterie speciale donc je ne peux pas avancer sur mon socle. 
