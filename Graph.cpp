#include "Graph.h"
#include "Portes.h"
#include "Vecteur.h"

#include <iostream>
#include <string>

#include <iostream>
#include <fstream>


using namespace std;

//=========================Constructeur=================================

Graph::Graph()
			{ 		
				m_ep=0;
				m_sp=0;
				m_pl=0;
				m_NodeName = NULL;
				m_OutName = NULL;
				m_LL = NULL;
				m_LL_Ncol = 0;
				MAdj = NULL;
				m_ptr = NULL;
				m_vect = NULL;
				valSorties = NULL;
				
				m_ep = calcule_ep();	
				m_sp = calcule_sp();
				m_pl= calcule_pl(); 
				m_LL_Ncol = calcul_largeur();
				cout << "\n\ncol= "<<m_LL_Ncol<<"\n\n";
				
				int taille = m_ep + m_sp + m_pl;
				
				m_NodeName = new string[taille];
				m_OutName = new string[taille];
				m_ptr = new portesGen *[m_pl];
				m_vect = new Vecteur();
				
				
				m_vect->set_nbreDentrees(m_ep);  //transmettre le nbre d'entrées a l'objet m_vect
				m_vect->remplissage_m_v();   // une fois le nbre d'entrées obtenue on peut remplir la matrice des valeurs
			
			
			    valSorties = new int[m_sp];
				for(int i=0; i<m_sp ; i++)
				 {valSorties[i]=33;}  // pour s'assurer que la valeure a changé ou pas
				 
			//------
				m_LL = new string *[m_pl]; 
				for(int i=0; i<m_pl ; i++)  
					{  m_LL[i] = new string[m_LL_Ncol];  } //largeur
			//------
			
				MAdj = new int *[taille];
				for(int i=0; i<taille ; i++)  
					{  MAdj[i] = new int[taille];  } 
				
				for(int i=0;i<taille;i++)
				{
					for(int j=0;j<taille;j++)
					{
						MAdj[i][j]=0;
						}
					}
					
				remplissage_m_LL();
				remplissage_m_NodeName();
				remplissage_m_OutName();
				remplissage_MAdj();
				
			
				 afficherResultats();
			}
			
//========================Destructeur===================================		
			
Graph::~Graph()
			{
				int taille = m_ep + m_sp + m_pl;
				
				delete[] m_NodeName;
				delete[] m_OutName;
				
				//for(int i=0; i<m_pl ; i++)
			 	//	 delete[] m_ptr[i]; 
				delete[] m_ptr;
			
				for(int i=0; i<m_pl ; i++)
			 			 delete[] m_LL[i]; 
				delete[] m_LL;
				
				for(int i=0; i<taille ; i++) 	
			 			 delete[] MAdj[i]; 
				delete[] MAdj;	  
				delete m_vect;
				delete[] valSorties;
				}
				
//========================calcule_ep====================================				

int Graph::calcule_ep(void)
{
	ifstream flux1("Portes.txt");
	string mot;
	if(flux1) //ok
		{
			flux1.seekg(ios::beg);
			do 
			{flux1 >> mot;} 
			while (mot != "INPUT");
			 
			while(mot !=";")
				{   
					flux1 >> mot;
					m_ep++;
				}	
			m_ep--;	
			cout << "\n\t Il existe : "<< m_ep << " Entrées.\n";
		}
	
	return m_ep;
	}

//========================calcule_sp====================================				
	
int Graph::calcule_sp(void)
{
	ifstream flux2("Portes.txt");
	string mot;
	
	if(flux2) //ok
		{
			flux2.seekg(ios::beg);
					
			do 
			{flux2 >> mot;} 
			while (mot != "OUTPUT");
			 
			while(mot !=";")
				{   
					flux2 >> mot;
					m_sp++;
				}	
			m_sp--;	
			cout << "\n\t Il existe : "<< m_sp << " Sorties.\n";
		}
	return m_sp;
	}
	
//========================calcule_pl====================================				

int Graph::calcule_pl(void)
{
	ifstream flux3("Portes.txt");
	string mot,ligne;
	
	if(flux3) //ok
		{
			flux3.seekg(ios::beg);
			getline(flux3,ligne);
			getline(flux3,ligne);
					
			while(getline(flux3,ligne))
				{  
				
					m_pl++; 
				}	
			
			cout << "\n\t Il existe : "<< m_pl << " Portes Logiques.\n";
		}
	return m_pl;
	}

//======================remplissage_m_OutName===========================

void Graph::remplissage_m_OutName(void)
{
		int i=0;
		int taille = m_ep + m_sp + m_pl;
		
		for(i=0 ; i<m_ep ; i++)
					{
						m_OutName[i] = "==";
					}
		for(i=0 ; i<m_pl ; i++)
					{
						m_OutName[i+m_ep] = m_LL[i][2];
						
					}
		for(i=0 ; i<m_sp ; i++)
					{
						m_OutName[i+m_ep+m_pl] = "==";
					}
					
					cout <<" \n -m_OutsName[i] :\n\n";
		for(i=0 ; i<taille; i++)
					{
						cout <<" "<<m_OutName[i]; 
					}
						cout <<" \n\n";
	}

//=====================remplissage_m_NodeName===========================								
		
void Graph::remplissage_m_NodeName(void)
{	
	ifstream flux5("Portes.txt");
	string mot,ligne;
	int taille = m_ep + m_sp + m_pl;
	int i=0;
			
	if(flux5) 
		{
			flux5.seekg(ios::beg);
			do 
			{flux5 >> mot;} 
			while (mot != "INPUT");
			
			for(i=0 ; i<m_ep; i++)
					{
						flux5>>m_NodeName[i];
					}
			
			flux5.seekg(ios::beg);		
			
			do 
			{flux5 >> mot;} 
			while (mot != "OUTPUT");
			
			for(i=0 ; i<m_sp ; i++)
					{
						flux5>>m_NodeName[i+m_ep+m_pl]; 
					}
			
			for(i=0 ; i<m_pl ; i++)
					{
					     m_NodeName[i+m_ep] = m_LL[i][1];
					}
						
			}
			cout <<" \n -m_NodeName[i] \n\n";
			
			for(i=0 ; i<taille; i++)
					{
						cout <<" "<<m_NodeName[i]; 
					}
						cout <<" \n\n"; 
		
	}
	
//======================remplissage_m_LL ===============================

void Graph::remplissage_m_LL(void)
{

	ifstream flux4("Portes.txt");
	string mot,ligne;
	int i=0,j=0,k=0;
	
	if(flux4) 
		{
			flux4.seekg(ios::beg);
			getline(flux4,ligne);
			
			cout << "\n -m_LL :\n" ;
			
			for(int i=0 ; i<m_pl ; i++)
			{
				getline(flux4,ligne);
				cout << "\n";
				
				for(int j=0 ; j<m_LL_Ncol; j++)
				{
					flux4 >> m_LL[i][j];
					if(m_LL[i][j] == ";")
					{
						for(k=j ; k<m_LL_Ncol; k++)
							{	
								m_LL[i][k] = ";";
					    		cout << "\t"<< m_LL[i][k];
					    		}
					
					break;	
					}
					cout << "\t"<< m_LL[i][j];
				}
			}	
		cout << "\n\n";
		}	
	}

//======================remplissage_MAdj===============================

void Graph::remplissage_MAdj(void)
{
	int i=0; int Pi=-1,Ei=-1;
	int nbreDentres = 0;  //stocker le nbre dentres de chq porte
	
	//Ei - Pi
	int *E = NULL;
	int nbrE = m_LL_Ncol-3; //nbre dentrees max
	E = new int[nbrE];  //pour stocker les indices de chq entrees de chq porte
	
	for(i=0 ;i<m_pl ; i++)
	{	
		nbreDentres = 0; //initialiser a chq ligne
		
		///----------methode simple pour 2 entrees au maximum-----
		/*
		
		Ei = get_ind_Name(m_LL[i][3]); //E1i
		Pi = get_ind_Name(m_LL[i][1]); //Pi
	
		MAdj[Ei][Pi] = 1;
		
		Ei = get_ind_Name(m_LL[i][4]); //E2i
		if(Ei != -1)
		{
			Pi = get_ind_Name(m_LL[i][1]); //Pi
			MAdj[Ei][Pi] = 2;
					}
		*/	
	
		///-------methode generalisée pour nbre_dentres_max = nbrE
		
		Pi = get_ind_Name(m_LL[i][1]); //Pi
		
		for(int j=0 ;j<nbrE ; j++)
		{
			E[j] = get_ind_Name(m_LL[i][3+j]);
			Ei = E[j];
			
			if(Ei != -1)
			{
				MAdj[Ei][Pi] = j+1;  //si j=0 > 1 ...
				nbreDentres++;
			}
		}	
				
			//Si  - Pi
		int Si=-1;
	
		Si = get_ind_Name(m_LL[i][2]);
		Pi = get_ind_Name(m_LL[i][1]);
		if(Pi!=Si)
		{MAdj[Pi][Si] = 1;}
				
				
			///-------creation des portes logiques--------
	 					
						
						if(m_LL[i][0]=="and") {	
												m_ptr[i] = new And(nbreDentres);     }
						else if(m_LL[i][0]=="or") {
													m_ptr[i] = new Or(nbreDentres); 
																					  }
						else if(m_LL[i][0]=="not") {
													 m_ptr[i] = new Not();			  }
						else if(m_LL[i][0]=="xor") {
													 m_ptr[i] = new Xor(nbreDentres);  }
	 	}


	 		
	///-------affichage de MAdj-------------------
	

		cout << "\n -MAdj[i][j] :\n" ;
				
		int taille = m_ep + m_sp + m_pl;
		cout<<"\n";
		cout<<"    ";
		for(int j=0;j<taille;j++)
					{cout<<m_NodeName[j]<<" ";}
					cout <<"\n";
		for(int i=0;i<taille;i++)
				{	cout<<m_NodeName[i]<<" ";
					
					for(int j=0;j<taille;j++)
					{	
						cout << "  "<<MAdj[i][j];
						}
						cout << "\n";
					} cout << "\n\n";
					
				
					
	delete[] E;		
	///======== -- affichage des informations sur les portes---=========
		
		for(int i=0; i<m_ep ;i++) 
		m_ptr[i]->print_info();	
			
	///============== affectation des valeurs aux entrees + DFS=========
		
		int nvect = m_vect->get_nvect(); 					 //calculer le nbre de vecteurs 
		for(int k=0; k<nvect ;k++)  						 //pour chaque vecteur 
		{		
				for(int i=0; i<m_ep ;i++) 					//pour chaque entrée
				{       
						int val = m_vect->get_value(k,i);  //valeur du kieme vecteur et iéme entrée
						DFS(i,val);				
				
				 }
			 
		///================= -- affichage des sorties---================
			
				cout<<"\n>>----valeur des sorties pour le Vecteur n°"<<k+1<<"\n";
				for(int s=0;s<m_sp;s++)
				 {  cout<<"[ s"<<s+1<<"= "<<valSorties[s]<<" ]";			}
					cout<<"\n ";
		 }
}
//=======================DFS============================================
void Graph::DFS(int i,int val)
{
	int ind = 0;
	for(int j=0; j<m_ep+m_pl+m_sp ;j++)							 //pour chaque porte
	{ 		
		if(MAdj[i][j]!=0)
		{	
				
			if(j<m_ep+m_pl)
				{
					ind = MAdj[i][j]-1 ;  						 //exple : si MAdj[i][j]=2 => 2éme entree => ind=1 
					m_ptr[j-m_ep]->Set_input(val,ind);
					int val2 = m_ptr[j-m_ep]->Calculate_output(); // la nouvelle valeur d'entree reçoit la sortie de la porte actuelle
					DFS(j,val2); 								 // faire propager cette nouvelle valeur d'enree
											}
											
			else if(j>=m_ep+m_pl)  								// on est arrivé a une sortie
				{
						valSorties[j-m_ep-m_pl] = val;  		// propager la derniere valeur vers la sortie correspondante
															}
			} 
		}
	}				
				
//======================get_ind_Name====================================

int Graph::get_ind_Name(string n)
{
		int taille = m_ep + m_sp + m_pl;
		int ind = -1;
		int i=0;
		//int egale=0;
		//string e;
		
		
	for(i=0 ;i<taille ; i++)
	{	
		//egale=comparreString(e,n);
				
		if(n.compare(m_NodeName[i])==0){ind = i;} 
		else if (n.compare(m_OutName[i])==0){ind = i;}
		
		}
		
	return ind;	
	}
	
//======================get_ind_out=====================================
	
	
int Graph::get_ind_out(string o)
{
								
								
				}
				
//=====================compareSting=====================================

int Graph::comparreString(std::string e,std::string n)
{
int afsa = 1, egale=0;
	
	
		for(int i=0;i<e.size();i++)
		{
			if(e[i]==n[i]){ egale =1;}
			else {afsa =0;}
			egale = egale * afsa;
			}
return egale;
}

//=========================calcule largeur===============================

int Graph::calcul_largeur(void)
{
	int m=0,max=0;
	
	ifstream flux5("Portes.txt");
	string mot,ligne;
	if(flux5) 
		{
			flux5.seekg(ios::beg);
			getline(flux5,ligne);
			getline(flux5,ligne);
					
			for(int i=0;i<=m_pl;i++)
			{	if(max>m){m=max;}
				max=0;
				do
				{	flux5>>mot;
				   	max++;
				 }while(mot!=";");
				getline(flux5,ligne);					
			}
			
		}
			
	return (m-1);
	}
//===========================afficherResultats===========================
void Graph::afficherResultats(void)
{
	ofstream out("Resultats.txt");
	int taille = m_ep + m_sp + m_pl;
			
	if(out) 
		{
			/// afficher des info sur portes , entrees sorties
			out << "\n1-Info sur portes , entrees sorties:\n";
			out << "\n\t Il existe : "<< m_ep << " Entrées.\n";
			out << "\n\t Il existe : "<< m_sp << " Sorties.\n";
			out << "\n\t Il existe : "<< m_pl << " Portes Logiques.\n";
			
			///info sur Outname et m_NodeName
			out << "\n\n2-info sur Outname et m_NodeName\n";
			out <<" \n-m_OutsName[i] :\n\n";
			for(int i=0 ; i<taille; i++)
			{ out <<" "<<m_OutName[i]; }out <<" \n\n";
			
			out <<" \n-m_NodeName[i] \n\n";
			for(int i=0 ; i<taille; i++)
			{out <<" "<<m_NodeName[i]; }out <<" \n\n"; 
			
			///info la matrice qui contient le fichier des donnees
			out <<"\n\n3-info la matrice qui contient le fichier des donnees\n";
			out << "\n-m_LL :\n" ;
			for(int i=0;i<m_pl;i++)
			{out << "\n";
			for(int j=0;j<m_LL_Ncol;j++)
			{out << "\t"; out <<m_LL[i][j];}}
			
			///-------affichage de MAdj-------------------
			out << "\n\n4-Affichage de MAdj\n";
			out << "\n-MAdj[i][j] :\n";	
			int taille = m_ep + m_sp + m_pl;
			out<<"\n";
			out<<"    ";
			for(int j=0;j<taille;j++)
			{out<<m_NodeName[j]<<" ";}out <<"\n";
			for(int i=0;i<taille;i++)
			{out<<m_NodeName[i]<<" ";			
			for(int j=0;j<taille;j++)
			{out << "  "<<MAdj[i][j];} out << "\n";} 
			out << "\n\n"; } 
			
			
			
			///===== affichage des informations sur les portes---=======
			out <<"\n\n5-Les vecteurs des valeurs d'enrees\n";
			int nvect = m_vect->get_nvect(); 
			out << "\n-Le nombre des Vecteurs d'entrees est : " <<nvect;
			for(int j=0 ; j< nvect;j++)
			{	out << "\n";
				for(int i=0 ; i < m_ep ;i++)
				{out << "\t"<< m_vect->get_value(j,i);}
			}out << "\n\n";
			
			
			///================= -- affichage des sorties---============
			out << "\n\n6-Valeurs des sorties Logiques Calculée\n";			
			for(int k=0; k<nvect ;k++)  						
		    {	out<<"\n>>----valeur des sorties pour le Vecteur n°"<<k+1<<"\n";
				for(int s=0;s<m_sp;s++)
				 {  out<<"[ s"<<s+1<<"= "<<valSorties[s]<<" ]";	} out<<"\n ";
						
						}
					}
