#include "../../include/model/point.h"
int Point::getX(){
    return x;
};

int Point::getY(){
    return y;
};

int Point::getValue(){
    return value;
}

Point::Point(){
    set(-1, -1, -1);
};

Point::Point(int x, int y, int value){
    set(x, y, value);
};

void Point::set(int x, int y, int value){
    this->x = x;
    this->y = y;
    this->value = value;
}
