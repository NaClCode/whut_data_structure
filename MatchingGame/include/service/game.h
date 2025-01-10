#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "control.h"
#include "QPressLabel.h"
#include <QTimer>
#include <QMediaPlayer>
#include "setting.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE
class Game: public QWidget
{
    Q_OBJECT

public:
    Game(Setting* setting, QWidget *parent = nullptr);
    ~Game();
    void updateMap();

private:

    int pCount = 0;
    bool isPaused = false;
    bool isPlay = false;
    PressLabel** imageLabel;
    QTimer* timer;
    Ui::Game *ui;
    Control* control;
    QMediaPlayer *player;
    Setting* setting;

    void main(int x, int y, int value);
    QString getImage(int num);

    void updateProgressBar();
    void togglePause();
    void help();
    void play();
    void init();
    void showEvent(QShowEvent *event) override{
        QWidget::showEvent(event);
        init();
    }
private slots:
    void exit();

signals:
    void exit_signal();

};
#endif // GAME_H
