#ifndef RESULT_H
#define RESULT_H
#include<QMessageBox>
#include<QWidget>
class Result{
private:
    QWidget *parant = nullptr;
public:
    Result(QWidget *parant):parant(parant){};

    void FileNameNull(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("未选择文件！"));
    };

    void FileError(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("文件打开失败！"));
    };

    void Create(){
        QMessageBox::information(parant, QMessageBox::tr("Success"), QMessageBox::tr("创造图成功"));
    }

    void CreateError(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("创建图失败！"));
    }

    void NumFormatError(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("请输入景点数字！"));
    }

    void QueryError(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("您输入的景点数字没有对应景点！"));
    }

    void LinkError(){
        QMessageBox::critical(parant, QMessageBox::tr("Error"), QMessageBox::tr("非连通图！"));
    }


};
#endif // RESULT_H
