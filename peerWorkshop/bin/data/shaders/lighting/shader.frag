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
	// This is where the light is
    vec3 light = vec3(0.5, 2.2, 1.0);
    light = normalize(light);

    // dot product
    float dProd = max(0.0, dot(vecNormal, light));

    //color
    // the materialcolor gets passed in from our program,
    // but we could calculate it here *i think*
    // so for example you could have color be a gradient or something
    vec4 color = u_materialColor;
    vec4 col = vec4( vec3( dProd ) * vec3( color ), 1.0 );
    fragColor = col;
}
