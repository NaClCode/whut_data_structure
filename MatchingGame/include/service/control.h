#ifndef CONTROL_H
#define CONTROL_H
#include "logic.h"

const int GAME_LOSE = -1;
const int GAME_SUCCESS = 0;
const int GAME_PLAY = 1;

class Control
{

public:
    Control(GameLogic* logic);
    ~Control();
    bool link(QVector<Point>& avPath);
    int isWin(int nTime);
    void startGame();
    void setFirstPoint(int row, int col);
    void setSecPoint(int row, int col);
    bool help(QVector<Point>& avPath);
    void reset();
    int getElement(int row, int col);

private:
    GameLogic* logic;
    Point p1, p2;


};
#endif // CONTROL_H
