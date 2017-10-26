//
// Created by martin on 24.10.17.
//

#include <iostream>
#include "Cube.h"
#include "../Shader.h"

Cube::Cube(): m_vbo(0)
{
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(s_data), s_data, GL_STATIC_DRAW);
    m_shaderProgram = glCreateProgram();
    auto vertex = compileShader(GL_VERTEX_SHADER, "default.vert");
    auto fragment = compileShader(GL_FRAGMENT_SHADER, "default.frag");
    glAttachShader(m_shaderProgram, vertex);
    glAttachShader(m_shaderProgram, fragment);
    glLinkProgram(m_shaderProgram);
    GLint success;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    glUseProgram(m_shaderProgram);
    GLint positionAttrib = glGetAttribLocation(m_shaderProgram, "position");
    m_positionAttrib = positionAttrib;
}

void Cube::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(m_positionAttrib, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(m_positionAttrib);
    glUseProgram(m_shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(m_positionAttrib);
}