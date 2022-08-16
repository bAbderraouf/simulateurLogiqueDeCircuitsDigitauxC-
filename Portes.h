#ifndef portes
#define portes

#include <iostream>

/*
 * Cette classe est faite pour la creation des differents objets permettant
 * la manipulation des differentes portes logiques (and , or , xor et not)
 * */

//------------------Class Mére-----------------------------

class portesGen{

public:
portesGen();
virtual ~portesGen();

virtual void print_info(void)=0;
virtual void Set_input(int val, int indice)=0;
virtual int Calculate_output(void)=0;

};

//--------------Classes filles ----------------
//-1-------------Class And----------------------

class And : public portesGen
{
private:

int m_nbreEntree;
int *m_entrees;
int m_s;

public:

And();
And(int ne); //2eme constructeur
~And();
void print_info(void);
void Set_input(int val, int indice);
int Calculate_output(void);

};

//--(2)-----------------------Class OR----------------------

class Or : public portesGen
{
private:

int m_nbreEntree;
int *m_entrees;
int m_s;

public:

Or();
Or(int ne); //2eme constructeur
~Or();
void print_info(void);
void Set_input(int val, int indice);
int Calculate_output(void);

};

//--(3)-----------------------Class Not----------------------

class Not : public portesGen
{

private:
int m_e;
int m_s;

public:
Not();
~Not();
void print_info(void);
void Set_input(int val, int indice);
int Calculate_output(void);

};

//--(4)-----------------------Class XOR----------------------


class Xor : public portesGen
{

private:
int m_nbreEntree;
int *m_entrees;
int m_s;


public:
Xor();
Xor(int ne); //2eme constructeur
~Xor();
void print_info(void);
void Set_input(int val, int indice);
int Calculate_output(void);
};




//-------------------void set_input(int val, int indice)
//----------------------un passage d'argument plus simple ( par exemple And::And(int ne)

//-int calculate_output(void) cette méthode doit retourner la sortie de la porte m_s dans votre cas. 
//---Et gardez l'affichage plutôt pour la méthode :--void print_info(void) 
//--il faut appeler la méthode calculate-ouput ensuite afficher toutes les données de la porte via la méthode print_info()

#endif
