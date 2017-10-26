#include <iostream>
#include "Engine.h"
#include "Primitives/Cube.h"

Engine::Engine(const char* name) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        // ERROR HANDLING
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Couldn't initialize video");
    } else {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        m_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if(m_window == nullptr) {
            SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Couldn't initialize window");
        }
        m_context = SDL_GL_CreateContext(m_window);
        SDL_GL_SetSwapInterval(1);
        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize glew");
        }
    }
}

void Engine::update() {
    SDL_Event event{};
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    Cube cube;
    bool run = true;
    while(run) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) run = false;
        }
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        cube.draw();
        GLenum error;
        while((error = glGetError()) != GL_NO_ERROR) {
            std::cout << error << std::endl;
            SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Opengl error: %i", error);
        }
        SDL_GL_SwapWindow(m_window);
    }
}

Engine::~Engine() {
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

