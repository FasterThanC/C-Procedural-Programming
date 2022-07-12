#ifndef VISOS_H
#define VISOS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Element
{
    int data;
    struct Element *next;
};

void launchUserInterface(struct Element **head);
void printMenuText();
void validateMenuIvestis(FILE *Ivestis, int *continueFlag, int *value);
void sarasoPasiekimoFunkcija(struct Element **rodykleIPirmaElementa);
int fileEmptyCheck(FILE *Ivestis);
void IvestisCheck(FILE *Stream, FILE **Ivestis, char failoPavadinimas[]);
void readFromFile(FILE **Ivestis, int *value, int *breakFlag, int *errorFlag, int *eofFlag);
void pushElement(struct Element **rodykleIPirmaElementa, int elementToAdd);
void printElements(struct Element *startingElement);
void deleteProcess(struct Element **rodykleIPirmaElementa);
void insertIvestis(FILE *Stream, int *valueToFind, int *valueToInsert);
void insertElement(struct Element **rodykleIPirmaElementa, int elementToFind, int elementToInsert);
void deleteWholeList(struct Element **rodykleIPirmaElementa);
int uzpildomasSarasas(FILE **Ivestis, struct Element **rodykleIPirmaElementa);

#endif
