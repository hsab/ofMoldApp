//
//  Sockets.hpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef Rings_h
#define Rings_h

#include "Ring.h"

#define MAX_RINGS 100

class Rings {
private:
  Ring *rings[MAX_RINGS];
  float space;

public:
  Rings(float space);
  int getRing(float radius) {return (int)(radius/this->space + 0.5f);}
  bool fill(int ring, float angle);
  void draw();
};

#endif /* Rings_h */
