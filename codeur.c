#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Indispensable pour rand




#define NB_TROUS 4
#define NB_COULEURS 9
#define NB_TOURS_MAX 12

typedef struct rangee
{
	int id;
	int tab_code[NB_TROUS];
	int tab_eval[NB_TROUS];
	struct range *suiv;
}*Rg;


//Provisoirement dans ce dossier
int main(void)
{
	srand(time(NULL)); //initialisation de rand
	return 0;
}


void initialisation(void)
{	

}


Rg combinaison_aléatoire(void)
{
	Rg CodeSecret = malloc(sizeof(Rg));
	Rg->id = 0;
	for(int = 0; i<NB_TROUS; i++)
	{
		Rg->tab_code[i] = rand()%((NB_COULEURS+1)-1) + 1; //Genere un nombre aléatoire entre [1;NB_COULEURS+1[
		Rg->tab_eval[i] = 0;
	}
	Rg->suiv = NULL;		
	return Rg;
}