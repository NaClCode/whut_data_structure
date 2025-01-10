#include "../../include/service/create.hpp"
#include "../../include/service/result.hpp"
#include "ui_create.h"
#include <qfiledialog.h>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>
Create::Create(CGraph* graph, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Create), graph(graph)
{
    ui->setupUi(this);
    connect(ui->accept, &QPushButton::clicked, this, &Create::main);
    connect(ui->exit, &QPushButton::clicked, this, &Create::exit);
    connect(ui->vexfile, &QPushButton::clicked, this, &Create::selectVexFile);
    connect(ui->edgefile, &QPushButton::clicked, this, &Create::selectEdgeFile);

}

Create::~Create(){
    delete ui;
}

void Create::exit(){
    emit exit_signal();
}

void Create::main(){
    Result ret(this);
    if(vexList.size() > 0 && edgeList.size() > 0){
        graph->init();
        for(Vex _: vexList){
            graph->insertVex(_);
        }

        for(Edge _: edgeList){
            graph->insertEdge(_);
        }
        ret.Create();
    }else{
        ret.CreateError();
    }

    this->exit();
}

void Create::selectVexFile(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "D:\\Code\\C++\\DataStructure\\InfoManager\\data\\vex.txt", "All Files (*)");
    Result ret(this);
    if (!fileName.isEmpty()) {     
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ret.FileError();
            return;
        } else {
            while(ui->vex->count()>0)
                ui->vex->takeItem(0);
            QTextStream in(&file);
            in.setEncoding(QStringConverter::System);

            int vex, num;
            QString name, desc;
            in >> vex;
            vexList.erase(vexList.begin(), vexList.end());
            vexItem = new QListWidgetItem[vex];

            for(int i = 0; i < vex; ++i) {
                in >> num;
                in >> name;
                in >> desc;
                Vex vex(num, name, desc);
                QString itemStr = QString::number(i) + "-" + name;

                vexItem[i].setText(itemStr);
                ui->vex->addItem(vexItem + i);
                vexList.push_back(vex);
            }
        }

    }else{
        ret.FileNameNull();
    }
}

void Create::selectEdgeFile(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "D:\\Code\\C++\\DataStructure\\InfoManager\\data\\edge.txt", "All Files (*)");
    Result ret(this);
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ret.FileError();
            return;
        } else {
            while(ui->edge->count()>0)
                ui->edge->takeItem(0);

            QTextStream in(&file);
            in.setEncoding(QStringConverter::System);

            edgeList.erase(edgeList.begin(), edgeList.end());

            int vex1, vex2, weight;
            while(!in.atEnd()){
                in >> vex1 >> vex2 >> weight;
                Edge edge(vex1, vex2, weight);
                edgeList.push_back(edge);
            }

            edgeItem = new QListWidgetItem[edgeList.size()];
            for(int i = 0; (unsigned)i < edgeList.size(); i++){
                QString itemStr = "<" + QString::number(edgeList.at(i).getVex1()) + ", " + QString::number(edgeList.at(i).getVex2()) + ">: " + QString::number(edgeList.at(i).getWeight());
                edgeItem[i].setText(itemStr);
                ui->edge->addItem(edgeItem + i);
            }

        }

    }else{

        ret.FileNameNull();
    }
}
