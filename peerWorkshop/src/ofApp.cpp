#include "ofApp.h"

float circleX = 0.0;

//---------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(34, 34, 34);
	shader.load("shaders/start.vert","shaders/start.frag");
	ofEnableDepthTest();
	ofSetVerticalSync(true);
    ofEnableLighting();
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    light.enable();
    light.setPointLight();
    light.setPosition(0,0,300);
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
	ofSetColor(245, 58, 135);
	ofFill();
	cam.begin();
	ofEnableLighting();
	shader.begin();
	ofDrawCircle(circleX,
		0.0,
		100.0
	);
	shader.end();
	ofDisableLighting();
	cam.end();
}

//---------------------------------
// CODE CHUNKS
// CHUNKY CODES
//---------------------------------
