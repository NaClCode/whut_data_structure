#ifndef SETTING_H
#define SETTING_H
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class Setting;
}
QT_END_NAMESPACE
class Setting : public QWidget
{
    Q_OBJECT

public:
    Setting( QWidget *parent = nullptr);
    void file();
    void time();
    QString getFileName();
    int getTime();
    ~Setting();

private:
    Ui::Setting *ui;
    QString fileName;
    int value;
    void exit();


signals:
    void exit_signal();

};
#endif // SETTING_H
