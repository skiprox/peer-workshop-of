#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void setupLightingExample();
		void setupRaycastingExample();
		void update();
		void draw();
        void keyPressed(int key);

		void runLightingExample();
		void runRaycastingExample();

		ofShader colorWithLightShader;
		ofShader raycastingShader;
        void setupInkExample();
        void setupGradientExample();

        void runInkExample();
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
    ofConePrimitive cone;
    ofIcoSpherePrimitive icoSphere;
    
    bool bWireframe;
    bool bFill;
    
    float rotate;
    float radius;
    ofTexture tex;
    ofImage img;
    ofVec3f center;
    
    

		
};
