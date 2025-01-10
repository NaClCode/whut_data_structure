#include "../../include/service/mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QDial>
#include <QPushButton>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
        game(&setting),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dial->setSliderPosition(0);
    ui->dial->setRange(0, 360);
    ui->dial->setValue(180);
    connect(ui->dial, &QDial::valueChanged, this, &MainWindow::onDialValueChanged);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::main);
    connect(ui->setting, &QPushButton::clicked, this, [=](){this->setHidden(true);setting.show();});
    connect(ui->helping, &QPushButton::clicked, this, [=](){QMessageBox::information(nullptr, "帮助", "有问题联系开发者");});
    connect(&game, &Game::exit_signal, [=](){game.setHidden(true);this->show();});
    connect(&setting, &Setting::exit_signal, [=](){setting.setHidden(true);this->show();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::main(){
    switch(flag){
    case 0:
        this->setHidden(true);
        game.show();
        break;
    }
}

void MainWindow::onDialValueChanged(int value) {

    QPalette basePalette = ui->base->palette();
    QPalette leisurePalette = ui->leisure->palette();
    QPalette rankingPalette = ui->ranking->palette();
    QPalette levelPalette = ui->level->palette();
    if(value >= 135 && value < 225){
        flag = 0;
        basePalette.setColor(QPalette::WindowText, Qt::gray);
        ui->base->setPalette(basePalette);

        leisurePalette.setColor(QPalette::WindowText, Qt::black);
        ui->leisure->setPalette(leisurePalette);

        rankingPalette.setColor(QPalette::WindowText, Qt::black);
        ui->ranking->setPalette(rankingPalette);

        levelPalette.setColor(QPalette::WindowText, Qt::black);
        ui->level->setPalette(levelPalette);

    }else if(value >= 225 && value < 315){
        flag = 1;
        basePalette.setColor(QPalette::WindowText, Qt::black);
        ui->base->setPalette(basePalette);

        leisurePalette.setColor(QPalette::WindowText, Qt::gray);
        ui->leisure->setPalette(leisurePalette);

        rankingPalette.setColor(QPalette::WindowText, Qt::black);
        ui->ranking->setPalette(rankingPalette);

        levelPalette.setColor(QPalette::WindowText, Qt::black);
        ui->level->setPalette(levelPalette);
    }else if(value >= 45 && value < 135){
        flag = 2;
        basePalette.setColor(QPalette::WindowText, Qt::black);
        ui->base->setPalette(basePalette);

        leisurePalette.setColor(QPalette::WindowText, Qt::black);
        ui->leisure->setPalette(leisurePalette);

        rankingPalette.setColor(QPalette::WindowText, Qt::black);
        ui->ranking->setPalette(rankingPalette);

        levelPalette.setColor(QPalette::WindowText, Qt::gray);
        ui->level->setPalette(levelPalette);
    }else{
        flag = 3;
        basePalette.setColor(QPalette::WindowText, Qt::black);
        ui->base->setPalette(basePalette);

        leisurePalette.setColor(QPalette::WindowText, Qt::black);
        ui->leisure->setPalette(leisurePalette);

        rankingPalette.setColor(QPalette::WindowText, Qt::gray);
        ui->ranking->setPalette(rankingPalette);

        levelPalette.setColor(QPalette::WindowText, Qt::black);
        ui->level->setPalette(levelPalette);
    }
}
