#ifndef DOCTOR_H
#define DOCTOR_H
#include "uidefine.h"

class doctor
{
public:
    doctor();
    int no;//医生编号
    int time;//当前病人诊疗所需剩余时间
    int current_patient;//当前检查病人的编号
};

#endif // DOCTOR_H
