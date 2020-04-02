#define NB_TROUS 4
#define NB_COULEURS 9
#define NB_TOURS_MAX 12


typedef struct rangee
{
	int id;
	int tab_code[NB_TROUS];
	int tab_eval[NB_TROUS];
	struct range *suiv;
}*Rg,rangee;

typedef struct Code
{
	int tours;
	int tab_code[NB_TROUS];
}*co,code;


