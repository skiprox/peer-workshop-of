# Workshop

## 01 Intro

Openframeworks is an opensource C++ library (FRAMEWORK!!) primarily used for creative coding.

It is a great tool for making computational sketches, interactive, and generatve art.

Good online documentation can be found at:

* [openFrameworks Home](https://openframeworks.cc)
* [openFrameworks Forums](https://forum.openframeworks.cc)
* [Lewis Lipton video tutorials](https://www.youtube.com/channel/UC8Wzk_R1GoPkPqLo-obU_kQ)

For inspiration, let's check out some of these projects:

* [Zach Lieberman's Instagram](https://www.instagram.com/zach.lieberman/?hl=en)
* [Memo Atkins Bodypaint](http://www.memo.tv/portfolio/bodypaint/)
* [Reface Portrait Sequencer](https://vimeo.com/2355887)
* [Augmented Hand Series](http://www.flong.com/projects/augmented-hand-series/)

## 02 Walkthrough

All openFrameworks projects have a similar structure to start, which looks like this:

```
> bin
  > data
    > shaders
      > shader.vert
      > shader.frag
    > images
> src
  > main.cpp
  > ofApp.cpp
  > ofApp.h
```

#### bin/data

This is where we have to store all our shader files (and any other cool things we want, like images or sound files or movie files, and so on).

#### src/main.cpp

If you've taken an openFrameworks class before (that didn't focus on shaders) you probably mostly ignored the `main.cpp` file that comes with all openFrameworks project builds (except when changing the window size). This becomes an important file when we start using shaders in openFrameworks because it's where we can tell the program which version of openGL to use.

For us, we're using openGL 3.2, which corresponds with GLSL 1.5 (which is noted `#version 150` in our shader programs). We're using this because it's the latest version that we can get running that (hopefully) will also work on all your machines.

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

To help understand what we're talking about in this section, here is a brief explanation of "model", "view" and "projection" matrices.

> The model, view and projection matrices are three separate matrices. The model matrix maps from an object's local coordinate space into world space. The view matrix maps from world space to camera space. The projection matrix from camera space to screen space.

With that, we're given some variables *for free* in openFrameworks available to shaders. These are:

* `uniform mat4 modelViewMatrix;`
	* A combination of model matrix and view matrix. Model matrix defines the frame's positions of the primitives you are going to draw, while view matrix defines the position of the camera.
* `uniform mat4 projectionMatrix;`
	* Defines the characteristics of your camera such as clip planes, field of view, and projection method.
* `uniform mat4 modelViewProjectionMatrix;`
	* A combination of the model, view, and projection matrices. 
* `uniform mat4 textureMatrix;`
	* TODO: Honestly? A little unsure about this one
* `uniform vec4 normalMatrix;`
	* TODO: Not sure!

## 03 Frag Shaders (lighting example)

Let's walk through the frag shaders we have for you. In our directory we have these shaders for our _viewing pleasure_:

```
> bin
  > data
    > shaders
      > gradient
        > shader.frag
        > shader.vert
      > lighting
        > shader.frag
        > shader.vert
      > inkInWater
        > shader.frag
        > shader.vert
```

We're going to start with the lighting example. The way shaders in openFrameworks works is that (if both vert and frag shaders are passed to the `cpp` file) the vert shader gets run first and then the frag shader, and you are able to pass things from the vert to the frag shader. So, here is what our `lighting/shader.vert` file looks like:

```
#version 150

// What we send out (to our frag shader)
out vec3 vecNormal;

// available attributes using programmable renderer
in vec4 position;
in vec4 color;
in vec4 normal;
in vec2 texcoord;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
// Honestly? not quite sure what these are
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;

void main(){
  vecNormal = normal.xzy;
  gl_Position = modelViewProjectionMatrix * position;
}

```

So what do we have here? After we declare the version of `GLSL` (1.5, which we note as `#version 150`) we declare what we will be sending `out` to our `frag` shader, a `vec3` called `vecNormal`, which if we look down we see is just the `xyz` values of our `normal`, which is an attribute available from the programmable renderer. We have a bunch of other things that we get for free from the programmable renderer, like the `modelViewProjectionMatrix` and so on. In our `main` function all we do is set our `vecNormal` variable to send out to our `frag` shader, and get `gl_Position` by multiplying the position attribute by the `modelViewProjectionMatrix` to get the position of our object on the screen.

Next, we have our frag shader:

```
#version 150

// Passed from our vert shader
in vec3 vecNormal;

// What we send out
out vec4 fragColor;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
// Honestly? not quite sure what these are
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;
// this is set in the OF app
uniform vec4 u_materialColor;
uniform vec2 u_resolution;

void main(){
  // This is where the light is
  vec3 light = vec3(.5, 2.2, 1.);
  light = normalize(light);
    
  // dot product
  // make the minimum 0.3 so we get *some* light everywhere
  float dProd = max(.3, dot(vecNormal, light));
    
  //color
  // the materialcolor gets passed in from our program,
  // but we could calculate it here *i think*
  // so for example you could have color be a gradient or something
  vec4 color = u_materialColor;
  vec4 col = vec4(vec3(dProd) * vec3(color), 1.);
  fragColor = col;
}

```

Let's ignore the attributes and uniforms from the programmable renderer. Other than those we have an input (`vecNormal`) which is coming from our `vert` shader, an output (`fragColor`) which we are sending back to our program, and two uniforms (`u_materialColor` and `u_resolution`) which come from our `main.cpp` file. We take these uniforms in our `main()` function and do essentially what we've seen before to calculate the color with lighting (check the Unity examples where we covered lighting).

## 04 Active Frag Shaders

Challenges:

* Play around with these frag shaders we've given you, and change the colors
* Add new uniforms to the existing frag shaders and use these to change them
* Make your own frag shader and apply it to a custom shape
* Use the shader as a once-over texture (in other words, the coordinates system should be in reference to the object itself and not the field of view)

## 05 Explore Vert Shaders

Goals:

* Use a vert shader to manipulate the vertices of an object
* Maintain lighting while manipulating the vertices
* Take in custom uniforms to manipulate vertices with user input (while maintaining lighting!)
