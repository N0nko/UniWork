#include <bits/stdc++.h>

using namespace std;

class Vertex
{
  private:
    int x, y;

  public:
    Vertex(int x, int y) : x(x), y(y) {}

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
    double ab, bc, ca;

  public:
    bool existTriangle()
    {
        ab = a->getDistance(b);
        bc = b->getDistance(c);
        ca = c->getDistance(a);

        return ((ab + bc > ca) && (ab + ca > bc) && (ca + bc > ab));
    }

    Triangle *newTriangle()
    {
        return new Triangle(ab, bc, ca);
    }

    //Žemiau pateiktos trikampių viršūnių koordinatės x1,x2,x3,y1,y2,y3
    void setABC()
    {
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
        this->a = new Vertex(x1, y1);
        this->c = new Vertex(x2, y2);
        this->b = new Vertex(x3, y3);
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
        newVertices->setABC();
        vertices.push_back(newVertices);
    }
    double totalArea = 0;
    bool triangleExists = false;
    //Raskite visų egzistuojančių trikampių plotų sumą
    for (Vertices *vert : vertices)
    {
        if (vert->existTriangle())
        {
            triangleExists = true;
            Triangle *triangle = vert->newTriangle();
            totalArea += triangle->getArea();
        }
    }
    if (triangleExists)
        cout << fixed << setprecision(3) << totalArea << endl;
    else
        cout << "NO";

    return 0;
}