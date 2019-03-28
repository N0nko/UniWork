#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Figure
{
  private:
    double x, y;
    //Vietoje pi naudokite 355/113.
    const double pi = double(355) / double(113);

  public:
    Figure(int x, int y) : x(x), y(y){};

    double getEllipseArea()
    {
        return pi * x * y;
    }
    double getRectArea()
    {
        return x * y;
    }
};
class Getter
{
  public:
    double getRectMaxValue()
    {
        double n = 0, x, y, maxValue = -INFINITY;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            Figure *newfigure = new Figure(x, y);
            double rectArea = newfigure->getRectArea();
            if (maxValue < rectArea)
                maxValue = rectArea;
        }
        return maxValue;
    }
    double getEllipseMaxValue()
    {
        double n = 0, x, y, maxValue = -INFINITY;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            Figure *newfigure = new Figure(x, y);
            double ellipseArea = newfigure->getEllipseArea();
            if (maxValue < ellipseArea)
                maxValue = ellipseArea;
        }
        return maxValue;
    }
};

int main()
{
    Getter get;
    //getfigures
    double rectangles = get.getRectMaxValue();
    double ellipses = get.getEllipseMaxValue();
    //compareFigures
    if (rectangles > ellipses)
    {
        cout << "Didžiausia figūra stačiakampis" << endl;
        cout << "Plotas " << rectangles;
    }
    else
    {
        cout << "Didžiausia figūra elipsė" << endl;
        cout << "Plotas " << ellipses;
    }

    return 0;
}