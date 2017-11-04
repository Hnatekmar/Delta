#version 330 core

in vec4 position;
in vec4 solidColor;
uniform mat4 transform;
out vec4 vertexColor;

void main() {
    gl_Position = transform * position;
    vertexColor = solidColor;
}