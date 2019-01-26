//
//  Hyphae.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Ink.h"
#include "Hypha.h"

class Hyphae {
private:
  Ink *ink;
  std::list<Hypha> elements;

public:
  Hyphae(Ink *ink) {this->ink = ink;}
  void update();
  void draw();
  void add(ofVec2f pos, ofVec2f vel);
};

#endif /* Hyphae_h */
