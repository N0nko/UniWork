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
	Circle(int x, int y, int d) : x(x), y(y), d(d) {}
	double distanceBetweenPoints(Circle *other)
	{
		return sqrt(pow(x - other->x, 2) + pow(y - other->y, 2));
	}

	bool checkCollision(Circle *other)
	{
		return (distanceBetweenPoints(other) <= d / 2 + other->d / 2);
	}
};

class CollisionCounter
{
private:
	int collisionCount = 0;

public:
	int countCollisions(vector<Circle *> circles)
	{
		Circle *constCircle = new Circle(6, 6, 6);

		for (Circle *each : circles)
		{
			if (constCircle->checkCollision(each))
				collisionCount++;
		}
		return collisionCount;
	}
};
int main()
{
	int n;
	cin >> n;
	CollisionCounter counter;
	vector<Circle *> circles;
	for (int i = 0; i < n; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		Circle *newCircle = new Circle(x, y, d);
		circles.push_back(newCircle);
	}
	cout << counter.countCollisions(circles);
	return 0;
}