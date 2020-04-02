#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Indispensable pour rand

#include "codeur.h" //Contient les fonctions d'utilisation des listes chainées


rangee *initialisation_code(void) //Initialise la liste
{
    rangee *CodeSecret = malloc(sizeof(rangee));

    if (CodeSecret == NULL) //En cas d'echec d'initialisation
    {
        exit(EXIT_FAILURE);
    }

    CodeSecret->id = 0;
	for(int i = 0; i<NB_TROUS; i++)
	{
		CodeSecret->tab_code[i] = rand()%((NB_COULEURS+1)-1) + 1; //Genere un nombre aléatoire entre [1;NB_COULEURS+1[
		CodeSecret->tab_eval[i] = 0;
	}
   	CodeSecret->suiv = NULL;

    return CodeSecret;
}

void test1(Rg seq0)
{
	printf("Affichage de la sequence :\n");
	for(int i=0; i<NB_TROUS;i++)
	{
		printf("%d\t",seq0->tab_code[i]);
	}
	printf("\n");
}

//Provisoirement dans ce dossier
int main(void)
{
	srand(time(NULL)); //initialisation de rand
	rangee* seq0 = initialisation_code();
	test1(seq0);
	return 0;
}
