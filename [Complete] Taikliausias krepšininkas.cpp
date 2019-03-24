#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

class throws {
public:
	int OnePointThrows, OnePointScores;
	int TwoPointThrows, TwoPointScores;
	int ThreePointThrows, ThreePointScores;
};

class highScore {
public:
	double ratio;
		int score;

};

class throwsUtil {
public:
	highScore throwCalc(throws data, highScore result) {

		double _scores = data.OnePointScores + data.TwoPointScores + data.ThreePointScores;
		double _throws = data.OnePointThrows + data.TwoPointThrows + data.ThreePointThrows;
		double _ratio = _scores / _throws;
		int _score = data.OnePointScores + data.TwoPointScores * 2 + data.ThreePointScores * 3;
		if (_ratio > result.ratio) {
			result.score = _score;
			result.ratio = _ratio;
		}

		return result;
	}
};
int main()
{
	int n;
	//ifstream IN("data.txt");
	throws startInput;
	throwsUtil calc;
	highScore result;
	result.ratio = 0;
	result.score = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> startInput.TwoPointThrows >> startInput.TwoPointScores >> startInput.ThreePointThrows >> startInput.ThreePointScores >> startInput.OnePointThrows >> startInput.OnePointScores;
		result = calc.throwCalc(startInput, result);
	}
	cout << result.score;
}