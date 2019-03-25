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
        double score = OnePointScores + 2 * TwoPointScores + 3 * ThreePointScores - OnePointThrows - TwoPointThrows - ThreePointThrows;
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
            if (i == 5 || i == 12 || i == 36)
                cout << " " << contributionValue << " " << index << " " << highestValue << endl;
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