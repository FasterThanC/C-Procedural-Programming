#include "visos.h"

int main()
{
    printf("Sveiki, si programa leidzia vartotojui sukurtame Vienpusiame Sarase iterpti elementa pries kita reiksme nurodyta elementa.\n");
    printf("Taciau, jei tokio elemento nepavyks surasti, tuomet bus isspasdintas pranesimas, kuris pranes apie klaida!\n\n");

    struct Element *head = NULL;
    FILE *Input;

    launchUserInterface(&head);
    printf("Programa baige savo darba. Dekojame uz naudojimasi!");

}

