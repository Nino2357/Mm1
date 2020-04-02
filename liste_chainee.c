#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"



Liste *initialisation(int nvNombre) //Initialise la liste
{
    Liste *liste = malloc(sizeof(Liste));
    Element *element = malloc(sizeof(Element));

    if (liste == NULL || element == NULL) //En cas d'echec d'initialisation
    {
        exit(EXIT_FAILURE);
    }
    liste->premier = element;
    /*Ajout du 1er élement*/
    element->nombre = nvNombre; //A modifier en fonction de la structure
    element->suivant = NULL;

    return liste;
}

void insertion_debut(Liste *liste, int nvNombre) //Ajoute un élément au début de la liste
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void insertion_fin(Liste *liste, int nvNombre) //Ajoute un élément à la fin de la liste
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = liste->premier;

    while (actuel->suivant != NULL) //Parcours de la liste
    {
        actuel = actuel->suivant;
    }
    /* Insertion de l'élément à la fin de la liste */
    nouveau->nombre = nvNombre; //A modifier
    nouveau->suivant = NULL;
    actuel->suivant = nouveau;
}
void suppression_debut(Liste *liste) //Supprime le 1er élement de la liste
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}
void suppression_fin(Liste *liste) //Supprime le 1er élement de la liste
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *actuel = liste->premier;
        Element *precedent = NULL;

        while (actuel->suivant != NULL) //Parcours de la liste
        {
            precedent = actuel;
            actuel = actuel->suivant;
        }
        Element *aSupprimer = actuel;
        precedent->suivant = NULL;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste) //Affiche le contenu de la liste
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}



