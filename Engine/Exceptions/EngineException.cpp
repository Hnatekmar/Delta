//
// Created by martin on 27.10.17.
//

#include "EngineException.h"

EngineException::EngineException(GLenum error) {
    m_error = (char*)(gluErrorString(error));
}


std::string EngineException::error() const {
    return m_error;
}
