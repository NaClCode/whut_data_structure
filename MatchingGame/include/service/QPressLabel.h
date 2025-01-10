#ifndef QPRESSLABEL_H
#define QPRESSLABEL_H
#include <QLabel>
#include <QMouseEvent>
class PressLabel : public QLabel {
    Q_OBJECT

private:
    int x, y, pressFlag, value, linkFlag;
public:
    explicit PressLabel(QWidget *parent = nullptr) : QLabel(parent) {
        this->x = -1;
        this->y = -1;
        this->pressFlag = 1;
        this->linkFlag = 1;
        this->value = -1;
        this->setStyleSheet("");
    };

    void pressed(){
        if(pressFlag){
            this->setStyleSheet("QLabel { border: 1px solid red; }");
            pressFlag = 0;
        }else{
            this->setStyleSheet("");
            pressFlag = 1;
        }
    }

    void setPressLabel(int x, int y, int value){
        this->x = x;
        this->y = y;
        this->pressFlag = 1;
        this->linkFlag = 1;
        this->value = value;
        this->setStyleSheet("");
    }

    void linkShow(){
        if(linkFlag){
            this->setStyleSheet("QLabel { border: 1px solid green; }");
            linkFlag = 0;
        }else{
            this->setStyleSheet("");
            linkFlag = 1;
        }
    }

signals:
    void clickedWithCoordinates(int x, int y, int value);

protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // QPRESSLABEL_H
