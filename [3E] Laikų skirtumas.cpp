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
    bool checkIfGood(Time *anotherTime)
    {
        return (getTDiff(anotherTime) > 0);
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
        double smallestDifference = INFINITY;
        double buffer;
        for (Time *each : times)
        {
            for (Time *anotherTime : times)
            {
                if (each->checkIfGood(anotherTime))
                {
                    buffer = each->getTDiff(anotherTime);
                    if (buffer < smallestDifference)
                        smallestDifference = buffer;
                }
            }
        }
        return smallestDifference;
    }
};
class Printer
{

  public:
    string printResult(double seconds)
    {

        int hour = seconds / 3600;
        int minute = (seconds - hour * 3600) / 60;
        int second = seconds - hour * 3600 - minute * 60;
        cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second << endl;
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
    Printer printer;

    printer.printResult(compareDiff.smallestDiff(times));
    return 0;
}