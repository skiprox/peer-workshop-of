#include "ofApp.h"

float circleX = 0.0;

//---------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofSetSphereResolution(128);
	ofBackground(34, 34, 34);
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	ofEnableLighting();
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	glEnable(GL_DEPTH_TEST);


	// Explore setup! [NOAH]
	// Create some shapes
	// This provides them with a few 3D shapes,
	// a basic shader on top of that (maybe returning one color)
	// and they can play around with that

	// for primitives

	// for backward compatibility reasons
	ofDisableArbTex();

	/*
	* Setup all primitive shapes
	*/
	setupPrimitiveShapes();

	// An example with lighting,
	// how to incorportate normals into your shader
	setupLightingExample();

	// Ink example
	setupInkExample();

	// Gradient example
	setupGradientExample();

	// Going further! [SEAN + NOAH, each add 2 frag shaders that can be used later]
	// A raycasting example? Just some more complex frag shaders
	// Passing in uniforms!
	setupRaycastingExample();

	// Vert shader stuff [SEAN]
	// What to do here? idk?
	// Make a blobby shape that wiggles AND RETAINS LIGHTING
}

// Establish all the primitive shapes
//---------------------------------------
void ofApp::setupPrimitiveShapes(){
	bFill = true;
    bWireframe = false;
    cone.setRadius(100);
    plane.setWidth(90);
    // basic lighting example
    cylinder.set(100, 200);
    // ink example
    icoSphere.setRadius(200);
    icoSphere.setPosition(0, 0, 0);
    // gradient example
    box.set(100);
	box.setPosition(-200, -200, 0);
	// raycasting example
	sphere.setRadius(100);
	sphere.setPosition(200, 200, 0);
}

// Lighting example
// help from
// https://forum.openframeworks.cc/t/3d-model-in-custom-shader/20004/2
//---------------------------------------
void ofApp::setupLightingExample(){
	colorWithLightShader.load("shaders/lighting/shader.vert","shaders/lighting/shader.frag");
	// Material stuff,
	// for this example specifically
	material.setShininess(120);
	material.setSpecularColor(ofColor(255, 255, 255, 255));
	material.setEmissiveColor(ofColor(0, 0, 0, 255));
	material.setDiffuseColor(ofColor(255, 255, 255, 255));
	material.setAmbientColor(ofColor(255, 255, 255, 255));
}

// Ink shader setup
//---------------------------------------
void ofApp::setupInkExample(){
	inkInWaterShader.load("shaders/inkInWater/shader");
}

// Gradient shader setup
//---------------------------------------
void ofApp::setupGradientExample(){
	basicGradient.load("shaders/gradient/shader");
}

// Raycasting shader setup
//---------------------------------------
void ofApp::setupRaycastingExample(){
	raycastingShader.load("shaders/raycasting/shader");
}

// Main update function
//---------------------------------------
void ofApp::update(){
	ofBackground(0);
	circleX = ofMap(
		sin(ofGetElapsedTimef()),
		-1.0,
		1.0,
		-ofGetWidth()/2.0,
		ofGetWidth()/2.0
	);
	rotate++;
}

//---------------------------------------
void ofApp::draw(){
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
	runGradientExample();

	// Ink shader example
	// this is a goopy ink shader on a sphere
	runInkExample();

	// Ray casting example
	// a sweet ray casting thing
	// on a sphere
	runRaycastingExample();

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

// Raycasting example
//---------------------------------------
void ofApp::runRaycastingExample(){
	if(bWireframe == true){
        sphere.drawWireframe();
    }
    if(bFill == true){
    	ofSetColor(255, 100, 140);
		ofFill();
		raycastingShader.begin();
		raycastingShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
		sphere.draw();
		raycastingShader.end();
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
