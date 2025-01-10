#ifndef LOGIC_H
#define LOGIC_H
#include "../model/point.h"
#include "../model/cGraph.h"
#include <QVector>
class GameLogic{
private:
    CGraph* cgraph;
    Point* avPath;
    int* anPath;
    int nVexNum = 0;
    int nCorner = 0;

public:
    GameLogic(CGraph* cgraph);
    void initMap();

    void updateArc(int row, int col);
    bool isLink(Point p1, Point p2);
    void clear(Point p1, Point p2);

    bool searchPath(int v1Index, int v2Index);
    bool isExist(int num);
    bool isCornor();

    int getVexPath(QVector<Point>& avPath);
    bool isBlank();
    bool searchValidPath();
    void resetGraph();
    void pushVex(int nV);
    void popVex();
    void clearStack();

    CGraph* getMap();
};
#endif // LOGIC_H
