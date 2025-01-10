#include "../../include/service/setting.h"
#include "ui_setting.h"
#include <QWidget>
#include <QDial>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
Setting::Setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Setting)
{
    ui->setupUi(this);
    ui->time->setRange(0, 600);
    connect(ui->file, &QPushButton::clicked, this, &Setting::file);
    value = 600;
    connect(ui->time, &QScrollBar::valueChanged, [&](int value) {
        ui->timeLabel->setText(QString::number(value) + "s");
        this->value = value;
    });
    fileName = "D://Code//C++//DataStructure//MatchingGame//Shanghai.mp3";
    connect(ui->exit, &QPushButton::clicked, this, &Setting::exit);

}

Setting::~Setting()
{
    delete ui;
}


void Setting::file(){
    fileName = QFileDialog::getOpenFileName(this, "Open File", "D://Code//C++//DataStructure//MatchingGame//Shanghai.mp3", "All Files (*)");
}

QString Setting::getFileName(){
    return fileName;
}

int Setting::getTime(){
    return value;
}

void Setting::exit(){
    emit exit_signal();
}
