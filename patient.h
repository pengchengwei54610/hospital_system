#ifndef PATIENT_H
#define PATIENT_H

#include "uidefine.h"
class patient
{
public:
    patient(int no);
    int no;//病人编号
    int visit_time;//需要诊疗时长（每个患者固定不会改变）
    int bultra_time;//需要B超时长（每个患者固定不会改变）
    void bultra_distribute();//诊疗结束后分配B超时长（可能为0）
};

#endif // PATIENT_H

