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
        if (timeDifference < 0)
            timeDifference = (hh * 3600 + mm * 60 + ss) + (24 * 3600 - (anotherTime->hh * 3600 + anotherTime->mm * 60 + anotherTime->ss));
        else if (timeDifference > 24 * 3600)
            timeDifference = abs(24 * 3600 - timeDifference);
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
        double smallestDifference = INFINITY;
        double buffer;
        for (Time *each : times)
            for (Time *anotherEach : times)
            {
                if (each != anotherEach)
                {
                    buffer = each->getTDiff(anotherEach);
                    if (buffer < smallestDifference && buffer >= 0)
                        smallestDifference = buffer;
                }
            }
        return smallestDifference;
    }
};
class Printer
{

  public:
    void printResult(double seconds)
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
    Printer printer;
    Comparator compareDiff;
    printer.printResult(compareDiff.smallestDiff(times));
    return 0;
}