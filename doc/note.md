# Notes


## Résumé du sujet

#### Application de visualisation
- Système de callbacks pour nos events dans notre cas.
- Utiliser Valgrind.
- Les tailles doivent être relatives seulement (homotétie)
- Séparer la partie "Moteur d'application" et "Moteur de rendu" 


#### Ressources et données

- Rotation du soleil : 25 jours
- Il faut faire apparaître les satellites de chaque planète
- On considère les planètes et satellites commes des sphères parfaites
- Les autres données à récupérer sont données dans le sujet et sont sur les liens fournis


#### Interaction avec utilisateur

- Plusieurs modes de vues
- 1er : Vue au dessus de l'elliptique du soleil
- 2nd : Vue sur le plan de l'elliptique
- 3eme : Vue planétaire
- Sur chaque mode de vue on devra (appui sur touche) :

        - Avancer (rapidement) dans le temps
        - En continu (temps défile jusqu'à ce qu'on appuie de nouveau sur la touche)
        - Sortir de l'application (proprement)


#### Apparence de l'application

- Quel que soit le mode de vue : Affichage texturé des planètes + trajectoires des satellites
- Le fond (l'espace) dpot être représenté par une bounding box affichant un ciel étoilé



## Réflexion personnelle


#### Moteur d'application : 

Partie qui gère le comportement de la scène : cerveau

- Interactions utilisateur
- éclairage
- caméras
- gestion de la fenêtre
- calculs de matrice et autres


#### Moteur de rendu : 

Génère l'image, il convertis les informations en pixels à afficher

- traitement lumières
- textures
- matériaux
- effets visuels


#### Modules

- Moteur application : Contient la boucle principale, gère les données et inclura les modules suivants, 
    
        - Computations : Contient matrices de transfos et tt ce qui est lié aux calculs
        - Camera : Gestion de la caméra avec une classe (comme dans les TPs)
        - Events : Contient les fonctions de callback des touches et clics
        - Textures/Resources : Gère l'import  des textures, ressources etc
        - Data : Contient les données sur les planètes par exemple, chaque planète pourrait faire l'objet d'une classe ou classe héritée
        - Gestion de la fenêtre : Initialisation, Fermeture, OUverture, redimensionnement de la fenêtre
        - Moteur de Rendu
  

- Moteur de rendu : Contient les fonctions de rendu (gldrawArray() dans la boucle principale) et de configuration du contexte graphique (sûrement le GL_DEPTH, glColorBIt etc), il gère les détails concernant la partie graphique
  
        
        - Materials : Gère les coefficients liés aux matériaux dans 
        - Shaders : Gère le link entre les shaders et openGL, compilation, lien et utilisation/gestion des variables uniformes
        - Tampons : VBO/VAO, gestion, allocation, libération
        - Textures : Manipulation des textures, multi texturing etc à travers des classes (comme les TPs), Chargement dans OpenGL (pas récup le fichier sur le disque) des textures, les allouer, les désallouer, gère les caches des textures pour éviter des les charger sans arrêt
 

        //Eventuellement
        - Post traitement
        - Effets spéciaux

main -> application -> rendu


