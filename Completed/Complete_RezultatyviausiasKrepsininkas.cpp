#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

class Throws
{
  private:
    double OnePointThrows, OnePointScores;
    double TwoPointThrows, TwoPointScores;
    double ThreePointThrows, ThreePointScores;

  public:
    //Žemiau pateikti dvitaškių (metė, pataikė), tritaškių (metė, pataikė) bei baudų metimų (metė, pataikė) skaičiai
    void setScores()
    { // dvm Dvp trm Drp bdm Bdp
        cin >>
            TwoPointThrows >> TwoPointScores >> ThreePointThrows >> ThreePointScores >> OnePointThrows >> OnePointScores;
    }
    //  Apskaičiuokite daugiausiai taškų pelniusio krepšininko taiklumą.
    double getScore()
    {
        return (OnePointScores + TwoPointScores * 2 + ThreePointScores * 3);
    }
    double getContribution()
    {
        double score = (OnePointScores + TwoPointScores + ThreePointScores);
        double misses = (OnePointThrows + TwoPointThrows + ThreePointThrows);
        return score / misses * 100;
    }
};

class ContributionComparer
{
  public:
    double getMostUsefulValue(vector<Throws *> throws)
    {
        int index;
        double highestValue = -INFINITY;
        for (int i = 0; i < throws.size(); i++)
        {
            double contributionValue = throws[i]->getScore();

            if (contributionValue > highestValue)
            {
                highestValue = contributionValue;
                index = i;
            }
        }
        return throws[index]->getContribution();
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Throws *> throws;
    for (int i = 0; i < n; i++)
    {
        Throws *newScore = new Throws();
        newScore->setScores();
        throws.push_back(newScore);
    }
    ContributionComparer comp;

    cout << fixed << setprecision(2) << comp.getMostUsefulValue(throws);
    return 0;
}