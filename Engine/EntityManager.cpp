//
// Created by martin on 28.10.17.
//

#include "EntityManager.h"
#include <algorithm>

void EntityManager::addEntity(std::shared_ptr<Entity> entity) {
    m_entities.push_back(std::move(entity));
}

void EntityManager::update(double delta) {
    std::for_each(m_entities.begin(), m_entities.end(), [&delta](std::shared_ptr<Entity>& entity) {
        entity->update(delta);
    });
}

std::vector<std::weak_ptr<Entity>> EntityManager::getEntityByType(std::string type) {
    std::vector<std::weak_ptr<Entity>> result;
    auto it = std::copy_if(m_entities.begin(), m_entities.end(), result.begin(), [&type](std::shared_ptr<Entity>& entity) {
        return entity->getType() == type;
    });
    return result;
}

std::weak_ptr<Entity> EntityManager::getEntityById(std::size_t id) {
    auto it = std::find_if(m_entities.begin(), m_entities.end(), [&id](std::shared_ptr<Entity>& entity) {
        return entity->getID() == id;
    });
    if(it != m_entities.end()) return *it;
    throw std::runtime_error("Entita s daným id nebyla nalezena!");
}
