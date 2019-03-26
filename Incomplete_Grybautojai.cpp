#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Contestant
{
  private:
    string name;    //contestant name
    int m1, m2, m3; //mushroom 1, 2 and 3
  public:
    //Žemiau pateikti dalyvių vardai ir surinktų raudonikių, baravykų bei šungrybių kiekiai
    void setContestant()
    {
        cin >> name >> m1 >> m2 >> m3;
    }
    //Kiekvienas raudonikis vertas 5, baravykas 3, šungrybis 15 taškų.
    int getScore()
    {
        return m1 * 5 + m2 * 3 + m3 * 15;
    }
    string getContendersName()
    {
        return name;
    }
};

class ScoreCounter
{
  public:
    bool checkWinnerExists(vector<Contestant *> contenders)
    {
        vector<int> contendersScore;
        for (Contestant *each : contenders)
            contendersScore.push_back(each->getScore());
        for (int i = 1; i < (int)contenders.size(); i++)
            if (contenders[0] != contenders[i])
                return true;
        return false;
    }

    string getWinnersName(vector<Contestant *> contenders)
    {
        int winnerIndex;
        int biggestScore = -INFINITY;
        int n = (int)contenders.size();
        for (int i = 0; i < n; i++)
        {
            int contendersScore = contenders[i]->getScore();
            if (contendersScore > biggestScore)
            {
                biggestScore = contendersScore;
                winnerIndex = i;
                // cout << "BiggestScore: " << contendersScore << endl;
            }
        }
        return contenders[winnerIndex]->getContendersName();
    }
    vector<Contestant *> RemoveDuplicates(vector<Contestant *> contenders)
    {
        int n = (int)contenders.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (contenders[i]->getScore() == contenders[j]->getScore())
                {
                    cout << "Removing: " << contenders[i]->getContendersName() << " score: " << contenders[i]->getScore() << " and " << contenders[j]->getContendersName() << " score: " << contenders[i]->getScore() << endl;
                    contenders.erase(contenders.begin() + i);
                    j -= 1;
                    contenders.erase(contenders.begin() + (j));
                    n = (int)contenders.size();
                }

        cout << "Size: " << (int)contenders.size() << endl;
        for (Contestant *each : contenders)
            cout << "Remaining: " << each->getContendersName() << endl;

        return contenders;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<Contestant *> contenders;
    for (int i = 0; i < n; i++)
    {
        Contestant *newContestant = new Contestant();
        newContestant->setContestant();
        contenders.push_back(newContestant);
    }
    ScoreCounter counter;
    if (counter.checkWinnerExists(contenders))
        cout << counter.getWinnersName(counter.RemoveDuplicates(contenders)) << endl;
    else
        cout << "Marcinkevičius";

    return 0;
}