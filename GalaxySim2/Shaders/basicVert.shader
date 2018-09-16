#version 330

in vec4 position;

uniform mat4 projection;
uniform mat4 translation;


void main()
{
	
	gl_Position = projection * translation * position;
}