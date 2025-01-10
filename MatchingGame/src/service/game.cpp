#include "ui_game.h"
#include "QMessageBox"
#include "../../include/service/game.h"
#include "../../include/service/setting.h"
#include <QAudioOutput>
Game::Game(Setting* setting, QWidget *parent): QWidget(parent), ui(new Ui::Game), setting(setting){
    ui->setupUi(this);
    control = new Control(new GameLogic(new CGraph));
    this->control->startGame();

    player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(setting->getFileName());
    imageLabel = new PressLabel*[MAX_ROW];
    for(int i = 0;i < MAX_ROW; i++){
        imageLabel[i] = new PressLabel[MAX_COL];
    }


    // 设置计时器
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Game::updateProgressBar);
    connect(ui->stop, &QPushButton::clicked, this, &Game::togglePause);
    connect(ui->help, &QPushButton::clicked, this, &Game::help);
    connect(ui->play, &QPushButton::clicked, this, &Game::play);
    connect(ui->exit, &QPushButton::clicked, this, &Game::exit);
    for(int i = 0;i < MAX_ROW; i ++){
        for(int j = 0;j < MAX_COL; j++){
            connect(&imageLabel[i][j], &PressLabel::clickedWithCoordinates,  [=](int x, int y, int value){main(x, y, value);});
        }
    }

    init();
};

void Game::init(){
    player->setSource(QUrl::fromLocalFile(setting->getFileName()));
    this->control->reset();
    updateMap();
    ui->progressBar->setRange(0, setting->getTime());  // 10分钟，以秒为单位计数
    ui->progressBar->setValue(setting->getTime());     // 开始值设置为10分钟
    timer->start(1000);  // 每秒更新一次
}

void Game::help(){
    QVector<Point> path;
    if (control->help(path)){
        qDebug() << path[0].getX() << path[0].getY();
        qDebug() << path[path.size() - 1].getX() << path[path.size() - 1].getY();
        qDebug() << path.size();
        imageLabel[path[0].getY()][path[0].getX()].linkShow();
        imageLabel[path[path.size() - 1].getY()][path[path.size() - 1].getX()].linkShow();
    }else{
        QMessageBox::information(nullptr, "失败", "帮助失败");
    }
}

Game::~Game(){
    delete ui;
};

void Game::updateProgressBar()
{
    if(!isPaused){
        int currentValue = ui->progressBar->value();
        int flag = control->isWin(currentValue);

        if(flag == GAME_SUCCESS){
            QMessageBox::information(nullptr, "成功", "恭喜你赢了");
            timer->stop();  // 停止计时器
            emit exit_signal();
        }else if(flag == GAME_LOSE){
            QMessageBox::information(nullptr, "失败", "再来一次");
            timer->stop();  // 停止计时器
            emit exit_signal();
        }else if(flag == GAME_PLAY){
            ui->progressBar->setValue(currentValue - 1);
        }
    }

}

void Game::togglePause()
{
    if (isPaused) {
        QMessageBox::information(nullptr, "继续", "继续游戏");
        isPaused = false;
    } else {

        QMessageBox::information(nullptr, "停止", "停止游戏");
        isPaused = true;
    }
}

void Game::updateMap(){
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            int nElemVal = control->getElement(i, j);
            imageLabel[i][j].setPressLabel(i, j, nElemVal);

            QPixmap pixmap(getImage(nElemVal));
            QPixmap scaledPixmap = pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 将图片缩放到 50x50 像素
            imageLabel[i][j].setPixmap(scaledPixmap);
            ui->gridLayout->addWidget(&imageLabel[i][j], i, j);

        }
    }
};

void Game::main(int x, int y, int value){
    if(pCount == 0) {
        control->setFirstPoint(x, y);
        pCount += 1;
    }else if(pCount == 1){
        control->setSecPoint(x, y);
        pCount = 0;
        QVector<Point> path;

        if(control->link(path)){
            updateMap();
        }

    }
};

void Game::play(){
    if(!isPlay){
        isPlay = true;
        qDebug() << 1;
        player->play();

    }else{
        isPlay = false;
        player->stop();
    }
}

void Game::exit(){
    player->stop();
    emit exit_signal();
}

QString Game::getImage(int num){
    QString imagePath;
    switch(num){
    case 0:
        imagePath = ":/images/image/claude.png";
        break;
    case 1:
        imagePath = ":/images/image/gemini.png";
        break;
    case 2:
        imagePath = ":/images/image/github.png";
        break;
    case 3:
        imagePath = ":/images/image/glm.png";
        break;
    case 4:
        imagePath = ":/images/image/gpt.png";
        break;
    case 5:
        imagePath = ":/images/image/huggingface.png";
        break;
    case 6:
        imagePath = ":/images/image/tongyi.png";
        break;
    case 7:
        imagePath = ":/images/image/wenxin.png";
        break;
    case 8:
        imagePath = ":/images/image/wenxin.png";
        break;
    case 9:
        imagePath = ":/images/image/xinhuo.png";
        break;
    default:
        imagePath = "";
        break;
    }
    return imagePath;
};
