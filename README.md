# Peer Workshop

> Noah and Sean's peer workshop

### General Description

In this workshop we will teach the shader openFrameworks pipeline. This will include:

* How versioning works (and what different versions offer)
* Built in variables available to shaders in openFrameworks
	* uniform mat4 modelViewMatrix;
	* uniform mat4 projectionMatrix;
	* uniform mat4 modelViewProjectionMatrix;
	* uniform mat4 textureMatrix;
	* uniform vec4 globalColor;
* Creating objects in openFrameworks to put shaders on
	* Meshes!
* Using the same shaders on different objects
* Using different shaders on different objects
* Using textures in shaders
	* Passing images and video as textures
* FBOs and VBOs

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
| Intro | 10 mins | Engage | Talk about openFrameworks, why it might be a good tool for you |
| Setup | 5 mins | Study | Get it running on everyones machines |
| Walkthrough | 15 mins | Study | Walk through the pipeline, from main.cpp to ofApp.h to ofApp.cpp to vert and frag shaders, talk about built in variables in OF shaders |
| Explore | 15 mins | Activate | Create a new shape or stick with the existing mesh, play around with values in your vert and frag shaders, pass different uniforms to the shaders to make them interactive |
| Frag Shaders | 15 mins | Study | Run the frag shader repo provided. Update the code to take multiple shaders for multiple objects |
| Frag Shaders cont. | 15 mins | Activate | Try to get some ray casting code (or something similarly insane) onto objects in your scene |
| Vert Shaders | 15 mins | Study | Run the vert shader repo provided. Talk about vertex manipulation and lighting, and passing information |
| Vert Shaders cont. | 15 mins | Activate | Play around with using both vert and frag shaders in conjunction |
| Textures | 5 mins | Study | How textures are used in OF |
| Textures cont. | 15 mins | Activate | Wrap it up! |


### To Prepare/Bring

* Students should have openFrameworks (>= 0.10.0) up and running on their machines
	* go to [openframeworks.cc/download](https://openframeworks.cc/download/) to download openFrameworks, follow instructions and get the necessary IDE for your operating system
	* run one example from the `examples/` folder in your openFrameworks root directory, debug if necessary
* Look through one or two examples in `examples/` folder to familiarize yourself with the build pipeline and what kind of files you'll be encountering (check out the `src/` folder in these examples)
* Clone this repository and run one of the openFrameworks examples, debug if necessary

### Materials Provided

* This repository with demo starter code to cover the following:
	* The pipeline, creating objects, built in variables, writing uniforms and varyings and passing them around
	* Frag shaders on meshes
	* Vert shaders on meshes
	* Textures!

