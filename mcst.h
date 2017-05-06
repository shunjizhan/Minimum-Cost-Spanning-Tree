#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
#include <vector>
#include <algorithm>
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
  return sqrt((d1 * d1) + (d2 * d2));
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

  bool contains(vector<int> v, int x) {
    if (std::find(v.begin(), v.end(), x) != v.end())
      return true;
    else
      return false;
  }

  void findMCST() {
    int** result = new int*[n-1];
    int* edge;

    int v1, v2;
    double minDistance;
    vector<int> known;
    known.push_back(0);

    while (known.size() < n) {
      minDistance = 999999999999999999;
      for (int i = 0; i < known.size(); i++) {    // all known points
        int thisIndex = known[i];
        vector<Edge> edges = vertices[thisIndex].edges;
        for (int j = 0; j < edges.size(); j++) {    // all edges for current point
          double distance = edges[j].distance;
          int targetIndex = edges[j].targetIndex;
          if (distance < minDistance && !contains(known, targetIndex)) {
            minDistance = distance;
            v1 = thisIndex;
            v2 = targetIndex;
          }
        }
      }

      known.push_back(v2);

      edge = new int[2];
      if (v1 < v2) {
        edge[0] = v1;
        edge[1] = v2;
      } else {
        edge[0] = v2;
        edge[1] = v1;
      }
      result[known.size() - 2] = edge;
    }

    // sort result
    for (int y = 0; y < n - 1; y++) {
      for (int x = y + 1; x < n - 1; x++) {
        if (result[x][0] < result[y][0] || (result[x][0] == result[y][0] && result[x][1] < result[y][1])) {
          int* temp = result[x];
          result[x] = result[y];
          result[y] = temp;
        }
      }
    }

    for (int a = 0; a < n - 1; a++) {
      cout << result[a][0] << " " << result[a][1] << endl;
    }


  }

};



