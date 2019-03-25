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
    //Žemiau pateikti dvitaškių (metė, pataikė), tritaškių (metė, pataikė) bei baudų metimų (metė, pataikė) skaičia
    void setScores()
    {
        cin >>
            TwoPointThrows >> TwoPointScores >>
            ThreePointThrows >> ThreePointScores >>
            OnePointThrows >> OnePointScores;
    }
    // Naudingumo balai skaičiuojami sumuojant pelnytus taškus ir atimant pramestų metimų skaičių.
   double getContribution()
    {
        double scored = OnePointScores + 2 * TwoPointScores + 3 * ThreePointScores;
        double missed = OnePointThrows + TwoPointThrows + ThreePointThrows - OnePointScores - TwoPointScores - ThreePointScores;
        double score = scored - missed;
        return score;
    }
};

class ContributionComparer
{
  public:
    double getMostUsefulValue(vector<Throws *> throws, int n)
    {
        int index;
        double highestValue = -INFINITY;
        for (int i = 0; i < n; i++)
        {
            double contributionValue = throws[i]->getContribution();

            if (contributionValue > highestValue)
            {
                index = i;
                highestValue = contributionValue;
            }
        }
        return index + 1;
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
    cout << comp.getMostUsefulValue(throws, n);
    return 0;
}