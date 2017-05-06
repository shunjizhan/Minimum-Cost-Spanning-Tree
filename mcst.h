#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
using namespace std;

struct Point {
  double x;
  double y;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << x << " " << y << endl;
  }

};

double getDistance(Point p1, Point p2) {
  return sqrt(abs(p1.x - p2.x) + abs(p1.y - p2.y));
}

struct Edge {
  Point p1;
  Point p2;
  double distance;

  Edge() {
    this->p1 = Point(0, 0);
    this->p2 = Point(0, 0);
    this->distance = getDistance(p1, p2);
  }

  Edge(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
    this->distance = getDistance(p1, p2);
  }

  void print() {
    p1.print();
    p2.print();
    cout << "distance = " << distance << endl;
  }

};

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

  void startAddingEdges(int m) {
    this->m = m;
    this->current = 0;
  }

  void addVertice(double x, double y) {
    vertices[current] = Point(x, y);
    current++;
  }

  void addVertice(Point p1, Point p2) {
    edges[current] = Edge(p1, p2);
    current++;
  }

  void printAllVertices() {
    for (int i = 0; i < n; i++) {
      vertices[i].print();
    }
  }

  void printAllEdges() {
    for (int i = 0; i < m; i++) {
      edges[i].print();
      cout << endl;
    }
  }
};



