# Cahier de suivi du projet de Yury Silvestrov-Henocq

* Séance du 18 Décembre 2017 

J'ai formé mon groupe avec Saveria et Jeremy.
On a décidé de créer un réveil qui s'enfuit à la manière de Clocky (https://nandahome.com/), mais qui a une forme sphérique, se déplace en roulant, affiche l'heure sur sa surface extêrne et se charge par induction.

Durant cette séance, on s'est mis d'accord sur les différents aspects du projet et on a défini un planning. En ce qui me concerne, je dois plus me concentrer sur la partie programmation du projet.

* Vacances de Noël

J'ai commencé à développer le code Arduino pour notre projet et je me suis rendu compte que pour que le réveil puisse afficher l'heure précise il nous faut un module horloge (par exemple ds1307).

Il faut également avoir une méthode pour déterminer si le réveil est bien sur son socle (pour forcer le mode "veille"). Je pense que le plus simple serait de détecter si le réveil est en train de charger par induction ou pas (s'il y a une tension qui est appliquée au module de chargement). J'ai donc besoin de savoir comment exactement va fonctionner notre socle ce qui est la partie gérée par Saveria.

Sinon j'ai réalisé plusieurs petites méthodes: une méthode de test qui gère les déplacements, une fonction qui règle de manière automatique le module BT etc. Pour détecter qu'on a attrapé le réveil j'ai tout simplement utiliser la tension fornie par l'axe z de l'accéléromètre. Si cette tension est plus élevée qu'une tension de seuil (s'il y a une accélération brusque) le réveil passe en mode "veille".

* Séance du 8 janvier 2018

J'ai décidé d'améliorer la partie du programme qui gère le ramassage du réveil par l'utilisateur. Maintenant on doit aussi définir le seuil du temps en ms. Si la tension délivrée par l'axe z est supérieure à la seulTension pendant un temps défini dans la variable seuilTemps le réveil est considéré ramassé et passe en mode "veille".

J'ai l'idée de réaliser une méthode qui, lorsque la connection bluetooth est établie ou lorsque l'on change l'heure de réveil, émet un bruit à partir du module sonore du réveil pour confirmer la réception des données.

J'ai aussi fait des recherches sur la peinture translucide qu'on pourrait appliquer à notre sphère pour l'affichage de l'heure. Malheureusement je n'ai pas trouvé grand chose. Une solution pour moi serait d'intégrer un petit tableau d'affichage avec des LEDs à la surface de la sphère à l'aide d'un aimant.

* Séance du 15 janvier 2018

Nous avons défait le bb8 de l'année dernière pour récupérer les deux moteurs, mais on hésite encore sur le mode de déplacement de notre réveil au niveau mécanique car il y a plusieurs systèmes possibles qu'on porrait essayer d'intégrer. J'ai donc regardé sur internet les différents modèles de bb8 réalisés avec ou sans arduino pour comprendre quel système serait le plus convenable pour nous.

http://www.instructables.com/id/DIY-Life-Size-Phone-Controlled-BB8-Droid/

http://www.instructables.com/id/DIY-Bluetooth-Phone-Controlled-BB-8-Droid-With-Ard/

https://ouiaremakers.com/posts/tutoriel-diy-un-clone-de-bb8

https://www.youtube.com/watch?v=p0MQ6b6bVsU

https://www.youtube.com/watch?v=iQ_PKRjQpDY

Finalement je pense que le modèle avec les deux roues convient le plus.

* Séance du 22 janvier 2018

Nous avons fait la présentation et à la fin de la séance on a pu tester le fonctionnement des moteurs avec le module de contrôle et voir que tout marche bien.

* Vacances de Ski

J'ai commencé à développer notre application Android. Les fonctionnalités qui me posent le plus de problèmes sont la connection et la transmission de données par bluetooth. En effet, il y a un grand nombre de notions de programmation que je ne connais pas dans les tutos trouvés sur internet, notamment l'utilisation des "thread" et des "socket". Finalement en cherchant un peu partout j'ai réussi à créer un programme dont je comprend le fonctionnement et il ne reste plus qu'à le tester la séance prochaine.

Liens utilisés pour le "timepicker" :

http://abhiandroid.com/ui/timepicker

https://android--code.blogspot.fr/2015/08/android-timepickerdialog-theme.html

Liens utilisés pour la connection BT :

http://www.tutos-android.com/utilisation-bluetooth-application-android

http://sberfini.developpez.com/tutoriaux/android/bluetooth/

* Séance du 4 mai 2018

J'ai travaillé sur la synchronisation automatique de l'heure du réveil avec l'heure du portable.

* Séance du 14 mai 2018

J'ai presque fini le code côté Arduino. Le plus gros problème qu'il faut résoudre en ce moment, c'est la trasmission par bluetooth, car apparemment il y a une quantité de données assez limitée qu'il peut transmettre en une fois (j'ai découvert ça quand j'ai vu qu'une partie des données envoyées était perdue). J'ai donc condensé les données en enlevant les séparateurs, mais il reste maintenant à bien les lire et mettre dans un tableau côté Arduino.

* Séance au Fablab

Nous avons passé toute l'après-midi au Fablab, j'ai soudé tous les composants sur la plaque à essai, mais sans tests, difficile à dire si ça a été fait correctement. Donc il faut tester au plus vite.
