#ifndef AUTRES_H_INCLUDED
#define AUTRES_H_INCLUDED

/**********
Toutes les autres fonctions serons dans ce document
**********/

/**********
listes des fonctions
**********/
#define MAX 10000 // nombres maximum de charractéres sur les lignes
int nombre_de_lignes(char* fichier);
int strlen_manual(char* monStr);
int compare(char a[], char b[]);
/**********
fin de la liste
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

#endif // AUTRES_H_INCLUDED
