#ifndef H_CODEUR
#define H_CODEUR

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Indispensable pour rand
#include <stdbool.h>

#define NB_TROUS 4
#define NB_COULEURS 9
#define NB_TOURS_MAX 12

#define DEBUG false
#define D if(DEBUG)


typedef struct rangee
{
	int id;
	int tab_code[NB_TROUS];
	int nb_blanc;
	int nb_rouge;
	struct rangee *suiv;
}*Rg,rangee;

typedef struct Code
{
	int tours;
	int tab_code[NB_TROUS];
}*co,code;

#endif