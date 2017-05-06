#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */
#include "mcst.h"
using namespace std;

int main() {
  int n, m;
  double intX, intY;
  string x, y;

  cin >> n;
  Mcst mcst(n);

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    intX = atof(x.c_str());
    intY = atof(y.c_str());

    mcst.addVertice(intX, intY);
  }

  // cin >> m;
  // mcst.startAddingEdges(m)

  // for (i = 0; i < m; i++) {
  //   cin >> x >> y;
  //   intX = atof(x.c_str());
  //   intY = atof(y.c_str());

  //   mcst.addVertice(intX, intY)
  // }

  mcst.printAllVertices();


  return 0;
}