#include "Vecteur.h"
#include <iostream>
#include <string>

#include <iostream>
#include <fstream>



using namespace std;

//===========================================


Vecteur::Vecteur()
{
	m_nbreDeVecteurs = 0;
	m_nbreDentrees = 0;
	m_v = NULL;
	
	calcul_nbreDeVecteurs();

	
	//remplissage_m_v();
}

//====================destructeur=======================

Vecteur::~Vecteur()
{	
	for(int i=0 ; i<m_nbreDeVecteurs ; i++)	
		delete[] m_v[i];
	delete[] m_v;

	}

//==================calcul du nbre de vecteurs=========================

void Vecteur::calcul_nbreDeVecteurs(void)
{
	
	ifstream flux("ValeursLogiques.txt");
	char a;
	
	
	if(flux) 
		{
			flux.seekg(ios::beg);
			flux.get(a);
			m_nbreDeVecteurs =  a -'0'; //conversion char >> int
			
			cout << "\n -m_nbreDeVecteurs = " <<m_nbreDeVecteurs<<".\n\n";
		}
	}


//========================remplissage des vecteurs======================


void Vecteur::remplissage_m_v(void)
{	
	m_v = new int *[m_nbreDeVecteurs];   //on peut pas définir cette matrice dans le constructeur
	for(int i=0 ; i<m_nbreDeVecteurs ; i++)	 	//car elle depond de ep (on doit d'abord)
	m_v[i] = new int[m_nbreDentrees];	//faire set_nbreDentrees() dans Graph.cpp
	
	ifstream flux1("ValeursLogiques.txt");
	char a;
	string mot;
	
	if(flux1) 
		{
			flux1.seekg(ios::beg);
			getline(flux1,mot);
			
			cout << "\n -Les Vecteurs d'entrees :\n" ;
			for(int j=0 ; j< m_nbreDeVecteurs ;j++)
			{	cout << "\n";
				for(int i=0 ; i < m_nbreDentrees ;i++)
				{
					flux1.get(a);
					m_v[j][i] = a - '0';
					cout << "\t"<< m_v[j][i];
			}
			getline(flux1,mot);
			}
			cout << "\n\n";
		}
	
	}
	
//========================set_nbreDentrees=======================================

void Vecteur::set_nbreDentrees(int value)
{
		m_nbreDentrees = value;
	
	}	
//======================= get_value ========================================

int Vecteur::get_value(int i,int j)
{
	return m_v[i][j];
	
	}
	
//========================= get_nvect() ======================================

int Vecteur::get_nvect()
{
	return m_nbreDeVecteurs;
	
	}
