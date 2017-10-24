#ifndef PROJECT_ENGINE_H
#define PROJECT_ENGINE_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

/*!
 * \brief Třída starající se o běh enginu.
 */
class Engine {

    SDL_Window* m_window;
    SDL_GLContext m_context;
public:
    explicit Engine(const char* name);
    ~Engine();
    void update();
};


#endif //PROJECT_ENGINE_H
