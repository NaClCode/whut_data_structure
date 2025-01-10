#ifndef EDGE_HPP
#define EDGE_HPP
class Edge{
private:
    int vex1, vex2, weight;
public:
    Edge(int vex1, int vex2, int weight);
    Edge();
    void setEdge(int vex1, int vex2, int weight);
    int getVex1();
    int getVex2();
    int getWeight();
};
#endif // EDGE_HPP
