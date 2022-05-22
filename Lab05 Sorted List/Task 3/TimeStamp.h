#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

class TimeStamp{

private :
    int hour;
    int minute;
    int second;
public :
    TimeStamp();
    void Initialize(int ,int ,int);
    int getHour();
    int getMinute();
    int getSecond();
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    bool operator==(TimeStamp);
    void print();

};

#endif // TIMESTAMP_H_INCLUDED
