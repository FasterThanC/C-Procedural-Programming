#include "visos.h"


void sarasoPasiekimoFunkcija(struct Element **rodykleIPirmaElementa)
{
    FILE *Ivestis;

    char failoPavadinimas[200];
    IvestisCheck(stdin, &Ivestis, failoPavadinimas);

    printf("Ivesties failas yra teisingas ir buvo sekmingai pasiektas.\n");

    uzpildomasSarasas(&Ivestis, rodykleIPirmaElementa);

    fclose(Ivestis);
}

int uzpildomasSarasas(FILE **Ivestis, struct Element **rodykleIPirmaElementa)
{

    int fileEmptyFlag = fileEmptyCheck(*Ivestis);

    if(fileEmptyFlag == 1) /// if after the previous function the value of fileEmptyFlag is changed, the list won't be appended.
    {
        printf("Ivesties failas, kuri nurodete, yra tuscias.\n");
        return 0;
    }

    while(!feof(*Ivestis))
    {
        int value = 0;
        int breakFlag = 0;
        int errorFlag = 0;
        int eofFlag = 0;

        readFromFile(Ivestis, &value, &breakFlag, &errorFlag, &eofFlag);

        /// processing flags
        if(errorFlag)
        {
            printf("\nVienas is failo elemento buvo neteisingai ivestas. Ivesties nuskaitymas buvo sustabdytas, kai pasieke neteisingai ivesta elementa, taciau visi kiti elementai pries ji buvo sekmingai nusaityti.\nMaloniai prasome isitikinti, ar visi elementai yra atskirti tarpais arba Enter.\n");
            return 1;
        }

        if(eofFlag)
        {
            printf("Sarasas buvo nuskaitytas is nurodyto failo.\n");
            return 1;
        }

        pushElement(rodykleIPirmaElementa, value);

        if(breakFlag)
        {
            printf("Sarasas buvo nuskaitytas is nurodyto failo.\n");
            break;
        }
    }
    return 1;
}

void pushElement(struct Element **rodykleIPirmaElementa, int elementToAdd)
{

    struct Element *newElement = (struct Element*) malloc(sizeof(struct Element));
    struct Element *currentElement = *rodykleIPirmaElementa;

    newElement->data = elementToAdd;
    newElement->next = NULL;

    while((currentElement != NULL) && (currentElement->next != NULL))
    {
        currentElement = currentElement->next;
    }

    if (currentElement != NULL)
    {
        currentElement->next = newElement;
    }
    else
    {
        *rodykleIPirmaElementa = newElement;
    }
}

void printElements(struct Element *startingElement)
{
    if(startingElement == NULL)
    {
        printf("Sarasas yra tuscias.\n");
        return;
    }

    printf("Siuo metu sarasas yra toks:\n");

    while(startingElement != NULL)
    {
        printf("%d ", startingElement->data);
        startingElement = startingElement->next;
    }
}

void deleteProcess(struct Element **rodykleIPirmaElementa)
{
    int elementToFind;
    int elementToInsert;

    insertIvestis(stdin, &elementToFind, &elementToInsert);

    insertElement(rodykleIPirmaElementa, elementToFind, elementToInsert);
}

void insertElement(struct Element **rodykleIPirmaElementa, int elementToFind, int elementToInsert)
{
    struct Element *currentElement = *rodykleIPirmaElementa;
    struct Element *newElement = malloc(sizeof(struct Element));
    struct Element *temp = (*rodykleIPirmaElementa)->next;

    newElement->data = elementToInsert;
    newElement->next = NULL;


    //printf("currentElement->data: %d\n", currentElement->data);
    //printf("ToFind: %d\n", elementToFind);

    if (currentElement != NULL && (currentElement->data) == elementToFind)
    {
        newElement->next = *rodykleIPirmaElementa;//currentElement-->next;
        //currentElement->next = newElement;
        *rodykleIPirmaElementa=newElement;
        return;
    }

    while ((temp->data) != elementToFind)
    {
        temp = temp->next;
        currentElement = currentElement->next;

        if(temp == NULL)
        {
            printf("Apgailestaujame, bet elementas nebuvo rastas sarase.\n");
            return;
        }
    }

    currentElement->next = newElement;
    newElement->next = temp;
}



void deleteWholeList(struct Element **rodykleIPirmaElementa)
{
    if(*rodykleIPirmaElementa == NULL)
    {
        printf("Sis sarasas jau tuscias.\n");
        return;
    }

    struct Element *currentElement = *rodykleIPirmaElementa;
    struct Element *temp;

    while(currentElement != NULL)
    {
        temp = currentElement->next;
        free(currentElement);
        currentElement = temp;
    }

    *rodykleIPirmaElementa = NULL;
    printf("Visas sarasas buvo pasalintas.\n");
}

