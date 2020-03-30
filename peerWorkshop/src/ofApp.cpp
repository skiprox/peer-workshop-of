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

    // Explore setup! [NOAH]
    // Create some shapes
    // This provides them with a few 3D shapes,
    // a basic shader on top of that (maybe returning one color)
    // and they can play around with that

    // An example with lighting,
    // how to incorportate normals into your shader
    setupLightingExample();

    // Going further! [SEAN + NOAH, each add 2 frag shaders that can be used later]
    // A raycasting example? Just some more complex frag shaders
    // Passing in uniforms!
    setupRaycastingExample();

    // Vert shader stuff [SEAN]
    // What to do here? idk?
    // Make a blobby shape that wiggles AND RETAINS LIGHTING
}

// Lighting example
// help from
// https://forum.openframeworks.cc/t/3d-model-in-custom-shader/20004/2
//---------------------------------------
void ofApp::setupLightingExample(){
	colorWithLightShader.load("shaders/lighting/shader.vert","shaders/lighting/shader.frag");
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

// Raycasting example
//---------------------------------------
void ofApp::setupRaycastingExample(){
	raycastingShader.load("shaders/raycasting/shader.vert","shaders/raycasting/shader.frag");
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

	// Explore examples

	// Lighting shader example
	runLightingExample();

	// Going further examples
	runRaycastingExample();

	cam.end();
}

//---------------------------------
// CODE CHUNKS
// CHUNKY CODES
//---------------------------------

// Lighting example
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

// Raycasting example
//---------------------------------------
void ofApp::runRaycastingExample(){
	ofSetColor(255, 100, 140);
	ofFill();
	raycastingShader.begin();
	raycastingShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	ofDrawSphere(0.0, 0.0, 0.0, 100);
	raycastingShader.end();
}
