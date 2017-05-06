#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
#include <vector>
using namespace std;

struct Edge {
  int targetIndex;
  double distance;

  Edge() {
    this->targetIndex = -1;
    this->distance = -1;
  }

  Edge(int i, double distance) {
    this->targetIndex = i;
    this->distance = distance;
  }

  void print() {
    cout << distance << " to " << targetIndex << endl;
  }

};

struct Point {
  double x;
  double y;
  vector<Edge> edges;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  void addEdge(int i, double distance) {
    edges.push_back(Edge(i ,distance));
  }

  void print() {
    cout << x << " " << y << endl;
    for (int i = 0; i < edges.size(); i++)
      edges[i].print();
  }

};

double getDistance(Point p1, Point p2) {
  double d1 = abs(p1.x - p2.x);
  double d2 = abs(p1.y - p2.y);
  return sqrt(d1 * d1 + d2 * d2);
}

class Mcst {
public:
  int n;
  int m;
  int current;  // current index to add
  Point* vertices;
  Edge* edges;

  Mcst(int n) {
    this->n = n;
    this->current = 0;
    this->vertices = new Point[n];
    this->edges = new Edge[m];
  }

  void addVertice(double x, double y) {
    vertices[current] = Point(x, y);
    current++;
  }

  void addEdge(int i1, int i2) {
    Point p1 = vertices[i1];
    Point p2 = vertices[i2];
    double distance = getDistance(p1, p2);

    vertices[i1].addEdge(i2, distance);
    vertices[i2].addEdge(i1, distance);
  }

  void printAllVertices() {
    for (int i = 0; i < n; i++) {
      vertices[i].print();
      cout << endl;
    }
  }

};



