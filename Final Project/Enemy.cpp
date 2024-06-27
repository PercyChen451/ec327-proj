#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int pic_number, float speed, float size, int health, const sf::Vector2f& position, const std::vector<sf::Vector2f>& path, int id, bool slowed)
    : pic_number(pic_number), speed(speed), originalSpeed(speed), size(size), health(health), maxHealth(health), path(path), currentTargetIndex(0), velocity(0, 0), id(id), slowed(false)
{   
    texture = std::make_shared<sf::Texture>();
    if (pic_number == 1) {
        texture->loadFromFile("assets/Enemy 1.png");
    } else if (pic_number == 2) {
        texture->loadFromFile("assets/Enemy 2.png");
    } else {
        texture->loadFromFile("assets/Enemy 3.png");  
    }
    sprite.setTexture(*texture);
    sprite.setScale(size / texture->getSize().x, size / texture->getSize().y);

    sprite.setPosition(position + sf::Vector2f(30, 30) - sf::Vector2f(size/2, size/2));

    // 初始化血条
    healthBarBackground.setSize(sf::Vector2f(size, 5));
    healthBarBackground.setFillColor(sf::Color(120, 120, 120));
    healthBarBackground.setPosition(position);

    healthBar.setSize(sf::Vector2f(size, 5));
    healthBar.setFillColor(sf::Color(100, 100, 100));
    healthBar.setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
    window.draw(healthBarBackground);
    window.draw(healthBar);
}

void Enemy::update(float deltaTime)
{
    if (slowed) {
        slowTimer += deltaTime;
        if (slowTimer >= 2.0f) { 
            speed = originalSpeed;
            slowed = false;
        }
    }

    if (currentTargetIndex < path.size()) {
        sf::Vector2f target = path[currentTargetIndex] + sf::Vector2f(35, 35) - sf::Vector2f(size/2, size/2);
        sf::Vector2f direction = target - sprite.getPosition();
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance < speed * deltaTime) {
            sprite.setPosition(target);
            currentTargetIndex++;
        } else {
            direction /= distance;
            velocity = direction * speed;
            sprite.move(velocity * deltaTime);
        }
    }

    // 更新血条位置和大小
    sf::Vector2f pos = sprite.getPosition();
    healthBarBackground.setPosition(pos.x, pos.y - 10);
    healthBar.setPosition(pos.x, pos.y - 10);
    healthBar.setSize(sf::Vector2f((static_cast<float>(health) / maxHealth) * size, 5));
}

void Enemy::takeDamage(int damage)
{
    health -= damage;
}

bool Enemy::isDead() const
{
    return health <= 0;
}

float Enemy::getSize() const
{
    return size;
}

sf::Vector2f Enemy::getPosition() const
{
    return sprite.getPosition() + sf::Vector2f(getSize()/2, getSize()/2);
}

sf::Vector2f Enemy::getVelocity() const
{
    return velocity;
}

bool Enemy::operator==(const Enemy& other) const
{
    return sprite.getPosition() == other.getPosition();
}

int Enemy::getId() const 
{ 
    return id; 
}

void Enemy::slower(float slowRatio) { 
    speed /= slowRatio;
    slowed = true;
    slowTimer = 0.0f; 
}

bool Enemy::isSlowed() const 
{
    return slowed;
}

