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
    int OnePointThrows, OnePointScores;
    int TwoPointThrows, TwoPointScores;
    int ThreePointThrows, ThreePointScores;

  public:
  //Žemiau pateikti dvitaškių (metė, pataikė), tritaškių (metė, pataikė) bei baudų metimų (metė, pataikė) skaičiai
    void setScores()
    {
        cin >>
            TwoPointThrows >> TwoPointScores >>
            ThreePointThrows >> ThreePointScores >>
            OnePointThrows >> OnePointScores;
    }
    //  Apskaičiuokite daugiausiai taškų pelniusio krepšininko taiklumą.
    double getContribution()
    {
        double scores = (OnePointScores + TwoPointScores + ThreePointScores);
        double misses = ( OnePointThrows + TwoPointThrows + ThreePointThrows);
        return scores/misses *100;
    }
};

class ContributionComparer
{
  public:
    double getMostUsefulValue(vector<Throws *> throws, int n)
    {
        double highestValue = -INFINITY;
        for (double i = 0; i < n; i++)
        {
            double contributionValue = throws[i]->getContribution();

            if (contributionValue > highestValue)
                highestValue = contributionValue;
            
        }
        return highestValue;
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

    cout << fixed << setprecision(2) << comp.getMostUsefulValue(throws, n);
    return 0;
}