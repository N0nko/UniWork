#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

class circleData
{
  public:
	int x, y, d;
};

class circleResult
{
  public:
	int circleCount;
};

class circleUtil
{
  public:
	circleResult CirRes(circleData newCircle, circleResult newRes)
	{
		double x = newCircle.x;
		double y = newCircle.y;
		double d = newCircle.d;

		double LengthToZero = pow(x, 2) + pow(y, 2);
		LengthToZero = sqrt(LengthToZero);

		if (d / 2 >= LengthToZero)
			newRes.circleCount++;

		return newRes;
	}
};
int main()
{
	int n;

	cin >> n;
	circleData circleDataInput;
	circleUtil circleCalc;
	circleResult res;
	res.circleCount = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> circleDataInput.x >> circleDataInput.y >> circleDataInput.d;
		res = circleCalc.CirRes(circleDataInput, res);
	}
	cout << res.circleCount;
}