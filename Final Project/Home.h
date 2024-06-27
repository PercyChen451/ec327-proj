#ifndef HOME_H
#define HOME_H

#include <SFML/Graphics.hpp>

class Home
{
public:
    Home(const sf::Vector2f& position, int health);

    void draw(sf::RenderWindow& window) const;
    void takeDamage(int damage);
    bool isDestroyed() const;
    sf::Vector2f getPosition() const;
    void update();

private:
    int health;
    int maxHealth;
    sf::RectangleShape healthBarBackground;
    sf::RectangleShape healthBar;
    std::shared_ptr<sf::Texture> texture;// 新增
    sf::Sprite sprite; // 新增
};

#endif
