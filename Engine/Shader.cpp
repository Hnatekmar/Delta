#include "Shader.h"

#include <fstream>
#include <vector>

GLuint compileShader(GLenum shaderType, const std::string &path) {
    GLuint shader = glCreateShader(shaderType);
    std::ifstream shaderFile(path, std::ifstream::in);
    std::string fileContent;
    std::string line;
    while(std::getline(shaderFile, line)) {
        fileContent += line + "\n";
    }
    auto str = fileContent.c_str();
    glShaderSource(shader, 1, &str, nullptr);
    glCompileShader(shader);
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE) {
        GLint logSize = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        GLchar* errorLog = new GLchar[logSize];
        glGetShaderInfoLog(shader, logSize, &logSize, errorLog);
        std::string persistantError(errorLog);
        glDeleteShader(shader);
        delete[] errorLog;
        throw std::runtime_error("OpenGL shader compilation failed: " + persistantError);
    }
    return shader;
}
