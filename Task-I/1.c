/*Užduotis - Įvesti sveikų skaičių seką, kurios pabaiga žymima skaičiumi 0. Išvesti narių, kurių skaitmenų suma lyginė, skaičių.
 1 užduotis, 2 variantas
LSP numeris - 2110545
VU el.paštas - vadim.ceremisinov@mif.stud.vu.lt
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{

    int skaicius = 0;
    int atskiriam_vienetus = 0;
    int rezultatas = 0;
    int skaitmenu_suma = 0;
    int input = 1;


    printf ("Si programa skaiciuoja kiek yra ivesta skaiciu, kuriu skaitmenu suma lygine.\n");
    printf ("Irasykite skaiciu seka:\n");

    while (input > 0 || input < 0)
    {
        int validInput = scanf("%d", &input);
        while (!validInput || getchar() != '\n')
        {
            printf("Neteisingai ivestas sveikas skaicius. Maloniai prasome ivedineti tik sveikus skaicius!\n");
            while(getchar() != '\n')
                ;
            validInput = scanf("%d", &input);
        }

        skaicius = input;

        skaicius = abs(skaicius);
        skaitmenu_suma = 0;

        while(skaicius != 0)
        {
            atskiriam_vienetus = skaicius % 10;
            skaitmenu_suma = skaitmenu_suma + atskiriam_vienetus;
            skaicius = skaicius / 10;
        }

        if (skaitmenu_suma % 2 == 0 && input != 0)
        {
            rezultatas++;
        }


    }
    printf ("Nariu skaicius, kuriu skaitmenu suma yra lygine: %d \n", rezultatas);




    return 0;
}

