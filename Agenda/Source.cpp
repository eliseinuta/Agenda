#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const int MAX_NAME_LENGTH = 50;
const int MAX_ADDRESS_LENGTH = 100;
const int MAX_NUMBER_LENGTH = 15;

struct Person
{
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_NUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    Person *next;
};

Person *start;

char* readName()
{
    char* name = new char[MAX_NAME_LENGTH];
    cout << "Insert name: ";
    cin.getline(name, MAX_NAME_LENGTH - 1, '\n');
    return name;
}

bool validatePhoneNumber(char phoneNumber[])
{
    int i;
    for (i = 0; i <= strlen(phoneNumber); i++)
    {
        if (phoneNumber[i]>'0' &&
            phoneNumber[i] <'9')
        {
            return true;
        }

        if (phoneNumber[i] == '+' &&
            phoneNumber[i] == '*' &&
            phoneNumber[i] == '#')
        {
            return true;
        }

        return false;
    }
}

bool avoidDuplicatePhoneNumber(char phoneNumber[])
{
    Person* p = start;
    while (p != NULL)
    {
        if (strcmp(p->phoneNumber, phoneNumber) == 0)
        {
            return false;
        }

        else
        {
            p = p->next;
        }
    }
    return true;
}

char* readPhoneNumber()
{
    char* phoneNumber = new char[MAX_NUMBER_LENGTH];

    loop: cout << "Insert phone number: ";
    cin.getline(phoneNumber, MAX_NUMBER_LENGTH - 1, '\n');
    if (!validatePhoneNumber(phoneNumber))
    {
        cout << "******Invalid phone number******\n";
        goto loop;
    }

    if (!avoidDuplicatePhoneNumber(phoneNumber))
    {
        cout << "******Phone number already exists******\n";
        goto loop;
    }
    return phoneNumber;

}

char* readAdress()
{
    char* address = new char[MAX_ADDRESS_LENGTH];
    cout << "Insert address: ";
    cin.getline(address, MAX_ADDRESS_LENGTH - 1, '\n');
    return address;
}

Person* createPerson(char personName[],
                     char personPhoneNumber[],
                     char personAdress[])
{
    Person* newPerson = new Person;
    strcpy_s(newPerson->name, personName);
    strcpy_s(newPerson->phoneNumber, personPhoneNumber);
    strcpy_s(newPerson->address, personAdress);
    newPerson->next = NULL;
    return newPerson;
}

void printPerson(Person* p)
{
	cout << "Name: " << p->name << "\n";
	cout << "Phone Number: " << p->phoneNumber << "\n";
	cout << "Address: " << p->address << "\n\n";
	cout << endl;
}

void printPersons()
{
    if (start == NULL)
    {
        cout << "No entries\n\n";
        return;
    }

    Person *p = start;
    int x = 1;
    while (p != NULL)
    {
        cout << "Entry #" << x << "\n";
		printPerson(p);
		p = p->next;
        x++;
    }
    cout << "\n\n";
}

void insertPersonAlphabetically(Person* newPerson)
{
    int position = 2;

    // When there are no persons
    if (start == NULL)
    {
        start = newPerson;
        return;
    }

    Person *p = start;

    // When there is only one person
    if (start->next == NULL)
    {
        // Compare newPerson and start
        int x = strcmp(newPerson->name, start->name);
        // When new goes after start
        if (x >= 0)
        {
            start->next = newPerson;
        }
        // When new goes before start
        if (x < 0)
        {
            start = newPerson;
            start->next = p;
        }

        return;
    }
    // When there are more than 2 persons
    else
    {
        Person *q = p->next;
        // Compare newPerson and start
        int x = (strcmp(newPerson->name, start->name));
        // When new goes before start
        if (x<0)
        {
            start = newPerson;
            start->next = p;
            return;
        }

        // Move p and q until new person goes between or q is NULL
        while (position > 0 && q != NULL)
        {
            p = p->next;
            q = q->next;

            if (q == NULL)
            {
                break;
            }

            position = strcmp(newPerson->name, q->name);
        }

        if (q == NULL)
        {
            p->next = newPerson;
        }
        else
        {
            newPerson->next = q;
            p->next = newPerson;
        }
    }

}

void deletePerson(char nameToDelete[])
{
    Person *p = start;
    Person *q = p->next;
    int x = -5;
    int y = -5;
    // When list is empty
    if (start == NULL)
    {
        cout << "\nThe list is empty\n\n";
        return;
    }
    // When there is only one entry
    if (start->next == NULL)
    {
        x = strcmp(nameToDelete, start->name);
        if (x == 0)
        {
            start = NULL;
            cout << "Person deleted successfully\n\n";
            return;
        }
        cout << "\nPerson not found\n\n";
        return;
    }

    y = strcmp(nameToDelete, start->name);

    if (y == 0)
    {
        Person *de = start;
        start = q;
        de = NULL;
        p = q;
        q = p->next;
        cout << "\nPerson deleted successfully\n\n";
        return;
    }


    while (x != 0)
    {
        if (q != NULL)
        {
            x = strcmp(nameToDelete, q->name);
        }
        if ((q == NULL) && (p != start))
        {
            cout << "\nPerson not found\n\n";
            return;
        }

        if (x != 0)
        {
            p = p->next;
            q = q->next;
        }
    }
    // When the name to delete is the last entry
    if (q->next == NULL)
    {
        q = NULL;
        p->next = NULL;
        cout << "\nPerson deleted successfully\n\n";
        return;
    }

    Person *d = q;
    // When the person to delete is between 2 other persons
    q = q->next;
    p->next = q;
    d = NULL;
    cout << "\nPerson deleted successfully\n\n";
}

void loadPersonsFromFile()
{
    ifstream fin("Agenda.txt");
    bool x = fin.eof();
    while (x == false)
    {
        Person* readPerson = new Person;

        fin.getline(readPerson->name, MAX_NAME_LENGTH);
        fin >> readPerson->phoneNumber;
        fin.ignore();
        fin.getline(readPerson->address, MAX_ADDRESS_LENGTH);
        readPerson->next = NULL;

        if (start == NULL)
        {
            start = readPerson;
        }

        else
        {
            Person *p = start;

            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = readPerson;
        }
        x = fin.eof();
        }
    fin.close();
}

void savePersonsToFile()
{
    ofstream fout("Agenda.txt");

    Person *p = start;
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            fout << p->name << "\n";
            fout << p->phoneNumber << "\n";
            fout << p->address;
            p = NULL;
        }
        else
        {
            fout << p->name << "\n";
            fout << p->phoneNumber << "\n";
            fout << p->address << "\n";
            p = p->next;
        }

    }
    fout.close();
}

void searchPersonByName(char name[])
{
    Person *p = start;

    int x = strcmp(name, p->name);

    while (x != 0 && p != NULL)
    {
        p = p->next;
        x = strcmp(name, p->name);
    }

    if (p == NULL)
    {
        cout << "Person not found\n\n";
        return;
    }

	printPerson(p);
}

void searchPersonByPhoneNumber(char phoneNumber[])
{
    Person *p = start;
    int x = strcmp(phoneNumber, p->phoneNumber);

    while (x != 0 && p != NULL)
    {
        p = p->next;
        x = strcmp(phoneNumber, p->phoneNumber);
    }

    if (p == NULL)
    {
        cout << "Person not found\n\n";
        return;
    }

	printPerson(p);
}

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

void menu()
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
        case '1': printPersons();
        break;
        case '2': insertPersonAlphabetically(
                      createPerson(readAdress(),
                                   readPhoneNumber(),
                                   readName())
                  );
        break;
        case '3': deletePerson(readName());
        break;
        case '4': searchPersonByName(readName());
        break;
        case '5': searchPersonByPhoneNumber(readPhoneNumber());
        break;
        case '6': savePersonsToFile();
        break;
        default: cout << "Option not found\nChoose action: ";
        break;
    }

}

int main()
{
    start = NULL;

    loadPersonsFromFile();

    cout << "*****Phonebook*****\n\n";

    while (true)
    {
        menu();
    }

    return 0;
}
