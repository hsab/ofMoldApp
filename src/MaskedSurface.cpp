//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "MaskedSurface.hpp"

MaskedSurface::MaskedSurface(IDrawable *surface,
                             const std::filesystem::path maskFilename) {

  this->surface = surface;
  mask.load(maskFilename);
  mask.resize(surface->getWidth(), surface->getHeight());

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "shaders/alphamask.frag");
  shader.linkProgram();

  fbo.allocate(getWidth(), getHeight());
}

void MaskedSurface::update() {
  surface->update();
}

void MaskedSurface::draw() {
  fbo.begin();
  ofClear(0, 0, 0, 0);
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  surface->draw();
  shader.end();
  fbo.end();

  ofSetColor(255,255);
  fbo.draw(0,0, getWidth(), getHeight());
}
