#pragma once

const int MAX_NAME_LENGTH = 21;
const int MAX_ADDRESS_LENGTH = 41;
const int MAX_NUMBER_LENGTH = 16;

struct Person
{
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_NUMBER_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};

bool validateName(char name[]);
char* readNameForSearch();
bool validatePhoneNumber(char phoneNumber[]);
char* readPhoneNumberForSearch();
bool validateAddress (char address []);
char* readAdress();
Person* createPerson(char personAdress[],
                     char personPhoneNumber[],
					 char personName[]);
void printPerson(Person* p);