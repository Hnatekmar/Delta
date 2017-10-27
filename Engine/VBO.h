//
// Created by martin on 27.10.17.
//

#ifndef PROJECT_VBO_H
#define PROJECT_VBO_H

#include <GL/glew.h>
#include <list>
#include "Exceptions/EngineException.h"

/**
 * @brief Obal nad vbo. Jeho hlavní výhoda je, že se díky RAII postará o uvolnění bufferu
 */
template<typename T>
class VBO {
    GLuint m_vbo;
    GLsizeiptr m_size;
public:
    VBO(const T* data, GLsizeiptr size, GLenum usagePattern): m_vbo(0), m_size(size) {
        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, size, data, usagePattern);
        HANDLE_GL_ERRORS()
    }

    /**
     * Vrací počet prvků uložených ve VBO
     * @return počet prvků
     */
    GLsizei count() const {
        return m_size / sizeof(T);
    }

    /**
     * @brief Nabinduje buffer
     */
    void bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    }

    ~VBO() {
        glDeleteBuffers(1, &m_vbo);
    }
};


#endif //PROJECT_VBO_H
