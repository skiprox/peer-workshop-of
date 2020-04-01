#version 150

// Passed from our vert shader
in vec3 vecNormal;

// What we send out
out vec4 fragColor;

// these are passed in from OF programmable renderer
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
// Honestly? not quite sure what these are
uniform mat4 textureMatrix;
uniform mat4 normalMatrix;
// this is set in the OF app
uniform vec2 u_resolution;
uniform float u_time;

void main(){
	float r = gl_FragCoord.x / u_resolution.x;
	float g = gl_FragCoord.y / u_resolution.y;
    float b = abs(sin(u_time) * g);
	float a = 1.0;

    // This is where the light is
    vec3 light = vec3(.5, 2.2, 1.);
    light = normalize(light);
    
    // dot product
    // make the minimum 0.3 so we get *some* light everywhere
    float dProd = max(.3, dot(vecNormal, light));
    
    // color
    vec4 color = vec4(r, g, b, a);
    vec4 col = vec4(vec3(dProd) * vec3(color), 1.);
    fragColor = col;
}
