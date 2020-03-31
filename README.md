# Peer Workshop

> Noah and Sean's peer workshop

### General Description

In this workshop we will teach the shader openFrameworks pipeline. This will include:

* How openGL versioning works in openFrameworks (and what different versions offer)
	* This is a warning because different versions use different keywords to the same things. We are going to use *openGL 3.2* with *GLSL 1.5*
* Built in variables available to shaders in openFrameworks
	* uniform mat4 modelViewMatrix;
	* uniform mat4 projectionMatrix;
	* uniform mat4 modelViewProjectionMatrix;
	* uniform mat4 textureMatrix;
	* uniform vec4 normalMatrix;
* Creating objects in openFrameworks to put shaders on them
	* Frag shaders!
	* Vert shaders!

### Learning Objectives

* Basic understanding of openFrameworks and the shader pipeline in OF
* Ability to create objects and apply different fragment shaders to them
* Ability to apply vert shaders to objects and maintain lighting


### Questions and Answers

* _Q_: What is openFrameworks, and what does it have to do with shaders?
* _Q_: Why might I want to use OF and shaders?
* _Q_: How do I set up a shader in OF?
* _Q_: How do I set up multiple shaders simultaneously in OF?
* _Q_: What are the built in variables in the openFrameworks shader pipeline, and what do they do?
* _Q_: How do I create and manipulate objects using shaders in OF?
* _Q_: How do I wrap textures around different shapes?
* _Q_: How can I make shaders interactive in OF?

### Lesson Plan

| Name | Duration | Purpose | Description |
| ---- | ---- | ---- | ---- |
| Intro | 5 mins | Engage | What can openFrameworks do for you? What's some cool stuff people have done in openFrameworks using shaders? |
| Walkthrough | 20 mins | Study | openFrameworks pipeline, from main.cpp to ofApp.h to ofApp.cpp to vert and frag shaders, talk about built in variables in OF shaders |
| Frag Shaders | 15 mins | Activate | Play around with the existing frag shaders in the repo, and write your own frag shader  |
| Vert Shaders | 15 mins | Explore | Work together as a class to try and use vert shaders and manipulate the vertices of objects while maintaining lighting |


### To Prepare/Bring

* Students should have openFrameworks (>= 0.10.0) up and running on their machines
	* go to [openframeworks.cc/download](https://openframeworks.cc/download/) to download openFrameworks, follow instructions and get the necessary IDE for your operating system
	* run one example from the `examples/` folder in your openFrameworks root directory, debug if necessary
* Look through one or two examples in `examples/` folder to familiarize yourself with the build pipeline and what kind of files you'll be encountering (check out the `src/` folder in these examples)
* Clone this repository and run one of the openFrameworks examples, debug if necessary

### Materials Provided

* This repository with demo starter code to cover the following:
	* The pipeline, creating objects, built in variables, writing uniforms and varyings, ins & outs, and passing them around
	* Frag shaders
	* Vert shaders

