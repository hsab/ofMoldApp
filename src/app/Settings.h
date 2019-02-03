//
//  Settings.h
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#ifndef Settings_h
#define Settings_h

#include "ofxXmlSettings.h"

struct HyphaSettings {
  int maxLifespan;
  float speed;
  float distortion;
  float forkAgeRatio;
  float maxForkAngle;
  float maxBendAngle;
  int maxForkDistance;
  float fertilityRateRatio;
  float fertilityRatePower;
  int transparency;
};

struct HyphaeSettings {
  int creationAreaSize;
  HyphaSettings hypha;
  int initHyphaCount;
  int maxHyphaCount;
};

struct ConidiumSettings {
  int lifespan;
};

struct ConidiaSettings {
  int space;
  float growthSpeed;
  float perimeterDistortion;
  int maxRings;
  int angleResolution;
  ConidiumSettings conidium;
};

struct MyceliumSettings {
  int lifespan;
  ConidiaSettings conidia;
  HyphaeSettings hyphae;
};

class Settings {
private:
  ofxXmlSettings xmlSettings;

public:
  int framerate;
  int width;
  int height;
  MyceliumSettings mycelium;
  Settings(const string& xmlFile);
};

#endif /* Settings_h */
