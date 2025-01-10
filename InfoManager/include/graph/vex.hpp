#ifndef VEX_H
#define VEX_H
#include <QString>
class Vex{
private:
    int num;
    QString name;
    QString desc;
public:
    Vex();
    Vex(int num, QString name, QString desc);
    void setVex(int num, QString name, QString desc);
    int getNum();
    QString getName();
    QString getDesc();
};

#endif // EDGE_H
