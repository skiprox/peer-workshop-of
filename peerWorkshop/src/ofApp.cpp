#include "ofApp.h"

float circleX = 0.0;

//---------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(34, 34, 34);
	shader.load("shaders/start.vert","shaders/start.frag");
}

//---------------------------------------
void ofApp::update(){
	circleX = ofMap(
		sin(ofGetElapsedTimef()),
		-1.0,
		1.0,
		0.0,
		ofGetWidth()
	);
}

//---------------------------------------
void ofApp::draw(){
	ofSetColor(245, 58, 135);
	ofFill();
	shader.begin();
	ofDrawCircle(circleX,
		ofGetHeight()/2.0,
		100.0
	);
	shader.end();
}

//---------------------------------
// CODE CHUNKS
// CHUNKY CODES
//---------------------------------
