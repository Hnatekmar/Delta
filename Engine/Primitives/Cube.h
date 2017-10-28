//
// Created by martin on 24.10.17.
//

#ifndef PROJECT_CUBE_H
#define PROJECT_CUBE_H

#include <GL/glew.h>
#include "../IDrawable.h"
#include "../VBO.h"

struct Vertex {
    glm::vec4 position;
    glm::vec4 color;
};


class Cube: public IDrawable {
    GLuint m_shaderProgram;
    GLuint m_positionAttrib;
    GLuint m_colorAttrib;
    GLuint m_transformMatrix;
    VBO<Vertex> m_vbo;
public:
    Cube();

    void draw(const glm::mat4 &transform) override;
};


#endif //PROJECT_CUBE_H
