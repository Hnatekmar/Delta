//
// Created by martin on 28.10.17.
//

#ifndef PROJECT_ENTITYMANAGER_H
#define PROJECT_ENTITYMANAGER_H

#include <vector>
#include "Entity.h"

class EntityManager {
    std::vector<Entity> m_entities;
public:
    void addEntity(Entity entity);
    void update(double delta);
    Entity& getEntityById(std::size_t id);
    std::vector<Entity> getEntityByType(std::string id);
};


#endif //PROJECT_ENTITYMANAGER_H
