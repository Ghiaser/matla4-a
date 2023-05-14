#pragma once
#include "Character.hpp"
#include <vector>

using namespace std;


namespace ariel
{
class Team2 {                        // The class
private:                            // private Access specifier
    Character& leader;              // leader
    vector<Character> team;         // team group

public:                             // Access specifier
    
    Team2(Character& lead);          // Constructor with parameters

    void add(Character *p);         // add a new member to the team

    void attack(Team2 *other);       // attack another team

    int stillAlive();               // return number of alive members in the team

    void print();

    ~Team2();                        // distructor


};
}