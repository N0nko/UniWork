#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class Circle
{
private:
	int x, y, d;

public:
	double getLengthToZero()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	bool checkCenter(double lengthToZero)
	{
		return d / 2 >= lengthToZero;
	}
	void setCircle()
	{
		cin >> x >> y >> d;
	}
};

class Counter
{
private:
	int circleCount = 0;

public:
	int countCircles(vector<Circle *> circles)
	{
		for (Circle *each : circles)
		{
			if (each->checkCenter(each->getLengthToZero()))
				circleCount++;
		}
		return circleCount;
	}
};
int main()
{
	int n;
	cin >> n;
	Counter counter;
	vector<Circle *> circles;
	for (int i = 0; i < n; i++)
	{
		Circle *newCircle = new Circle();
		newCircle->setCircle();
		circles.push_back(newCircle);
	}
	cout << counter.countCircles(circles);
}