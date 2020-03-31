#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
        void setup();
        void setupPrimitiveShapes();
        void setupLightingExample();
        void setupRaycastingExample();
        void setupInkExample();
        void setupGradientExample();
        void setupInClassExample();
        void setupVertExample();
        void update();
        void draw();
        void keyPressed(int key);

        void runLightingExample();
        void runRaycastingExample();
        void runInkExample();
        void runGradientExample();
        void runInClassExample();
        void runVertExample();

        ofShader inkInWaterShader;
        ofShader basicGradient;
        ofShader colorWithLightShader;
        ofShader raycastingShader;
        ofShader inClassShader;
        ofShader vertShader;

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

        // Options for drawing 3d primitives
        bool bWireframe;
        bool bFill;

        float circleX = 0.0;
        
        float radius;
        ofTexture tex;
        ofImage img;
        ofVec3f center;	
};
