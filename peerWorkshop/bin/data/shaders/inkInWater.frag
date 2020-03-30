#version 150

// input from vertex shader
in vec2 vTexcoord;

out vec4 outputColor;// fragment shader always has one vec4 output: the pixel color

uniform vec2 u_resolution;
uniform float u_time;

const int AMOUNT=12;

void main(){
    
    vec2 coord=(17.*(gl_FragCoord.xy-u_resolution/2.)/min(u_resolution.y,u_resolution.x));
    
    float len;
    
    for(int i=0;i<AMOUNT;i++){
        len=length(vec2(coord.x,coord.y));
        
        coord.x=coord.x-cos(coord.y+sin(len))+cos(u_time/7.);
        coord.y=coord.y+sin(coord.x+cos(len))+sin(u_time/10.);
        
    }
    outputColor=vec4(cos(len),cos(len*1.4),cos(len*1.3),1.);
}
