#version 150
in vec3 vecNormal;

out vec4 fragColor;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;
// this is set in the OF app
uniform vec4 u_materialColor;
uniform vec2 u_resolution;

void main(){
    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
