#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "graph/cGraph.hpp"
using namespace std;
class View{
private:
    CGraph* graph;
    Config* config;
    int nSelection;
public:
    View(CGraph* graph, Config* config);
    void main();
    void creat();
    void query();

};
#endif