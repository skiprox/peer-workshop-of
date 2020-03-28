#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetLogLevel(OF_LOG_VERBOSE);

	ofGLWindowSettings settings;
    settings.setGLVersion(4,1); /// < select your GL Version here
    ofCreateWindow(settings);

	ofRunApp( new ofApp());

}
