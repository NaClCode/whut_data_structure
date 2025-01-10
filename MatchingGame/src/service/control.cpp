#include "../../include/service/control.h"
#include <QRandomGenerator>
#include <QPushButton>
#include <QList>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
void Control::startGame(){
    this->logic->initMap();
};

int Control::getElement(int row, int col){
    return logic->getMap()->getVex(row * MAX_COL + col);
};

void Control::setFirstPoint(int row, int col){
    p1.set(row, col, -1);
};
void Control::setSecPoint(int row, int col){
    p2.set(row, col, -1);
}

bool Control::link(QVector<Point>& avPath){
    if(p1.getX() == p2.getX() && p1.getY() == p2.getY()){
        return false;
    }
    // 判断图片是否相同，如果不同则不能连通
    int nInfo1 = logic->getMap()->getVex(p1.getX() * MAX_COL + p1.getY());
    int nInfo2 = logic->getMap()->getVex(p2.getX() * MAX_COL + p2.getY());

    if (nInfo1 != nInfo2 || nInfo1 == BLANK || nInfo2 == BLANK)
    {
        return false;
    }

    logic->clearStack();
    if (logic->isLink(p1, p2))
    {

        // 消子
        logic->clear(p1, p2);

        // 返回路径顶点
        logic->getVexPath(avPath);

        return true;
    }
    return false;
};

int Control::isWin(int nTime){
    // 判断游戏时间
    if (nTime <= 0)
    {
        // 清除图
        logic->getMap()->initGraph();
        return GAME_LOSE;
    }

    // 判断是否图中所有点为空
    if (logic->isBlank() == true)
    {
        // 清除图
        logic->getMap()->initGraph();
        return GAME_SUCCESS;
    }
    return GAME_PLAY;
}


bool Control::help(QVector<Point>& avPath){
    // 判断是否为空
    logic->clearStack();
    if (logic->isBlank() == true)
    {
        return false;
    }

    // 查找一条有效的提示路径
    if (logic->searchValidPath())
    {
        logic->getVexPath(avPath);
        return true;
    }
    return false;
};

void Control::reset(){
    logic->resetGraph();
};

Control::Control(GameLogic* logic){
    this->logic = logic;
};

// Game::Game(Map* map, QWidget *parent)
//     : QWidget(parent),
//     ui(new Ui::Game),
//     logic(new GameLogic(map))
// {
//     ui->setupUi(this);


//     // 初始化定时器
//     timer = new QTimer(this);
//     connect(timer, &QTimer::timeout, this, &Game::updateProgress);
//     remainingTime = totalTime  = 200000; // 总时间为10秒
//     ui->progressBar->setMaximum(totalTime);
//     ui->progressBar->setValue(remainingTime);
//     // 开始计时
//     timer->start(100); // 每100毫秒更新一次进度条

//     p1_flag = p2_flag = false;
//     map->initMap(12, 12, 8);
//     // 随机分配图片到网格布局中
//     mapLabel = new PressLabel**[logic->getMapRow()];
//     for (int row = 0; row < logic->getMapCol(); ++row) {
//         mapLabel[row] = new PressLabel*[logic->getMapCol()];
//         for (int col = 0; col < logic->getMapRow(); ++col) {

//             PressLabel *imageLabel = new PressLabel(row, col, logic->getMapNum(row, col));

//             QPixmap pixmap(getImage(logic->getMapNum(row, col)));
//             QPixmap scaledPixmap = pixmap.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 将图片缩放到 50x50 像素
//             imageLabel->setPixmap(scaledPixmap);
//             ui->qgridLayout->addWidget(imageLabel, row, col);
//             connect(imageLabel, &PressLabel::clickedWithCoordinates,  [=](int x, int y, int value){main(x, y, value);});
//             mapLabel[row][col] = imageLabel;
//         }
//     }



//     // 设置主布局
//     this->setLayout(ui->mainLayout);

// }

// void Game::updateProgress(){
//     remainingTime -= 100; // 减去100毫秒
//         if (remainingTime <= 0) {
//             timer->stop(); // 时间到，停止计时
//             ui->progressBar->setValue(0);
//             QMessageBox::information(this, "游戏结束", "游戏结束，请重新开始");
//             // 在这里添加时间到的提示或其他操作
//         } else {
//             ui->progressBar->setValue(remainingTime);
//         }
// }

// Game::~Game(){
//     delete ui;
// };

// void Control::exit(){
//     emit exit_signal();
// };


