#version 150

in vec4 position;

uniform mat4 modelViewProjectionMatrix;


void main(){
    	
	//get our current vertex position so we can modify it
	vec4 pos = modelViewProjectionMatrix * position;
	gl_Position = pos;
}
