#pragma once

#include "person.h"
struct LinkNode
{
    Person person;
    LinkNode *next;	
};
// =========================== Unique Checkers =======================
bool isUniqueName(char[], LinkNode* listStart);
bool isUniquePhoneNumber(char[], LinkNode* listStart);

// =========================== Readers ==========================
char* readNameForInsert(LinkNode* listStart);
char* readPhoneNumberForInsert(LinkNode* listStart);

// ======================== Linked List Operations ========================
void insertPersonAlphabetically(LinkNode* &start, Person);
void deletePerson(char[], LinkNode* &listStart);

// ======================== File Storage ========================
void loadPersonsFromFile(LinkNode* &start);
void savePersonsToFile(LinkNode* start);

// =========================== Search ==========================
void searchPersonByName(char[], LinkNode* start);
void searchPersonByPhoneNumber(char[], LinkNode* start);

// =========================== Printer ==========================
void printPersons(LinkNode* start);