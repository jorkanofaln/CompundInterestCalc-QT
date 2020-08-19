#include "compondcalc.h"

CompondCalc::CompondCalc(double p_interest,double p_value, double p_time):m_interest(p_interest),m_value(p_value),m_time(p_time){

}
double CompondCalc::calculateFutureValue(){
    double futureValue;
    futureValue = m_value * pow((1+m_interest),m_time);
    return futureValue;
}
double CompondCalc::calculatePresentValue(){
    double presentValue;
    presentValue = m_value / pow((1+m_interest),m_time);
    return presentValue;
}
