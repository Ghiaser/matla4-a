#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

using namespace std;


namespace ariel
{
class Team {                        // The class
private:                            // private Access specifier
    Character& leader;              // leader
    vector<Character> team;         // team group

public:                             // Access specifier
    
    Team(Character *lead);          // Constructor with parameters

    void add(Character *p);         // add a new member to the team

    void attack(Team *other);       // attack another team

    int stillAlive();               // return number of alive members in the team

    void print();

    ~Team();                        // distructor


};
}