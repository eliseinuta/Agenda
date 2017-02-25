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

// ========== Constructor ===========
Person* createPerson(char, char, char);

// ========== Validators ===========
bool validateName(char[]);
bool validatePhoneNumber(char[]);
bool validateAddress(char[]);

// ========== Readers ===========
char* readName();
char* readPhoneNumber();
char* readAdress();

// ========== Printer ===========
void printPerson(Person*);
//test
