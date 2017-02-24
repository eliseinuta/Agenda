#pragma once

#include "Person.h"

struct LinkedNode
{
	Person *person;
	LinkedNode *next;
};

bool avoidDuplicateName(char name[], LinkedNode* p);
char* readName(LinkedNode *p);
bool avoidDuplicatePhoneNumber(char phoneNumber[], LinkedNode* p);
char* readPhoneNumber(LinkedNode *p);
void printPersons(LinkedNode* start, LinkedNode* p);
void insertPersonAlphabetically(Person* newPerson, LinkedNode* start, LinkedNode* p);
void deletePerson(char nameToDelete[], LinkedNode *start, LinkedNode *p);
void loadPersonsFromFile(LinkedNode *start, LinkedNode *p);
void savePersonsToFile(LinkedNode *p);
void searchPersonByName(char name[], LinkedNode *p);
void searchPersonByPhoneNumber(char phoneNumber[], LinkedNode *p);