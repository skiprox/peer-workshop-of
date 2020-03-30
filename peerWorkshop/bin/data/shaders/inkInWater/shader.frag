#version 150

// in
in vec3 vecNormal;

// out
out vec4 outputColor;// fragment shader always has one vec4 output: the pixel color

// uniforms
uniform vec2 u_resolution;
uniform float u_time;

// variables
const int AMOUNT=12;

void main(){
    
    vec2 coord = (17.*(gl_FragCoord.xy-u_resolution/2.)/min(u_resolution.y,u_resolution.x));
    
    float len;
    
    for(int i=0;i<AMOUNT;i++){
        len=length(vec2(coord.x,coord.y));
        coord.x=coord.x-cos(coord.y+sin(len))+cos(u_time/7.);
        coord.y=coord.y+sin(coord.x+cos(len))+sin(u_time/10.);
    }

    // This is where the light is
    vec3 light=vec3(.5,2.2,1.);
    light=normalize(light);
    
    // dot product
    // make the minimum 0.3 so we get *some* light everywhere
    float dProd=max(.3,dot(vecNormal,light));

    vec4 color = vec4(cos(len), cos(len*1.4), cos(len*1.3), 1.);
    vec4 colorWithLighting = vec4(vec3(dProd)*vec3(color),1.);

    outputColor = colorWithLighting;
}
