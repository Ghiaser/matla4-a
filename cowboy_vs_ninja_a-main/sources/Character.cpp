#include "Character.hpp"

namespace ariel
{
    Character::Character(string name,Point location,int hitpoints):name(name),location(location),hitpoints(hitpoints){}

    bool Character::isAlive(){return true;}
    double Character::distance(Character *other){return 0;}
    void Character::hit(int damage){}
    string Character::getName() const{return this->name;}
    Point Character::getLocation() const{return this->location;}
    string Character::print(){return "";}

    /* methods to help with test */
    int Character::getHitPoints(){return this->hitpoints;}

}