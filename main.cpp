#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>


#include "Test_Portes.h"
#include "Portes.h"
#include "Graph.h"
#include "Vecteur.h"


using namespace std;


int main()
{
	system("clear");

	Teste t;  						// objet de type Teste

	int i=0,n=0;
	while(n==0)
		{	t.init();
			cin >> i;
			switch(i)
			{	
				case 1: 	{  	   system("clear");
								   t.test_portes(); 
								   n=t.terminer();  
								   break; 			}
				case 2: 	{  
								   system("clear");
								   Graph a;   /// tout le calcul se fait dans la classe Graph
								   cout<<"\n\n\n******************************************************************\n";
								   cout<<"  Les Resultats ont été affichés dans le fichier";
								   cout<<"\n  'Resultat.txt' qui se trouve au màme chemin que l'executable\n";
								   cout<<"*******************************************************************\n";
								   n=t.terminer(); 		 		 
								   break; 			}
				default: 	{	  
								   cout << "\n Le choix doit etre entre 1 et 2\n";
								   break;			}
			 }
		}

	return 0;
}

