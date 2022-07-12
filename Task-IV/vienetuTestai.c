#include "visos.h"
#include <assert.h>
#include <string.h>

void removeAllElementsTest(char *msg);
int countElements(struct Element *head);
void deleteElementTest(char *msg);
void uzpildomasSarasasTest(char *msg);
void pushElementTest();
void deleteIvestisTest(FILE *InputStream);
void IvestisCheckTest(FILE *InputStream);
void validateMenuIvestisTest(FILE *InputStream1, FILE *InputStream2);
void fileEmptyCheckTest(FILE *EmptyFile, FILE *NotEmptyFile);

int main()
{
    /// Linked-list
    removeAllElementsTest("ivestis/testuojam1.txt");
    removeAllElementsTest("ivestis/testuojam2.txt");
    deleteElementTest("ivestis/testuojam1.txt");
    deleteElementTest("ivestis/testuojam2.txt");
    pushElementTest();
    uzpildomasSarasasTest("ivestis/testuojam1.txt");
    uzpildomasSarasasTest("ivestis/testuojam2.txt");


    /// Ivestis
    FILE *InputInt;
    InputInt = fopen("ivestis/patikrintIvesti1.txt", "r");
    assert(InputInt != NULL);

    FILE *InputStr;
    InputStr = fopen("ivestis/patikrintIvesti2.txt", "r");
    assert(InputStr != NULL);

    FILE *InputEmpty;
    InputEmpty = fopen("ivestis/patikrintIvesti3.txt", "r");
    assert(InputEmpty != NULL);

    FILE *InputInt2;
    InputInt2 = fopen("ivestis/patikrintIvesti4.txt", "r");
    assert(InputInt2 != NULL);

    FILE *InputInt3;
    InputInt3 = fopen("ivestis/patikrintIvesti5.txt", "r");
    assert(InputInt3 != NULL);

    deleteIvestisTest(InputInt);
    IvestisCheckTest(InputStr);
    validateMenuIvestisTest(InputInt2, InputInt3);
    fileEmptyCheckTest(InputEmpty, InputInt);


    system("clear");
    printf("Visi testai buvo sekmingai iveikti.\n");
    fclose(InputInt);
    fclose(InputStr);
    fclose(InputEmpty);
    fclose(InputInt2);
    fclose(InputInt3);
    return 0;
}

void removeAllElementsTest(char *msg)
{
    struct Element *head = NULL;
    FILE *Ivestis;
    Ivestis = fopen(msg, "r");
    assert(Ivestis != NULL);
    int emptyCheck = uzpildomasSarasas(&Ivestis, &head);
    if(emptyCheck == 0)
    {
        assert(head == NULL);
        deleteWholeList(&head);
        assert(head == NULL);
    }
    else
    {
        assert(head != NULL);
        deleteWholeList(&head);
        assert(head == NULL);
    }
    assert(countElements(head) == 0);
    fclose(Ivestis);
}

void deleteElementTest(char *msg)
{
    struct Element *head = NULL;
    struct Element *prevHead = NULL;
    FILE *Ivestis;
    Ivestis = fopen(msg, "r");
    assert(Ivestis != NULL);
    int emptyCheck = uzpildomasSarasas(&Ivestis, &head);
    prevHead = head;
    int elementCount = countElements(head);
    if(emptyCheck == 0)
    {
        assert(head == NULL);
        insertElement(&head, 1, 2);
        assert(head == NULL);
    }
    else
    {
        assert(head != NULL);
        insertElement(&head, 3, 4);
        insertElement(&head, 5, 6);
        assert(elementCount - 2 == countElements(head));
        assert(head != prevHead);
    }
    fclose(Ivestis);

}

void uzpildomasSarasasTest(char *msg)
{
    struct Element *head = NULL;
    struct Element *prevHead = head;
    FILE *Ivestis;
    Ivestis = fopen(msg, "r");
    assert(Ivestis != NULL);
    int emptyCheck = uzpildomasSarasas(&Ivestis, &head);
    if(emptyCheck == 0)
    {
        assert(head == NULL);
        assert(countElements(head) == 0);
        assert(head == prevHead);
    }
    else
    {
        assert(head != NULL);
        assert(countElements(head) == 5);
        assert(head != prevHead);
    }
}

void pushElementTest()
{
    struct Element *head = NULL;
    struct Element *prevHead = NULL;
    pushElement(&head, 3);
    prevHead = head;
    assert(head != NULL);
    assert(head->data == 3);
    pushElement(&head, 2);
    assert(head != prevHead);
    assert(head->data == 2);
    assert(countElements(head) == 2);
}

int countElements(struct Element *head)
{
    if(head != NULL)
    {
        return 1 + countElements(head->next);
    }
    return 0;
}

void deleteIvestisTest(FILE *InputStream)
{
    int value = 1;
    int value2 = 1;
    insertIvestis(InputStream, &value, &value2);
    assert(value != 1 && value == -123);
}

void IvestisCheckTest(FILE *InputStream)
{
    FILE *Result = NULL;
    char failoPavadinimas [200];
    IvestisCheck(InputStream, &Result, failoPavadinimas);
    assert(Result != NULL);
    assert(strcmp(failoPavadinimas, "input/duomenys.txt") == 0);
}

void validateMenuIvestisTest(FILE *InputStream1, FILE *InputStream2)
{
    int continueFlag = 0, value = 0;
    validateMenuIvestis(InputStream1, &continueFlag, &value);
    assert(continueFlag == 1);

    continueFlag = 0, value = 0;
    validateMenuIvestis(InputStream2, &continueFlag, &value);
    assert(value == 3 && continueFlag == 0);
}

void fileEmptyCheckTest(FILE *EmptyFile, FILE *NotEmptyFile)
{
    assert(fileEmptyCheck(EmptyFile) == 1);
    assert(fileEmptyCheck(NotEmptyFile) == 0);
}

void readFromFileTest()
{
    FILE *Input1, *Input2;
    Input1 = fopen("patikrintiFailoIvesti1.txt", "r");
    Input2 = fopen("patikrintiFailoIvesti1.txt", "r");
    assert(Input1 != NULL && Input2 != NULL);

    int value = 0;
    int breakFlag = 0;
    int errorFlag = 0;
    int eofFlag = 0;

    readFromFile(&Input1, &value, &breakFlag, &errorFlag, &eofFlag);
    assert(breakFlag == 0 && errorFlag == 0 && eofFlag == 0);

    value = 0, breakFlag = 0, errorFlag = 0, eofFlag = 0;
    readFromFile(&Input2, &value, &breakFlag, &errorFlag, &eofFlag);
    assert(eofFlag == 0 && errorFlag == 1 && breakFlag == 0);

    fclose(Input1);
    fclose(Input2);
}
