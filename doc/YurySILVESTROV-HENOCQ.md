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

J'ai l'idée de réaliser une méthode qui, lorsque la connection bluetooth est établie ou lorsque l'on change l'heure de réveil, émet un bruit à partir du module sonore du réveil pour confirmer la réception des informations.

J'ai aussi effectué des recherches sur la peinture translucide qu'on pourrait appliquer à notre sphère pour l'affichage de l'heure. Malheureusement je n'ai pas trouvé grand chose. La seule solution efficace à mon avis serait d'intégrer un petit tableau d'affichage avec des LEDs à la surface intérieure de la sphère et peindre la sphère en noir (ou une autre couleur) en laissant des petit bout transparents pour les LEDs.
