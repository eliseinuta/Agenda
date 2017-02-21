#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
const int MAX_NAME_LENGTH = 50;
const int MAX_ADDRESS_LENGTH = 100;
const int MAX_NUMBER_LENGTH = 15;

struct person
{
	char name[MAX_NAME_LENGTH];
	char phoneNumber[MAX_NUMBER_LENGTH];
	char address[MAX_ADDRESS_LENGTH];
	person *next;
};

person *start;

char* ReadName()
{
	char* name = new char[MAX_NAME_LENGTH];
	cout << "Insert name: ";
	cin.getline(name, MAX_NAME_LENGTH - 1, '\n');
	return name;
}

bool ValidatePhoneNumber(char phoneNumber[])
{
	int i;
	for (i = 0; i <= strlen(phoneNumber); i++)
	{
		if (phoneNumber[i]>'0' && phoneNumber[i] <'9')
		{
			return true;
		}

		if (phoneNumber[i] == '+' && phoneNumber[i] == '*' && phoneNumber[i] == '#')
		{
			return true;
		}

		return false;
	}
}

bool AvoidDuplicatePhoneNumber(char phoneNumber[])
{
	person* p = start;
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

char* ReadPhoneNumber()
{
	char* phoneNumber = new char[MAX_NUMBER_LENGTH];

	loop: cout << "Insert phone number: ";
	cin.getline(phoneNumber, MAX_NUMBER_LENGTH - 1, '\n');
	if (!ValidatePhoneNumber(phoneNumber))
	{
		cout << "******Invalid phone number******\n";
		goto loop;
	}

	if (!AvoidDuplicatePhoneNumber(phoneNumber))
	{
		cout << "******Phone number already exists******\n";
		goto loop;
	}
	return phoneNumber;
	
}

char* ReadAdress()
{
	char* address = new char[MAX_ADDRESS_LENGTH];
	cout << "Insert address: ";
	cin.getline(address, MAX_ADDRESS_LENGTH - 1, '\n');
	return address;
}

person* CreatePerson(char personName[], char personPhoneNumber[], char personAdress[])
{
	person* newPerson = new person;
	strcpy_s(newPerson->name, personName);
	strcpy_s(newPerson->phoneNumber, personPhoneNumber);
	strcpy_s(newPerson->address, personAdress);
	newPerson->next = NULL;
	return newPerson;
	}

/*void AddPerson(person* newPerson)
 {
 	if(start==NULL)
 		start=newPerson;
 	else
 	{
 		person *p = start;
 		while (p->next!=NULL)
 		{
 			p=p->next;
 		}
 		p->next=newPerson;
 	}
 }*/
	
void PrintPersons()
	 {
	if (start == NULL)
		 {
		cout << "No entries\n\n";
		return;
		}
	
		
		person *p = start;
	int x = 1;
	while (p != NULL)
		 {
		cout << "Entry #" << x << "\n";
		cout << "Name: " << p->name << "\nPhone Number: " << p->phoneNumber << "\nAddress: " << p->address << "\n\n";
		cout << endl;
		p = p->next;
		x++;
		}
	cout << "\n\n";
	}

void InsertPersonAlphabetically(person* newPerson)
 {
	int position = 2;
	
		if (start == NULL)										//When there are no persons
		 {
		start = newPerson;
		return;
		}
	
		person *p = start;
	
		if (start->next == NULL)								 //When there is only one person
		 {
		int x = strcmp(newPerson->name, start->name);				//Compare newPerson and start
		
			if (x >= 0)													//When new goes after start
			 {
			start->next = newPerson;
			}
		
			if (x < 0)													//When new goes before start
			 {
			start = newPerson;
			start->next = p;
			}
		
			return;
		}
	
		
		
		
		else													//When there are more than 2 persons
		 {
		person *q = p->next;
		
			int x = (strcmp(newPerson->name, start->name));			//Compare newPerson and start
		
			if (x<0)												//When new goes before start
			 {
				start = newPerson;
				start->next = p;
				return;
			}
		
			
			while (position > 0 && q != NULL)							//Move p and q until new person goes between or q is NULL
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

void DeletePerson(char nameToDelete[])
{
	person *p = start;
	person *q = p->next;
	int x = -5;
	int y = -5;
	
	if (start == NULL)			//When list is empty
	{
		cout << "\nThe list is empty\n\n";
		return;
	}
	
	if (start->next == NULL)			//When there is only one entry
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
			person *de = start;
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
	
		if (q->next == NULL)				//When the name to delete is the last entry
		 {
		q = NULL;
		p->next = NULL;
		cout << "\nPerson deleted successfully\n\n";
		return;
		}
	
		person *d = q;
	q = q->next;				//When the person to delete is between 2 other persons
	p->next = q;
	d = NULL;
	cout << "\nPerson deleted successfully\n\n";
	
		
		
		
}

person* GetNameToDelete()
 {
	person* nameToDelete = new person;
	cout << "Insert name of the person to delete: ";
	cin.getline(nameToDelete->name, MAX_NAME_LENGTH - 1, '\n');
	return nameToDelete;
	}

void LoadPersonsFromFile()
{
	ifstream fin("Agenda.txt");
	bool x = fin.eof();
	while (x == false)
		 {
		person* readPerson = new person;
		
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
			person *p = start;
			
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

void SavePersonsToFile()
 {
	ofstream fout("Agenda.txt");

	
		person *p = start;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			fout << p->name << "\n" << p->phoneNumber << "\n" << p->address;
			p = NULL;
		}
		else
			 {
			fout << p->name << "\n" << p->phoneNumber << "\n" << p->address << "\n";
			p = p->next;
			}
		
	}
	fout.close();
	}

void SearchPersonByName()
 {
	char nameToSearch[MAX_NAME_LENGTH];
	cout << "Insert name to search: ";
	cin.ignore();
	cin.getline(nameToSearch, MAX_NAME_LENGTH - 1, '\n');

	person *p = start;
	
		int x = strcmp(nameToSearch, p->name);
	
		while (x != 0 && p != NULL)
		 {
		p = p->next;
		x = strcmp(nameToSearch, p->name);
		}
	
		if (p == NULL)
		 {
		cout << "Person not found\n\n";
		return;
		}
	
		cout << "Name: " << p->name << "\nPhone Number: " << p->phoneNumber << "\nAddress: " << p->address << "\n\n";
	}

void SearchPersonByPhoneNumber()
 {
	char phoneNumberToSearch[MAX_NAME_LENGTH];
	cout << "Insert phone number to search: ";
	cin.ignore();
	cin.getline(phoneNumberToSearch, MAX_NUMBER_LENGTH, '\n');
	
		person *p = start;
	
		int x = strcmp(phoneNumberToSearch, p->phoneNumber);
	
		while (x != 0 && p != NULL)
		 {
		p = p->next;
		x = strcmp(phoneNumberToSearch, p->phoneNumber);
	}

	if (p == NULL)
		 {
		cout << "Person not found\n\n";
		return;
		}
	
		cout << "Name: " << p->name << "\nPhone Number: " << p->phoneNumber << "\nAddress: " << p->address << "\n\n";
	}

void MenuOneCharValidation(char* option)
 {
	*option = getchar();
	
		if ('\n' != getchar())
		 {
		while ('\n' != getchar());
		cout << "Option not found\nChoose action: ";
		MenuOneCharValidation(option);
		}
	
		}

int MenuOptionValidation(char* option, char* validOptions)
 {
	MenuOneCharValidation(option);
	
		while (*validOptions)
		 {
		if (*validOptions == *option)
			 return 1;
		
			else
			 validOptions++;
		}
	return 0;
	
		}



void Menu()
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
	while (!MenuOptionValidation(&option, validOptions))
		 {
		cout << "Option not found\nChoose action: ";
		}
	cout << "\n\n";
	switch (option)
		{
		case '1': PrintPersons();
		break;
		case '2': InsertPersonAlphabetically(CreatePerson(ReadAdress(), ReadPhoneNumber(), ReadName()));
		break;
		case '3': DeletePerson(ReadName());
		break;
		case '4': SearchPersonByName();
		break;
		case '5': SearchPersonByPhoneNumber();
		break;
		case '6': SavePersonsToFile();
		break;
		default: cout << "Option not found\nChoose action: ";
		break;
		}
	
		}

int main()
 {
	start = NULL;
	
		LoadPersonsFromFile();
	
		cout << "*****Phonebook*****\n\n";
	
		while (true)
		 {
		Menu();
		}
	
		return 0;
	}



/*	char x [16];
 	int y=0;
 	int i;
 	int a;
 	char q='\n';
 	while (true)
 	{
 		cout<<"Insert a number: ";
 		cin.getline(x,5,'\n');
 		q = getchar();
 
 		if (q != '\n')
 		{
 			cout<<"Number too long\n";
 			while (q != '\n')
 			{
 				q = getchar();
 			}
 
 		}
 		else
 		{
 			for (i=0; i<=strlen(x)-1;i++)
 			{
 				if(x[i] >='0' && x[i]<='9')
 				{
 				y *=10;
 				y = y + (x[i]-'0');
 				}
 
 				else
 				{
 					cout<<"Invalid number";
 					break;
 				}
 
 			}
 			cout<<"Number = "<<y;
 		}
 	}*/