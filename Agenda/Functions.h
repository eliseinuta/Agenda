#pragma once

bool validateName(char name[]);
bool avoidDuplicateName(char name[]);
char* readName();
char* readNameForSearch();
bool validatePhoneNumber(char phoneNumber[]);
bool avoidDuplicatePhoneNumber(char phoneNumber[]);
char* readPhoneNumber();
char* readPhoneNumberForSearch();
bool validateAddress(char address[]);
char* readAdress();
Person* createPerson(char personAdress[],
	char personPhoneNumber[],
	char personName[]);
void printPerson(Person* p);
void printPersons();
void insertPersonAlphabetically(Person* newPerson);
void deletePerson(char nameToDelete[]);
void loadPersonsFromFile();
void savePersonsToFile();
void searchPersonByName(char name[]);
void searchPersonByPhoneNumber(char phoneNumber[]);
