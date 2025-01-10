#include "../../include/service/mainwindow.hpp"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(CGraph* cgraph, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    graph(cgraph),
    create(new Create(cgraph)),
    query(new Query(cgraph)),
    direct(new Direction(cgraph)),
    shortest(new Shortest(cgraph)),
    planning(new Planning(cgraph))
{
    ui->setupUi(this);
    connect(ui->create, &QPushButton::pressed, [=](){this->setHidden(true); create->show();});
    connect(create, &Create::exit_signal, [=](){create->setHidden(true);this->show();});

    connect(ui->query, &QPushButton::pressed, [=](){this->setHidden(true); query->show();});
    connect(query, &Query::exit_signal, [=](){query->setHidden(true);this->show();});

    connect(ui->direct, &QPushButton::pressed, [=](){this->setHidden(true); direct->show();});
    connect(direct, &Direction::exit_signal, [=](){direct->setHidden(true);this->show();});

    connect(ui->shortest, &QPushButton::pressed, [=](){this->setHidden(true); shortest->show();});
    connect(shortest, &Shortest::exit_signal, [=](){shortest->setHidden(true);this->show();});

    connect(ui->planning, &QPushButton::pressed, [=](){this->setHidden(true); planning->show();});
    connect(planning, &Planning::exit_signal, [=](){planning->setHidden(true);this->show();});

    connect(ui->exit, &QPushButton::pressed, [=](){this->setHidden(true);});
}


MainWindow::~MainWindow()
{
    delete ui;
}



