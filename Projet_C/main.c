#include <stdio.h>
#include <stdlib.h>

#include "Options.h"
#include "autres.h"
int main(int argc,char** argv)
{
    /************
    Verification nombres arguments
    ************/
    if(argc <= 2)
    {
        printf("Pas assez d'arguments");
        return 1;
    }

    /************
    liste Options
    ************/
    int opt_q = 0;
    int opt_s = 0;
    int opt_c = 0;
    int opt_u = 0;
    int opt_e = 0;
    int opt_n = 0;
    int opt_y = 0;
    int opt_w = 0;
    int opt_p = 0;
    int opt_F = 0;
    int opt_t = 0;
    int opt_T = 0;
    int opt_l = 0;
    int opt_r = 0;
    int opt_N = 0;
    int opt_x = 0;
    int opt_X = 0;
    int opt_S = 0;
    int opt_i = 0;
    int opt_E = 0;
    int opt_Z = 0;
    int opt_b = 0;
    int opt_B = 0;
    int opt_I = 0;
    int opt_a = 0;
    int opt_D = 0;
    int opt_d = 0;
    int opt_v = 0;
    /************
    Fin liste options
    ************/

    /************
    Quelles options ont été choisis
    ************/
    int argument; //arguments que l'on vas parcourirs

    for(argument=1;argument<argc;argument++)
    {
        if(compare(argv[argument], "-q") || compare( argv[argument],  "--brief"))
        {
            opt_q = 1;
        }
        if(compare( argv[argument],  "-s") || compare( argv[argument],  "--report-identical-files"))
        {
            opt_s = 1;
        }
        if(compare( argv[argument],  "-o")) // A FINIR
        {
            opt_c = 1;
        }
        if(compare( argv[argument],  "-u")) // A FINIR
        {
            opt_u = 1;
        }
        if(compare( argv[argument],  "-e") || compare( argv[argument],  "--ed"))
        {
            opt_e = 1;
        }
        if(compare( argv[argument],  "-n") || compare( argv[argument],  "--rcs"))
        {
            opt_n = 1;
        }
        if(compare( argv[argument],  "-y") || compare( argv[argument],  "--side-by-side"))
        {
            opt_y = 1;
        }
        if(compare( argv[argument],  "-w")) // A FINIR
        {
            opt_w = 1;
        }
        if(compare( argv[argument],  "-p") || compare( argv[argument],  "--show-c-function"))
        {
            opt_p = 1;
        }
        if(compare( argv[argument],  "-F")) // A FINIR
        {
            opt_F = 1;
        }
        if(compare( argv[argument],  "-t") || compare( argv[argument],  "--expand-tabs"))
        {
            opt_t = 1;
        }
        if(compare( argv[argument],  "-T")) // A FINIR
        {
            opt_T = 1;
        }
        if(compare( argv[argument],  "-l") || compare( argv[argument],  "--paginate"))
        {
            opt_l = 1;
        }
        if(compare( argv[argument],  "-r") || compare( argv[argument],  "--recursive"))
        {
            opt_r = 1;
        }
        if(compare( argv[argument],  "-N")) // A FINIR
        {
            opt_N = 1;
        }
        if(compare( argv[argument],  "-x")) // A FINIR
        {
            opt_x = 1;
        }
        if(compare( argv[argument],  "-X")) // A FINIR
        {
            opt_X = 1;
        }
        if(compare( argv[argument],  "-S")) // A FINIR
        {
            opt_S = 1;
        }
        if(compare( argv[argument],  "-i") || compare( argv[argument],  "--ignore-case"))
        {
            opt_i = 1;
        }
        if(compare( argv[argument],  "-E") || compare( argv[argument],  "--ignore-tab-expansion"))
        {
            opt_E = 1;
        }
        if(compare( argv[argument],  "-Z") || compare( argv[argument],  "--ignore-trailing-space"))
        {
            opt_Z = 1;
        }
        if(compare( argv[argument],  "-b") || compare( argv[argument],  "--ignore-space-change"))
        {
            opt_b = 1;
        }
        if(compare( argv[argument],  "-w") || compare( argv[argument],  "--ignore-all-space"))
        {
            opt_w = 1;
        }
        if(compare( argv[argument],  "-B") || compare( argv[argument],  "--ignore-blank-lines"))
        {
            opt_B = 1;
        }
        if(compare( argv[argument],  "-I")) // A FINIR
        {
            opt_I = 1;
        }
        if(compare( argv[argument],  "-a")) // A FINIT
        {
            opt_a = 1;
        }
        if(compare( argv[argument],  "-D")) // A FINIR
        {
            opt_D = 1;
        }
        if(compare( argv[argument],  "-d")) // A FINIR
        {
            opt_d = 1;
        }
        if(compare( argv[argument],  "-v") || compare( argv[argument],  "--version"))
        {
            printf("Version 2013 \n");
            printf("Créé par Nicolas Bino, Aurelien Gille et Louis Du Beux.");
            return 0; //fin de programme
        }
        if(compare(argv[argument], "--help"))
        {
        printf(" [OPTIONS] fichier 1 fichier 2 \n\n");
        opt_help();
        return 0;
        }
    }



    //je définis les deux dernier arguments comme des types char;
    char* file1 = argv[argument-2];
    char* file2 = argv[argument-1];

    //je vais chercher les nombres de lignes des deux fichiers
    int nombre_ligne_fichier1 = nombre_de_lignes(file1);
    int nombre_ligne_fichier2 = nombre_de_lignes(file2);

    char** chaine1 = fichier_to_char(file1,nombre_ligne_fichier1);
    char** chaine2 = fichier_to_char(file2,nombre_ligne_fichier2);

printf("Diff of %s with %s:\n\n",file1,file2);

	// i is the index of the line we're processing in chaine1.
	int i;
	// j is the index of the line we're processing in chaine2.
	int j = 0;

	//Process each line of chaine1 and do our job
	for (i=0; i<nombre_ligne_fichier1; i++)
	{
		//Indicates if a matching line was found in chaine2 (true = 1)
		int found = 0;
		//Indicates the number of lines we've skipped in chaine2 before finding the matching line.
		int skipped = 0;

		//we process each line of chaine2 (starting from the j-th one)
		//until we either find a matching line or the end of file
		while (j<nombre_ligne_fichier2 && found == 0)
		{
			// Compare both lines
			if(strcmp(chaine1[i], chaine2[j]) == 0)
			{
				found = 1;
			}
			else
			{
			    skipped++;
			}
			j++;
		}

		//Now process the result:
		if (found == 1)
		{
			//Print lines we skipped (from j-skipped to j)
			int a;
			for (a=j-skipped;a<j;a++)
			{
				printf("> %s\n", chaine2[a-1]);
			}
            //Print the matched line
			printf("= %s\n", chaine1[i]);



		}
		else
		{
			//Only print the line from chaine1, and rollback the
			//index j because we'll have to read those lines again.
			printf("< %s\n", chaine1[i]);
			j = j-skipped;

		}
	}

    return 0;
}
