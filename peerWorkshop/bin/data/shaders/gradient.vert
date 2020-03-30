#version 150

out vec3 vecNormal;

in vec4 position;
in vec4 color;
in vec4 normal;// vertex's normal
in vec2 texcoord;// vertex's texture coordinate

uniform mat4 modelViewProjectionMatrix;
out vec2 vTexcoord;

void main(){
    vecNormal=normal.xzy;
    
    vTexcoord=texcoord;
    
    // this is the only really important part of the vertex shader:
    // tells openGL where this vertex is on screen
    gl_Position=position*modelViewProjectionMatrix;
}

