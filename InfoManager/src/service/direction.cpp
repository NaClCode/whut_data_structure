#include "../../include/service/direction.hpp"
#include "../../include/service/result.hpp"
#include "../../include/graph/path.hpp"
#include "ui_direct.h"
#include <qfiledialog.h>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>
#include <vector>
using namespace std;
Direction::Direction(CGraph* graph, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Direction), graph(graph)
{
    ui->setupUi(this);
    connect(ui->direct, &QPushButton::clicked, this, &Direction::main);
    connect(ui->exit, &QPushButton::clicked, this, &Direction::exit);

}

Direction::~Direction(){
    delete ui;
}

void Direction::exit(){
    emit exit_signal();
}

void Direction::main(){
    Result ret(this);

    QString listVex = this->ui->input->text();
    bool isNum = false;
    int num = listVex.toInt(&isNum);


    if(isNum){
        if(num >= graph->getVexNum() || num < 0){
            ret.QueryError();
        }else{
            vector<Path> pathlist;
            graph->DFSTraverse(num, pathlist);

            while(ui->path->count()>0)
                ui->path->takeItem(0);

            pathItem = new QListWidgetItem[pathlist.size()];

            for(int i = 0;(unsigned)i < pathlist.size();i ++){
                Vex vex;

                QString pathString = "";
                for(int j = 0;j < graph->getVexNum();j ++){
                    if(j == 0){
                        graph->getVex(pathlist[i].vexs[j], vex);
                        pathString += vex.getName();
                    }else{
                        graph->getVex(pathlist[i].vexs[j], vex);
                        pathString += "->" + vex.getName();
                    }
                }
                pathItem[i].setText(pathString);
                ui->path->addItem(pathItem + i);
            }

        }


    }else{
        ret.NumFormatError();
    }
}


void Direction::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    while(ui->vex->count()>0)
        ui->vex->takeItem(0);

    vexItem = new QListWidgetItem[graph->getVexNum()];
    Vex vex;
    for(int i = 0;i < graph->getVexNum();i ++){
        graph->getVex(i, vex);
        vexItem[i].setText(QString::number(i) + "-" + vex.getName());
        ui->vex->addItem(vexItem + i);
    }

}
