//
// Created by martin on 28.10.17.
//

#ifndef PROJECT_ENTITY_H
#define PROJECT_ENTITY_H

#include <string>

class Entity {
    static std::size_t s_lastId;
    std::size_t m_id;
    std::string m_type;
public:
    explicit Entity(std::string type): m_id(++s_lastId), m_type(type) {
    }

    const std::string& getType() {
        return m_type;
    }

    std::size_t getID() {
        return m_id;
    }

    virtual void update(double delta) = 0;
};


#endif //PROJECT_ENTITY_H
