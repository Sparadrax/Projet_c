#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED


/************
Liste des options que nous avons
************/

/************
Fin liste
************/
void opt_help();
int compare(char a[], char b[]);
/************
D�but des fonctions
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
Fonciton HELP --help
************/
void opt_help()
{
printf("    -q, --brief Indiquer seulement si les fichiers diff�rent \n");
printf("-s, --report-identical-files Indiquer si les deux fichiers sont identiques \n");
printf("-c, -C N, --context[=N] Afficher N (3 par d�faut) lignes du contexte copi� \n");
printf("-u, -U N, --unified[=N] Afficher N (3 par d�faut) lignes dans le context unifi� \n");
printf("-e, --ed G�n�rer un script pour � ed � \n");
printf("-n, --rcs G�n�rer un fichier � diff � au format RCS \n");
printf("-y, --side-by-side Affichage sur deux colonnes \n");
printf("-w, --width=N Limiter la sortie � au plus N colonnes imprim�es (130 par d�faut) \n");
printf("--left-column Afficher les lignes identiques uniquement dans la colonne de gauche \n");
printf("--suppress-common-lines Ne pas afficher les lignes identiques \n");
printf("-p, --show-c-function Afficher dans quelle fonction C le changement se trouve \n");
printf("-F, --show-function-line=RE Montrer la ligne la plus r�cente correspondant � RE \n");
printf("--label �TIQUETTE Utiliser �TIQUETTE au lieu du nom de fichier \n");
printf("(peut �tre r�p�t�) \n");
printf("-t, --expand-tabs �taler les tabulateurs en espaces dans la sortie \n");
printf("-T, --initial-tab Aligner les tabulateurs en pr�fixant un tabulateur \n");
printf("--tabsize=N Les balises de tabulation sont � chaque N (8 par d�faut) colonnes \n");
printf("SUPPORT DE COURS EXERCICES R�SULTATS PROJET \n");
printf("--suppress-blank-empty Supprimer les espaces et les tabulations avant les lignes vides \n");
printf("-l, --paginate Relayer la sortie � � pr � afin de la paginer \n");
printf("-r, --recursive Comparer r�cursivement les sous-r�pertoires trouv�s \n");
printf("-N, --new-file Traiter les fichiers absents comme des fichiers vides \n");
printf("--unidirectional-new-file Traiter les premiers fichiers absents comme vides \n");
printf("--ignore-file-name-case Ignorer la casse lors de la comparaison des noms de fichiers \n");
printf("--no-ignore-file-name-case Tenir compte de la casse lors de la comparaison des noms de fichiers \n");
printf("-x, --exclude=PAT Exclure les fichiers dont les noms concordent avec le PATron \n");
printf("-X, --exclude-from=FICHIER Exclure les fichiers dont les noms \n");
printf("concordent avec ceux contenus dans le FICHIER \n");
printf("-S, --starting-file=FICHIER D�buter la comparaison des r�pertoires par le FICHIER \n");
printf("--from-file=FICHIER1 Comparer le FICHIER1 � toutes les op�randes. \n");
printf("FICHIER1 peut �tre un r�pertoire \n");
printf("--to-file=FICHIER2 Comparer toutes les op�randes � FICHIER2. \n");
printf("FICHIER2 peut �tre un r�pertoire \n");
printf("-i, --ignore-case Ignorer les diff�rences de casses dans le contenu des fichiers \n");
printf("-E, --ignore-tab-expansion Ignorer les changements li�s � l'expansion des tabulations \n");
printf("-Z, --ignore-trailing-space ignore white space at line end \n");
printf("-b, --ignore-space-change Ignorer les changements dans le nombre d'espaces \n");
printf("-w, --ignore-all-space Ignorer tout blanc d'espacement \n");
printf("-B, --ignore-blank-lines Ignorer les changements dont toutes les lignes sont blanches \n");
printf("-I, --ignore-matching-lines=RE Ignorer les diff�rences dont toutes les \n");
printf("lignes concordent avec l'expression r�guli�re RE \n");
printf("-a, --text Traiter tous les fichiers comme des textes \n");
printf("--strip-trailing-cr �liminer les retours de chariot de l'entr�e \n");
printf("-D, --ifdef=NOM Afficher les fichiers fusionn�s en marquant les diff�rences par des � #ifdef NOM � \n");
printf("--GTYPE-group-format=GFMT Formater les groupes d'entr�e GTYPE avec GFMT \n");
printf("--line-format=LFMT Formater toutes les lignes d'entr�e avec LFMT \n");
printf("--LTYPE-line-format=LFMT Formater les lignes d'entr�e LTYPE avec LFMT \n");
printf("Ces options de formatage fournissent un contr�le fin sur la sortie \n");
printf("de diff et g�n�ralise -D/--ifdef. \n");
printf("LTYPE peut �tre soit � old �, � new �, ou � unchanged �. GTYPE prend une des valeurs de LTYPE ou � changed �. \n");
printf("GFMT (uniquement) peut contenir : \n");
printf("%< pour marquer les lignes du FICHIER1 \n");
printf("%> pour marquer les lignes du FICHIER2 \n");
printf("%= pour marquer les lignes identiques entre FICHIER1 et FICHIER2 \n");
printf("%[-][LARGEUR][.[PREC]]{doxX}LETTRE la sp�cification de LETTRE \n");
printf("est identique � la notation de printf() \n");
printf("dont les codes possibles de LETTRE sont \n");
printf("en majuscule pour le nouveau groupe, \n");
printf("en minuscules pour l'ancien groupe: \n");
printf("F num�ro de la premi�re ligne \n");
printf("L num�ro de la derni�re ligne \n");
printf("N nombre de lignes = L-F+1 \n");
printf("E F-1 \n");
printf("M L+1 %(A=B?T:E) si A �gal B alors T sinon E \n");
printf("LFMT (uniquement) peut contenir : \n");
printf("%L pour le contenu de la ligne \n");
printf("%l pour le contenu de la ligne sans fin de ligne \n");
printf("%[-][LARGEUR][.[PREC]]{doxX}n la sp�cification du num�ro de ligne \n");
printf("d'entr�e selon le format de printf \n");
printf("GFMT et LFMT peuvent contenir : \n");
printf("%% % \n");
printf("%c�C� le caract�re �C� lui-m�me \n");
printf("%c'\OOO� le caract�re dont le code octal est OOO C le caract�re C (les autres caract�res se repr�sentent eux-m�mes) \n");
printf("-d, --minimal Rechercher assid�ment le plus petit ensemble de diff�rences \n");
printf("--horizon-lines=N Retenir N lignes ayant des pr�fixes et suffixes identiques \n");
printf("--speed-large-files Suppose de grands fichiers et de nombreux petits changements �parpill�s \n");
printf("--help Afficher cette aide et terminer \n");
printf("-v, --version Afficher le nom et la version du logiciel et terminer \n");
}
/************
FIN FONCTION HELP --help
************/


/************
Fin des fonctions
************/


#endif // OPTIONS_H_INCLUDED
