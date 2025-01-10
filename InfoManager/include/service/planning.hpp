#ifndef PLANNING_HPP
#define PLANNING_HPP

#include "../graph/cGraph.hpp"
#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class  Planning;
}

class Planning : public QWidget
{
    Q_OBJECT

public:
    explicit Planning(CGraph* graph, QWidget *parent = nullptr);
    ~Planning();

private:
    Ui::Planning *ui;
    CGraph* graph;
    QListWidgetItem* vexItem = nullptr;
    QListWidgetItem* PlanningItem = nullptr;

private slots:
    void main();
    void exit();


protected:
    void showEvent(QShowEvent *event);

signals:
    void exit_signal();
};

#endif // PLANNING_HPP
