
#include "sources/Team.hpp" //no need for other includes

using namespace std;
using namespace ariel;

#include "doctest.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

    TEST_CASE("Point Test")
    {
        Point p;

        CHECK_EQ(p , Point(0,0));                // Default Constructor Test

        CHECK( (Point(0,0).distance(Point(4,0))) == 4);

        CHECK_EQ( (Point(0,0).distance(Point(4,0))) , (Point(4,0).distance(Point(0,0))));

        Point a(5,7),b(7,10);

        CHECK(a.distance(b) == b.distance(a));

        Point p1(2,3);
        Point p2(4,5);

        Point p4 = p1.moveTowards(p1, p2, 1);
        CHECK(p4.distance(p2) == 1);
    
    }

    TEST_CASE("Character Test")
    {
        Character c("fighter1", Point(1,2), 10);
    
        CHECK(c.isAlive());                      // fighter1 should be alive
        
        Character c2("fighter2", Point(3,4), 10);
        CHECK(c.distance(&c2) == sqrt(5));       // distance test between fighter1 and fighter2
        
        c.hit(5);                                // decrease 5 from fighter1 Hp
        CHECK(c.isAlive() == true);              // fighter1 Hp should be 5, so he is alive
        
        CHECK(c.getName() == "fighter1");
        
        CHECK_EQ(c.getLocation(),Point(1,2));    // get location test

        c.hit(5);                                // decrease 5 from fighter1 Hp
        CHECK(c.isAlive() == false);             // fighter1 Hp should be 0, so he is Not alive
    
    }

    TEST_CASE("Cowboy Test")
    {
        Point p(1,2);
        Cowboy c("fighter1", p);                 /* 4 test-rows to test Cowboy Constructor */
        
        CHECK_EQ(c.getName(), "fighter1");
        CHECK_EQ(c.getLocation(), p);
        CHECK_EQ(c.getBullets(), 6);             // initial constructor make it 6 bullets
        CHECK_EQ(c.getHitPoints(), 110);         // initial constructor make it 110 Hp

        CHECK_THROWS(c.shoot(&c));               // Shooting oneself in not allowed

        Cowboy c2("fighter2", Point(3,4));
        
        c.shoot(&c2);
        CHECK_EQ(c.getBullets(), 5);             // fighter1 shoot fighter2 so fighter1 should have 5 bullets now
        CHECK_EQ(c2.getHitPoints(), 100);        // fighter2 Hp is 100 now

        for(int i=0;i<5;i++){                    // use all bullets fighter1 had
            c.shoot(&c2);
        }
        CHECK_EQ(c.hasboolets(),false);          // fighter1 got 0 bullets now 
        CHECK_EQ(c2.getHitPoints(), 50);         // fighter2 Hp is 50 now

        CHECK_EQ(c2.isAlive(), true);            // fighter2 Hp is 50 he still alive

        c.reload();                              // reload bullets 
        CHECK_EQ(c.getBullets(), 6);             // now got new 6 bullets

        for(int i=0;i<5;i++){                    
            c.shoot(&c2);                        // shoot fighter2 till death
        }
        CHECK_EQ(c2.isAlive(), false);           // fighter2 is dead now
        CHECK_THROWS(c.shoot(&c2));              // fighter2 is already dead, cannot shoot him 

    }

    TEST_CASE("Ninja Test")
    {
        YoungNinja yn("young", Point(1,2));      // 100 hp - 14 speed
        TrainedNinja tn("trained", Point(2,3));  // 120 hp - 12 speed
        OldNinja on("old", Point(22,36));        // 150 hp - 8 speed
        
        yn.move(&tn);

        CHECK(yn.getLocation() == Point(2,3));   // yn now behind tn

        int hp = tn.getHitPoints();              // hp is {120}
        yn.slash(&tn);                           // yn slash {13} tn

        CHECK(tn.getHitPoints() == (hp - 13));

        tn.move(&on);

        CHECK(tn.getLocation() == Point(8.842,14.289));   // tn moved 12 km from his prev location
    }

    TEST_CASE("Teams Test")
    {
        YoungNinja yn("young", Point(1,2));      // 100 hp - 14 speed
        TrainedNinja tn("trained", Point(2,3));  // 120 hp - 12 speed
        OldNinja on("old", Point(22,36));        // 150 hp - 8 speed
        
        Team t(&yn);                             // initial new team and yn is the leader
        t.add(&tn);                              /* add {tn} and {on} to the team */
        t.add(&on);

        CHECK_EQ(t.stillAlive() , 3);            // got 3 fighters in the team alive

        Cowboy a("a", Point(1,2));
        TrainedNinja b("b", Point(2,3));
        OldNinja c("c", Point(22,36));

        Team nt(&a);                             // create new team - a is the leader
        nt.add(&b);
        nt.add(&c);

        CHECK_EQ(nt.stillAlive() , 3);           // got 3 fighters in the team alive

        CHECK_THROWS(t.attack(NULL));            // cant attack null pointer team

        while (nt.stillAlive() > 0)
        {
            t.attack(&nt);
        }

        CHECK(nt.stillAlive() == 0);
        /* nt members all dead */
        CHECK_FALSE(a.isAlive());
        CHECK_FALSE(b.isAlive());
        CHECK_FALSE(b.isAlive());
    }
    