#include <bits/stdc++.h>

using namespace std;

class Pipe
{
  private:
    double length, circleRadius, hexRadius;
    //Vietoje pi naudokite 355/113.
    const double pi = double(355) / double(113);

  public:
    //Žinome kiekvieno vamzdžio ilgį L, vidinio apskritimo skersmenį R bei šešiakampio didžiausią galimą diametrą D.
    void setPipe()
    {
        cin >> length >> circleRadius >> hexRadius;
        circleRadius /= 2;
        hexRadius /= 2;
    }
    //Apskaičiuokite ir išveskite kiekvieno vamzdžio tūrį (metalo tūrį)
    double getCylinderArea()
    {
        return pi * pow(circleRadius, 2);
    }
    double getHexArea()
    {
        return ((3 * sqrt(3)) / 2) * pow(hexRadius, 2);
    }

    double getMetalCapacity()
    {
        return getHexArea() * length - getCylinderCapacity();
    }

    double getArea()
    {
        return 2 * pi * circleRadius * length + 6 * hexRadius * length + 2 * (getHexArea() - getCylinderArea());
    }
    double getCylinderCapacity()
    {
        return getCylinderArea() * length;
    }
};

class Printer
{
  public:
    void PrintCapacity(int index, double capacity)
    {
        cout << index << " vamzdžio tūris: " << fixed << setprecision(3) << capacity << endl;
    }
    //bei visų vamzdžių paviršiaus plotų sumą.
    void PrintTotalArea(vector<Pipe *> pipes)
    {
        double totalArea = 0;
        for (Pipe *each : pipes)
            totalArea += each->getArea();
        cout << "Paviršių plotų suma yra " << fixed << setprecision(3) << totalArea << endl;
    }
    //Taip pat raskite vamzdį, pro kurį ilgiausiai tekėtų 666 litrai pieno.
    void PrintLongestFlow(vector<Pipe *> pipes)
    {
        double smallestRadius = INFINITY;
        int index;
        for (int i = 0; i < pipes.size(); i++)
        {
            double pipeRadius = pipes[i]->getCylinderCapacity();
            if (pipeRadius <= smallestRadius)
            {
                index = i + 1;
                smallestRadius = pipeRadius;
            }
        }
        cout << "Pienas ilgiausiai tekės pro " << index << " vamzdį" << endl;
    }
};
int main()
{
    int n = 0;
    cin >> n;
    vector<Pipe *> pipes;
    Printer printer;

    for (int i = 0; i < n; i++)
    {
        Pipe *newPipe = new Pipe();
        newPipe->setPipe();
        printer.PrintCapacity(i + 1, newPipe->getMetalCapacity());
        pipes.push_back(newPipe);
    }
    printer.PrintTotalArea(pipes);
    printer.PrintLongestFlow(pipes);

    return 0;
}