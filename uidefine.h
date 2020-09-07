#ifndef UIDEFINE_H
#define UIDEFINE_H

#include<QFile>
#include<QFileDialog>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtWidgets/QMessageBox>
#include <QWidget>
#include <QFile>
#include <QTextBrowser>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QIntValidator>

#define backgroundpic_path ":/ico/resource/background.png"//背景图片路径

#define codedata_path "../hospital/doctor_information.txt"//QT编译运行时使用的路径（注意此处hospital为QT代码的文件夹名，若需更改文件夹名此处需同步更改）
//#define codedata_path "doctor_information.txt"//运行exe版本时若数据文件与exe在同目录下可更改为此

#define max_doctor_time 3//最长就诊时间，用以取随机值
#define max_bultra_time 3//最长B超时间，用以取随机值

#define department_sum 15//科室数目

extern int current_time;//全局变量：当前经过时间
extern int patient_no;//全局变量：当前分配的患者编号

#endif // UIDEFINE_H
