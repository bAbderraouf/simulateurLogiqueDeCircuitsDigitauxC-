Réalisation d'un simulateur logique de circuits digitaux en C++ (Projet universitaire en tant que Roboticien).

L’objectif de ce travail est de réaliser un simulateur logique de circuits digitaux. qui va
permettre le calcul des valeurs de sorties en fonction de celles d’entr´ees en simulant le
fonctionnement des diff´erentes portes logiques, choisit par l’utilisateur sous forme d’un
fichier texte.


Le simulateur est constitu´e de quatre parties :

  • Lecture du fichier texte qui contiens la description du circuit au niveau des portes logiques.
  • Lecture du fichier texte qui contient les valeurs en entr´ee du circuit.
  • Aprés la lecture du fichier on obtiens un modele du circuit.
  • Simulation logique : 
      on calcul les valeurs de chaque sortie du circuit en fonction des entrées.

Remarque : Voir le fichier MoreAboutTheProject.pdf pour Plus de details.

Pour la compilation:
  g++ Portes.cpp Graph.cpp Vecteur.cpp Test_Portes.cpp main.cpp -o nom_exucutable
