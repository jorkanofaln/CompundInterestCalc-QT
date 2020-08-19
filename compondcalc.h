#ifndef COMPONDCALC_H
#define COMPONDCALC_H
#include "math.h"

class CompondCalc
{
public:
    CompondCalc(double p_interest,double p_value, double p_time);
    double calculatePresentValue();
    double calculateFutureValue();
private:
    double m_interest;
    double m_value;
    double m_time;
};

#endif // COMPONDCALC_H
