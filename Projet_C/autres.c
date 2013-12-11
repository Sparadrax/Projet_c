#include "autres.h"
#include <stdio.h>
#include <stdlib.h>

/**********
Fonction fichier en liste Char
**********/
char* fichier_to_char(char* file, int* taille)
{
char* tableau_fichier = NULL;

FILE* fichier = NULL;
fichier = fopen(file,"r");

if(fichier != NULL)
{
    char lecture_ligne = MAX;
    int i;
    for(i=0 ; i<taille ; i++)
    {
        lecture_ligne = fgets(lecture_ligne, MAX, fichier);
    }
}
 return tableau_fichier;
}
/**********
Fin fonction fichier liste char
**********/


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
