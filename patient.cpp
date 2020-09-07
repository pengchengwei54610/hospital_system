#include "patient.h"

patient::patient(int no1)
{
    no=no1;
    visit_time=rand()%max_doctor_time+1;//随机就诊时间(+1避免0时间）   
}

void patient::bultra_distribute()
{
    bultra_time=rand()%max_bultra_time;//随机B超时间（有可能不需要B超检查所以不+1）
}

