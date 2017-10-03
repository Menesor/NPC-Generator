// @file Character.h
// Header file for Character class

#ifndef H_Character
#define H_Character

#include <string>

using namespace std;

class Character {
	private:
		string name, race, nationality, job, role;	// role = class
	public:
		Character(const string& sName, const string& sRace, const string& sNationality, const string& sJob, const string& sRole);
		void PrintCharacter();
};
#endif // !H_Character
