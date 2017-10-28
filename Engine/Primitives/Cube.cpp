//
// Created by martin on 24.10.17.
//

#include <iostream>
#include "Cube.h"
#include "../Shader.h"


Vertex data[] = {
        // FRONT
        {glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
        // RIGHT
        {glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
        {glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
        // BACK
        {glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)},
        {glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)},
        // LEFT
        {glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)},
        {glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)},
        // TOP
        {glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)},
        {glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)},
        // BOTTOM
        {glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)},
        {glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)},
        {glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)},
        {glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)},
};

Cube::Cube(): m_vbo(data, sizeof(data), GL_STATIC_DRAW)
{
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
    assert(positionAttrib != -1);
    GLint colorAttrib = glGetAttribLocation(m_shaderProgram, "color");
    assert(colorAttrib != -1);
    m_colorAttrib = static_cast<GLuint>(colorAttrib);
    m_positionAttrib = static_cast<GLuint>(positionAttrib);
    m_transformMatrix = static_cast<GLuint>(glGetUniformLocation(m_shaderProgram, "transform"));
    HANDLE_GL_ERRORS()
}


void Cube::draw(const glm::mat4 &transform) {
    m_vbo.bind();
    glVertexAttribPointer(m_positionAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glVertexAttribPointer(m_colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(glm::vec4));
    glUniformMatrix4fv(m_transformMatrix, 1, GL_FALSE, &transform[0][0]);
    glEnableVertexAttribArray(m_positionAttrib);
    glEnableVertexAttribArray(m_colorAttrib);
    glUseProgram(m_shaderProgram);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vbo.count() - 8);
    glDrawArrays(GL_TRIANGLE_STRIP, m_vbo.count() - 8, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, m_vbo.count() - 4, 4);
    glDisableVertexAttribArray(m_colorAttrib);
    glDisableVertexAttribArray(m_positionAttrib);
}