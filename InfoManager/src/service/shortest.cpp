#include "../../include/service/shortest.hpp"
#include "../../include/service/result.hpp"
#include "ui_shortest.h"
Shortest::Shortest(CGraph* graph, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Shortest), graph(graph)
{
    ui->setupUi(this);
    connect(ui->shortest, &QPushButton::clicked, this, &Shortest::main);
    connect(ui->exit, &QPushButton::clicked, this, &Shortest::exit);
}

Shortest::~Shortest(){
    delete ui;
}

void Shortest::exit(){
    emit exit_signal();
}

void Shortest::main(){
    Result ret(this);

    QString start = this->ui->start->text();
    QString end = this->ui->end->text();

    bool startIsNum = false;
    bool endIsNum = false;
    int startNum = start.toInt(&startIsNum);
    int endNum = end.toInt(&endIsNum);
    int path[21];
    memset(path, -1, sizeof(path));

    if(startIsNum && endIsNum){
        if((startIsNum >= graph->getVexNum() || startIsNum < 0) || (endIsNum >= graph->getVexNum() || endIsNum < 0)){
            ret.QueryError();
        }else{
            graph->findShortPath(startNum, endNum, path);
            Vex vex;
            QString shortestPath = "";

            while(ui->path->count()>0)
                ui->path->takeItem(0);

            for(int i = 0;path[i] != -1; i++){
                qDebug() << path[i];
                graph->getVex(path[i], vex);
                if(i == 0) shortestPath += vex.getName();
                else shortestPath += "->" + vex.getName();
            }

            this->shortestItem = new QListWidgetItem[1];
            this->shortestItem->setText(shortestPath);
            ui->path->addItem(shortestItem);
        }
    }else{
        ret.NumFormatError();
    }
}

void Shortest::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    while(ui->list->count()>0)
        ui->list->takeItem(0);

    vexItem = new QListWidgetItem[graph->getVexNum()];
    Vex vex;
    for(int i = 0;i < graph->getVexNum();i ++){
        graph->getVex(i, vex);
        vexItem[i].setText(QString::number(i) + "-" + vex.getName());
        ui->list->addItem(vexItem + i);
    }

}
