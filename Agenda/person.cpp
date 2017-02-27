#include "person.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// =============== Constructor ========================
Person* createPerson(char personAdress[],
                     char personPhoneNumber[],
                     char personName[])
{
    Person* newPerson = new Person;
    strcpy_s(newPerson->name, personName);
    strcpy_s(newPerson->phoneNumber, personPhoneNumber);
    strcpy_s(newPerson->address, personAdress);
    return newPerson;
}

// =============== Validators ========================
bool validateName(char name[])
{
    if (strlen(name) == MAX_NAME_LENGTH)
    {
        cout << "******Name too long******\n";
        return false;
    }
    if (strlen(name) > MAX_NAME_LENGTH)
    {
        while ('\n' != getchar())
            ;
        cin.clear();
        cout << "******Name too long******\n";
        return false;
    }

    else
        return true;
}

bool validatePhoneNumber(char phoneNumber[])
{
    unsigned int i;
    if (strlen(phoneNumber) == MAX_NUMBER_LENGTH)
    {
        cout << "******Number too long******\n";
        return false;
    }
    if (strlen(phoneNumber) > MAX_NUMBER_LENGTH)
    {
        while ('\n' != getchar())
            ;
        cin.clear();
        cout << "******Number too long******\n";
        return false;
    }

    for (i = 0; i <= strlen(phoneNumber); i++)
    {
        if (phoneNumber[i] >= '0' && phoneNumber[i] <= '9')
        {
            return true;
        }

        if (phoneNumber[i] == '+' && phoneNumber[i] == '*' && phoneNumber[i] == '#')
        {
            return true;
        }
        cout << "******Invalid phone number******\n";
        return false;
    }
}

bool validateAddress(char address[])
{
    if (strlen(address) == MAX_ADDRESS_LENGTH)
    {
        cout << "******Address too long******\n";
        return false;
    }
    if (strlen(address) > MAX_ADDRESS_LENGTH)
    {
        while ('\n' != getchar())
            ;
        cin.clear();
        cout << "******Address too long******\n";
        return false;
    }
    else
        return true;
}

// =============== Readers ========================
/*char* readName()
{
    char* name = new char[MAX_NAME_LENGTH + 1];
loop:
    cout << "Insert name: ";
    cin.getline(name, MAX_NAME_LENGTH + 1, '\n');

    if (!validateName(name))
    {
        goto loop;
    }
    return name;
}*/

/*char* readPhoneNumber()
{
    char* phoneNumber = new char[MAX_NUMBER_LENGTH + 1];

loop:
    cout << "Insert phone number: ";
    cin.getline(phoneNumber, MAX_NUMBER_LENGTH + 1, '\n');
    if (!validatePhoneNumber(phoneNumber))
    {
        goto loop;
    }
    return phoneNumber;
}*/

char* readAdress()
{
    char* address = new char[MAX_ADDRESS_LENGTH + 1];
loop:
    cout << "Insert address: ";
    cin.getline(address, MAX_ADDRESS_LENGTH + 1, '\n');
    if (!validateAddress(address))
    {
        goto loop;
    }

    return address;
}

// =============== Printer ========================
void printPerson(Person* p)
{
    cout << "Name: " << p->name << "\n";
    cout << "Phone Number: " << p->phoneNumber << "\n";
    cout << "Address: " << p->address << "\n\n";
    cout << endl;
}
