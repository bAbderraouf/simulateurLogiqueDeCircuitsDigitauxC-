#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "Portes.h"
#include "Test_Portes.h"

using namespace std;


//=====================================================================

Teste::Teste(){}
Teste::~Teste(){}

//=====================================================================

void Teste::test_portes(void)
{

	int i=0,n=0;
	while(n==0)
	{
		cout<<"\n\n Choisissez l'objet a creer\n\n";
		cout<<"\t[1] Porte AND.\n\t[2] Un Inverseur (NOT).\n\t[3] Porte OR.\n\t[4] Porte XOR.\n";
		cin >> i;
		switch(i)
		{
			case 1: 	{And p1(2); 
						p1.Set_input(1,0);
						p1.Set_input(1,1);
						p1.Calculate_output();
						p1.print_info();
						n=terminer();
						break;}
			case 2: 	{Not p2;
						p2.Set_input(1,0);
						p2.Calculate_output();
						p2.print_info();
						n=terminer();
						break;}
			case 3: 	{Or p3(2);
						p3.Set_input(1,0);
						p3.Set_input(1,1);
						p3.Calculate_output();
						p3.print_info();
						n=terminer();
						break;}
			case 4: 	{Xor p4(2);
						p4.Set_input(1,0);
						p4.Set_input(1,1);
						p4.Calculate_output();
						p4.print_info();
						n=terminer();
						break;}
			default: 	{cout << "\n Le choix doit etre entre 1 et 4\n";
						break;}
			
			}
	}
}

//=====================================================================


int Teste::terminer(void)
{   int n=5;
	cout << "\n....Pour continuer tappez 0 sinon tappez 1 pour finir\n";
	cin >> n;
	system("clear");
	return n;
	}
//========================================================================

void Teste::init(void)
{
		cout<<"\n\n\n\t**************************************************************\n";
		cout<<"\t   BOUSRI Aderraouf --- TP Informatique GMEE325 – Langage C++";
		cout<<"\n\t**************************************************************\n";
		cout<<"\n\t\t\t\t____________";
		cout<<"\n\n==>> Choisissez ce que vous voudriez faire\n\n";
		cout<<"\t[1] Tester le fonctionnement des portes Logiques (séparement).";
		cout<<"\n\t[2] Executer le Simulateur logique de circuits digitaux.\n";
		cout<<"\n\t\t\t\t____________";
		cout<<"\n\n\n NB : Le simulateur peut calculer les sorties logiques de n'importe\n";
		cout<<" nbre d'entrées et de portes logique, en calculant la matrice d'adjacence\n";
		cout<<" correspondante, et en appliquant l'algorithme de DFS, et ceci pour n'importe\n";
		cout<<" quelle nbre de vecteurs d'entrees, et stocke les resultats dans un fichier\n";
		cout<<" texte appelé 'Resultats.txt'.\n";
	}
