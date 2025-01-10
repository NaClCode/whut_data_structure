#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../graph/cGraph.hpp"
#include "create.hpp"
#include "query.hpp"
#include "direction.hpp"
#include "shortest.hpp"
#include "planning.hpp"
class Create;
class Query;
class Direction;
class Shortest;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(CGraph* graph, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CGraph* graph;
    Create* create;
    Query* query;
    Direction* direct;
    Shortest* shortest;
    Planning* planning;
};
#endif // MAINWINDOW_H
