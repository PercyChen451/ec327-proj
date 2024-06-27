#include "Tower.h"
#include <iostream>
#include "globals.h"
Tower::Tower(Type type, const sf::Vector2f& position) : type(type), position(position), fireCooldown(0.0f)
{
    texture = std::make_shared<sf::Texture>();
    bool loaded = false;

    switch (type)
    {
    case Type::Circle:
        loaded = texture->loadFromFile("assets/Tower 1.png");
        cost = 40;
        fireRate = 0.5f;
        range = 300.0f;
        damage = 60;
        slowSpeed = false;
        splashDamage = false;
        piercing = false;
        break;
    case Type::Square:
        loaded = texture->loadFromFile("assets/Tower 2.png");
        cost = 60;
        fireRate = 0.8f;
        range = 150.0f;
        damage = 80;
        slowSpeed = false;
        splashDamage = true;
        piercing = false;
        break;
    case Type::Triangle:
        loaded = texture->loadFromFile("assets/Tower 3.png");
        cost = 100;
        fireRate = 1.25f;
        range = 250.0f;
        damage = 180;
        slowSpeed = false;
        splashDamage = false;
        piercing = true;
        break;
    case Type::Star:
        loaded = texture->loadFromFile("assets/Tower 4.png");
        cost = 80;
        fireRate = 0.25f;
        range = 200.0f;
        damage = 40;
        slowSpeed = true;
        splashDamage = false;
        piercing = false;
        break;
    }

    sprite.setTexture(*texture);
    sprite.setScale(50.f / texture->getSize().x, 50.f / texture->getSize().y);

    sprite.setPosition(position);
}

sf::Vector2f Tower::getPosition() const {
    return position + sf::Vector2f(sprite.getGlobalBounds().width / 2 - 25, sprite.getGlobalBounds().height / 2 - 25);
}

void Tower::shoot(std::vector<Bullet>& bullets, const std::vector<Enemy>& enemies)
{
    if (fireCooldown <= 0.0f) {
        sf::Vector2f towerCenter = position + sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

        // 查找最近的敌人
        const Enemy* targetEnemy = nullptr;
        float closestDistance = range;

        for (const auto& enemy : enemies) {
            float distance = sqrt(pow(enemy.getPosition().x + enemy.getSize() - towerCenter.x, 2) + pow(enemy.getPosition().y + enemy.getSize() - towerCenter.y, 2));
            if (distance <= range && distance < closestDistance) {
                closestDistance = distance;
                targetEnemy = &enemy;
            }
        }

        // 如果找到敌人在射程内，则射击
        if (targetEnemy) {
            fireSounds[type].play();
            if (piercing) {
                bullets.push_back(Bullet(towerCenter + sf::Vector2f(0, 5), targetEnemy->getPosition(), targetEnemy->getVelocity(), true, false, 0.0, false, 1, damage));
            } else if (splashDamage){
                bullets.push_back(Bullet(towerCenter, targetEnemy->getPosition(), targetEnemy->getVelocity(), false, true, 150.0, false, 1, damage));
            } else if (slowSpeed){
                bullets.push_back(Bullet(towerCenter, targetEnemy->getPosition(), targetEnemy->getVelocity(), false, false, 0.0, true, 2, damage));
            } else {
                bullets.push_back(Bullet(towerCenter, targetEnemy->getPosition(), targetEnemy->getVelocity(), false, false, 0.0, false, 1, damage));
            }
            fireCooldown = fireRate;
        }
    }
}

void Tower::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void Tower::update(float deltaTime)
{
    if (fireCooldown > 0.0f) {
        fireCooldown -= deltaTime;
    }
}

int Tower::getCost(Type type)
{
    switch (type)
    {
    case Type::Circle:
        return 40;
    case Type::Square:
        return 60;
    case Type::Triangle:
        return 100;
    case Type::Star:
        return 80;
    }
    return 0; 
}

Tower::Type Tower::getType() const
{
    return type;
}