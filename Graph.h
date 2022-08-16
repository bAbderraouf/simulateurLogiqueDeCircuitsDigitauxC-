#ifndef gr
#define gr

#include "Portes.h"
#include "Vecteur.h"
#include <iostream>
#include <string.h>

/*
 * Cette classe a pour objectif de representer le model du circuit sous forme 
 * de graph, les différentes variables néssaisaires sont les suivants:
 * - m_ep: 			nombre d'entrées primaires.
 * - m_sp: 			nombre de sorties.
 * - m_pl: 			nbre de portes logiques.
 * - m_NodeName :   vecteur qui contient les sommets du graph.
 * - m_OutName : 	vecteur qui stocke les entrées secondaires.
 * - m_LL : 		matrice qui contient la discription du circuit logique.
 * - m_LL_Ncol :    nbre de colones de la matrice m_LL.
 * - MAdj :			matrcie d'adjacence du graph.
 * - valSorties :   vecteur des sorties calculées (s1 s2 ... sN).
 * - m_ptr :        est un vecteur de pointeurs vers des objets de types portesGen.
 * - m_vect : 		un objet de type Vecteur pour la lecture des valeurs d'entrées.
 * 
 * Les fonctions correspondantes sont les suivantes:
 * calcule_ep , calcule_sp , calcule_pl, calcul_largeur pour calculer 
 * des variables correspondantes. et les autres pour le remplissages des vecteurs
 * DFS(int i, int val): pour appliquer l'algorithme de DFS pour le calcul des Si.
 * afficherResultats(): pour afficher les résultats dans le fichier texte .
 * */

class Graph 
	{
		private:
		
		int m_ep;
		int m_sp;
		int m_pl;
		std::string *m_NodeName;
		std::string *m_OutName;
		int **MAdj;
		std::string **m_LL;
		int m_LL_Ncol; //largeur de m_LL
		portesGen **m_ptr;
		Vecteur *m_vect;
		int *valSorties;
		
		public:
		
		Graph();
		~Graph();
		int get_ind_Name(std::string n);
		int get_ind_out(std::string o);
		
		int calcule_ep(void);
		int calcule_sp(void);
		int calcule_pl(void);
		int calcul_largeur(void);
		void DFS(int i, int val);
		
		void remplissage_m_NodeName(void);
		void remplissage_m_OutName(void);
		void remplissage_m_LL(void);
		void remplissage_MAdj(void);
		int comparreString(std::string a,std::string b);
		
		void afficherResultats(void);
	};

#endif
