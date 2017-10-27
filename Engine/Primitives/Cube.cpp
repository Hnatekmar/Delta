//
// Created by martin on 24.10.17.
//

#include <iostream>
#include "Cube.h"
#include "../Shader.h"

Cube::Cube(): m_vbo(&s_data[0], sizeof(s_data), GL_STATIC_DRAW)
{
    m_vbo.bind();
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
    m_positionAttrib = static_cast<GLuint>(positionAttrib);
    m_transformMatrix = static_cast<GLuint>(glGetUniformLocation(m_shaderProgram, "transform"));
}


void Cube::draw(const glm::mat4 &transform) {
    m_vbo.bind();
    glVertexAttribPointer(m_positionAttrib, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glUniformMatrix4fv(m_transformMatrix, 1, GL_FALSE, &transform[0][0]);
    glEnableVertexAttribArray(m_positionAttrib);
    glUseProgram(m_shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, m_vbo.count() / 3); // 9 GLFloatu, které reprezentují 3 vertexy
    glDisableVertexAttribArray(m_positionAttrib);
}