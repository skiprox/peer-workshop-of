#version 150
in vec3 vecNormal;

out vec4 outputColor;

uniform vec2 u_resolution;
uniform float u_time;

void main(){
    vec3 light=vec3(.5,.2,1.);
    light=normalize(light);
    
    // dot product
    float dProd=max(0.,dot(vecNormal,light));
    
    float r=gl_FragCoord.x/u_resolution.x;
    float g=gl_FragCoord.y/u_resolution.y;
    float b=abs(sin(u_time)*g);
    float a=1.;
    
    outputColor=vec4((vec3(r,g,b)*vec3(dProd)),1.);
}