#ifndef CGRAPH_H
#define CGRAPH_H
const int MAXNUM = 144;
const int MAX_ROW = 12;
const int MAX_COL = 12;
const int MAX_PIC_NUM = 8;
const int REPEAT_NUM = 18;

class CGraph{
private:
    int vex[MAXNUM];
    bool adj[MAXNUM][MAXNUM];
    int arcnum;
    int vexnum;
public:
    void initGraph();
    int addVex(int vex);
    int getVex(int index);
    int getVexnum();
    void addArc(int v1Index, int v2Index);
    bool getArc(int v1Index, int v2Index);
    void updateVex(int v1Index, int value);
    void changeVex(int v1Index, int v2Index);
};
#endif // CGRAPH_H
