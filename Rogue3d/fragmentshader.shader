#version 330 core
out vec4 FragColor;
uniform vec4 ourColor;
uniform sampler2D texture1;
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  

void main()
{
    FragColor = texture(texture1, vertexColor.xy);
} 