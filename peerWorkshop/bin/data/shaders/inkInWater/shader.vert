#version 150

// in
in vec4 position;
in vec4 color;
in vec4 normal;// vertex's normal
in vec2 texcoord;// vertex's texture coordinate

// out
out vec3 vecNormal;

// uniforms
uniform mat4 modelViewProjectionMatrix;

void main(){

    vecNormal = normal.xzy;
    
    // this is the only really important part of the vertex shader:
    // tells openGL where this vertex is on screen
    gl_Position=modelViewProjectionMatrix * position;
}

