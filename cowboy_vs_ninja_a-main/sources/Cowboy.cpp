#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point l):Character(name,l,110),bullets(6){}
    void Cowboy::shoot(Character *c){}
    bool Cowboy::hasboolets(){return true;}
    void Cowboy::reload(){}
    string Cowboy::print(){
        return "C";
    }

    /* methods to help with test */
    int Cowboy::getBullets(){ return this->bullets;}
}