#include "Shader.h"

#include <fstream>

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
    return shader;
}
