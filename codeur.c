#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Indispensable pour rand

#include "codeur.h" //Contient les fonctions d'utilisation des listes chainées


code *initialisation_code(void) //Initialise la liste
{
    code *CodeSecret = malloc(sizeof(code));

    if (CodeSecret == NULL) //En cas d'echec d'initialisation
    {
        exit(EXIT_FAILURE);
    }
	for(int i = 0; i<NB_TROUS; i++)
	{
		CodeSecret->tab_code[i] = rand()%((NB_COULEURS+1)-1) + 1; //Genere un nombre aléatoire entre [1;NB_COULEURS+1[
	}
    return CodeSecret;
}

void test1(code* seq0) //Teste la fonction initialisation_code
{
	printf("Affichage de la sequence :\n");
	for(int i=0; i<NB_TROUS;i++)
	{
		printf("%d\t",seq0->tab_code[i]);
	}
	printf("\n");
}

rangee *capture_rangee(void)
{
	rangee *rang_actuel = malloc(sizeof(rangee));
	int nb_temp = -1;
	printf("Choisir une combinaison :\nPrendre des nombres compris entre 0 et %d\n",NB_COULEURS);
	for(int i=0;i<NB_TROUS;i++)
	{
		printf("Nb%d :\t",i+1);
		scanf("%d",&nb_temp);
		if(nb_temp<0 || nb_temp>=NB_COULEURS)
		{
			printf("Erreur de saisie\nPrendre des nombres compris entre 0 et %d\n",NB_COULEURS);
			i --;
		}
		else
		{
			rang_actuel->tab_code[i]=nb_temp;
		}
	}
	return rang_actuel;
}

void test2(rangee* rg) //Teste la fonction capture_rangee
{
	printf("La rangee saisie est :\n");
	for(int i=0; i<NB_TROUS;i++)
	{
		printf("%d\t",rg->tab_code[i]);
	}
	printf("\n");
}


//Provisoirement dans ce dossier
int main(void)
{
	srand(time(NULL)); //initialisation de rand
	code* seq0 = initialisation_code();
	test1(seq0);

	rangee* rg = capture_rangee();
	test2(rg);
	return 0;
}
