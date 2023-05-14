#include "Point.hpp"

namespace ariel
{

    Point::Point(double x,double y):_x(x),_y(y){}

    double Point::distance(Point p){return 0;}

    void Point::print(){}

    Point Point::moveTowards(Point src , Point dest , double distance){return Point(0,0);}

    /* == */
    bool operator ==(const Point& a, const Point& b){
        return( ((a._x == b._x) && (a._y == b._y)) );
    }

}