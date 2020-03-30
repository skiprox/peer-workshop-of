#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void setupLightingExample();
		void setupRaycastingExample();
		void update();
		void draw();
		void runLightingExample();
		void runRaycastingExample();

		ofShader colorWithLightShader;
		ofShader raycastingShader;

		ofEasyCam cam;
		ofLight light;
		ofMaterial material;
		
};
