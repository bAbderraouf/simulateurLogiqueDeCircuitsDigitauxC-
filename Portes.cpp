#include "Portes.h"
#include <iostream>
#include <string>
#include <fstream> //pour getchar()


using namespace std;

//------------------Class Mere-----------------------------

portesGen::portesGen(){}
portesGen::~portesGen(){}


//--------------------------Classes filles ------------------
//--(1)-----------------------Class And----------------------

And::And():m_nbreEntree(0),m_s(0),m_entrees(0)
{
	int ne=0;
	int juste=0;
		do
		{
			cout<< "\n Veuillez Introduire le Nombre d'entrees :\n";
			cin >> ne;
			int i=0;
			if(ne<2)
				{ 
					cout<<"veuillez introduire un nbre > 2 ";
					juste=1;				
				}
			else
				{
					m_nbreEntree = ne;
					m_entrees = new int[m_nbreEntree];
					juste=0;

					for(i=0 ; i <= m_nbreEntree ; i++)
						{m_entrees[i] = 0;}
					m_s=0;
				}
		}while(juste==1);
}
//---------------------------2eme constructeur---------------------------------


And::And(int ne):m_nbreEntree(0),m_s(0),m_entrees(0)
{
	int juste=0;
		do
		{
			int i=0;
			if(ne<2)
				{ 
					cout<<"veuillez introduire un nbre d'entrees > 2 ";
					juste=1;				
				}
			else
				{
					m_nbreEntree = ne;
					m_entrees = new int[m_nbreEntree];
					juste=0;

					for(i=0 ; i <= m_nbreEntree ; i++)
						{m_entrees[i] = 0;}
					m_s=0;
				}
		}while(juste==1);
}


//-------------------------------------------------------------

And::~And()
{	delete[] m_entrees;	}

//-------------------------------------------------------------

void And::print_info(void)
{
	
	cout<< "\n\n-Porte : AND \t à: "<<m_nbreEntree <<" entrees:  \n";

	int i=0;
	for(i=1;i<=m_nbreEntree;i++)
		{
			cout<< "E"<< i <<" = "<< m_entrees[i-1] <<"\n";
		}
		 cout<< "La sortie de la porte AND vaut = " <<Calculate_output()<< "\n";
}

//------------------------------------------------------------------

void And::Set_input(int val, int indice)
{
	m_entrees[indice] = val;
	
	if(m_entrees[indice]>1)
		{
			while(1)
	    	 cout <<"Erreur: veuillez introduire un booleen a l'entree de And \n\n";
	  	   		}
}

//--------------------------------------------------------------------

int And::Calculate_output()
{
 int i=0;
 m_s = m_entrees[i];
 
 for(i=1 ; i<m_nbreEntree ; i++)
    {
     m_s = m_s * m_entrees[i];
	}
    return m_s;
}

//-------------------------------------------------------------------
//--(2)-----------------------Class OR-------------------------------

Or::Or():m_nbreEntree(0),m_s(0),m_entrees(0)
{
int ne=0;
int juste=0;
		do
		{
		cout<< "\n Veuillez Introduire le Nombre d'entrees :\n";
		cin >> ne;
		int i=0;
		if(ne<2)
			{ 
			cout<<"veuillez introduire un nbre > 2 ";
			juste=1;				
			}
		else
		    {
		    m_nbreEntree = ne;
		    m_entrees = new int[m_nbreEntree];
		    juste=0;

		    for(i=0 ; i <= m_nbreEntree ; i++)
			{m_entrees[i] = 0;}
		    m_s=0;
		    }
		}while(juste==1);
}

//---------------------------2eme constructeur---------------------------------


Or::Or(int ne):m_nbreEntree(0),m_s(0),m_entrees(0)
{
	int juste=0;
		do
		{
			int i=0;
			if(ne<2)
				{ 
					cout<<"veuillez introduire un nbre d'entrees > 2 ";
					juste=1;				
				}
			else
				{
					m_nbreEntree = ne;
					m_entrees = new int[m_nbreEntree];
					juste=0;

					for(i=0 ; i <= m_nbreEntree ; i++)
						{m_entrees[i] = 0;}
					m_s=0;
				}
		}while(juste==1);
}




//-------------------------------------------------------------------

Or::~Or()
{
delete m_entrees;
}

//-------------------------------------------------------------------

void Or::print_info(void)
{
cout<< "\n\n-Porte : OR \t à: "<<m_nbreEntree <<" entrees:  \n";

int i=0;
for(i=1;i<=m_nbreEntree;i++)
	{
	 cout<< "E"<< i <<" = "<< m_entrees[i-1] <<"\n";
	 
		}
				 cout<< "La sortie de la porte OR vaut = " <<Calculate_output()<< "\n";

}

//-------------------------------------------------------------------

void Or::Set_input(int val, int indice)
{
	m_entrees[indice] = val;
	
	if(m_entrees[indice]>1)
		{
			while(1)
	    	 cout <<"Erreur: veuillez introduire un booleen a l'entree de OR \n\n";
	   		}
}


//-------------------------------------------------------------------

int Or::Calculate_output(void)
{
 int i=0;
 m_s = m_entrees[i];
 
 for(i=1 ; i<m_nbreEntree ; i++)
    {
     m_s = m_s or m_entrees[i];
	}
    return m_s;
    }



//--(3)-----------------------Class Not------------------------------

Not::Not():m_e(0),m_s(0){}
Not::~Not(){}

//------------------------------------------------------------

void Not::print_info(void)
{
cout<< "\n\n-Porte : NOT. \n";
cout<< "E = "<< m_e <<"\n";
cout<< "La sortie de la porte NOT vaut = " <<Calculate_output()<<"\n";
}

//------------------------------------------------------------

void Not::Set_input(int val, int indice)
{
	m_e = val;
	
	if(m_e>1)
		{	while(1)
	    	 cout <<"Erreur: veuillez introduire un booleen a l'entree de Not \n\n";
	   	} 
}


//------------------------------------------------------------

int Not::Calculate_output(void)
{
return not(m_e);
}


//--(4)-----------------------Class XOR----------------------

Xor::Xor():m_nbreEntree(0),m_s(0),m_entrees(0)
{
int ne=0;
int juste=0;
		do
		{
		cout<< "\n Veuillez Introduire le Nombre d'entrees :\n";
		cin >> ne;
		int i=0;
		if(ne<2)
			{ 
			cout<<"veuillez introduire un nbre > 2 ";
			juste=1;				
			}
		else
		    {
		    m_nbreEntree = ne;
		    m_entrees = new int[m_nbreEntree];
		    juste=0;

		    for(i=0 ; i <= m_nbreEntree ; i++)
			{m_entrees[i] = 0;}
		    m_s=0;
		    }
		}while(juste==1);
}


//---------------------------2eme constructeur---------------------------------


Xor::Xor(int ne):m_nbreEntree(0),m_s(0),m_entrees(0)
{
	int juste=0;
		do
		{
			int i=0;
			if(ne<2)
				{ 
					cout<<"veuillez introduire un nbre d'entrees > 2 ";
					juste=1;				
				}
			else
				{
					m_nbreEntree = ne;
					m_entrees = new int[m_nbreEntree];
					juste=0;

					for(i=0 ; i <= m_nbreEntree ; i++)
						{m_entrees[i] = 0;}
					m_s=0;
				}
		}while(juste==1);
}





//-----------------------------------------------------------
	
	
Xor::~Xor()
{
delete m_entrees;		
	}

//--------------------------------------------------------------

void Xor::print_info(void)
{
	cout<< "\n\n-Porte : XOR \t à: "<<m_nbreEntree <<" entrees:  \n";

	int i=0;
	for(i=1;i<=m_nbreEntree;i++)
		{
		 cout<< "E"<< i <<" = "<< m_entrees[i-1] <<"\n";
			}
	     cout<< "La sortie de la porte XOR vaut = " <<Calculate_output()<< "\n";	

	}
	
//--------------------------------------------------------------
	
void Xor::Set_input(int val, int indice)
{
	m_entrees[indice] = val;
	
	if(m_entrees[indice]>1)
		{
	    	while(1)
	    	 cout <<"Erreur: veuillez introduire un booleen a l'entree de Xor \n\n";
	    	
		}
}

	
//--------------------------------------------------------------	
	
int Xor::Calculate_output(void)
{

 int i=0;
 m_s = m_entrees[i];
 
 for(i=1 ; i<m_nbreEntree ; i++)
    {
     m_s = m_s xor m_entrees[i];
	}
return m_s;
	}





