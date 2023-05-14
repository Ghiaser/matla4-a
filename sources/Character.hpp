#pragma once
#include <string>
#include "Point.hpp"

using namespace std;


namespace ariel
{
class Character {                       // The class
private:                                // private Access specifier
    Point location;                     // Character location
    int hitpoints;                      // Hp
    string name;                        // Character name

public:                                 // Access specifier

    Character(string name,Point location,int hitpoints);

    virtual bool isAlive();
    virtual double distance(Character *other);
    virtual void hit(int damage);
    virtual string getName() const;
    virtual Point getLocation() const;
    virtual string print();

    /* methods to help with test */
    virtual int getHitPoints();


};
}