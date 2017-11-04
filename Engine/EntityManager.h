//
// Created by martin on 28.10.17.
//

#ifndef PROJECT_ENTITYMANAGER_H
#define PROJECT_ENTITYMANAGER_H

#include <vector>
#include <memory>
#include "Entity.h"

class EntityManager {
    std::vector<std::shared_ptr<Entity> > m_entities;
public:
    void addEntity(std::shared_ptr<Entity> entity);
    void update(double delta);
    std::weak_ptr<Entity> getEntityById(std::size_t id);
    std::vector<std::weak_ptr<Entity>> getEntityByType(std::string id);
};


#endif //PROJECT_ENTITYMANAGER_H
