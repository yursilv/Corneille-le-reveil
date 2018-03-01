<h1>Cahier de suivi du projet de Saveria FRATI--PERALDI</h1>

<h2>Début du projet.</h2>
Yuri, Jérémy et moi décidons de former un groupe, nous nous réunissons autour d'un même projet qu'est "Corneille le réveil", qui s'inspire largement du principe de Clocky (<b>clocky.jpg</b>), un réveil actuellement commercialisé, et du projet BB8 de l'année dernière (<b>BB8_1.jpg</b>).
Au cours de cette séance, et comme mentionné dans mes specs, nous partageons le travail en fonction de nos aptitudes et centres d'intérêts.
<br></br>
<b><i>« Nous avons convenu pour les premières semaines du projet que Yuri traiterait essentiellement de ce qui relève de la programmation de l’Arduino et que Jérémy concevrait le schéma et montage de notre prototype. Me concernant, il s’agira d’étudier les similitudes que présentent le projet BB-8 et notre réveil mobile, et faire les recherches nécessaires concernant la fabrication du socle.
En effet, je dois comprendre le but et fonctionnement du BB-8 puis évaluer ses points fort/faible afin de les adapter à notre projet. Je donnerai aussi un dessin illustrant la future apparence du réveil et étudierait les matériaux (notamment de la sphère extérieure) les plus résistants. » </i></b>

<hr>

<h2>Semaine du 08/01/18</h2>

Je m’attèle à comprendre comment marche le chargement par induction. 
Pour celà, j'entreprends des recherches, dont ci -joint mes notes: 
<br/>
<i>« Les chargeurs par induction sont aussi appelés chargeurs sans fil, du fait de leur fonctionnement reposant sur l’induction électromagnétique. Le système génère un signal électrique qui permet de recharger » :</i> dans notre cas, les chargeurs sans fil à induction.
<br/>
<i>« Plus en détails, la charge par induction consiste à générer de l’énergie qui transite via un champ électromagnétique sur une très courte distance afin d’être récupérée ensuite par les capteurs d’énergie du téléphone pour enfin être transmis à la batterie »</i>: il faut trouver le moyen de récupérer cette énergie et la délivrer à la batterie sans endommager ni cette dernière, ni l'Arduino.
<br/>
<i>« La norme Qi est conçue pour les appareils (smartphones, appareils photo et télécommandes) utilisant au maximum 5 watts de puissance » </i>: après vérification, l’Arduino est compatible. 
<br/>
<i>« La norme Qi est basée sur la transmission d’énergie sans fil sur une distance maximale de 40 mm »</i>: si le chargement par induction paraît viable, dès réception des bobines, il faudra vérifier cette distance, et voir si la sphère en plastique sera compatible avec le chargement. <em>cf Semaine du 05/02/18</em>
<br/>
Il faut maintenant choisir d'utiliser une batterie Li-ion (Lithium - ion) ou LiPo (Lithium Polymère), nous choisissons Li-ion par défaut, puisqu'elle est la plus mentionnée dans les forums que je consulte. 
<br/>
Le principe du chargement est le suivant (ci-joint schéma) : <b>schéma_chargement.pdf</b>.
Dans les recherches que j'effectue concernant l'intégration des bobines au socle, je note le commentaire d'un utilisateur: <i>« Attention, il faut impérativement que le chargeur intégré à ton socle soit équipé d'une protection contre les courts-circuits, car il est facile de court-circuiter des contacts "nus".»</i> L'utilisateur a aussi prescrit l'utilisation d'un fusible réarmable (polyswitch) qui <i>«fait l'affaire en général»</i>, après vérification auprès de M.Masson et d'autres informations sur Internet, ce composant est adapté à notre projet.
<br/>
On prend la décision de commander :
  - Bobines améliorées : <b>bobines_induction.jpeg</b> ;
  - Sphère : <b>sphere_transparente.jpeg</b> .

<hr>

<h2>Semaine du 15/01/18</h2>
Cette semaine, sur les bons conseils de M.Masson, nous procédons au démantèlement total de feu BB-8 (<b>BB8_(2/3).jpg</b>). 
<br/>
Nous récupérons les deux moteurs simple arbre et les roues. Nous mettons de coté la plaque de plexiglass (sur laquelle reposait la majorité des composants électroniques), la sphère externe, la batterie et la troisième roue de l'ensemble (qui augmentait l'adhérence de la structure à la sphère extérieure).
<br/>
Nous créeons un petit prototype en carton de l'ensemble "deux roues + deux moteurs + batterie" (cf. <b>prototype_carton_0(a/b/c).jpg</b>), et nous le testons en pleine classe. Les moteurs marchent bien! 

<hr>

<h2>Semaine du 22/01/18</h2>
Nous tentons à nouveau de faire marcher les moteurs sans asservissement, ça marche aussi mais on remarque que dès que la sphère acquiert une certaine vitesse et heurte un obstacle (mur, paillasse, chaise...), les deux parties de la sphère se désolidarisent. 
<br/>
Il faudra peut-être réfléchir sur la façon dont <u>les sphères seront soudées dans le prototype final</u>.  
<br/>
Nous utilisons donc un L298N (cf. <b>L298N.png</b>), un composant qui a pour but de "driver" (contrôler) les moteurs, dont voici le circuit branchement final: <b>test_driver_1.jpg</b>.
<br/>
Yuri code et l'applique aux roues, on témoigne du bon fonctionnement des roues, puisqu'elle tournent dans deux sens différents mais en ayant la même vitesse de rotation. Ce composant est plus puissant que les autres drivers, puisqu'il peut réguler sa température mais pose un désavantage notoire dans le cadre de notre projet puisqu'il prend beaucoup plus de place que prévu. Ce dernier critère pourra poser à terme un problème au niveau du barycentre de notre structure. 

<hr>

<h2>Semaine du 29/01/18</h2>
Semaine de ski: je n'ai pas pris de matériel avec moi, et donc pas de travail notoire à mentionner même si j'ai quand même regarder les types de projets qui ressemblaient au notre. 
<br/>
Je regarde notamment les différentes applications du chargement par induction à des objets autres que des smartphones et je tombe sur cette vidéo: <b>https://www.youtube.com/watch?v=QJC4SwJc32Y&t=3s</b>. Je trouve aussi le schéma <b>souris_induction.png</b> qui retient toute mon attention.

<hr>

<h2>Semaine du 05/02/18</h2>

Cette semaine je m'intéresse plus au socle et à ma partie à proprement parler, puisque nous avons reçu les bobines en début de séance. 
<br/>
Je continue mes recherches puisque qu'un nouveau problème se pose: <u>"Est-ce-que l'énergie récupérée émergeant des bobines va être automatiquement transformée en tension aux bornes de la batterie et que cette dernière sera chargée, de fait?".</u> Je lis donc un commentaire qui m'ouvre une piste: 
<br/>
<i>« Il va falloir quelque chose capable de charger une batterie, par exemple un module à base de TP4056 pour gérer la charge une cellule LiPo (bien choisir la résistance qui définit l'intensité de charge en fonction de la batterie et de l'alimentation). 
  En sortie on a une tension variant de 3.7 à 4.2V en fonction de la charge de la batterie, donc tu peux ajouter un convertisseur boost (module à base de MT3608 par exemple) à la suite pour amener la tension finale à 5V pour alimenter l'arduino. »</i> : après vérification, l'utilisation d'un convertisseur boost couplé à un Arduino n'est pas conseillé, il pourrait créer des parasites. 
<br/>
J'oriente donc ma séance sur l'étude des bobines: mise en place et évaluation de la distance maximale à laquelle les bobines offrent un bon rendement. En les intégrant dans mon circuit en série avec un voltmètre (cf. <b>circuit_test_1.jpg</b>), je me rends rapidement compte que le petit module électronique couplé aux bobines a pour but de transformer l'énergie captée en tension. En effet, Yuri nous avait montré une expérience simple où les bobines étaient directement reliées à l'Arduino et alimentaient des LEDs. 
<br/>
Voici donc les résultats de cette séance:
<em>résultats à retranscrire</em>
<br/>
Je commence maintenant à contruire le socle, il est carré et fait de carton et sur sa face supérieure je crée un espace moins rigide que le carton pour y placer la bobine 1 et faire en sorte que la sphère repose au mieux sur son socle.
Je me rends compte que pour connecter la bobine 1 au secteur et l'autre bobine à la pile, il va falloir sectionner un chargeur micro usb en deux et comme défini dans le <b>brouillon_socle_1.jpg</b>:
 -  d'une part, relier l'embout secteur à l'embout jaune de la bobine 1, afin qu'elle puisse être alientée;
 -  d'autre part, relier l'embout micro usb à la bobine 2, puis connecter la prise micro usb à la batterie.
 <br/>
 Pour celà, Jérémy a trouvé une super pipile LiPo avec prise micro usb, nous l'avons donc commandée.

<hr>

<h2>Semaine du 12/02/18</h2>
Pas d'Arduino cette semaine, je n'avance pas sur le projet de mon coté puisque je laisse le matériel en salle de TP Elec.

<hr>

<h2>Semaine du 19/02/18</h2>
On estime que le driver des moteurs actuel (L298N) est trop gros pour la structure, Yuri et moi en récupèrons un plus petit (<b>L293D.jpeg</b>) que le précédent (environ 4 fois). J'essaie de faire le lien entre les deux pour pouvoir l'intégrer à notre structure. Il va peut-être falloir y ajouter un NAND. 
<br/>
Nous n'avons toujours pas reçu la batterie speciale donc je ne peux pas avancer sur mon socle. 
<br/>
En fin de séance, j'ai enfin transposé tout sur L293D, j'ai aussi pris beaucoup de temps pour ressouder les fils rouge et noir de la batterie et ceux des moteurs. 
<br/>
Dès réception de la pile, je pourrai connecter les bobines, la batterie et la prise secteur pour faire les premiers tests, et <u>finaliser le socle</u>.
<br/>
La prochaine étape sera de <u>passer du prototype carton au plastique/plexi</u>.

<hr>

<h2>Semaine du 26/02/18</h2>
Nous avons reçu la pile avec la prise micro USB (<b>batterie_LiPo.jpg</b>).
