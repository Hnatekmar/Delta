//
// Created by martin on 27.10.17.
//

#ifndef PROJECT_ENGINEEXCEPTION_H
#define PROJECT_ENGINEEXCEPTION_H

#include <string>
#include <GL/glew.h>

#define HANDLE_GL_ERRORS() \
    static GLenum error; \
    while((error = glGetError()) != GL_NO_ERROR) { \
        throw EngineException(error); \
    }

class EngineException {
    std::string m_error;
public:
    explicit EngineException(GLenum error);
    std::string error() const;
};


#endif //PROJECT_ENGINEEXCEPTION_H
