#include <bits/stdc++.h>

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
class Setter
{
  public:
    //zinome kiekvieno stačiakampio kraštines bei elipsių pusašių ilgius.
    Figure *Rect()
    {
        int x, y;
        cin >> x >> y;
        Figure *newfigure = new Figure(x, y);
        return newfigure;
    }
    Figure *Ellipse()
    {
        int x, y;
        cin >> x >> y;
        Figure *newfigure = new Figure(x, y);
        return newfigure;
    }
};
class Getter
{
  public:
    //Raskite didžiausią plotą turinčią figūrą.
    double getRectMaxValue()
    {
        double n = 0, maxValue = -INFINITY;
        Setter set;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            double rectArea = set.Rect()->getRectArea();
            if (maxValue < rectArea)
                maxValue = rectArea;
        }
        return maxValue;
    }
    double getEllipseMaxValue()
    {
        double n = 0, x, y, maxValue = -INFINITY;
        Setter set;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            double ellipseArea = set.Ellipse()->getEllipseArea();
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