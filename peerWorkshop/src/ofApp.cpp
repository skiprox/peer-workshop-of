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
	sphere.setRadius(100);

	// for backward compatibility reasons
	ofDisableArbTex();
	// ofLoadImage(tex, "images/empireOfLight.jpg");
	// img.load("images/empireOfLight.jpg");

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
//    center.set(0, 0, 0);
	// sphere.setRadius(180.0f);
//    sphere.mapTexCoordsFromTexture(img.getTexture());
//    ofMesh* mesh = sphere.getMeshPtr();
//    mesh->setColorForIndices(0, mesh->getNumIndices(), ofColor::red);


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
	ofDrawSphere(100.0, 100.0, 0.0, 100);
	raycastingShader.end();
}

void ofApp::runInkExample(){
	inkInWaterShader.begin();
	inkInWaterShader.setUniform1f("u_time", ofGetElapsedTimef());
	inkInWaterShader.setUniform2f("u_resolution", ofGetWidth(),ofGetHeight());

//    ofRotateZDeg(rotate);
//    ofRotateXDeg(rotate);
//    tex.bind();
//    box.set(100);
//    box.setPosition(0,0,0);
//    box.draw();
	// ofDrawBox(0, 0, 0, 200);
//    ofDrawCylinder(0, 0, 0, 50, 100);
	sphere.setRadius(100);
	sphere.draw();
//    ofDrawSphere(0,0,0,100);

//    ofPushMatrix();
//    ofTranslate(center.x, center.y, center.z - 300);
//    ofRotate(ofGetElapsedTimef() * .8 * RAD_TO_DEG, 0, 1, 0);
//    sphere.draw();
//    ofPopMatrix();
	//    tex.unbind();
//    ofPopMatrix();
	inkInWaterShader.end();

}
//---------------------------------------
void ofApp::runGradientExample(){
	basicGradient.begin();
	basicGradient.setUniform1f("u_time", ofGetElapsedTimef());
	basicGradient.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	ofDrawSphere(-100.0, -100.0, 0.0, 100);
	basicGradient.end();
}
