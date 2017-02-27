#include "linkedlist.h"
#include "person.h"

#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

// =========================== Unique Checkers =======================
// TODO: Bad name. Names that return true or false should not have
//       verbs in them. Should refator to something like : isUniqueName
bool isUniqueName(char name[], LinkedList* p)
{
    while (p != 0)
    {
        if (strcmp(p->person->name, name) == 0)
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

// TODO: Bad name. Names that return true or false should not have
//       verbs in them. Should refator to something like : isUniquePhoneNr
bool isUniquePhoneNumber(char phoneNumber[], LinkedList* p)
{
    while (p != 0)
    {
        if (strcmp(p->person->phoneNumber, phoneNumber) == 0)
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

// =========================== Readers ==========================
char* readName(LinkedList *p)
{
    char* name = new char[MAX_NAME_LENGTH + 1];
loop:
    cout << "Insert name: ";
    cin.getline(name, MAX_NAME_LENGTH + 1, '\n');


    if (!validateName(name))
    {
        goto loop;
    }

    if (!isUniqueName(name, p))
    {
        cout << "******Name already exists******\n";
        goto loop;
    }

    return name;
}

char* readPhoneNumber(LinkedList *p)
{
    char* phoneNumber = new char[MAX_NUMBER_LENGTH + 1];

loop:
    cout << "Insert phone number: ";
    cin.getline(phoneNumber, MAX_NUMBER_LENGTH + 1, '\n');
    if (!validatePhoneNumber(phoneNumber))
    {
        goto loop;
    }

    if (!isUniquePhoneNumber(phoneNumber, p))
    {
        cout << "******Phone number already exists******\n";
        goto loop;
    }
    return phoneNumber;

}


// ======================== Linked List Operations ========================
void insertPersonAlphabetically(Person* newPerson, LinkedList* start, LinkedList* p)
{
    int position = 2;

    // When there are no persons
    if (start == 0)
    {
        start->person = newPerson;
        return;
    }

    // When there is only one person
    if (start->next == 0)
    {
        // Compare newPerson and start
        int x = strcmp(newPerson->name, start->person->name);
        // When new goes after start
        if (x >= 0)
        {
            start->next->person = newPerson;
        }
        // When new goes before start
        if (x < 0)
        {
            start->person = newPerson;
            start->next = p;
        }

        return;
    }
    // When there are more than 2 persons
    else
    {
        LinkedList *q = p->next;
        // Compare newPerson and start
        int x = (strcmp(newPerson->name, start->person->name));
        // When new goes before start
        if (x < 0)
        {
            start->person = newPerson;
            start->next = p;
            return;
        }

        // Move p and q until new person goes between or q is 0
        while (position > 0 && q != 0)
        {
            p = p->next;
            q = q->next;

            if (q == 0)
            {
                break;
            }

            position = strcmp(newPerson->name, q->person->name);
        }

        if (q == 0)
        {
            p->next->person = newPerson;
        }
        else
        {
            LinkedList *newNode;
            newNode->person = newPerson;

            newNode->next = q;
            p->next = newNode;
        }
    }

}

void deletePerson(char nameToDelete[], LinkedList *start, LinkedList *p)
{
    // When list is empty
    if (start == 0)
    {
        cout << "\nThe list is empty\n\n";
        return;
    }

    LinkedList *q = p->next;
    int x = -5;
    int y = -5;

    // When there is only one entry
    if (start->next == 0)
    {
        x = strcmp(nameToDelete, start->person->name);
        if (x == 0)
        {
            start = 0;
            cout << "Person deleted successfully\n\n";
            return;
        }
        cout << "\nPerson not found\n\n";
        return;
    }

    y = strcmp(nameToDelete, start->person->name);

    if (y == 0)     //When starts needs to be deleted
    {
        LinkedList *del = start;
        start = q;
        del = 0;
        p = q;
        q = p->next;
        cout << "\nPerson deleted successfully\n\n";
        return;
    }


    while (x != 0)
    {
        if (q != 0)
        {
            x = strcmp(nameToDelete, q->person->name);
        }
        if ((q == 0) && (p != start))
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
    if (q->next == 0)
    {
        q = 0;
        p->next = 0;
        cout << "\nPerson deleted successfully\n\n";
        return;
    }

    LinkedList *d = q;
    // When the person to delete is between 2 other persons
    q = q->next;
    p->next = q;
    d = 0;
    cout << "\nPerson deleted successfully\n\n";
}

// ======================== File Storage ========================
void loadPersonsFromFile(LinkedList *start, LinkedList *p)
{
    ifstream fin("AgendaRefactor.txt");
    bool x = fin.eof();
    while (x == false)
    {
        LinkedList *newNode = new LinkedList;
        Person* readPerson = new Person;

        fin.getline(readPerson->name, MAX_NAME_LENGTH);
        fin >> readPerson->phoneNumber;
        fin.ignore();
        fin.getline(readPerson->address, MAX_ADDRESS_LENGTH);
        newNode->person = readPerson;
        newNode->next = 0;

        if (start == 0)
        {
            //start = new LinkedList;
            start->person = newNode->person;
            //start->next = 0;
        }

        else
        {
            while (p->next != 0)
            {
                p = p->next;
            }
            p->next = newNode;
        }
        x = fin.eof();
    }
    fin.close();
}

void savePersonsToFile(LinkedList *p)
{
    ofstream fout("Agenda.txt");

    while (p != 0)
    {
        if (p->next == 0)
        {
            fout << p->person->name << "\n";
            fout << p->person->phoneNumber << "\n";
            fout << p->person->address;
            p = 0;
        }
        else
        {
            fout << p->person->name << "\n";
            fout << p->person->phoneNumber << "\n";
            fout << p->person->address << "\n";
            p = p->next;
        }

    }
    fout.close();
}


// =========================== Search ==========================
void searchPersonByName(char name[], LinkedList *p)
{

    int x = strcmp(name, p->person->name);

    while (x != 0 && p->next != 0)
    {
        p = p->next;
        x = strcmp(name, p->person->name);
    }
    x = strcmp(name, p->person->name);
    if (p->next == 0 && x != 0)
    {
        cout << "Person not found\n\n";
        return;
    }

    printPerson(p->person);
}

void searchPersonByPhoneNumber(char phoneNumber[], LinkedList *p)
{
    int x = strcmp(phoneNumber, p->person->phoneNumber);

    while (x != 0 && p->next != 0)
    {
        p = p->next;
        x = strcmp(phoneNumber, p->person->phoneNumber);
    }
    x = strcmp(phoneNumber, p->person->phoneNumber);

    if (p->next == 0 && x != 0)
    {
        cout << "Person not found\n\n";
        return;
    }

    printPerson(p->person);
}

// =========================== Printer ==========================
void printPersons(LinkedList* start, LinkedList* p)
{
    if (start == 0)
    {
        cout << "No entries\n\n";
        return;
    }

    int x = 1;
    while (p != 0)
    {
        cout << "Entry #" << x << "\n";
        printPerson(p->person);
        p = p->next;
        x++;
    }
    cout << "\n\n";
}
