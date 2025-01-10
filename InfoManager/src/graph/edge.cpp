#include "../../include/graph/edge.hpp"
#include <iostream>
using namespace std;
Edge::Edge(int vex1, int vex2, int weight){
    this->vex1 = vex1;
    this->vex2 = vex2;
    this->weight = weight;
};

Edge::Edge(){
    this->vex1 = this->vex2 = this->weight = -1;
};

void Edge::setEdge(int vex1, int vex2, int weight){
    this->vex1 = vex1;
    this->vex2 = vex2;
    this->weight = weight;
};

int Edge::getVex1(){
    return this->vex1;
};

int Edge::getVex2(){
    return this->vex2;
};

int Edge::getWeight(){
    return this->weight;
};
