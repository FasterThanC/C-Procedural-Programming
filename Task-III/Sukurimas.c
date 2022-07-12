#include "visos.h"

FILE *Sukurimas()
{
    FILE *fp;
    char failoPavadinimas[100]="";

    printf("\nPrasome ivesti failo pavadinima, kuriame rasite skaiciavimu rezultata: \n");
    scanf("%s", &failoPavadinimas);

    fp = fopen(failoPavadinimas, "w");
    if (fp==NULL)
    {
        printf("\n%s\" Deja, tokio failo nepavyko rasti \n",failoPavadinimas);
        return 0;
    }
    else
        return fp;
}
