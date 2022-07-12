#include "visos.h"

void launchUserInterface(struct Element **head)
{
    int value;
    int printMenu = 0;

    while(1)
    {
        printMenu = (printMenu + 1) % 5; /// to not spam the menu, every fifth wrong request will have the menu printed.
        if(printMenu == 1)
        {
            printMenuText();
        }

        int continueFlag = 0;
        validateMenuIvestis(stdin, &continueFlag, &value);

        if(continueFlag == 0) /// if a right value is found, the validating process ends.
        {
            break;
        }
    }

    switch(value) /// menu logical execution
    {
        case 0:
        {
            sarasoPasiekimoFunkcija(head);
            break;
        }
        case 1:
        {
            printElements(*head);
            break;
        }
        case 2:
        {
            deleteProcess(head);
            break;
        }
        case 3:
        {
            deleteWholeList(head);
            break;
        }
        case 4:
        {
            return;
        }
        default:
        {
            ;
        }
    }

    launchUserInterface(head); /// the function is recursive
    return;
}

void printMenuText() /// prints the user interface menu.
{
    puts("");
    puts("");
    puts("Galimu vartotojo veiksmu meniu:");
    puts("");
    puts("0. Iveskite failo pavadinima ir sukurkite vienpusi sarasa su duomenim is to failo.");
    puts("1. Atspausdinti vienpusi sarasa kompiuterio atmintyje.");
    puts("2. Iterpti elementa pries kita elementa nurodant ju reiksmes.");
    puts("3. Pasalinti visa vienpusi sarasa.");
    puts("4. Iseiti is programos.");
    puts("Prasome ivedineti tik skaicius!");
    puts("");
    printf("Jusu ivestis: ");
}
