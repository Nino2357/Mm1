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
	printf("Choisir une combinaison :\nPrendre des nombres compris entre 1 et %d\n",NB_COULEURS);
	for(int i=0;i<NB_TROUS;i++)
	{
		printf("Nb%d :\t",i+1);
		scanf("%d",&nb_temp);
		if(nb_temp<1 || nb_temp>=NB_COULEURS+1)
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

void comparaison(rangee* rg, code* co)
{
	int nb_blanc=0;	//Un pour chaque fiche du code ayant une fiche de la meme couleur placée par le décodeur
	bool blanc_util[NB_TROUS]; //Sert a compter qu'une seul fois chaque fiche réponse lors du décompte des blancs
	for(int y=0;y<NB_TROUS;y++) //met les valeurs a true par défaut
	{
		blanc_util[y]=true;
	}
	int nb_rouge=0;	//Quand emplacement + couleur ok
	for(int i=0;i<NB_TROUS;i++) //Parcours du code
	{
		if (rg->tab_code[i]==co->tab_code[i]) //s'il y a un parfait (rouge)
		{
			nb_rouge++;
			blanc_util[i]= false;


		}
		else
		{
			for(int k=0;k<NB_TROUS;k++) //Parcours de la proposition de décodage
			{
				D printf("code %d\tsol %d\tutil? %s\n ",co->tab_code[i],rg->tab_code[k], blanc_util[k]?"true":"false");
				if(rg->tab_code[k]==co->tab_code[i] && blanc_util[k])
				{
					D printf("ok\n");
					nb_blanc++;
					blanc_util[k]=false;
					break;
				}
				D printf("non ok\n");
			}
		}
	}
	rg->nb_rouge=nb_rouge;
	rg->nb_blanc=nb_blanc;
}
void test3(rangee* rg, code* co)
{
	comparaison(rg,co);
	printf("nb blanc: %d\nnb rouge: %d\n",rg->nb_blanc,rg->nb_rouge);
}

//Provisoirement dans ce dossier
int main(void)
{
	srand(time(NULL)); //initialisation de rand
	code* seq0 = initialisation_code();
	test1(seq0);

	rangee* rg = capture_rangee();
	test2(rg);

	test3(rg,seq0);
	return 0;
}
