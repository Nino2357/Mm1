#include "f_decodage.h"

long nb_comb(void) //renvoie le nombre de combianaisons possibles
{
	long nb_comb = 1;
	for(int i=0;i<NB_TROUS;i++)
	{
		nb_comb = nb_comb * NB_COULEURS;
	}
	return nb_comb;
}
int puiss(int nb, int exp)
{
	int res = 1;
	for(int i=0;i<exp;i++)
	{
		res = res * nb;
	}
	return res;
}

void creation_liste(void)
{
	FILE* liste_comb = NULL;
	liste_comb = fopen("liste_comb.txt","w");
	long compte = 0;
	int unit = 0;
	int reste = 0;
	while(compte < nb_comb())
	{
		reste = compte;
		for(int i=0;i<NB_TROUS;i++)
		{
			unit =(int) reste / (NB_COULEURS* puiss(NB_COULEURS,NB_TROUS - i));
			reste =(int) compte % NB_COULEURS;
			fprintf(liste_comb, "%d\t",unit);
		}
		fprintf(liste_comb, "\n");
		compte++;
	}
	fclose(liste_comb);
}


void test_nb_comb(void)
{
	printf("%ld\n",nb_comb());
}
void test_c_liste(void)
{
	creation_liste();
}

int main(void)
{
	test_nb_comb();
	test_c_liste();

	return 0;
}

