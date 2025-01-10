#include "../../include/service/planning.hpp"
#include "../../include/service/result.hpp"
#include "ui_planning.h"
Planning::Planning(CGraph* graph, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Planning), graph(graph)
{
    ui->setupUi(this);
    connect(ui->main, &QPushButton::clicked, this, &Planning::main);
    connect(ui->exit, &QPushButton::clicked, this, &Planning::exit);
}

Planning::~Planning(){
    delete ui;
}

void Planning::exit(){
    emit exit_signal();
}

void Planning::main(){
    Result ret(this);
    Edge edge[graph->getVexNum() - 1];

    if(graph->getVexNum() >= 1){
        bool isLink = graph->findMinTree(edge);
        PlanningItem = new QListWidgetItem[graph->getVexNum()];
        int total = 0;
        if(isLink){
            Vex vex1, vex2;
            while(ui->path->count()>0)
                ui->path->takeItem(0);
            for(int i = 0;i < graph->getVexNum() - 1;i ++){
                graph->getVex(edge[i].getVex1(), vex1);
                graph->getVex(edge[i].getVex2(), vex2);
                PlanningItem[i].setText(vex1.getName() + "->" + vex2.getName() + ":" + QString::number(edge[i].getWeight()));
                ui->path->addItem(PlanningItem + i);
                total += edge[i].getWeight();
            }
            PlanningItem[graph->getVexNum() - 1].setText("Total:" + QString::number(total));
            ui->path->addItem(PlanningItem + graph->getVexNum() - 1);
        }else{
            ret.LinkError();
        }
    }else{
        ret.LinkError();
    }


}

void Planning::showEvent(QShowEvent *event) {
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
