#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void setupLightingExample();
		void update();
		void draw();
		void runLightingExample();

		ofShader colorWithLightShader;

		ofEasyCam cam;
		ofLight light;
		ofMaterial material;
		
};
