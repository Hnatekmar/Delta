#version 330

in vec4 color;
in vec4 position;
out vec4 vertexColor;
uniform mat4 transform;

void main() {
    gl_Position = transform * position;
    vertexColor = color;
}