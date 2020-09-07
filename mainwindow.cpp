#include "mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uidefine.h"
#include <QQueue>
#include <QDebug>
QQueue<patient> patient_queue[department_sum+1+1];
doctor doctor1[department_sum+1][4];
Bultrasound  bultrasound1[4];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //清空前一次运行产生的数据文件，每次打开软件均更新就诊记录
    QFile file(codedata_path);
    QString temp1;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Truncate))//打开指定文件
    {
        QMessageBox::about(NULL, "文件", "文件打开失败");
    }

    ui->setupUi(this);
    fresh();//运行前刷新界面
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//刷新界面
void MainWindow::fresh()
{
    ui->timedisplay->setText(QString::number(current_time));
    ui->a1->setText(QString::number(doctor1[1][1].time));
    ui->a2->setText(QString::number(doctor1[2][1].time));
    ui->a3->setText(QString::number(doctor1[3][1].time));
    ui->a4->setText(QString::number(doctor1[4][1].time));
    ui->a5->setText(QString::number(doctor1[5][1].time));
    ui->a6->setText(QString::number(doctor1[6][1].time));
    ui->a7->setText(QString::number(doctor1[7][1].time));
    ui->a8->setText(QString::number(doctor1[8][1].time));
    ui->a9->setText(QString::number(doctor1[9][1].time));
    ui->a10->setText(QString::number(doctor1[10][1].time));
    ui->a11->setText(QString::number(doctor1[11][1].time));
    ui->a12->setText(QString::number(doctor1[12][1].time));
    ui->a13->setText(QString::number(doctor1[13][1].time));
    ui->a14->setText(QString::number(doctor1[14][1].time));
    ui->a15->setText(QString::number(doctor1[15][1].time));
    ui->b1->setText(QString::number(doctor1[1][2].time));
    ui->b2->setText(QString::number(doctor1[2][2].time));
    ui->b3->setText(QString::number(doctor1[3][2].time));
    ui->b4->setText(QString::number(doctor1[4][2].time));
    ui->b5->setText(QString::number(doctor1[5][2].time));
    ui->b6->setText(QString::number(doctor1[6][2].time));
    ui->b7->setText(QString::number(doctor1[7][2].time));
    ui->b8->setText(QString::number(doctor1[8][2].time));
    ui->b9->setText(QString::number(doctor1[9][2].time));
    ui->b10->setText(QString::number(doctor1[10][2].time));
    ui->b11->setText(QString::number(doctor1[11][2].time));
    ui->b12->setText(QString::number(doctor1[12][2].time));
    ui->b13->setText(QString::number(doctor1[13][2].time));
    ui->b14->setText(QString::number(doctor1[14][2].time));
    ui->b15->setText(QString::number(doctor1[15][2].time));
    ui->c1->setText(QString::number(doctor1[1][3].time));
    ui->c2->setText(QString::number(doctor1[2][3].time));
    ui->c3->setText(QString::number(doctor1[3][3].time));
    ui->c4->setText(QString::number(doctor1[4][3].time));
    ui->c5->setText(QString::number(doctor1[5][3].time));
    ui->c6->setText(QString::number(doctor1[6][3].time));
    ui->c7->setText(QString::number(doctor1[7][3].time));
    ui->c8->setText(QString::number(doctor1[8][3].time));
    ui->c9->setText(QString::number(doctor1[9][3].time));
    ui->c10->setText(QString::number(doctor1[10][3].time));
    ui->c11->setText(QString::number(doctor1[11][3].time));
    ui->c12->setText(QString::number(doctor1[12][3].time));
    ui->c13->setText(QString::number(doctor1[13][3].time));
    ui->c14->setText(QString::number(doctor1[14][3].time));
    ui->c15->setText(QString::number(doctor1[15][3].time));
    ui->m1->setText(QString::number(bultrasound1[1].time));
    ui->m2->setText(QString::number(bultrasound1[2].time));
    ui->m3->setText(QString::number(bultrasound1[3].time));
    ui->remainnum1->setText(QString::number(patient_queue[1].size()));
    ui->remainnum2->setText(QString::number(patient_queue[2].size()));
    ui->remainnum3->setText(QString::number(patient_queue[3].size()));
    ui->remainnum4->setText(QString::number(patient_queue[4].size()));
    ui->remainnum5->setText(QString::number(patient_queue[5].size()));
    ui->remainnum6->setText(QString::number(patient_queue[6].size()));
    ui->remainnum7->setText(QString::number(patient_queue[7].size()));
    ui->remainnum8->setText(QString::number(patient_queue[8].size()));
    ui->remainnum9->setText(QString::number(patient_queue[9].size()));
    ui->remainnum10->setText(QString::number(patient_queue[10].size()));
    ui->remainnum11->setText(QString::number(patient_queue[11].size()));
    ui->remainnum12->setText(QString::number(patient_queue[12].size()));
    ui->remainnum13->setText(QString::number(patient_queue[13].size()));
    ui->remainnum14->setText(QString::number(patient_queue[14].size()));
    ui->remainnum15->setText(QString::number(patient_queue[15].size()));
    ui->remainnumbultra->setText(QString::number(patient_queue[16].size()));
}

void MainWindow::initUI()
{
    //设置标题
    this->setWindowTitle("医院就诊系统");
    //设置背景图片
    QPixmap background(backgroundpic_path);
    QPalette palette;
    palette.setBrush(QPalette::Background,background);
    this->setPalette(palette);
    //仅允许输入数字
    ui->registerroomid->setPlaceholderText("1-15的整形数字");
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->registerroomid);
    ui->registerroomid->setValidator( validator );
}
//点击挂号，并且自动分配患者编号，需要就诊时间，是否需要b超以及b超需要的时间
void MainWindow::on_registercheck_clicked()
{
    QString department_no=ui->registerroomid->text();
    //输入正确性判断
    if(department_no.isEmpty()||department_no.toInt()>15||department_no.toInt()<1)
    {

            QMessageBox::information(NULL, "错误提示", "请输入1-15内的整数",QMessageBox::Yes);
            return;
    }

    QFile file(codedata_path);
    //文件打开判断
    if (!file.open(QIODevice::Append|QIODevice::Text))//打开指定文件
    {
        QMessageBox::about(NULL, "文件", "文件打开失败");
    }
    //分配患者编号
    int department_no1=department_no.toInt();
    patient temp1(patient_no);
    ui->patientregisterid->setText(QString::number(patient_no));
    //判断科室中是否有医生当前无病人
    if(doctor1[department_no1][1].time==0)
    {
        doctor1[department_no1][1].time=temp1.visit_time;
        doctor1[department_no1][1].current_patient=patient_no;
        //打开医生对应的txt文件存储病人信息
        QString temp3;
        temp3='A'+department_no+' '+QString::number(patient_no)+' '+QString::number(temp1.visit_time)+"min\n";
        file.write(temp3.toUtf8());
    }
    else if(doctor1[department_no1][2].time==0)
    {
        doctor1[department_no1][2].time=temp1.visit_time;
        doctor1[department_no1][2].current_patient=patient_no;
        //打开医生对应的txt文件存储病人信息
        QString temp3;
        temp3='B'+department_no+' '+QString::number(patient_no)+' '+QString::number(temp1.visit_time)+"min\n";
        file.write(temp3.toUtf8());

    }
    else if(doctor1[department_no1][3].time==0)
    {
        doctor1[department_no1][3].time=temp1.visit_time;
        doctor1[department_no1][3].current_patient=patient_no;
        //打开医生对应的txt文件存储病人信息
        QString temp3;
        temp3='C'+department_no+' '+QString::number(patient_no)+' '+QString::number(temp1.visit_time)+"min\n";
        file.write(temp3.toUtf8());
    }
    else//无医生空闲
    {
        patient_queue[department_no1].enqueue(temp1);
    }
    fresh();
    patient_no++;
    file.close();//关闭文件
}

//点击查询医生就诊病人的情况（通过医生编号查找）
void MainWindow::on_searchcheck_clicked()
{
    QString doctor_searchid=ui->searchdoctorid->text();
    //输入错误判断
    if(doctor_searchid.isEmpty())
    {
         QMessageBox::information(NULL, "错误提示", "请输入医生编号（如A1,B3）必须大写",QMessageBox::Yes);
        return;
    }
    char* ch1;
    char* ch2;
    QByteArray ba1,ba2;
    ba1 = doctor_searchid.toLatin1();
    ch1=ba1.data();
    //打开数据文件查找
    QFile file(codedata_path);
    QString temp1;
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))//打开指定文件
    {
        QMessageBox::about(NULL, "文件", "文件打开失败");
    }
    QByteArray t;
    //逐行比对，通过医生编号查找
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        ba2 = str.toLatin1();
        ch2=ba2.data();
        //分为2位和3位的医生编号比对
        if((strlen(ch1)==2&&*ch1==*ch2&&*(ch1+1)==*(ch2+1)&&(*(ch2+2)==' '))||(strlen(ch1)==3&&*ch1==*ch2&&*(ch1+1)==*(ch2+1)&&*(ch1+2)==*(ch2+2)&&(*(ch2+3)==' ')))
        {
            qDebug()<< str;
            t.append(str);
        }
    }
    file.close();
    ui->searchresult->setText(t);
}

//切换时间（刷新医生，B超室和等候队列）
void MainWindow::on_nextminute_clicked()
{
    QFile file(codedata_path);
    //文件打开判断
    if (!file.open(QIODevice::Append|QIODevice::Text))//打开指定文件
    {
        QMessageBox::about(NULL, "文件", "文件打开失败");
    }
    patient temp_patient1(0),temp_patient2(0),temp_patient3(0);
    current_time++;
    //对每个医生当前的患者时间刷新，若有需要B超的进去B超队列，并且从对应科室排队队列中寻找下一个患者
    for(int temp1=1;temp1<=department_sum;temp1++)
    {
        for(int temp2=1;temp2<=3;temp2++)
        {
            if(doctor1[temp1][temp2].time>0)
            {
                doctor1[temp1][temp2].time--;
                //当前患者是否治疗完毕
                if(doctor1[temp1][temp2].time==0)
                {
                    temp_patient2.no=doctor1[temp1][temp2].current_patient;
                    temp_patient2.bultra_distribute();
                    //是否需要B超治疗
                    if(temp_patient2.bultra_time>0)
                    {
                        patient_queue[department_sum+1].enqueue(temp_patient2);
                    }
                    //科室等待队列中是否有人
                    if(patient_queue[temp1].size()>0)
                    {
                        temp_patient1=patient_queue[temp1].dequeue();
                        QString temp3;
                        if(temp2==1)
                            temp3='A'+QString::number(temp1)+' '+QString::number(temp_patient1.no)+' '+QString::number(temp_patient1.visit_time)+"min\n";
                        else if(temp2==2)
                            temp3='B'+QString::number(temp1)+' '+QString::number(temp_patient1.no)+' '+QString::number(temp_patient1.visit_time)+"min\n";
                        else
                            temp3='C'+QString::number(temp1)+' '+QString::number(temp_patient1.no)+' '+QString::number(temp_patient1.visit_time)+"min\n";
                        file.write(temp3.toUtf8());
                        doctor1[temp1][temp2].time=temp_patient1.visit_time;
                        doctor1[temp1][temp2].current_patient=temp_patient1.no;
                    }

                }
            }
        }
    }
    //b超室时间刷新，判断是否检查完毕
    for(int temp1=1;temp1<=3;temp1++)
    {
        //B超室原先有人时的处理
        if(bultrasound1[temp1].time>0)
        {
            bultrasound1[temp1].time--;
            //判断b超是否检查完毕
            if(bultrasound1[temp1].time==0)
            {
                //判断检查等待队列是否有人
                if(patient_queue[department_sum+1].size()>0)
                {
                    temp_patient3=patient_queue[department_sum+1].dequeue();
                    bultrasound1[temp1].time=temp_patient3.bultra_time;
                }

            }
        }
        //当原先B超室没人时进行等待队列判断
        if(bultrasound1[temp1].time==0)
        {
            if(patient_queue[department_sum+1].size()>0)
            {
                temp_patient3=patient_queue[department_sum+1].dequeue();
                bultrasound1[temp1].time=temp_patient3.bultra_time;
            }

        }
    }
    fresh();//操作完毕，刷新界面
    file.close();//关闭文件
}
