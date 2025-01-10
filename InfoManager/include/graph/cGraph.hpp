#ifndef CGRAPH_H
#define CGRAPH_H
#include "path.hpp"
#include "edge.hpp"
#include "vex.hpp"
#include<vector>
using namespace std;
const int N = 20;
class CGraph{
private:
    int adj_matrix[N][N];
    Vex vex_matrix[N];
    int vex_num;
public:
    CGraph();
    void init();
    int getVexNum();
    bool insertVex(Vex vex);
    bool insertEdge(Edge edge);
    bool getVex(int v, Vex& vew);
    int findEdge(int v, Edge edge[]);
    void DFS(int nVex, bool Visited[], int& nIndex,vector<Path>& list, int path[]);
    void DFSTraverse(int nVex, vector<Path>& list);
    int findShortPath(int nVexStart, int nVexEnd, int aPath[]);
    bool findMinTree(Edge aPath[]);

};
#endif // CGRAPH_H
