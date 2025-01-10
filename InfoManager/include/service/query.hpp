#ifndef QUERY_HPP
#define QUERY_HPP

#include "../graph/cGraph.hpp"
#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
    class Query;
}

class Query : public QWidget
{
    Q_OBJECT

public:
    explicit Query(CGraph* graph, QWidget *parent = nullptr);
    ~Query();

private:
    Ui::Query *ui;
    CGraph* graph;
    QListWidgetItem* vexItem = nullptr;
    QListWidgetItem* vexDesc = nullptr;
    QListWidgetItem* edgeItem = nullptr;

private slots:
    void main();
    void exit();

protected:
    void showEvent(QShowEvent *event);

signals:
    void exit_signal();
};

#endif // CREATE_H
