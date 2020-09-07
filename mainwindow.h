#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPalette>
#include "patient.h"
#include "doctor.h"
#include "bultrasound.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_registercheck_clicked();//点击挂号

    void on_searchcheck_clicked();//点击搜索医生的治疗记录

    void on_nextminute_clicked();//点击刷新时间（同步更新各诊室情况）

private:
    Ui::MainWindow *ui;
    void fresh();//界面刷新

    void initUI();
};
#endif // MAINWINDOW_H
