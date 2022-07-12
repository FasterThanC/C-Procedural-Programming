#include "visos.h"

FILE *Atidarymas ()
{
    FILE *fp;
    char failoPavadinimas[100]="";

    printf("Si programa duotame tekste pasikartojancius vienodus simbolius pakeicia simboliu $ ir skaiciumi buvusiu simboliu.\n");
    printf("\nPrasome ivesti kokiame faile yra laikomi reikalingi duomenys: \n");
    scanf("%s",&failoPavadinimas);
    fp = fopen(failoPavadinimas,"r");
        if(fp==NULL)
        {
            printf("\n%s\" Apgailestaujame, bet failas nebuvo rastas. \n",failoPavadinimas);
            return 0;
        }
        else
            return fp;
}
