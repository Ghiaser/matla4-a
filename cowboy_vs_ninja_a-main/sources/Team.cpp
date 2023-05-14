#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *lead):leader(*lead){}

    void Team::add(Character *p){}

    void Team::attack(Team *other){}

    int Team::stillAlive(){return 0;}
    
    void Team::print(){}

    Team::~Team(){}
}