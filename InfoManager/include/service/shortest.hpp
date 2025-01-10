#ifndef SHORTEST_HPP
#define SHORTEST_HPP

#include "../graph/cGraph.hpp"
#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class  Shortest;
}

class Shortest : public QWidget
{
    Q_OBJECT

public:
    explicit Shortest(CGraph* graph, QWidget *parent = nullptr);
    ~Shortest();

private:
    Ui::Shortest *ui;
    CGraph* graph;
    QListWidgetItem* vexItem = nullptr;
    QListWidgetItem* shortestItem = nullptr;

private slots:
    void main();
    void exit();


protected:
    void showEvent(QShowEvent *event);

signals:
    void exit_signal();
};

#endif // SHORTEST_HPP
