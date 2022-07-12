/*
Studentas - Vadim Čeremisinov
VU paštas: vadim.ceremisinov@mif.stud.vu.lt
3 užduotis 7 variantas
*/


//Ši programa duotame tekste pasikartojančius vienodus simbolius pakeičia simboliu $ ir skaičiumi buvusių simbolių.

#include <stdio.h>
#include "visos.h"


int main (int argc, char *argv[]){

        FILE *fp, *isvestis;

        fp = Atidarymas();
        if(fp != 0)
    {
        isvestis = Sukurimas();
        if(isvestis != 0){

        KeitimoFunkcija(fp, isvestis);
        fclose(fp);
        fclose(isvestis);}
        else
        printf("Apgailestaujame, bet isvesties failo nepavyko sukurti\n");
    }
        else
        printf("Apgailestaujame, bet nepavyko pasiekti faila\n");

return 0;
}
