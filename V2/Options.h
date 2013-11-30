#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED


/************
Liste des options que nous avons
************/

/************
Fin liste
************/
void opt_help();
char* str_onespace(const char* a);
char* str_lower(const char* a);

/************
Début des fonctions
************/

/************
Fonction to lower -i
************/
char* str_lower(const char* a)
{
    char* b;
        if(a != NULL)
        {
            b = malloc((strlen_manual(a)+1)*sizeof(*b));

            int i;
            if(b != NULL)
            {
                for(i=0;a[i];i++)
                {
                    b[i] = tolower(a[i]);
                }
                b[i] = '\0';
            }
            return b;

        }
}
/************
Fin to lower
************/

/************
Fonction ignore space change
************/
char* str_onespace(const char* a)
{
    char* espace = NULL;
    int espace2 = 0;
    if(a!=NULL)
    {
        espace = malloc((strlen_manual(a)+1) * sizeof(*espace));
            int i = 0;
            int i2 = 0;

        for(i=0; a[i];i++)
        {
            if(a[i]==' ')
            {
                if(espace2 == 0)
                {
                    espace2 = 1;
                    espace[j] = a[i];
                    i2++;
                }
                else
                {
                    espace2 = 0;
                    espace[i2] = a[i];
                    i2++;
                }
            }
            espace[i2] = '\0'
        }
    }
    return espace;
}

/************
Fin ignore space change
************/


/************
Fonciton HELP --help
************/
void opt_help()
{
printf("    -q, --brief Indiquer seulement si les fichiers diffèrent \n");
printf("-s, --report-identical-files Indiquer si les deux fichiers sont identiques \n");
printf("-c, -C N, --context[=N] Afficher N (3 par défaut) lignes du contexte copié \n");
printf("-u, -U N, --unified[=N] Afficher N (3 par défaut) lignes dans le context unifié \n");
printf("-e, --ed Générer un script pour « ed » \n");
printf("-n, --rcs Générer un fichier « diff » au format RCS \n");
printf("-y, --side-by-side Affichage sur deux colonnes \n");
printf("-w, --width=N Limiter la sortie à au plus N colonnes imprimées (130 par défaut) \n");
printf("--left-column Afficher les lignes identiques uniquement dans la colonne de gauche \n");
printf("--suppress-common-lines Ne pas afficher les lignes identiques \n");
printf("-p, --show-c-function Afficher dans quelle fonction C le changement se trouve \n");
printf("-F, --show-function-line=RE Montrer la ligne la plus récente correspondant à RE \n");
printf("--label ÉTIQUETTE Utiliser ÉTIQUETTE au lieu du nom de fichier \n");
printf("(peut être répété) \n");
printf("-t, --expand-tabs Étaler les tabulateurs en espaces dans la sortie \n");
printf("-T, --initial-tab Aligner les tabulateurs en préfixant un tabulateur \n");
printf("--tabsize=N Les balises de tabulation sont à chaque N (8 par défaut) colonnes \n");
printf("SUPPORT DE COURS EXERCICES RÉSULTATS PROJET \n");
printf("--suppress-blank-empty Supprimer les espaces et les tabulations avant les lignes vides \n");
printf("-l, --paginate Relayer la sortie à « pr » afin de la paginer \n");
printf("-r, --recursive Comparer récursivement les sous-répertoires trouvés \n");
printf("-N, --new-file Traiter les fichiers absents comme des fichiers vides \n");
printf("--unidirectional-new-file Traiter les premiers fichiers absents comme vides \n");
printf("--ignore-file-name-case Ignorer la casse lors de la comparaison des noms de fichiers \n");
printf("--no-ignore-file-name-case Tenir compte de la casse lors de la comparaison des noms de fichiers \n");
printf("-x, --exclude=PAT Exclure les fichiers dont les noms concordent avec le PATron \n");
printf("-X, --exclude-from=FICHIER Exclure les fichiers dont les noms \n");
printf("concordent avec ceux contenus dans le FICHIER \n");
printf("-S, --starting-file=FICHIER Débuter la comparaison des répertoires par le FICHIER \n");
printf("--from-file=FICHIER1 Comparer le FICHIER1 à toutes les opérandes. \n");
printf("FICHIER1 peut être un répertoire \n");
printf("--to-file=FICHIER2 Comparer toutes les opérandes à FICHIER2. \n");
printf("FICHIER2 peut être un répertoire \n");
printf("-i, --ignore-case Ignorer les différences de casses dans le contenu des fichiers \n");
printf("-E, --ignore-tab-expansion Ignorer les changements liés à l'expansion des tabulations \n");
printf("-Z, --ignore-trailing-space ignore white space at line end \n");
printf("-b, --ignore-space-change Ignorer les changements dans le nombre d'espaces \n");
printf("-w, --ignore-all-space Ignorer tout blanc d'espacement \n");
printf("-B, --ignore-blank-lines Ignorer les changements dont toutes les lignes sont blanches \n");
printf("-I, --ignore-matching-lines=RE Ignorer les différences dont toutes les \n");
printf("lignes concordent avec l'expression régulière RE \n");
printf("-a, --text Traiter tous les fichiers comme des textes \n");
printf("--strip-trailing-cr Éliminer les retours de chariot de l'entrée \n");
printf("-D, --ifdef=NOM Afficher les fichiers fusionnés en marquant les différences par des « #ifdef NOM » \n");
printf("--GTYPE-group-format=GFMT Formater les groupes d'entrée GTYPE avec GFMT \n");
printf("--line-format=LFMT Formater toutes les lignes d'entrée avec LFMT \n");
printf("--LTYPE-line-format=LFMT Formater les lignes d'entrée LTYPE avec LFMT \n");
printf("Ces options de formatage fournissent un contrôle fin sur la sortie \n");
printf("de diff et généralise -D/--ifdef. \n");
printf("LTYPE peut être soit « old », « new », ou « unchanged ». GTYPE prend une des valeurs de LTYPE ou « changed ». \n");
printf("GFMT (uniquement) peut contenir : \n");
printf("%< pour marquer les lignes du FICHIER1 \n");
printf("%> pour marquer les lignes du FICHIER2 \n");
printf("%= pour marquer les lignes identiques entre FICHIER1 et FICHIER2 \n");
printf("%[-][LARGEUR][.[PREC]]{doxX}LETTRE la spécification de LETTRE \n");
printf("est identique à la notation de printf() \n");
printf("dont les codes possibles de LETTRE sont \n");
printf("en majuscule pour le nouveau groupe, \n");
printf("en minuscules pour l'ancien groupe: \n");
printf("F numéro de la première ligne \n");
printf("L numéro de la dernière ligne \n");
printf("N nombre de lignes = L-F+1 \n");
printf("E F-1 \n");
printf("M L+1 %(A=B?T:E) si A égal B alors T sinon E \n");
printf("LFMT (uniquement) peut contenir : \n");
printf("%L pour le contenu de la ligne \n");
printf("%l pour le contenu de la ligne sans fin de ligne \n");
printf("%[-][LARGEUR][.[PREC]]{doxX}n la spécification du numéro de ligne \n");
printf("d'entrée selon le format de printf \n");
printf("GFMT et LFMT peuvent contenir : \n");
printf("%% % \n");
printf("%c«C» le caractère «C» lui-même \n");
printf("%c'\OOO» le caractère dont le code octal est OOO C le caractère C (les autres caractères se représentent eux-mêmes) \n");
printf("-d, --minimal Rechercher assidûment le plus petit ensemble de différences \n");
printf("--horizon-lines=N Retenir N lignes ayant des préfixes et suffixes identiques \n");
printf("--speed-large-files Suppose de grands fichiers et de nombreux petits changements éparpillés \n");
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
