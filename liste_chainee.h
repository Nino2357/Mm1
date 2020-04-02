#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Liste
{
    Rg *premier;
}*Li;


Liste *initialisation(int nvNombre);
void insertion_debut(Liste *liste, int nvNombre);
void insertion_fin(Liste *liste, int nvNombre);
void suppression_debut(Liste *liste);
void suppression_fin(Liste *liste);
void afficherListe(Liste *liste);

#endif
