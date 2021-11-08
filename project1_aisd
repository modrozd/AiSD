// Project 1, AiSD 2020
// Monika Drozd

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define N 100000
#define SIZE 150
#define findMAX 1
#define findMIN 0

char* theMAX, * theMIN;
void myStrcpy(char* dest, char* from);
int myStrlen(char* number);
int myStrcmp(char* num1, char* num2, int digits);


class numberData {
public:
    int index;
    char* thisNumber;
    numberData* nextNumber;
};

numberData* createMemory(char* sentNumber)
{
    numberData* newNumber = new numberData();

    if (!(newNumber->thisNumber = new char[myStrlen(sentNumber) + 1])) {
        std::cout << "error with new\n";
        delete newNumber;
        return NULL;
    }

    myStrcpy(newNumber->thisNumber, sentNumber);
    newNumber->nextNumber = NULL;

    return newNumber;
}

void addNumber(numberData** myData, char* number) {

    static int index = 0;

    numberData* newNumber = createMemory(number);
    newNumber->index = index++;
    newNumber->nextNumber = *myData;
    *myData = newNumber;
}
int myStrlen(char* number)
{
    int counter = 0;
    while (number[counter] != '\0')
        counter++;
    return counter;
}

int myStrcmp(char* num1, char* num2, int digits)
{
    int counter = 0;
    while (counter < digits)
    {
        if (num1[counter] != num2[counter])
            return -1; //not equal
        counter++;
    }
    return 0; //equal
}

void myStrcpy(char* dest, char* from)
{
    int counter = 0;
    while (from[counter] != '\0')
    {
        dest[counter] = from[counter];
        counter++;
    }
    dest[counter] = '\0';
}

char* checkDigits(char* theNUM, char* next, int digits, int option)
{
    if (theNUM[0] == '-' && next[0] != '-')
        return theNUM = option ? next : theNUM;
    else if (theNUM[0] != '-' && next[0] == '-')
        return theNUM = option ? theNUM : next;
    else if (theNUM[0] == '-' && next[0] == '-')
        for (int i = 0; i < digits; i++)
        {
            if ((int)theNUM[i] > (int)next[i])
                return theNUM = option ? next : theNUM;
            else if ((int)theNUM[i] < (int)next[i])
                return theNUM = option ? theNUM : next;
        }
    else
    {
        for (int i = 0; i < digits; i++)
        {
            if ((int)theNUM[i] > (int)next[i])
                return theNUM = option ? theNUM : next;
            else if ((int)theNUM[i] < (int)next[i])
                return theNUM = option ? next : theNUM;
        }
    }
    return theNUM;
}

void checkMax(char* number)
{
    int digitsMAX = myStrlen(theMAX);
    int digitsNext = myStrlen(number);
    int areEqual = myStrcmp(number, theMAX, digitsMAX);

    if (areEqual == 0)
        return;
    else if (digitsMAX == digitsNext)
        myStrcpy(theMAX, checkDigits(theMAX, number, digitsMAX, findMAX));
    else
    {                                                 //     theMAX     next  --> theMAX
        if (theMAX[0] == '-' && number[0] != '-')       //e.g.  -55  and   5         next
            myStrcpy(theMAX, number);
        else if (theMAX[0] != '-' && number[0] == '-')  //e.g.   55  and  -5        theMAX
            return;
        else if (theMAX[0] == '-' && number[0] == '-')  //e.g.   -5  and  -66
        {
            if (digitsMAX > digitsNext)               //e.g. -990  and  -10
                myStrcpy(theMAX, number);
            else if (digitsMAX < digitsNext)          //e.g.  -74  and  -555
                return;
        }
        else if (digitsMAX > digitsNext)              //e.g.  727  and   27 
            return;
        else if (digitsMAX < digitsNext)              //e.g.   27  and   727
            myStrcpy(theMAX, number);
    }
}

void checkMin(char* number)
{
    int digitsMIN = myStrlen(theMIN);
    int digitsNext = myStrlen(number);
    int areEqual = myStrcmp(number, theMIN, digitsMIN);

    if (areEqual == 0)
        return;
    else if (digitsMIN == digitsNext)
        myStrcpy(theMIN, checkDigits(theMIN, number, digitsMIN, findMIN)); //for strings with equal numbers of digits
    else
    {                                                 //     theMIN     next  --> theMIN
        if (theMIN[0] == '-' && number[0] != '-')       //e.g.  -55  and   5         
            return;
        else if (theMIN[0] != '-' && number[0] == '-')  //e.g.   55  and  -5        
            myStrcpy(theMIN, number);
        else if (theMIN[0] == '-' && number[0] == '-')  //e.g.   -5  and  -66
        {
            if (digitsMIN > digitsNext)               //e.g. -990  and  -10
                return;
            else if (digitsMIN < digitsNext)          //e.g.  -74  and  -555
                myStrcpy(theMIN, number);
        }
        else if (digitsMIN > digitsNext)              //e.g.  727  and   27 
            myStrcpy(theMIN, number);
        else if (digitsMIN < digitsNext)              //e.g.   27  and   727
            return;
    }
}

int readNumbers(numberData** myData) {
    int n, numbersInput;
    static bool startValue = true;
    do {
        if (!(std::cin >> n) || n < 1 || n > N)
            std::cout << "ERROR: value between 0 and 100 000. Load again. " << std::endl;
    } while (n < 1 || n > N);

    numbersInput = n;
    char input[SIZE];  // ROZMIAR 
    while (n-- > 0)
    {
        if (scanf("%149s", input) != 1)
            std::cout << "ERROR INPUT\n";
        else
        {
            int inputSize = myStrlen(input) + 1;
            char* temp = new char[inputSize];
            if (startValue) {
                theMAX = new char[inputSize];
                theMIN = new char[inputSize];
                myStrcpy(theMAX, input);
                myStrcpy(theMIN, input);
                startValue = !startValue;
            }
            if (myStrlen(input) > myStrlen(theMAX)) {
                myStrcpy(temp, theMAX);
                theMAX = new char[inputSize];
                myStrcpy(theMAX, temp);
            }
            if (myStrlen(input) > myStrlen(theMIN)) {
                myStrcpy(temp, theMIN);
                theMIN = new char[inputSize];
                myStrcpy(theMIN, temp);
            }
            checkMax(input);
            checkMin(input);
            addNumber(myData, input);
            delete[] temp;
        }
    }
    return numbersInput;
}

void showNumbers(numberData* myData)
{
    if (myData == NULL)
        std::cout << "There are no numbers" << std::endl;
    else
    {
        while (myData->nextNumber != NULL)
        {
            std::cout << myData->thisNumber << std::endl;
            myData = myData->nextNumber;
        }
        std::cout << myData->thisNumber << std::endl;
    }
}

void deleteList(numberData** myData)
{
    numberData* temp = *myData;
    while (temp != NULL)
    {
        *myData = temp->nextNumber;
        delete temp;
        temp = *myData;
    }
    delete theMAX;
    delete theMIN;
}

char* actionNumbers(char* num1, char* num2) //num2 has to be bigger
{
    int digits1 = myStrlen(num1);
    int digits2 = myStrlen(num2);
    int resultSize = digits1 > digits2 ? digits1 + 1 : digits2 + 1;
    char* result = new char[resultSize + 1];
    char* temp = new char[resultSize + 1];

    if (num1[0] != '-' && num2[0] == '-') { // jeszcze przypadek, ze oba ujemne
        myStrcpy(temp, num2);
        myStrcpy(num2, num1);
        myStrcpy(num1, temp);
    }
    else if (digits1 > digits2) {
        myStrcpy(temp, num2);
        myStrcpy(num2, num1);
        myStrcpy(num1, temp);
    }

    digits1 = myStrlen(num1); //po ewentualnej zamianie miejsc
    digits2 = myStrlen(num2);

    int difference, sum, rest = 0, r = 0;
    difference = digits2 - digits1;

    for (int i = digits1 - 1; i >= 0; i--)
    {
        sum = ((num1[i] - '0') + (num2[i + difference] - '0') + rest);
        result[r++] = sum % 10 + '0';
        rest = sum / 10;
    }

    for (int i = digits2 - digits1 - 1; i >= 0; i--)
    {
        sum = ((num2[i] - '0') + rest);
        result[r++] = sum % 10 + '0';
        rest = sum / 10;
    }

    if (rest) {
        result[r++] = rest + '0';
        resultSize++;
    }

    int begin;
    for (begin = 0; begin < resultSize - 1; begin++)
        temp[begin] = result[--r];

    temp[begin] = '\0';
    myStrcpy(result, temp);
    delete[] temp;
    checkMax(result);
    checkMin(result);

    return result;
}

void changeNumber(int i, int j, int k, numberData* myData)
{
    char* jNumber = NULL, * kNumber = NULL;
    char** iPointer = NULL;
    bool jFind = true, kFind = true, iFind = true;
    while (jFind != false || kFind != false || iFind != false) {
        if (myData->index == i) {
            //iPointer = new char* [myStrlen(myData->thisNumber) + 1];
            iPointer = &(myData->thisNumber);
            iFind = !iFind;
        }
        if (myData->index == j) {
            int jSize = myStrlen(myData->thisNumber);
            jNumber = new char[jSize + 1];
            myStrcpy(jNumber, myData->thisNumber);
            jFind = !jFind;
        }
        if (myData->index == k) {
            int kSize = myStrlen(myData->thisNumber);
            kNumber = new char[kSize + 1];
            myStrcpy(kNumber, myData->thisNumber);
            kFind = !kFind;
        }
        myData = myData->nextNumber;
    }
    myStrcpy(*iPointer, actionNumbers(jNumber, kNumber));
    delete[] jNumber, kNumber; //uwaga na delete
}

void reverseData(numberData* now, numberData* before, numberData** myData)
{
    if (!now->nextNumber) {
        *myData = now;
        now->nextNumber = before;
        return;
    }
    numberData* next = now->nextNumber;
    now->nextNumber = before;
    reverseData(next, now, myData);
}

void reverse(numberData** myData)
{
    if (!myData)
        return;
    reverseData(*myData, NULL, myData);
}

void splitChoice(char* choice, int *i, int *j, int *k)
{
    int index = 0, w = 0;
    char num[10];
    while (choice[index] != ' ')
        num[w++] = choice[index++];
    num[w] = '\0';

    *i = atoi(num);
    index = index + 3;
    w = 0;

    while (choice[index] != ' ')
        num[w++] = choice[index++];
    num[w] = '\0';

    *j = atoi(num);
    index = index + 3;
    w = 0;

    while (choice[index] != '\0')
        num[w++] = choice[index++];
    num[w] = '\0';

    *k = atoi(num);
}

int main()
{
    numberData* myData = NULL;
    int num = readNumbers(&myData);
    reverse(&myData);

    int i, j, k;
    i, j, k = 0;
    char choice[50];
    bool check = true;
    while (check)
    {
        if (scanf(" %[^\n]", choice) != 1)
            std::cout << "error with choice\n";
        if (choice[0] == 'm' && choice[1] == 'a' && choice[2] == 'x')
            std::cout << theMAX << std::endl;
        else if (choice[0] == 'm' && choice[1] == 'i' && choice[2] == 'n')
            std::cout << theMIN << std::endl;
        else if (isdigit(choice[0]))
        {
            splitChoice(choice, &i, &j, &k);
            if(i >= 0 && i < num && j >= 0 && j < num && k >= 0 && k < num)
                changeNumber(i, j, k, myData);
        }
        else if (choice[0] == '?')
            showNumbers(myData);
        else if (choice[0] == 'q')
            check = !check;
        else
            continue;
    }
    //deleteList(&myData);
    return 0;
}
