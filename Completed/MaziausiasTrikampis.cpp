#include <bits/stdc++.h>

using namespace std;

class Vertex
{
  private:
    long long x, y;

  public:
    Vertex(long x, long y) : x(x), y(y) {}

    double getDistance(Vertex *anotherVertex)
    {
        double distance = sqrt(pow(x - anotherVertex->x, 2) + pow(y - anotherVertex->y, 2));
        return distance;
    }
};

class Triangle
{
  private:
    double ab, bc, ca;

  public:
    Triangle(double ab, double bc, double ca) : ab(ab), bc(bc), ca(ca) {}

    double getArea()
    {
        double p = (ab + bc + ca) / 2;
        double area = sqrt(p * (p - ab) * (p - bc) * (p - ca));
        return area;
    }
};

class Vertices
{
  private:
    Vertex *a, *b, *c;

  public:
    bool existTriangle()
    {
        double ab = a->getDistance(b);
        double bc = b->getDistance(c);
        double ca = c->getDistance(a);

        return ((ab + bc > ca) && (ab + ca > bc) && (ca + bc > ab));
    }

    Triangle *newTriangle()
    {
        double ab = a->getDistance(b);
        double bc = b->getDistance(c);
        double ca = c->getDistance(a);

        return new Triangle(ab, bc, ca);
    }
    //pateiktos trikampių viršūnių koordinatės x1,y1,x2,y2,x3,y3
    void setA()
    {
        long long x, y;
        cin >> x >> y;
        this->a = new Vertex(x, y);
    }
    void setB()
    {
        long long x, y;
        cin >> x >> y;
        this->b = new Vertex(x, y);
    }
    void setC()
    {
        long long x, y;
        cin >> x >> y;
        this->c = new Vertex(x, y);
    }
};

int main()
{
    int n = 0;
    cin >> n;
    list<Vertices *> vertices;
    for (int i = 0; i < n; i++)
    {
        Vertices *newVertices = new Vertices();
        newVertices->setA();
        newVertices->setB();
        newVertices->setC();
        vertices.push_back(newVertices);
    }
    double smallestArea = INFINITY;
    bool triangleExists = false;
    //Raskite trikampį, kurio plotas būtų mažiausias
    for (Vertices *vert : vertices)
    {
        if (vert->existTriangle())
        {
            triangleExists = true;
            Triangle *triangle = vert->newTriangle();
            double area = triangle->getArea();
            if (area < smallestArea)
            {
                smallestArea = area;
            }
        }
    }
    if (triangleExists)
        cout << fixed << setprecision(2) << smallestArea << endl;
    else
        cout << "NO";

    return 0;
}