#include <iostream>
#include "Engine.h"
#include "Primitives/Cube.h"
#include <glm/gtx/transform.hpp>

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
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 projection = glm::perspective(
            glm::radians(45.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
            4.0f / 3.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
            0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
            100.0f             // Far clipping plane. Keep as little as possible.
    );
    Cube cube;
    bool run = true;
    auto previousFrameTimestamp = SDL_GetTicks();
    glEnable(GL_DEPTH_TEST);
    while(run) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) run = false;
        }
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        auto current = SDL_GetTicks();
        auto delta = current - previousFrameTimestamp;
        previousFrameTimestamp = current;
        m_entityManager.update(delta);
        SDL_GL_SwapWindow(m_window);
        HANDLE_GL_ERRORS()
    }
}

Engine::~Engine() {
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

EntityManager &Engine::getEntityManager() {
    return m_entityManager;
}

