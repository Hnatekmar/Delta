//
// Created by martin on 24.10.17.
//

#include "Cube.h"

Cube::Cube(): m_vbo(0)
{
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(m_vbo, sizeof(s_data), s_data, GL_STATIC_DRAW);
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vertexSource =
            "#version 120\n"
            "layout(location = 0) in vec3 pos;"
            "void main() {\n"
            "   gl_Position = vec4(pos, 1.0);"
            "}\n";
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fragmentSource =
            "#version 120\n"
            "out vec4 color;"
            "void main() {\n"
            "   gl_FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);"
            "}\n";
    glShaderSource(vertex, 1, &vertexSource, nullptr);
    glShaderSource(fragment, 1, &fragmentSource, nullptr);
    glCompileShader(vertex);
    glCompileShader(fragment);
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, vertex);
    glAttachShader(m_shaderProgram, fragment);
    glLinkProgram(m_shaderProgram);
    glUseProgram(m_shaderProgram);
}

void Cube::draw() {
    glUseProgram(m_shaderProgram);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glEnableVertexAttribArray(0);
    glVertexPointer(3, GL_FLOAT, GL_FALSE, nullptr);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 1);
    glDisableVertexAttribArray(0);
}