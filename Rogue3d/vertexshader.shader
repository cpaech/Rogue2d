#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
  
out vec4 vertexColor; // specify a color output to the fragment shader
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
float rand(vec2 co)
{
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}
void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(rand(aPos.xy), rand(aPos.xy), rand(aPos.xy), 1.0); // set the output variable to a dark-red color
}