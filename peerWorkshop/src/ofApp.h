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
        void setupPrimitiveExample();
        void setupGradientExample();

        void runPrimitiveExample();
        void runGradientExample();

        ofShader inkInWaterShader;
        ofShader basicGradient;
    
		ofEasyCam cam;
		ofLight light;
		ofMaterial material;
    
    
    //3d primitives
    ofSpherePrimitive sphere;
    ofCylinderPrimitive cylinder;
    ofPlanePrimitive plane;
    ofMesh mesh;
    ofBoxPrimitive box;
    
    float rotate;
    ofTexture tex;
    ofImage img;
    ofVec3f center;

		
};
