# Workshop

## 01 Intro

Openframeworks is an opensource C++ library (FRAMEWORK!!) primarily used for creative coding.

It is a great tool for making computational sketches, interactive, and generatve art.

Good online documentation can be found at:

* [openFrameworks Home](https://openframeworks.cc)
* [openFrameworks Forums](https://forum.openframeworks.cc)
* [Lewis Lipton video tutorials](https://www.youtube.com/channel/UC8Wzk_R1GoPkPqLo-obU_kQ)

For inspiration, let's check out some of these projects:

* [Reface Portrait Sequencer](https://vimeo.com/2355887)
* [Augmented Hnad Series](http://www.flong.com/projects/augmented-hand-series/)

## 02 Walkthrough

All openFrameworks projects have a similar structure to start, which looks like this:

```
> bin
	> data
		> someShaderFile.frag
		> anotherShaderFile.vert
		> zebra_doing_a_kickflip.jpg
> src
	> main.cpp
	> ofApp.cpp
	> ofApp.h
```

#### bin/data

This is where we have to store all our shader files (and any other cool things we want, like images or sound files or movie files, and so on).

#### src/main.cpp

If you've taken an openFrameworks class before (that didn't focus on shaders) you probably mostly ignored the `main.cpp` file that comes with all openFrameworks project builds. This becomes an important file when we start using shaders in openFrameworks because it's where we can tell the program which version of openGL to use.

#### src/ofApp.h

The header file for our `ofApp.cpp` file (which is where _the magic happens_). In this header file we can store references that we need throughout our `ofApp.cpp` file (for example, a reference to our shader files).

#### src/ofApp.cpp

Where _the magic happens_. The main functions we want to pay attention to in this file are our `setup()`, and our `update()`/`draw()` functions. `setup()` gets called once at the beginning, and then `update()`/`draw()` get called over and over throughout the lifecycle of the program.

If we're drawing a cool circle on our screen, the file will look something like this:

```
#include "ofApp.h"

float circleX = 0.0;

//--------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(34, 34, 34);
}

//--------------------------
void ofApp::update(){
	circleX = ofMap(
		sin(ofGetElapsedTimef()/100.0),
		-1.0,
		1.0,
		0.0,
		ofGetWidth()
	);
}

//--------------------------
void ofApp::draw(){
	ofSetColor(245, 58, 135);
	ofFill();
	ofDrawCircle(circleX, ofGetHeight()/2.0, 100.0);
}
```

#### Getting a shader in there

To get to the good parts: it is very easy to load shaders into your OF project via the ofShader object.

This command loads a shader from files stored in your bin/data folder:

```
shader.load()
```

To access your shader and use it for everything that comes after the function is called: 

```
shader.begin()
```

And, to stop using your shader:
```
shader.end()
```

Let's check this all out in action:

```
#include "ofApp.h"

ofShader shader;
float circleX = 0.0;

//--------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(34, 34, 34);
	// load our shaders
	shader.load(
		"someShaderFile.vert",
		"anotherShaderFile.frag"
	);
}

//--------------------------
void ofApp::update(){
	circleX = ofMap(
		sin(ofGetElapsedTimef()/100.0),
		-1.0,
		1.0,
		0.0,
		ofGetWidth()
	);
}

//--------------------------
void ofApp::draw(){
	ofSetColor(245, 58, 135);
	ofFill();
	shader.begin();
	ofDrawCircle(circleX, ofGetHeight()/2.0, 100.0);
	shader.end();
}
```

#### openFrameworks openGL variables

We're given some variables *for free* in openFrameworks available to shaders. These are:

* `uniform mat4 modelViewMatrix;`
* `uniform mat4 projectionMatrix;`
* `uniform mat4 modelViewProjectionMatrix;`
* `uniform mat4 textureMatrix;`
* `uniform vec4 globalColor;`

## 03 Explore

> Oh that's cool [SEAN]

## 04 Frag Shaders

> Oh, so cool [NOAH]

## 05 Vert Shaders

> Oh cool, neat [BOTH]
