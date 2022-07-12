/*Užduotis - Įvesti sveiką skaičių N. Įvesti N sveikų skaičių, kurie sudarys vektorių. Rasti didžiausią atstumą (matuojant elementų pozicijomis) tarp šio vektoriaus ekstremumų. Ekstremumu laikomas toks vektoriaus elementas, iki kurio yra didėjanti seka, o po jo yra mažėjanti seka, arba, atvirkščiai, iki jo yra mažėjanti seka, o po jo yra didėjanti seka. Programa turėtų išvesti elementų numerius ir atstumą tarp jų.
 2 užduotis, 9 variantas
Studentas - Vadim Čeremisinov
VU el.paštas - vadim.ceremisinov@mif.stud.vu.lt
*/

#include <stdlib.h>
#include <stdio.h>


void tikrinamInputa (int *elementas)
{

    int validInput = scanf("%d", elementas);
        while (!validInput || getchar() != '\n')
        {
            printf("Neteisingai ivestas sveikas skaicius. Maloniai prasome ivedineti tik sveikus skaicius!\n");
            while(getchar() != '\n')
                ;
            validInput = scanf("%d", elementas);
        }

}

// int tikrinamInputa ()
// {
//     int elementas;
//     int validInput = scanf("%d", &elementas);
//         while (!validInput || getchar() != '\n')
//         {
//             printf("Neteisingai ivestas sveikas skaicius. Maloniai prasome ivedineti tik sveikus skaicius!\n");
//             while(getchar() != '\n')
//                 ;
//             validInput = scanf("%d", &elementas);
//         }
//         return elementas;
// }

void ivestiesFunkcija(int sekosElementuSkaicius, int Elementai[])
{

    int skaiciuojamEkstremumus = 0;

    for(int k = 0; k < sekosElementuSkaicius; ++k)
    {
        printf ("Irasykite sveiku skaiciu seka:\n");

        //Elementai[k] = tikrinamInputa();
        tikrinamInputa(&Elementai[k]);
    }
}


int ekstremumuPaieska (int k, int Elementai[], int EkstremumuNumeriaiMasyve[])
{
  int skaiciuojamEkstremumus = 0;
  for (int i = 1; i < k; ++i)
  {
    if(((Elementai[i] > Elementai[i-1])&&(Elementai[i] > Elementai[i+1]))||((Elementai[i] < Elementai[i-1])&&(Elementai[i] < Elementai[i+1]) ))
            {
            EkstremumuNumeriaiMasyve[skaiciuojamEkstremumus] = i + 1;
            ++skaiciuojamEkstremumus;
            }
        }

  return skaiciuojamEkstremumus;
}



int main ()
{
    int sekosElementuSkaicius, skaiciuojamEkstremumus = 0;
    int ekstremumuSkaicius = 0;

    printf ("Si programa skaiciuoja didziausia atstuma tarp ivesto vektoriaus ekstremumu ir isveda tu elementu numerius.\n");
    printf ("Irasykite kiek elementu bus jusu skaiciu sekoje:\n");

    tikrinamInputa(&sekosElementuSkaicius);

    int Elementai[sekosElementuSkaicius];
    int EkstremumuNumeriaiMasyve[sekosElementuSkaicius];

    ivestiesFunkcija(sekosElementuSkaicius, Elementai);

    skaiciuojamEkstremumus = ekstremumuPaieska(sekosElementuSkaicius, Elementai, EkstremumuNumeriaiMasyve);


    int vektoriausEkstremumasNr1 = EkstremumuNumeriaiMasyve[0];

    int vektoriausEkstremumasNr2 = EkstremumuNumeriaiMasyve[1];


    int didziausiasAtstumasTarpVektoriausEkstremumu = EkstremumuNumeriaiMasyve[1] - EkstremumuNumeriaiMasyve[0];




for (int i = 0; i < skaiciuojamEkstremumus - 1; ++i)
    {
        if (didziausiasAtstumasTarpVektoriausEkstremumu < EkstremumuNumeriaiMasyve[i + 1] - EkstremumuNumeriaiMasyve[i])
        {
            didziausiasAtstumasTarpVektoriausEkstremumu = EkstremumuNumeriaiMasyve[i + 1] - EkstremumuNumeriaiMasyve[i];
            vektoriausEkstremumasNr1 = EkstremumuNumeriaiMasyve[i];
            vektoriausEkstremumasNr2 = EkstremumuNumeriaiMasyve[i + 1];
        }
    }

    printf ("Pirmojo ekstremumo numeris yra: %d \n", vektoriausEkstremumasNr1);
    printf ("Antrojo ekstremumo numeris yra: %d \n", vektoriausEkstremumasNr2);

    printf ("Didziausias atstumas tarp sio vektoriaus ekstremumu yra: %d \n", didziausiasAtstumasTarpVektoriausEkstremumu);

    return 0;

}
