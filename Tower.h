#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

class Tower
{
public:
    enum class Type { Circle, Square, Triangle, Star };
    Tower(Type type, const sf::Vector2f& position);
    
    void draw(sf::RenderWindow& window) const;
    void shoot(std::vector<Bullet>& bullets, const std::vector<Enemy>& enemies);
    void update(float deltaTime);
    static int getCost(Type type); 
    sf::Vector2f getPosition() const;
    Type getType() const; 

private:
    Type type; 
    sf::Vector2f position;
    int cost;
    float fireRate; //射速
    float fireCooldown;
    float range; // 射程
    int damage; // 伤害
    bool slowSpeed; // 是否减速
    bool splashDamage; // 是否群体伤害
    bool piercing; // 是否穿透
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;  
};


#endif
