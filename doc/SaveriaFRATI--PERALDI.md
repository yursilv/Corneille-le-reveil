<h1>Cahier de suivi du projet de Saveria FRATI--PERALDI</h1>

<h2>Début du projet.</h2>
Yuri, Jérémy et moi décidons de former un groupe, nous nous réunissons autour d'un même projet qu'est "Corneille le réveil".
Au cours de cette séance, et comme mentionné dans mes specs, nous partageons le travail en fonction de nos aptitudes et centres d'intérêts.
<br><b><i>« Nous avons convenu pour les premières semaines du projet que Yuri traiterait essentiellement de ce qui relève de la programmation de l’Arduino et que Jérémy concevrait le schéma et montage de notre prototype. Me concernant, il s’agira d’étudier les similitudes que présentent le projet BB-8 et notre réveil mobile, et faire les recherches nécessaires concernant la fabrication du socle.
En effet, je dois comprendre le but et fonctionnement du BB-8 puis évaluer ses points fort/faible afin de les adapter à notre projet. Je donnerai aussi un dessin illustrant la future apparence du réveil et étudierait les matériaux (notamment de la sphère extérieure) les plus résistants. » </i></b>

<hr>

<h2>Semaine du 08/01/18</h2>

Je m’attèle à comprendre comment marche le chargement par induction. 
Pour celà, j'entreprends des recherches, dont ci -joint mes notes: 
<br><i>« Les chargeurs par induction sont aussi appelés chargeurs sans fil, du fait de leur fonctionnement reposant sur l’induction électromagnétique. Le système génère un signal électrique qui permet de recharger » :</i> dans notre cas, les chargeurs sans fil à induction.
<br><i>« Plus en détails, la charge par induction consiste à générer de l’énergie qui transite via un champ électromagnétique sur une très courte distance afin d’être récupérée ensuite par les capteurs d’énergie du téléphone pour enfin être transmis à la batterie »</i>: il faut trouver le moyen de récupérer cette énergie et la délivrer à la batterie sans endommager ni cette dernière, ni l'Arduino.
<br><i>« La norme Qi est conçue pour les appareils (smartphones, appareils photo et télécommandes) utilisant au maximum 5 watts de puissance » </i>: après vérification, l’Arduino est compatible. 
<br><i>« La norme Qi est basée sur la transmission d’énergie sans fil sur une distance maximale de 40 mm »</i>: si le chargement par induction paraît viable, dès réception des bobines, il faudra vérifier cette distance, et voir si la sphère en plastique sera compatible avec le chargement. <em>cf Semaine du 05/02/18</em>

Il faut maintenant choisir d'utiliser une batterie Li-ion (Lithium - ion) ou LiPo (Lithium Polymère), nous choisissons Li-ion par défaut, puisqu'elle est la plus mentionnée dans les forums que je consulte. 

Le principe du chargement est le suivant (ci-joint schéma) : <b>schéma_chargement.pdf</b>.
Dans les recherches que j'effectue concernant l'intégration des bobines au socle, je note le commentaire d'un utilisateur: <i>« Attention, il faut impérativement que le chargeur intégré à ton socle soit équipé d'une protection contre les courts-circuits, car il est facile de court-circuiter des contacts "nus".»</i> L'utilisateur a aussi prescrit l'utilisation d'un fusible réarmable (polyswitch) qui <i>«fait l'affaire en général»</i>, après vérification auprès de M.Masson et d'autres informations sur Internet, ce composant est adapté à notre projet.

On prend la décision de commander :
  - Bobines améliorées : <b>bobines_induction.jpeg</b> ;
  - Sphère : <b>sphere_transparente.jpeg</b> .

<hr>

<h2>Semaine du 15/01/18</h2>
Cette semaine, sur les bons conseils de M.Masson, nous procédons au démantèlement total de feu BB-8. Nous récupérons les deux moteurs simple arbre et les roues. Nous mettons de coté la plaque de plexiglass (sur laquelle reposait la majorité des composants électroniques), la sphère externe, la batterie et la troisième roue de l'ensemble (qui augmentait l'adhérence de la structure à la sphère extérieure).
Nous créeons un petit prototype en carton de l'ensemble "deux roues + deux moteurs + batterie" (cf. <b>prototype_carton_0.jpg</b>), et nous le testons en pleine classe. Les moteurs marchent bien! 

<hr>

<h2>Semaine du 22/01/18</h2>
Il va te falloir quelque chose capable de charger une batterie, par exemple un module à base de TP4056 pour gérer la charge une cellule LiPo (bien choisir la résistance qui définie l'intensité de charge en fonction de la batterie et de l'alim). 
En sortie on a une tension variant de 3.7 à 4.2V en fonction de la charge de la batterie, donc tu peux ajouter un convertisseur boost (module à base de MT3608 par exemple) à la suite pour amener la tension finale à 5V pour alimenter l'arduino
dem semaine apres mise en place du prototype en carton

<hr>

<h2>Semaine du 29/01/18</h2>
semaine de ski (neant)

<hr>

<h2>Semaine du 05/02/18</h2>

Sur papier, à retranscrire (fabrication du socle) réception des bobines à induction
il faut commandr une batterie rechargeable avec port micro usb

<hr>

<h2>Semaine du 12/02/18</h2>
pas darduino cette semaine, je navance pas sur le projet de mon coté

<hr>

<h2>Semaine du 19/02/18</h2>
Je mets à jour mon cahier d'avancement. On estime que le driver des moteurs actuel (L298N) est trop gros pour la structure, Yuri et moi en récupèrons un plus petit (L293D) que le précédent (environ 4 fois). J'essaie de faire le lien entre les deux pour pouvoir l'intégrer à notre structure. Il va peut-être falloir y ajouter un NAND. On a pas reçu la batterie speciale donc je ne peux pas avancer sur mon socle. 
AJOUTER LES PHOTOS/SCHEMAS de la structure /IMAGES des composats
J'ai transposé tout sur L293D, j'ai aussi pris beaucoup de temps pour ressouder labatterie et les moteurs. La prochaine etape sera de passer du prototype carton au plastique/plexi.
