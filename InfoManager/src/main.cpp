// #include "config.hpp"
// #include "graph/cGraph.hpp"
// #include "view.hpp"
// #include "../include/mainwindow.hpp"
// int main(int argc, char *argv[]){
//     // Config* config = new Config("D://Code//C++//DataStructure//Graph//data//");
//     // CGraph* cgraph = new CGraph();

//     // View* view = new View(cgraph, config);
//     // view->main();
//     return 0;
// }

#include "../include/service/mainwindow.hpp"
#include "../include/graph/cGraph.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CGraph* cgraph = new CGraph();
    MainWindow w(cgraph);
    w.show();
    return a.exec();
}
