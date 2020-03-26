#version 120

void main(){
	
	//get our current vertex position so we can modify it
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
	
	//finally set the pos to be that actual position rendered
	gl_Position = pos;
}
