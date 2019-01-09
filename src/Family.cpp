//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"

Family::Family(const std::filesystem::path imageFilename, ofVec2f pos, float size) {
  image.load(imageFilename);
  this->pos = pos;
  this->size = size;
  for(int i=0;i<10;i++) {
    spotPositions.push_back(ofVec2f(ofRandom(-50, 50), ofRandom(-50, 50)));
  }
}

void Family::update() {
  
}

void Family::draw() {
  ofSetColor(255,255);
  for( list<ofVec2f>::iterator itr = spotPositions.begin(); itr != spotPositions.end(); ++itr ) {
    image.draw(pos + *itr, size, size);
  }
}
