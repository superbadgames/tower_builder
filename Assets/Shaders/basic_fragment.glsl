#version 330 core
out vec4 outputColor;

in vec2 vertex_uvs;

uniform sampler2D myTexture;
uniform vec4 color;


void main()
{
    outputColor = color * texture(myTexture, vertex_uvs);
}