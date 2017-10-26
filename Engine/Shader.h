//
// Created by martin on 26.10.17.
//

#ifndef PROJECT_SHADER_H
#define PROJECT_SHADER_H


#include <GL/glew.h>
#include <string>

GLuint compileShader(GLenum shaderType, const std::string& path);

#endif //PROJECT_SHADER_H
