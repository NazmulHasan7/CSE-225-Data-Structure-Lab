#include "TimeStamp.h"
#include <iostream>

using namespace std;

TimeStamp::TimeStamp()
{
    hour = minute = second = 0;
}
void TimeStamp::Initialize(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
int TimeStamp::getHour()
{
    return hour;
}
int TimeStamp::getMinute()
{
    return minute;
}
int TimeStamp::getSecond()
{
    return second;
}
void TimeStamp::setHour(int h)
{
    hour = h;
}
void TimeStamp::setMinute(int m)
{
    minute = m;
}
void TimeStamp::setSecond(int s)
{
    second = s;
}
bool TimeStamp::operator ==(TimeStamp tm)
{
    if(hour == tm.hour && minute == tm.minute && second == tm.second)
        return true;
    else
        return false;
}
void TimeStamp::print()
{
    cout <<"Hour : "<<hour<<" Minute : "<<minute<<" Second : "<<second<<endl;
}
