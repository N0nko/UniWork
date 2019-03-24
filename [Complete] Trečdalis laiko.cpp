#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

class Time
{
public:
    int h,m,s;
};

class TimeUtil
{
public:
    Time calcOneThird(Time time)
    {
        Time newTime;
        int total = time.s + time.m*60+ time.h*60*60;
        total /= 3;
        newTime.h = total/3600;
        newTime.m = (total - newTime.h*60*60)/60;
        newTime.s = total - newTime.h*3600 - newTime.m*60;
        return newTime;
    }
};

int main()
{
    int n;
    Time startInput;
    cin >> n;
    cin >> startInput.h;
    cin >> startInput.m;
    cin >> startInput.s;

    list<Time> times;


    TimeUtil timeCalc;
    for (int i = 0; i < n; i++)
    {
        Time newTime = timeCalc.calcOneThird(startInput);
        startInput = newTime;
        //cout << newTime.h << " " << newTime.m << " " << newTime.s;
        times.push_back(newTime);
    }
    for (Time time : times)
    {
        cout << setfill('0') << setw(2) << time.h << ":"<< setfill('0') << setw(2) << time.m << ":" << setfill('0') << setw(2) <<time.s<< endl;

    }

}