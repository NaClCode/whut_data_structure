#ifndef CREATE_H
#define CREATE_H

#include "../graph/cGraph.hpp"
#include <QWidget>
#include <vector>
#include <QListWidgetItem>
namespace Ui {
class Create;
}

using namespace std;
class Create : public QWidget
{
    Q_OBJECT

public:
    explicit Create(CGraph* graph, QWidget *parent = nullptr);
    ~Create();

private:
    Ui::Create *ui;
    CGraph* graph;
    vector<Vex> vexList;
    vector<Edge> edgeList;
    QListWidgetItem* vexItem = nullptr;
    QListWidgetItem* edgeItem = nullptr;

    void selectVexFile();
    void selectEdgeFile();

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};

#endif // CREATE_H
