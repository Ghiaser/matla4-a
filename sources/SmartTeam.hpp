#pragma once
#include "Character.hpp"
#include <vector>

using namespace std;


namespace ariel
{
class SmartTeam {                        // The class
private:                            // private Access specifier
    Character& leader;              // leader
    vector<Character> team;         // team group

public:                             // Access specifier
    
    SmartTeam(Character& lead);          // Constructor with parameters

    void add(Character *p);         // add a new member to the team

    void attack(SmartTeam *other);       // attack another team

    int stillAlive();               // return number of alive members in the team

    void print();

    ~SmartTeam();                        // distructor


};
}