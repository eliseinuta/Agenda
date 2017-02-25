#pragma once

#include "person.h"

struct LinkedList
{
    Person *person = NULL;
    LinkedList *next = NULL;
};

// =========================== Unique Checkers =======================
bool avoidDuplicateName(char[], LinkedList*);
bool avoidDuplicatePhoneNumber(char[], LinkedList*);

// =========================== Readers ==========================
char* readName(LinkedList*);
char* readPhoneNumber(LinkedList*);

// ======================== Linked List Operations ========================
void insertPersonAlphabetically(Person*, LinkedList*, LinkedList*);
void deletePerson(char[], LinkedList*, LinkedList*);

// ======================== File Storage ========================
void loadPersonsFromFile(LinkedList*, LinkedList*);
void savePersonsToFile(LinkedList*);

// =========================== Search ==========================
void searchPersonByName(char[], LinkedList*);
void searchPersonByPhoneNumber(char[], LinkedList *);

// =========================== Printer ==========================
void printPersons(LinkedList*, LinkedList*);
