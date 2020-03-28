#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofShader colorWithLightShader;

		ofEasyCam cam;
		ofLight light;
		ofMaterial material;
		
};
