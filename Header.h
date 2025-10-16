#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Resident {
    char name[50];
    int age;
    bool assigned;
};

struct Apartment {
    int number;
    int floor;
    int rooms;
    Resident residents[5];
    int residentCount;
};

// функции
void addApartment(Apartment apartments[], int& count);
void deleteApartment(Apartment apartments[], int& count, int number);
void addResident(Apartment& apartment);
void showAll(const Apartment apartments[], int count);

//функции для файла txt
void saveToFile(const Apartment apartments[], int count);
void loadFromFile(Apartment apartments[], int& count);
