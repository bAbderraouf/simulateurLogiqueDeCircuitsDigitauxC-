#ifndef vectt
#define vectt
 


#include <iostream>
#include <string.h>

/*
 * la classe vecteur est celle qui s'occupe du calcul des vecteurs d'entrées et 
 * les stocker dans la mémoire dans la matrice <<m_v>>, cette matrice a <<m_nbreDeVecteurs>> 
 * lignes et <<m_nbreDentrees>> collonnes
 * la fonction : - get_nvect() est pour faire sortir le nbre de vecteurs
 * 				   et l'utiliser a l'exterieur .
 * 				 - get_value() est faite pour obtenir la valeur de n'inmporte
 * 					quelle entrées de l'exterieur de la classe.
*/
class Vecteur
{
	private:
	
	int m_nbreDeVecteurs;
	int m_nbreDentrees;
	int **m_v;
	
	
	public:
	
	Vecteur();
	~Vecteur();
	
	void calcul_nbreDeVecteurs(void);
	void remplissage_m_v(void);
	
	void set_nbreDentrees(int value);
	int get_value(int i,int j);
	int get_nvect();
		
	};

#endif
