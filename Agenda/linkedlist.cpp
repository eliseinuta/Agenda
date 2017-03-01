#include "linkedlist.h"
#include "person.h"

#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

// =========================== Unique Checkers =======================

bool isUniqueName(char name[], LinkNode* listStart)
{
	LinkNode *p=listStart;

	while (p != 0)
	{
		if (strcmp(p->person.name, name) == 0)
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

bool isUniquePhoneNumber(char phoneNumber[], LinkNode* listStart)
{
	LinkNode *p=listStart;
	while (p != 0)
	{
		if (strcmp(p->person.phoneNumber, phoneNumber) == 0)
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
char* readNameForInsert(LinkNode* start)
{

	char* name = new char[MAX_NAME_LENGTH + 1];
loop:
	cout << "Insert name: ";
	cin.getline(name, MAX_NAME_LENGTH + 1, '\n');


	if (!validateName(name))
	{
		goto loop;
	}

	if (!isUniqueName(name, start))
	{
		cout << "******Name already exists******\n";
		goto loop;
	}

	return name;
}

char* readPhoneNumberForInsert(LinkNode* start)
{
	char* phoneNumber = new char[MAX_NUMBER_LENGTH + 1];

loop:
	cout << "Insert phone number: ";
	cin.getline(phoneNumber, MAX_NUMBER_LENGTH + 1, '\n');
	if (!validatePhoneNumber(phoneNumber))
	{
		goto loop;
	}

	if (!isUniquePhoneNumber(phoneNumber, start))
	{
		cout << "******Phone number already exists******\n";
		goto loop;
	}
	return phoneNumber;

}


// ======================== Linked List Operations ========================
void insertPersonAlphabetically(LinkNode* &start, Person newPerson)
{
	LinkNode* nodeToInsert=new LinkNode();
	nodeToInsert->person=newPerson;
	nodeToInsert->next=0;

	// When there are no persons
	if (start == 0)
	{
		start=nodeToInsert;
		return;
	}

	LinkNode* p=start;
	LinkNode* q = p->next;	  
	int x = strcmp(newPerson.name, p->person.name);
	// When new goes before start
	if (x < 0)
	{	 
		nodeToInsert->next=start;
		start=nodeToInsert;       
		return;
	}
	else 
	{
		if (q==0)
		{
			start->next=nodeToInsert;
			return;
		}		
		x = strcmp(newPerson.name, q->person.name);
		while (x>=0)
		{
			p=q;
			q=q->next;
			if (q==0)
				break;
			x = strcmp(newPerson.name, q->person.name);			
		}

		nodeToInsert->next=q;
		p->next=nodeToInsert;
	}
	/*
	// When there is only one person
	if (start->next == 0)
	{
	// Compare newPerson and start



	// When new goes after start
	if (x >= 0)
	{					
	start->next=n;
	}

	return;
	}
	// When there are more than 2 persons
	else
	{
	LinkNode *q = start->next;
	// Compare newPerson and start
	int x = (strcmp(newPerson.name, start->person.name));
	// When new goes before start
	if (x < 0)
	{
	start->person = newPerson;
	start->next = q;
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
	LinkNode *newNode;
	newNode->person = newPerson;

	newNode->next = q;
	p->next = newNode;
	}
	}*/

}

void deletePerson(char nameToDelete[], LinkNode* &start)
{
		// When list is empty
	if (start == 0)
	{
		cout << "\nThe list is empty\n\n";
		return;
	}

	LinkNode* p = start;
	LinkNode* q = p->next;
	int x=-2;


	//When start needs to be deleted
	x = strcmp(nameToDelete, start->person.name);
	if (x==0)
	{
		start = q;
		p = 0;
		cout << "Person deleted successfully\n\n";
		return;
	}
	//When there is only start and is not to be deleted
	if (start->next == 0)
	{
			cout << "\nPerson not found: "<<nameToDelete<<"\n\n";
			return;
	}

	//When name to delete is last node or between nodes
	x = strcmp(nameToDelete, q->person.name);
	while (q->next!=0)
	{
		x = strcmp(nameToDelete, q->person.name);
		if (x==0)
		{
			break;
		}
		p=p->next;
		q=q->next;
	}
	x = strcmp(nameToDelete, q->person.name);
	//When person is not found
	if (x!=0)
	{
			cout << "\nPerson not found: "<<nameToDelete<<"\n\n";
			return;
	}
	p->next = q->next;
	q=0;
	cout << "Person deleted successfully\n\n";
}

// ======================== File Storage ========================

void loadPersonsFromFile(LinkNode* &start)
{
    ifstream fin("Agenda.txt");
    bool x = fin.eof();
    while (x == false)
    {
        LinkNode *newNode = new LinkNode();
		LinkNode *p= start;
		Person readPerson;

        fin.getline(readPerson.name, MAX_NAME_LENGTH);
        fin >> readPerson.phoneNumber;
        fin.ignore();
        fin.getline(readPerson.address, MAX_ADDRESS_LENGTH);
		newNode->person = readPerson;
		newNode->next = 0;

        if (start == 0)
        {
            start = newNode;
        }

        else
        {
			LinkNode *p = start;

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

void savePersonsToFile(LinkNode *listStart)
{
	ofstream fout("Agenda.txt");
	LinkNode *p=listStart;
	while (p != 0)
	{
		if (p->next == 0)
		{
			fout << p->person.name << "\n";
			fout << p->person.phoneNumber << "\n";
			fout << p->person.address;
			p = 0;
		}
		else
		{
			fout << p->person.name << "\n";
			fout << p->person.phoneNumber << "\n";
			fout << p->person.address << "\n";
			p = p->next;
		}

	}
	fout.close();
}


// =========================== Search ==========================
void searchPersonByName(char name[], LinkNode *start)
{
	LinkNode *p = start;
	int x = strcmp(name, p->person.name);

	while (x != 0 && p->next != 0)
	{
		p = p->next;
		x = strcmp(name, p->person.name);
	}
	x = strcmp(name, p->person.name);
	if (p->next == 0 && x != 0)
	{
		cout << "Person not found\n\n";
		return;
	}

	printPerson(p->person);
}

void searchPersonByPhoneNumber(char phoneNumber[], LinkNode *start)
{
	LinkNode *p = start;
	int x = strcmp(phoneNumber, p->person.phoneNumber);

	while (x != 0 && p->next != 0)
	{
		p = p->next;
		x = strcmp(phoneNumber, p->person.phoneNumber);
	}
	x = strcmp(phoneNumber, p->person.phoneNumber);

	if (p->next == 0 && x != 0)
	{
		cout << "Person not found\n\n";
		return;
	}

	printPerson(p->person);
}

// =========================== Printer ==========================
void printPersons(LinkNode* start)
{
	if (start == 0)
	{
		cout << "No entries\n\n";
		return;
	}
	LinkNode *p = start;
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