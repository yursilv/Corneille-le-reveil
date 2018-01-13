![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'Nice Sophia

# Corneille-le-reveil
Projet Arduino : réveil roulant

![Corneille le réveil](https://img15.hostingpics.net/pics/173985tocky.jpg)

# Description du projet

Corneille le réveil est un projet Arduino dont le but est la création d'un réveil qui non seulement produit des bruits désagréables mais qui en plus roule sans arrêt pour nous empêcher de l'éteindre.

# Fonctionnalités

Corneille le réveil a une forme sphérique et projette l'heure actuelle sur sa surface extérieure. Lorsqu'il faut se réveiller, il passe en mode "actif" en sortant un son pré-enregistré et se déplace de manière aléatoire en roulant comme le droïde BB-8 de Star Wars, le seul moyen de l’éteindre étant de l'attraper. Une application sous Android est mise en place pour régler l'heure et la date du réveil depuis son mobile.


Le chargement du réveil se fait par induction sur un socle spécial. Lorsque le réveil se trouve sur le socle, il est en mode "veille" et ne peut donc pas se déplacer.

# Materiel utilisé

Un moteur à double arbre(https://fr.aliexpress.com/item/1pcs-lot-K803-Double-Output-Shaft-DC-Motor-1-5-6V-3V-11000rpm-DIY-Model-Making/32738378510.html?src=google&albslr=229364883&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=61865531738&plac=&crea=fr32738378510&netw=g&device=c&mtctp=&gclid=Cj0KCQiAyszSBRDJARIsAHAqQ4qwRn1335biiy_gyZQhkbwpWmwhq-Y1AqSzrQt87_KIMnHnsF4aic4aAs8eEALw_wcB).

Une batterie pour alimenter les moteurs.

Une carte d’Arduino.

Plusieurs Led afin d’afficher l’heure.

Un module Bluetooth pour pouvoir contrôler le réveil à distance.

Un accéléromètre pour pouvoir détecter la variation d’altitude du réveil.

Un synthétiseur vocal qu  délivre des messages audio à l’utilisateur.

Bobines pour faire le socle (https://www.aliexpress.com/item/Wireless-power-supply-experimental-suite-small-size-ultra-thin-wireless-inductive-power-supply-wireless-charging-DIY/32759633964.html?spm=a2g0s.9042311.0.0.d3KMgS).

Un module horloge (par ex. ds1307)

Un convertisseur boost: module à base de MT3608. (0,33 e à 2,05e)

Un module pour charger une batterie: un module à base de TP4056.

Une batterie LiPo ou Li-ion.

Un systeme de cremaillere (roue dirigée par un servo-moteur + ligne crantée) pour déplacer un poids.

Des roulements à bille et un bloc(ou une cage) pour fixer le système electronique dans la sphère sans contact avec cette dernière.

Une sphère transparente (https://fr.aliexpress.com/item/Transparent-clear-plastic-ball-hollow-sphere-store-window-wedding-favor-box-decoration-ornament-balls-candy-box/32609381016.html?src=google&albslr=205711857&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=57344828050&plac=&crea=fr32609381016&netw=g&device=c&mtctp=&gclid=EAIaIQobChMI4LTZiInI2AIV5RXTCh24awLUEAQYASABEgKIMPD_BwE).
