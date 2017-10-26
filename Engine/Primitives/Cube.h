//
// Created by martin on 24.10.17.
//

#ifndef PROJECT_CUBE_H
#define PROJECT_CUBE_H

#include <GL/glew.h>
#include "../IDrawable.h"

class Cube: public IDrawable {
    GLuint m_vbo;
    GLuint m_shaderProgram;
    GLuint m_positionAttrib;
    GLuint m_transformMatrix;
    static constexpr GLfloat s_data[] = {
            0.0f, 0.0f, 0.0f,
            0.5f, 1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
    };
public:
    Cube();

    void draw(const glm::mat4 &transform) override;
};


#endif //PROJECT_CUBE_H
