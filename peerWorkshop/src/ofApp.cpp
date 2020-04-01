#include "ofApp.h"

//---------------------------------------
void ofApp::setup(){
	ofSetSphereResolution(128);
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	ofEnableLighting();
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	glEnable(GL_DEPTH_TEST);

	// for backward compatibility reasons
	ofDisableArbTex();

	/*
	* Setup all primitive shapes
	*/
	setupPrimitiveShapes();

	// An example with lighting,
	// how to incorportate normals into your shader
	setupLightingExample();

	// Gradient example
	// setupGradientExample();

	// Ink example
	// setupInkExample();

	// By yourself!
	// Do some stuff!
	// setupInClassExample();

	// Vert shader stuff
	// What to do here? idk?
	// Make a blobby shape that wiggles AND RETAINS LIGHTING
	// setupVertExample();
}

// Establish all the primitive shapes
//---------------------------------------
void ofApp::setupPrimitiveShapes(){
	bFill = true;
    bWireframe = false;
    // basic lighting example
    cylinder.set(100, 200);
    // ink example
    icoSphere.setRadius(200);
    icoSphere.setPosition(0, 0, 0);
    // gradient example
    box.set(100);
	box.setPosition(-200, -200, 0);
	// in class examples
	// what shape do you want to use?
	sphere.setRadius(100);
	sphere.setPosition(200, 200, 0);
	cone.setRadius(100);
	cone.setPosition(200, -200, 0);
    plane.setWidth(90);
    plane.setPosition(-200, 200, 0);
}

// Main update function
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
	ofBackground(0);
	/*
	* Lights! Camera! Action!
	* *~* That's showbiz, baby *~*
	*/
	cam.begin();

	// Lighting shader example
	// this is a solid color on a sphere,
	// with lighting applied
	runLightingExample();

	// Gradient shader example
	// this is a gradient on a box
	// runGradientExample();

	// Ink shader example
	// this is a goopy ink shader on a sphere
	// runInkExample();

	// In class example
	// do whatever you want!
	// runInClassExample();

	// In class vert work
	// runVertExample();

	/*
	* Closing time
	* *~* you don't have to go home, but you can't stay here *~*
	*/
	cam.end();


    // Some notes on the screen,
    // instead of a GUI
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    stringstream ss;
    ss << "(f): Toggle Fullscreen"<<endl<<"(s): Draw Solid Shapes"<<endl<<"(w): Draw Wireframes"<<endl;
    ss <<"(1/2/3/4): Set Resolutions" <<endl;
    ofDrawBitmapStringHighlight(ss.str().c_str(), 20, 20);

}

//---------------------------------
// CODE CHUNKS
// CHUNKY CODES
//---------------------------------

// Lighting example
// help from
// https://forum.openframeworks.cc/t/3d-model-in-custom-shader/20004/2
//---------------------------------------
void ofApp::setupLightingExample(){
	colorWithLightShader.load("shaders/lighting/shader");
	// Material stuff,
	// for this example specifically
	material.setShininess(120);
	material.setSpecularColor(ofColor(255, 255, 255, 255));
	material.setEmissiveColor(ofColor(0, 0, 0, 255));
	material.setDiffuseColor(ofColor(255, 255, 255, 255));
	material.setAmbientColor(ofColor(255, 255, 255, 255));
}

// Lighting example
//---------------------------------------
void ofApp::runLightingExample(){
	if(bWireframe == true){
        cylinder.setPosition(circleX, 0.0, 0.0);
		cylinder.drawWireframe();
    }
    if(bFill == true){
    	ofFill();
		colorWithLightShader.begin();
		colorWithLightShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
		colorWithLightShader.setUniform4f("u_materialColor", ofColor(255.0, 80.0, 130.0, 255.0));
		cylinder.setPosition(circleX, 0.0, 0.0);
		cylinder.draw();
		colorWithLightShader.end();
    }
}

// Gradient shader setup
//---------------------------------------
void ofApp::setupGradientExample(){
	basicGradient.load("shaders/gradient/shader");
}

// Gradient example, on a box
//---------------------------------------
void ofApp::runGradientExample(){
	if(bWireframe == true){
        box.drawWireframe();
    }
    if(bFill == true){
    	basicGradient.begin();
		basicGradient.setUniform1f("u_time", ofGetElapsedTimef());
		basicGradient.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	    box.draw();
		basicGradient.end();
    }
}

// Ink shader setup
//---------------------------------------
void ofApp::setupInkExample(){
	inkInWaterShader.load("shaders/inkInWater/shader");
}

// Ink example
//---------------------------------------
void ofApp::runInkExample(){
    if(bWireframe == true){
        icoSphere.drawWireframe();
    }
    if(bFill == true){
    	inkInWaterShader.begin();
		inkInWaterShader.setUniform1f("u_time", ofGetElapsedTimef());
		inkInWaterShader.setUniform2f("u_resolution", ofGetWidth(),ofGetHeight());
        icoSphere.draw();
        inkInWaterShader.end();
    }
}

// In Class shader setup
//---------------------------------------
void ofApp::setupInClassExample(){
	inClassShader.load("shaders/inClass/shader");
}

// In Class example
//---------------------------------------
void ofApp::runInClassExample(){
	if(bWireframe == true){
        sphere.drawWireframe();
    }
    if(bFill == true){
    	ofSetColor(255, 100, 140);
		ofFill();
		inClassShader.begin();
		// Challenges!
		// See the WORKSHOP.md doc for stuff to do
		// (search for "04 Explore")
		inClassShader.end();
    }
}

// Vert shader setup
//---------------------------------------
void ofApp::setupVertExample(){
	vertShader.load("shaders/vert/shader");
}

// Vert example
//---------------------------------------
void ofApp::runVertExample(){
	if(bWireframe == true){
        sphere.drawWireframe();
    }
    if(bFill == true){
    	ofSetColor(255, 100, 140);
		ofFill();
		vertShader.begin();
		// How do we manipulate vertices and maintain lighting?
		// work together on this!
		vertShader.end();
    }
}

// Key pressed
//
// this changes some stuff in the sketch,
// make it nice for the users :)
//---------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
        case 's':
            bFill = !bFill;
            break;
        case 'w':
            bWireframe = !bWireframe;
            break;
        case '1':
            sphere.setResolution(4);
            icoSphere.setResolution(0); // number of subdivides //
            plane.setResolution(3, 2);
            cylinder.setResolution(4,2,0);
            cone.setResolution(4, 1, 0);
            box.setResolution(1);
            break;
        case '2':
            sphere.setResolution(8);
            icoSphere.setResolution(1);
            plane.setResolution(6, 4);
            cylinder.setResolution(8,4,1);
            cone.setResolution(7, 2, 1);
            box.setResolution(2);
            break;
        case '3':
            sphere.setResolution(16);
            icoSphere.setResolution(2);
            plane.setResolution(8,5);
            cylinder.setResolution(12, 9, 2);
            cone.setResolution(10, 5, 2);
            box.setResolution(6);
            break;
        case '4':
            sphere.setResolution(48);
            icoSphere.setResolution(4);
            plane.setResolution(12, 9);
            cylinder.setResolution(20, 13, 4);
            cone.setResolution(20, 9, 3);
            box.setResolution(10);
            break;
    }

}
