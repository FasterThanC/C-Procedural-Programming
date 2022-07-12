#include "visos.h"

void validateMenuIvestis(FILE *Stream, int *continueFlag, int *value)
{
    char c; /// a character used for validating purposes
    int inputValidateCheck = fscanf(Stream, " %d%c", value, &c);
    if(inputValidateCheck != 2)
    {
        printf("Deja, bet jusu ivestis buvo neteisinga. Prasome ivesti is naujo.\n");
        *continueFlag = 1;
        while ((getc(Stream)) != '\n')
            ;
        return;
    }
    if(c != '\n')
    {
        printf("Apgailestaujame, bet jusu ivestis turejo neteisingu simboliu. Prasome ivesti tik meniu skaiciu.\n");
        *continueFlag = 1;
        while ((getc(Stream)) != '\n')
            ;
        return;
    }
    if(*value > 4 || *value < 0) /// the menu only provides options 0-4
    {
        printf("Meniu susideda is pasirinkimu nuo 0 iki 4. Prasome ivesti teisinga skaiciu.\n");
        *continueFlag = 1;
        return;
    }
    printf("\n");
}

void IvestisCheck(FILE *Stream, FILE **Input, char failoPavadinimas[])
{
    char c; /// for data validating purposes

    while(1)
    {
        printf("\nPrasome ivesti failo pavadinima kartu su pletiniu (pvz: input.txt).\n");

        int inputValidateCheck = fscanf(Stream, " %s%c", failoPavadinimas, &c);

        if(inputValidateCheck != 2)
        {
            printf("Deja, bet ivestyje buvo nepakankamas kiekis elementu. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        if(c != '\n')
        {
            printf("Deja, bet buvo ivesti neteisingi elementai po ivesties failo pavadinimo. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        *Input = fopen(failoPavadinimas, "r");

        if(*Input == NULL) /// if there is no access to the given file.
        {
            printf("Deja, bet ivyko klaida bandant pasiekti faila pavadinimu %s. Prasome isitikinti ar toks failas tikrai egzistuoja ir pabandyti is naujo.\n", failoPavadinimas);
            continue;
        }

        break;
    }

    printf("\n");
}

int fileEmptyCheck(FILE *Input)
{
    char nextSymbolCheck = getc(Input);

    if(nextSymbolCheck == EOF)
    {
        fclose(Input);
        return 1;
    }

    ungetc(nextSymbolCheck, Input); /// if c != EOF the character is put back to the stream.
    return 0;
}

void readFromFile(FILE **Input, int *value, int *breakFlag, int *errorFlag, int *eofFlag)
{
    char c; /// used for validating

    int inputValidateCheck = fscanf(*Input, " %d", value);
    if(inputValidateCheck != 1)
    {
        if(!feof(*Input))
        {
            *errorFlag = 1;
            return;
        }
        *eofFlag = 1;
        return;
    }

    inputValidateCheck = fscanf(*Input, "%c", &c);
    if(inputValidateCheck != 1) /// if a char cannot be read, it is EOF.
    {
        *breakFlag = 1;
        return;
    }

    if(c != ' ' && c != '\n') /// if a char right after the integer has been read, it has to be a whitespace
    {
        *errorFlag = 1;
        return;
    }
}

void insertIvestis(FILE *Stream, int *valueToFind, int *valueToInsert)
{
    char c; /// used for validating purposes
    while(1)
    {
        printf("Prasome ivesti reiksme is saraso, kuria norite surasti ir pries ja iterpti skaiciu.\n");

        int inputValidateCheck = fscanf(Stream, " %d%c", valueToFind, &c);

        if(inputValidateCheck != 2)
        {
            printf("Reiksme yra neteisingo formato. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        if(c != '\n')
        {
            printf("Reiksme buvo ivesta kartu su simboliu, kuris nera skaitmuo. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        break;
    }

    while(1)
    {
        printf("Prasome ivesti skaiciu, kuri norite iterpti.\n");

        int inputValidateCheck = fscanf(Stream, " %d%c", valueToInsert, &c);

        if(inputValidateCheck != 2)
        {
            printf("Reiksme yra neteisingo formato. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        if(c != '\n')
        {
            printf("Reiksme buvo ivesta kartu su simboliu, kuris nera skaitmuo. Prasome pabandyti dar karta.\n");
            while ((getc(Stream)) != '\n')
                ;
            continue;
        }

        break;
    }
}
