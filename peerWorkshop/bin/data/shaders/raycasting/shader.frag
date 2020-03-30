#version 150
in vec3 vecNormal;

out vec4 fragColor;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;
uniform vec2 u_resolution;

void main(){
    //color
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
	float r = gl_FragCoord.x / u_resolution.x;
	float g = gl_FragCoord.y / u_resolution.y;
	float b = 1.0;
	float a = 1.0;
    fragColor = vec4(r, g, b, a);
}
