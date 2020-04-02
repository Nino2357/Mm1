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

void capture_rangee(rangee* tete)
{	
	D printf("dans capture rangee\n");
    rangee *nouv_rg = malloc(sizeof(rangee));
	rangee *actuel = tete;
	D printf("%p\n", &actuel);
    while (actuel->suiv != NULL) //Parcours de la liste
    {
    	D printf("dans while\n");
        actuel = actuel->suiv;
    }
    D printf("apres while\n");
    actuel->suiv = nouv_rg;
        D printf("apres parcours\n");
    nouv_rg->suiv = NULL;
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
			nouv_rg->tab_code[i]=nb_temp;
		}
	}
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

void comparaison(rangee* tete, code* co)
{
	D printf("dans comparaison\n");
	rangee *actuel = tete;
	D printf("%p\n", &actuel);
    while (actuel->suiv != NULL) //Parcours de la liste
    {
    	D printf("dans while\n");
        actuel = actuel->suiv;
    }
	int nb_blanc=0;	//Un pour chaque fiche du code ayant une fiche de la meme couleur placée par le décodeur
	bool blanc_util[NB_TROUS]; //Sert a compter qu'une seul fois chaque fiche réponse lors du décompte des blancs
	for(int y=0;y<NB_TROUS;y++) //met les valeurs a true par défaut
	{
		blanc_util[y]=true;
	}
	int nb_rouge=0;	//Quand emplacement + couleur ok
	for(int i=0;i<NB_TROUS;i++) //Parcours du code
	{
		if (actuel->tab_code[i]==co->tab_code[i]) //s'il y a un parfait (rouge)
		{
			nb_rouge++;
			blanc_util[i]= false;
		}
		else
		{
			for(int k=0;k<NB_TROUS;k++) //Parcours de la proposition de décodage
			{
				D printf("code %d\tsol %d\tutil? %s\n ",co->tab_code[i],actuel->tab_code[k], blanc_util[k]?"true":"false");
				if(actuel->tab_code[k]==co->tab_code[i] && blanc_util[k])
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
	actuel->nb_rouge=nb_rouge;
	actuel->nb_blanc=nb_blanc;
}
void test3(rangee* rg, code* co)
{
	comparaison(rg,co);
	printf("nb blanc: %d\nnb rouge: %d\n",rg->nb_blanc,rg->nb_rouge);
}
/*
void test_global(void)
{
	code* seq0 = initialisation_code();
	test1(seq0);

	rangee* rg = capture_rangee(tete);
	test2(rg);

	test3(rg,seq0);	
}*/
bool affichage_board(rangee* tete)
{
	bool victoire = false;
	rangee *actuel = tete;
	int tour =1;
	printf("************************************************************************\n\n");
    while (actuel->suiv != NULL) //Parcours de la liste
    {	
    	printf("Tour%d :\t\t",tour);
    	tour ++;
        actuel = actuel->suiv;
    	for(int i=0; i<NB_TROUS;i++)
    	{
    		printf("%d\t",actuel->tab_code[i]);
    	}
    	printf("Blanc :%d\tRouge :%d\n",actuel->nb_blanc,actuel->nb_rouge);
    	if(actuel->nb_rouge==NB_TROUS)
    	{
    		victoire = true;
    	}
    }
    printf("\n");
    printf("************************************************************************\n");
    return victoire;
}
void partie_decodage(void)
{
	srand(time(NULL)); //initialisation de rand
	code* seq= initialisation_code();
	test1(seq);
	rangee* tete = malloc(sizeof(rangee));
	tete->suiv = NULL;
	int tour = 0;
	bool fin = false;
	D printf("avant boucle\n");
	while(tour<NB_TOURS_MAX)
	{
		D printf("dans boucle\n");
		capture_rangee(tete);
		D printf("apres capture\n");
		comparaison(tete,seq);
		fin = affichage_board(tete);
		if (fin) break;
		tour ++;
	}
	if (fin)
	{
		printf("\n\n\t\t\t!!! VICTOIRE !!!\n\n\n");
	}
	else 
	{
		printf("\n\n\t\t\t     DEFAITE\n\n\n");
	}
}
//Provisoirement dans ce dossier
int main(void)
{
	partie_decodage();
	return 0;
}
