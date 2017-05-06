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

  cin >> m;
  if (m != 0) {
    for (int j = 0; j < m; j++) {
      cin >> x >> y;
      int index1 = atoi(x.c_str());
      int index2 = atoi(y.c_str());

      mcst.addEdge(index1, index2);
    }
  } else {
    mcst.fullyConnected();
  }

  if (mcst.isConnect() == false) {
    exit (EXIT_FAILURE);
  }

  mcst.findMCST();

  return 0;
}