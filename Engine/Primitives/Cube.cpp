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
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    glLinkProgram(m_shaderProgram);
    GLint position = glGetAttribLocation(m_shaderProgram, "position");
    assert(position != -1);
    GLint color = glGetAttribLocation(m_shaderProgram, "solidColor");
    assert(color != -1);
    GLint transform = glGetUniformLocation(m_shaderProgram, "transform");
    assert(transform != -1);
    m_positionAttrib = static_cast<GLuint>(position);
    m_colorAttrib = static_cast<GLuint>(color);
    m_transformMatrix = static_cast<GLuint>(transform);
    HANDLE_GL_ERRORS()
}


void Cube::draw(const glm::mat4 &transform) {
    m_vbo.bind();
    glUseProgram(m_shaderProgram);
    glEnableVertexAttribArray(m_positionAttrib);
    glEnableVertexAttribArray(m_colorAttrib);
    glVertexAttribPointer(m_positionAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glVertexAttribPointer(m_colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(glm::vec4));
    glUniformMatrix4fv(m_transformMatrix, 1, GL_FALSE, &transform[0][0]);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vbo.count() - 8);
    glDrawArrays(GL_TRIANGLE_STRIP, m_vbo.count() - 8, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, m_vbo.count() - 4, 4);
    glDisableVertexAttribArray(m_colorAttrib);
    glDisableVertexAttribArray(m_positionAttrib);
    m_vbo.unbind();
    HANDLE_GL_ERRORS()
}