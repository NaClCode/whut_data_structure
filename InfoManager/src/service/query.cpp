#include "../../include/service/query.hpp"
#include "../../include/service/result.hpp"
#include "ui_query.h"
Query::Query(CGraph* graph, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Query), graph(graph)
{
    ui->setupUi(this);
    connect(ui->query, &QPushButton::clicked, this, &Query::main);
    connect(ui->queryexit, &QPushButton::clicked, this, &Query::exit);
}

Query::~Query(){
    delete ui;
}

void Query::exit(){
    emit exit_signal();
}

void Query::main(){
    Result ret(this);

    QString listVex = this->ui->lineEdit->text();
    bool isNum = false;
    int num = listVex.toInt(&isNum);

    if(isNum){
        Edge edge[N];
        Vex vex, vex1, vex2;
        if(num >= graph->getVexNum() || num < 0){
            ret.QueryError();
        }else{
            while(ui->edge->count()>0)
                ui->edge->takeItem(0);

            while(ui->vex->count()>0)
                ui->vex->takeItem(0);

            int findLen = graph->findEdge(num, edge);
            edgeItem= new QListWidgetItem[findLen];
            for(int i = 0;i < findLen;i ++){
                graph->getVex(edge[i].getVex1(), vex1);
                graph->getVex(edge[i].getVex2(), vex2);
                edgeItem[i].setText(vex1.getName() + "->" + vex2.getName() + " " + QString::number(edge[i].getWeight()) + "m");
                ui->edge->addItem(edgeItem + i);
            }

            graph->getVex(num, vex);
            vexDesc = new QListWidgetItem();
            vexDesc->setText(vex.getDesc());
            ui->vex->addItem(vexDesc);
        }

    }else{
        ret.NumFormatError();
    }
}

void Query::showEvent(QShowEvent *event) {
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
