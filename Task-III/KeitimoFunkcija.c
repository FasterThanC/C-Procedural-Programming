#include "visos.h"

void KeitimoFunkcija (FILE *duomp, FILE *rezp)
{
    int tekstoIlgis = 0, PasikartojantiIvestis = 1;
    char *ivestasTekstas;
    int a = 0;
    int paskutineEilute = 0;

    while(1)
    {
        int kiekSymboliu = 0;
        //printf("%s %d\n", "numeris", a);
        ++a;
        char b;
        while((b = fgetc(duomp)) != '\n' && !feof(duomp))
        {
            ++kiekSymboliu;     //pakeitimas
            //printf("%d : %c\n", kiekSymboliu, b);
        }
        if (feof(duomp))
        {
            //printf("failo pabaiga");
            ++paskutineEilute;
            fseek(duomp, -kiekSymboliu, SEEK_CUR);
        }
        else
        {
            fseek(duomp, -(kiekSymboliu+2), SEEK_CUR);
        }
        if (kiekSymboliu > 255)
        {
            kiekSymboliu = 255;
        }
        ivestasTekstas = (char*)malloc(kiekSymboliu+1); //pakeitimas


        fgets(ivestasTekstas, kiekSymboliu + 1, duomp);

        //if (ivestasTekstas[253])

               while((fgetc(duomp)) != '\n' && !feof(duomp))  //pakeitimas
            ;

        tekstoIlgis = strlen(ivestasTekstas);
        for(int i = 1; i <= tekstoIlgis; ++i)
        {
            if(ivestasTekstas[i-1] != 32)
            {
                //printf("%d : %c - %d : %c \n", i, ivestasTekstas[i], i - 1, ivestasTekstas[i-1]);
                if (ivestasTekstas[i] == ivestasTekstas [i-1])
                {
                    ++PasikartojantiIvestis;

                }
                else
                {
                    if(PasikartojantiIvestis > 1)
                    {
                        fprintf(rezp, "%c$%d", ivestasTekstas[i-1], PasikartojantiIvestis);
                    }
                    else
                        fprintf(rezp, "%c", ivestasTekstas[i-1]);
                    PasikartojantiIvestis = 1;
                }
            }
            else
                fprintf(rezp, "%c", ivestasTekstas[i-1]);
        }
        //if (ivestasTekstas[253]) //pakeitimas

         fprintf(rezp, "%c", '\n');

        memset(ivestasTekstas, 0, kiekSymboliu+1); //pakeitimas
        free(ivestasTekstas); //pakeitimas
        if (paskutineEilute)
        {
           break;
        }
    }
    printf("Rezultatas irasytas i faila\n");
}
