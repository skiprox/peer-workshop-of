#include "ofApp.h"

float circleX = 0.0;

//---------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(34, 34, 34);
	ofEnableDepthTest();
	ofSetVerticalSync(true);
    ofEnableLighting();
    ofEnableAlphaBlending();
    ofEnableSmoothing();

    // An example with lighting
    setupLightingExample();
}

// Example from
// https://forum.openframeworks.cc/t/3d-model-in-custom-shader/20004/2
//---------------------------------------
void ofApp::setupLightingExample(){
	colorWithLightShader.load("shaders/colorWithLight.vert","shaders/colorWithLight.frag");
	// Material stuff
    material.setShininess(120);
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    material.setEmissiveColor(ofColor(0, 0, 0, 255));
    material.setDiffuseColor(ofColor(255, 255, 255, 255));
    material.setAmbientColor(ofColor(255, 255, 255, 255));
    // Light stuff
    // no longer needed
    // light.enable();
    // light.setDiffuseColor(ofColor(255.0, 255.0, 0.0));
    // light.setPointLight();
}

//---------------------------------------
void ofApp::update(){
	circleX = ofMap(
		sin(ofGetElapsedTimef()),
		-1.0,
		1.0,
		-ofGetWidth()/2.0,
		ofGetWidth()/2.0
	);
}

//---------------------------------------
void ofApp::draw(){
	cam.begin();
	runLightingExample();
	cam.end();
}

//---------------------------------
// CODE CHUNKS
// CHUNKY CODES
//---------------------------------

//---------------------------------------
void ofApp::runLightingExample(){
	// Light stuff,
	// no longer needed
	// ofEnableLighting();
	ofFill();
	colorWithLightShader.begin();
	colorWithLightShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	colorWithLightShader.setUniform4f("u_materialColor", ofColor(255.0, 80.0, 130.0, 255.0));
	ofDrawSphere(circleX, 0.0, 0.0, 100);
	colorWithLightShader.end();
	// Light stuff,
	// no longer needed
	// ofDisableLighting();
	// light.draw();
}
