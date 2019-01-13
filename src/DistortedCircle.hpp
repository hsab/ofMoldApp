//
//  DistortedCircle.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef DistortedCircle_hpp
#define DistortedCircle_hpp

#include "ofMain.h"
#include "Utils.hpp"

class DistortedCircle {

private:
  ofVec2f offset;
  float scale;
  
public:
  DistortedCircle(float scale);
  float get(float angle, float radius);
};

#endif /* DistortedCircle_hpp */
