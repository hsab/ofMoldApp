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

#define CREATION_AREA_SIZE 40

class Hyphae {
private:
  Ink *ink;
  std::list<Hypha> elements;
  float hyphaDistortion;
  int hyphaMaxLifespan;
  
  void addAtPosition(ofVec2f pos, ofVec2f vel);

public:
  Hyphae(Ink *ink, int hyphaMaxLifespan, float hyphaDistortion); 
  void update();
  void draw();
  void add(ofVec2f vel);

  void onHyphaFork(HyphaForkEventArgs &e);
};

#endif /* Hyphae_h */
