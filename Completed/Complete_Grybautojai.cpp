#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

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
    //checks if a difference in contestant scores exists
    bool checkIfAnySumDifferenceExists(vector<Contestant *> contenders)
    {
        vector<int> contendersScore;
        for (Contestant *each : contenders)
            contendersScore.push_back(each->getScore());
        for (int i = 1; i < (int)contenders.size(); i++)
            if (contenders[0] != contenders[i])
                return true;
        return false;
    }
    //find winner
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
};
class DupeKiller
{
  private:
    vector<int> RemoveIntDuplicates(vector<int> contendersToRemove)
    {
        //remove duplicates from duplicate array
        sort(contendersToRemove.begin(), contendersToRemove.end());
        contendersToRemove.erase(unique(contendersToRemove.begin(), contendersToRemove.end()), contendersToRemove.end());

        return contendersToRemove;
    }

  public:
    vector<Contestant *> RemoveDuplicates(vector<Contestant *> contenders)
    {
        //create array where duplicates are marked
        int n = (int)contenders.size();
        vector<int> contendersToRemove;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (contenders[i]->getScore() == contenders[j]->getScore())
                {
                    contendersToRemove.push_back(i);
                    contendersToRemove.push_back(j);
                }

        contendersToRemove = RemoveIntDuplicates(contendersToRemove);

        //create a new contender array where you add contenders that were not marked
        vector<Contestant *> reformedContenders;
        for (int i = 0; i < n; i++)
        {
            bool addContestant = true;
            for (int anotherEach : contendersToRemove)
                if (i == (int)anotherEach)
                    addContestant = false;

            if (addContestant)
                reformedContenders.push_back(contenders[i]);
        }
        return reformedContenders;
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
    DupeKiller corrector;
    contenders = corrector.RemoveDuplicates(contenders);

    if (contenders.size() > 0 || counter.checkIfAnySumDifferenceExists(contenders))
        cout << counter.getWinnersName(contenders) << endl;
    else
        cout << "MARCINKEVIČIUS";

    return 0;
}