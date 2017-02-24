#include "Person.h"
#include "LinkedNode.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void menuOneCharValidation(char* option)
{
    *option = getchar();

    if ('\n' != getchar())
    {
		while ('\n' != getchar());
		cout << "Option not found\nChoose action: ";
		menuOneCharValidation(option);
    }

}

int menuOptionValidation(char* option, char* validOptions)
{
    menuOneCharValidation(option);

    while (*validOptions)
    {
        if (*validOptions == *option)
             return 1;

        else
            validOptions++;
    }
    return 0;

}

void menu(LinkedNode *start, LinkedNode *p)
{
    char option;
    char validOptions[7] = "123456";

    cout << "1 = Print list\n";
    cout << "2 = Insert Person Alphabetically\n";
    cout << "3 = Delete Person\n";
    cout << "4 = Search Person by name\n";
    cout << "5 = Search Person by phone number\n";
    cout << "6 = Save to file\n\n";
    cout << "Choose action: ";
    while (!menuOptionValidation(&option, validOptions))
    {
        cout << "Option not found\nChoose action: ";
    }
    cout << "\n\n";
    switch (option)
    {
        case '1': printPersons(start, p);
        break;
        case '2': insertPersonAlphabetically(
                      createPerson(readAdress(),
                                   readPhoneNumber(p),
                                   readName(p)),
                  start, p);
        break;
        case '3': deletePerson(readNameForSearch(), start, p);
        break;
        case '4': searchPersonByName(readNameForSearch(), p);
        break;
        case '5': searchPersonByPhoneNumber(readPhoneNumberForSearch(), p);
        break;
        case '6': savePersonsToFile(p);
        break;
        default: cout << "Option not found\nChoose action: ";
        break;
    }

}

int main()
{
LinkedNode *start, *p;
p = start = new LinkedNode;
start = NULL;

   // loadPersonsFromFile(start,p);

    cout << "*****Phonebook*****\n\n";

    while (true)
    {
        menu(start, p);
    }

    return 0;
}
