#include "Home.h"

Home::Home(const sf::Vector2f& position, int health)
    : health(health), maxHealth(health)
{
    texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("assets/Home.png");

    sprite.setTexture(*texture);
    sprite.setScale(60.f / texture->getSize().x, 60.f / texture->getSize().y);

    sprite.setPosition(position);

    // 初始化血条
    healthBarBackground.setSize(sf::Vector2f(60, 7.5));
    healthBarBackground.setFillColor(sf::Color(120, 120, 120));
    healthBarBackground.setPosition(position);

    healthBar.setSize(sf::Vector2f(60, 7.5));
    healthBar.setFillColor(sf::Color(100, 100, 100));
    healthBar.setPosition(position);
}

void Home::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
    window.draw(healthBarBackground);
    window.draw(healthBar);
}

void Home::takeDamage(int damage)
{
    health -= damage;
}

bool Home::isDestroyed() const
{
    return health <= 0;
}

sf::Vector2f Home::getPosition() const
{
    return sprite.getPosition() + sf::Vector2f(30, 30);;
}

void Home::update()
{
    // 更新血条位置和大小
    sf::Vector2f pos = sprite.getPosition();
    healthBarBackground.setPosition(pos.x, pos.y - 15);
    healthBar.setPosition(pos.x, pos.y - 15);
    healthBar.setSize(sf::Vector2f((static_cast<float>(health) / maxHealth) * 60, 7.5));
}
