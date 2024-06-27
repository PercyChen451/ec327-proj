#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Enemy
{
public:
    Enemy(int pic_number, float speed, float size, int health, const sf::Vector2f& position, const std::vector<sf::Vector2f>& path, int id, bool slowed);

    void draw(sf::RenderWindow& window) const;
    void update(float deltaTime);
    void takeDamage(int damage);
    void slower(float slowRatio);
    bool isDead() const;
    bool isSlowed() const;
    sf::Vector2f getPosition() const;
    float getSize() const; 
    sf::Vector2f getVelocity() const; 
    bool operator==(const Enemy& other) const;
    int getId() const;
    std::shared_ptr<sf::Texture> texture;// 新增
    sf::Sprite sprite; // 新增


private:
    float speed;
    float originalSpeed;
    float size;
    int health;
    int id;
    int pic_number;
    std::vector<sf::Vector2f> path;
    int currentTargetIndex;
    sf::Vector2f velocity; 
    bool slowed;
    float slowTimer;
    int maxHealth; // 最大生命值
    sf::RectangleShape healthBarBackground;
    sf::RectangleShape healthBar;
};

#endif

