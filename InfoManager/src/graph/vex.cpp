#include "../../include/graph/vex.hpp"
#include <QString>
Vex::Vex(){
    this->name = "";
    this->desc = "";
    this->num = -1;
};

Vex::Vex(int num, QString name,QString desc){
    this->num = num;
    this->name = name;
    this->desc = desc;
};

void Vex::setVex(int num, QString name, QString desc){
    this->num = num;
    this->name = name;
    this->desc = desc;
};

int Vex::getNum(){
    return num;
};

QString Vex::getName(){
    return name;
};

QString Vex::getDesc(){
    return desc;
};

