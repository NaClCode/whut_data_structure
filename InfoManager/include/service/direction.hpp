#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include "../graph/cGraph.hpp"
#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class Direction;
}

class Direction : public QWidget
{
    Q_OBJECT

public:
    explicit Direction(CGraph* graph, QWidget *parent = nullptr);
    ~Direction();

private:
    Ui::Direction *ui;
    CGraph* graph;
    QListWidgetItem* vexItem = nullptr;
    QListWidgetItem* pathItem = nullptr;

private slots:
    void main();
    void exit();


protected:
    void showEvent(QShowEvent *event);

signals:
    void exit_signal();
};

#endif // DIRECTION_HPP
