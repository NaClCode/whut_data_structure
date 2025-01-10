#include "../../include/model/cGraph.h"
void CGraph::initGraph(){
    arcnum = vexnum = 0;
    for (int i = 0; i < MAXNUM; i++){
        vex[i] = -1;

        for (int j = 0; j < MAXNUM; j++){
            adj[i][j] = 0;
        }
    }
};

int CGraph::addVex(int vex){
    if (vexnum > MAXNUM) return 0;
    this->vex[vexnum++] = vex;
    return vexnum;
};

int CGraph::getVex(int index){
    return this->vex[index];
};

int CGraph::getVexnum(){
    return this->vexnum;
};

void CGraph::addArc(int v1Index, int v2Index){
    this->adj[v1Index][v2Index] = true;
    this->adj[v2Index][v1Index] = true;
};

bool CGraph::getArc(int v1Index, int v2Index){
    return this->adj[v1Index][v2Index];
};

void CGraph::updateVex(int v1Index, int value){
    this->vex[v1Index] = value;
};

void CGraph::changeVex(int v1Index, int v2Index){
    int temp = this->vex[v1Index];
    this->vex[v1Index] = this->vex[v2Index];
    this->vex[v2Index] = temp;
}
