// @file Main.cpp
// Main file for NPC Generator

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "tinyxml2.h"

using namespace std;

int GenerateRandomInt(const int& max);
void GenerateCharacters(const int& num, const tinyxml2::XMLDocument& xmlDoc);

int main() {

	int num;
	char choice;
	bool isOk = false,
		 isDone = false;

	// initialize xml document
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("strings.xml");

	// seed rand function
	srand((int)time(0));

	while (!isDone) {
		system("CLS");
		cout << "Please enter the numbers of characters to generate: ";
		while (!isOk) {
			cin >> num;
			if (cin.fail()) {
				cout << "Please input a valid number" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				isOk = true;
			}
		}
		isOk = false;

		GenerateCharacters(num, xmlDoc);

		cout << "Would you like to generate more characters? (y/n): ";
		while (!isOk) {
			cin >> choice;
			if (cin.fail()) {
				cout << "Please enter a valid input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
				cout << "Please enter a valid input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (choice == 'y' || choice == 'Y') {
				isOk = true;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else {
				isOk = true;
				isDone = true;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		isOk = false;
	}
	
	return 0;
}

int GenerateRandomInt(const int& max) {
	return (rand() % max) + 1;
}

void GenerateCharacters(const int& num, const tinyxml2::XMLDocument& xmlDoc) {
	const tinyxml2::XMLElement* elementPtr;
	int randomInt = 0;
	int itemCount = 0;
	for (int i = 0; i < num; i++) {
		const char* race = char();
		const char* nationality = char();
		const char* name = char();
		const char* role = char();
		const char* job = char();
		string fullName;

		// Generate random race
		itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Races")->IntAttribute("itemcount");
		randomInt = GenerateRandomInt(itemCount);
		elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Races")->FirstChildElement();
		for (int j = 1; j < randomInt; j++) {
			elementPtr = elementPtr->NextSiblingElement();
		}
		race = elementPtr->GetText();

		// Generate random nationality
		itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Nationalities")->IntAttribute("itemcount");
		randomInt = GenerateRandomInt(itemCount);
		elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Nationalities")->FirstChildElement();
		for (int j = 1; j < randomInt; j++) {
			elementPtr = elementPtr->NextSiblingElement();
		}
		nationality = elementPtr->GetText();

		// Generate random name
		
		// First name
		if (strcmp(xmlDoc.FirstChildElement()->FirstChildElement("FirstNames")->FirstChildElement(race)->FirstChildElement()->Value(), "name") != 0) {
			itemCount = xmlDoc.FirstChildElement()->FirstChildElement("FirstNames")->FirstChildElement(race)->FirstChildElement()->IntAttribute("itemcount");
			randomInt = GenerateRandomInt(itemCount);
			elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("FirstNames")->FirstChildElement(race)->FirstChildElement(nationality)->FirstChildElement();
			for (int j = 1; j < randomInt; j++) {
				elementPtr = elementPtr->NextSiblingElement();
			}
			name = elementPtr->GetText();
		}
		else {
			itemCount = xmlDoc.FirstChildElement()->FirstChildElement("FirstNames")->FirstChildElement(race)->IntAttribute("itemcount");
			randomInt = GenerateRandomInt(itemCount);
			elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("FirstNames")->FirstChildElement(race)->FirstChildElement();
			for (int j = 1; j < randomInt; j++) {
				elementPtr = elementPtr->NextSiblingElement();
			}
			name = elementPtr->GetText();
		}

		// append first name to full name
		fullName.append(name);

		// add a space to separate first and last names
		fullName += " ";

		// Last name
		if (strcmp(xmlDoc.FirstChildElement()->FirstChildElement("Surnames")->FirstChildElement(race)->FirstChildElement()->Value(), "name") != 0) {
			itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Surnames")->FirstChildElement(race)->FirstChildElement()->IntAttribute("itemcount");
			randomInt = GenerateRandomInt(itemCount);
			elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Surnames")->FirstChildElement(race)->FirstChildElement(nationality)->FirstChildElement();
			for (int j = 1; j < randomInt; j++) {
				elementPtr = elementPtr->NextSiblingElement();
			}
			name = elementPtr->GetText();
		}
		else {
			itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Surnames")->FirstChildElement(race)->IntAttribute("itemcount");
			randomInt = GenerateRandomInt(itemCount);
			elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Surnames")->FirstChildElement(race)->FirstChildElement();
			for (int j = 1; j < randomInt; j++) {
				elementPtr = elementPtr->NextSiblingElement();
			}
			name = elementPtr->GetText();
		}

		// append last name to full name
		fullName.append(name);

		// Generate Random class
		itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Roles")->IntAttribute("itemcount");
		randomInt = GenerateRandomInt(itemCount);
		elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Roles")->FirstChildElement();
		for (int j = 1; j < randomInt; j++) {
			elementPtr = elementPtr->NextSiblingElement();
		}
		role = elementPtr->GetText();

		// Generate Random Job
		itemCount = xmlDoc.FirstChildElement()->FirstChildElement("Jobs")->IntAttribute("itemcount");
		randomInt = GenerateRandomInt(itemCount);
		elementPtr = xmlDoc.FirstChildElement()->FirstChildElement("Jobs")->FirstChildElement();
		for (int j = 1; j < randomInt; j++) {
			elementPtr = elementPtr->NextSiblingElement();
		}
		job = elementPtr->GetText();

		// Create character
		Character c = Character(fullName, race, nationality, job, role);
		c.PrintCharacter();
	}
}