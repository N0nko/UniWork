#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Time
{
  private:
    long long hh, mm, ss;

  public:
    double getTDiff(Time *anotherTime)
    {
        double timeDifference = (hh * 3600 + mm * 60 + ss) - (anotherTime->hh * 3600 + anotherTime->mm * 60 + anotherTime->ss);
        return timeDifference;
    }
    void setTime()
    {
        cin >> hh >> mm >> ss;
    }
};

class Comparator
{
  private:
  public:
    double smallestDiff(vector<Time *> times)
    {

        double x = 0;
        return x;
    }
};

int main()
{
    int n = 0;
    cin >> n;

    vector<Time *> times;
    for (int i = 0; i < n; i++)
    {
        Time *newTime = new Time();
        newTime->setTime();
        times.push_back(newTime);
    }
    Comparator compareDiff;
    compareDiff.smallestDiff(times);

    for (Time *each : times)
    {
        each->getTDiff();
    }
    cout << << endl;
    return 0;
}