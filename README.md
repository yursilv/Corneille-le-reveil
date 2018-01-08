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

Deux moteurs à courant continu qui seront asservis par l’Arduino. Chaque moteur commande une roue.

Une batterie pour alimenter les moteurs.

Une carte d’Arduino.

Plusieurs Led afin d’afficher l’heure.

Un module Bluetooth pour pouvoir contrôler le réveil à distance.

Un accéléromètre pour pouvoir détecter la variation d’altitude du réveil.

Un synthétiseur vocal qu  délivre des messages audio à l’utilisateur.

Bobines pour faire le socle.

Un module horloge.

Un convertisseur boost :module à base de MT3608. (0,33 e à 2,05e)

Un module pour charger une batterie: un module à base de TP4056.

Une batterie LiPo ou Li-ion.

Un systeme de cremaillere (roue + ligne crantée) pour déplacer un poids.

Une sphère transparente (https://fr.aliexpress.com/item/Transparent-clear-plastic-ball-hollow-sphere-store-window-wedding-favor-box-decoration-ornament-balls-candy-box/32609381016.html?src=google&albslr=205711857&isdl=y&aff_short_key=UneMJZVf&source=%7Bifdyn:dyn%7D%7Bifpla:pla%7D%7Bifdbm:DBM&albch=DID%7D&src=google&albch=shopping&acnt=494-037-6276&isdl=y&albcp=653151748&albag=36672819047&slnk=&trgt=57344828050&plac=&crea=fr32609381016&netw=g&device=c&mtctp=&gclid=EAIaIQobChMI4LTZiInI2AIV5RXTCh24awLUEAQYASABEgKIMPD_BwE).
