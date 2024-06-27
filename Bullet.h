#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <unordered_set>

class Bullet
{
public:
    Bullet(const sf::Vector2f& position, const sf::Vector2f& target, const sf::Vector2f& enemyVelocity, bool piercing, bool splashDamage, float areaDamageRadius, bool slowSpeed, float slowRatio, int damage);

    void draw(sf::RenderWindow& window) const;
    void update(float deltaTime);
    bool hasHitTarget(const Enemy& enemy) const; 
    bool operator==(const Bullet& other) const;
    bool isPiercing() const;
    bool isSplashDamage() const;
    bool isSlowSpeed() const;
    float getSlowRatio() const;
    int getDamage() const;
    void registerHit(const Enemy& enemy);
    bool hasAlreadyHit(const Enemy& enemy) const;
    void applyAreaDamage(std::vector<Enemy>& enemies);

private:
    sf::Vector2f position;
    sf::Vector2f target;
    sf::Vector2f direction;
    sf::CircleShape shape;
    float speed;
    bool piercing;
    bool splashDamage; 
    float areaDamageRadius;
    bool slowSpeed; 
    float slowRatio;
    int damage; // 伤害
    std::unordered_set<int> hitEnemies; // 记录已经命中的敌人ID
    
};

#endif
