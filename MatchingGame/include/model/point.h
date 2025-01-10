#ifndef POINT_H
#define POINT_H
const int BLANK = -1;
class Point{
private:
    int x, y, value;
public:
    Point();
    Point(int x, int y, int value);
    int getX();
    int getY();
    int getValue();
    void set(int x, int y, int value);
};

#endif // POINT_H
