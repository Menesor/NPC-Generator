// @file Character.cpp
// Implementation for Character class

#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(const string& sName, const string& sRace, const string& sNationality, const string& sJob, const string& sRole) : name(sName), race(sRace), nationality(sNationality), job(sJob), role(sRole) {};

void Character::PrintCharacter() {
	cout << "Name: " << name << endl << "Race: " << race << endl << "Nationality: " << nationality << endl << "Job: " << job << endl << "Class: " << role << endl << endl;
}