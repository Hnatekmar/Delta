//
// Created by martin on 28.10.17.
//

#include "EntityManager.h"
#include <algorithm>

void EntityManager::addEntity(Entity entity) {
    m_entities.push_back(entity);
}

void EntityManager::update(double delta) {
    std::for_each(m_entities.begin(), m_entities.end(), [](Entity& entity) {
        entity.update(delta);
    });
}

std::vector<Entity> EntityManager::getEntityByType(std::string type) {
    std::vector<Entity> result;
    auto it = std::copy_if(m_entities.begin(), m_entities.end(), result.begin(), [](Entity& entity) {
        return entity.getType() == type;
    });
    return result;
}

Entity &EntityManager::getEntityById(std::size_t id) {
    return *std::find_if(m_entities.begin(), m_entities.end(), [](Entity& entity) {
        return entity.getID() == id;
    });
}
