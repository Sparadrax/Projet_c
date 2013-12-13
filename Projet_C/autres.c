#include "autres.h"
#include <stdio.h>
#include <stdlib.h>




/**********
Fonction nombres de lignes
**********/
int nombre_de_lignes(char* fichier)
{
    FILE* fichier2 = NULL;
    fichier2 = fopen(fichier, "r");
    char chaine[MAX]="";
    int nombre_lignes = 0;
    if(fichier2!=NULL)
    {
        while(fgets(chaine,MAX,fichier2))
        {
            nombre_lignes++;
        }
    }
    fclose(fichier2);
    return nombre_lignes;
}
/***********
Fin fonction nombres de lignes
***********/

/************
Fonction Strlen
************/
int strlen_manual(char* monStr)
{
int taille = 0;
    while(monStr[taille] != '\0')
    {
            taille++;
    }
return taille;
}
/************
Fin Strln
************/

/************
Fonction compare string
************/
int compare(char a[], char b[])
{
int i = 0; //parcours char
int stop = 0; //flag
while(a[i]!='\0' && b[i]!='\0')
    {
        if(a[i]!=b[i])
            {
                stop = 1;
                break;
            }
    i++;
    }
if(stop==0 && a[i]=='\0' && b[i]=='\0')
    {
        return 1;
    }
else
    {

        return 0;
    }
}
/************
Fin fonction compare string
************/

/************
Fonction creation tab
************/
char** fichier_to_char(char* file, int nb)
{
    /*
    On aloue l'espace mémoire
    */
    char** chaine_tab = NULL;
    chaine_tab = (char**)malloc(nb*sizeof(char*));
    if (chaine_tab == NULL)
    {
        fprintf(stderr,"Allocation impossible\n");
        exit(EXIT_FAILURE);
    }

    //Open src1 which is a fichier in this draft
    FILE* fichier = NULL;
    fichier = fopen(fichier,"r");

    //allocation of every line in memory
    if (fichier != NULL)
    {
        char buffer[MAX];
        char *chaine = buffer;
        int i;
        for (i=0;i<nb;i++)
        {
            chaine = fgets(chaine, MAX, fichier);
            if (chaine == NULL)
            {
                fprintf(stderr,"probleme lros de la lecture\n");
                exit(EXIT_FAILURE);
            }
            chaine_tab[i] = NULL;
            chaine_tab[i] = (char*)malloc((strlen(chaine))*sizeof(char)+1);

            //malloc return the address of the first octet allocated
            //it returns NULL if there was no allocation, so we test it
            if (chaine_tab[i] == NULL)
            {
                fprintf(stderr,"Allocation impossible\n");
                exit(EXIT_FAILURE);
            }

            strcpy(chaine_tab[i],chaine); //copy of chaine in our table[i]

            //we must change the last character if we want the last line to
            //be considered in the same way of the others in our comparisons
            if (chaine_tab[i][strlen(chaine)-1] == '\n')
            {
                chaine_tab[i][strlen(chaine)-1]='\0';
            }
        }
    }
    fclose(fichier);
    return chaine_tab;
}
/************
fin de creation de tab
************/
