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
}

// Raycasting example
//---------------------------------------
void ofApp::setupRaycastingExample(){
	raycastingShader.load("shaders/raycasting/shader.vert","shaders/raycasting/shader.frag");
}

//---------------------------------------
void ofApp::setupInkExample(){
	inkInWaterShader.load("shaders/inkInWater");
    bFill = true;
    bWireframe = false;
    
    sphere.setRadius(100);
    box.set(100);
    cylinder.setRadius(100);
    cone.setRadius(100);
    icoSphere.setRadius(200);
    plane.setWidth(90);

}
//---------------------------------------
void ofApp::setupGradientExample(){
	basicGradient.load("shaders/gradient");
}
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
	cam.begin();

	// Explore examples
    
	// Lighting shader example
	runLightingExample();

	//basic gradient example
	runGradientExample();

	//primitive shape texturing example
	runInkExample();

	// Going further examples
	runRaycastingExample();

	cam.end();
    
    
    //instead of gui
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
	ofFill();
	colorWithLightShader.begin();
	colorWithLightShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	colorWithLightShader.setUniform4f("u_materialColor", ofColor(255.0, 80.0, 130.0, 255.0));
	ofDrawSphere(circleX, 0.0, 0.0, 100);
	colorWithLightShader.end();

}

// Raycasting example
//---------------------------------------
void ofApp::runRaycastingExample(){
	ofSetColor(255, 100, 140);
	ofFill();
	raycastingShader.begin();
	raycastingShader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	ofDrawSphere(100.0, 100.0, 0.0, 100);
	raycastingShader.end();
}
//---------------------------------------

void ofApp::runInkExample(){
	inkInWaterShader.begin();
	inkInWaterShader.setUniform1f("u_time", ofGetElapsedTimef());
	inkInWaterShader.setUniform2f("u_resolution", ofGetWidth(),ofGetHeight());

    ofPushMatrix();
    ofRotateZDeg(rotate);
    ofRotateXDeg(rotate);
    if(bWireframe == true){
//        sphere.drawWireframe();
//        cone.drawWireframe();
//        cylinder.drawWireframe();
//        plane.drawWireframe();
//        mesh.drawWireframe();
        icoSphere.drawWireframe();
//        box.drawWireframe();
    }
    if(bFill == true){
//        sphere.draw();
//        cone.draw();
//        cylinder.draw();
//        plane.draw();
//        mesh.draw();
        icoSphere.draw();
//        box.draw();
    }
    
    ofPopMatrix();
	inkInWaterShader.end();

}
//---------------------------------------
void ofApp::runGradientExample(){
	basicGradient.begin();
	basicGradient.setUniform1f("u_time", ofGetElapsedTimef());
	basicGradient.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    box.draw();
	basicGradient.end();
}
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
