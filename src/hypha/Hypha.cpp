//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"

#define OFFSET_MAX 1000

Hypha::Hypha(const ofVec3f pos, const ofVec3f dir, const HyphaSettings settings, const int generation) {
  this->pos = pos;
  this->settings = settings;
  this->vel = getInitialVelocity(dir);
  this->generation = generation;
  this->forkCount = 0;
  this->lifespan = ofRandom(0,settings.maxLifespan);
  this->noiseOffset = ofVec2f(ofRandom(OFFSET_MAX), ofRandom(OFFSET_MAX));
  calcNextForkDistance();
}

void Hypha::growOlder() {
  lifespan--;
  if (lifespan<=0 || pos.z>=settings.maxHeight) {
    this->dead = true;
    throwDieEvent();
  }
}

ofVec3f Hypha::getInitialVelocity(ofVec3f dir) const {
   return dir.getNormalized() * ofRandom(settings.speed*(1-settings.speedVariation/100),
                                         settings.speed*(1+settings.speedVariation/100));
}

void Hypha::updateVelocity() {
  float bendAngle = 2*(ofNoise(pos.x*settings.distortion+noiseOffset.x,
                        pos.y*settings.distortion+noiseOffset.y)-0.5f)*settings.maxBendAngle;
  vel.rotate(bendAngle, ofVec3f(0,0,1));
  vel.z -= settings.gravity;
  if (pos.z<0) {vel.z=0;}
}

float Hypha::getFertilityRate() const {
  return settings.fertilityRateRatio*(pow(generation/2.0f+forkCount,settings.fertilityRatePower)+1);
}

void Hypha::calcNextForkDistance() {
  this->nextForkDistance = (int)(ofRandom(1,(getFertilityRate()))+0.5f);
}

void Hypha::fork() {
  throwForkEvent();

  this->lifespan /= settings.forkAgeRatio;
  this->forkCount++;

  calcNextForkDistance();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e;
  e.generation = this->generation + 1;
  e.pos = this->pos;
  float angle = ofRandom(-settings.maxForkAngle, settings.maxForkAngle);
  e.dir = this->vel.getRotated(angle, ofVec3f(0,0,1));
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::throwDieEvent() {
  HyphaDieEventArgs e;
  e.pos = this->pos;
  ofNotifyEvent(this->dieEvent, e);
}

void Hypha::update() {
  growOlder();
  if (isAlive()) {
    pos += vel;
    ofVec3f newIntPos = ofVec3f((int)(pos.x+0.5f),
                                (int)(pos.y+0.5f),
                                (int)(pos.z+0.5f));
    if (newIntPos != lastIntPos) {
      updateVelocity();
      lastIntPos = newIntPos;
      posIsNewPixel = true;
      nextForkDistance--;
      if (nextForkDistance==0) {
        fork();
      }
    }
  }
}

void Hypha::draw() {
  if (isAlive()) {
    if (this->posIsNewPixel) {
      ofPushStyle();
      ofEnableAlphaBlending();
      ofSetColor(settings.color);
      ofDrawRectangle(this->pos.x, this->pos.y, 1, 1);
      //drawZ();
      ofPopStyle();
      this->posIsNewPixel = false;
    }
  } else {
    //ofPushStyle();
    //ofSetColor(0, 0, 255);
    //ofDrawRectangle(this->pos.x, this->pos.y, 1, 1);
    //ofPopStyle();
  }
}

void Hypha::drawZ() const {
  ofPushMatrix();
  ofTranslate(0, -200);
  ofDrawRectangle(pos.x, -pos.z, 1, 1);
  ofPopMatrix();
}
