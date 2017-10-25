//
// Created by martin on 24.10.17.
//

#ifndef PROJECT_IDRAWABLE_H
#define PROJECT_IDRAWABLE_H

/**
 * @brief Generický interface pro cokoliv vykreslitelného
 */
class IDrawable {
public:
    virtual void draw() = 0;
};

#endif //PROJECT_IDRAWABLE_H
