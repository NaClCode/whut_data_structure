#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "setting.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr);
    void main();
    ~MainWindow();

private slots:
    void onDialValueChanged(int value);
private:
    Ui::MainWindow *ui;
    Setting setting;
    Game game;

    int flag = 0;
};
#endif // MAINWINDOW_H
