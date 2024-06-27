#include "Bullet.h"
#include <cmath>
#include <limits>
#include <iostream>
using std::cout;

// 定义方程
double equation(double t, double a, double b, double c, double d, double e, double f, double v) {
    return std::pow(a + c * t - e, 2) + std::pow(b + d * t - f, 2) - std::pow(t * v, 2);
}

// 二分法求解方程
double solve_equation(double a, double b, double c, double d, double e, double f, double v, double left, double right, double tolerance = 1e-7, int max_iterations = 1000) {
    int iterations = 0;
    while (iterations < max_iterations) {
        double mid = (left + right) / 2;
        double f_mid = equation(mid, a, b, c, d, e, f, v);

        if (std::abs(f_mid) < tolerance) {
            return mid;
        }

        double f_left = equation(left, a, b, c, d, e, f, v);

        if (f_left * f_mid < 0) {
            right = mid;
        } else {
            left = mid;
        }

        ++iterations;
    }
    std::cerr << "Max iterations reached; solution may not have converged." << std::endl;
    return (left + right) / 2;
}


Bullet::Bullet(const sf::Vector2f& position, const sf::Vector2f& target, const sf::Vector2f& enemyVelocity, bool piercing, bool splashDamage, float areaDamageRadius, bool slowSpeed, float slowRatio, int damage)
    : position(position), shape(5), speed(500.0f), piercing(piercing), splashDamage(splashDamage), areaDamageRadius(areaDamageRadius), slowSpeed(slowSpeed), slowRatio(slowRatio), damage(damage)
{  
    // 计算预判位置
    float t = static_cast<float>(solve_equation(target.x, target.y, enemyVelocity.x, enemyVelocity.y, position.x, position.y, speed, 0.0, 2.0));

    sf::Vector2f predictedTarget = target + t * enemyVelocity;

    direction = predictedTarget - position;
    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= magnitude; 

    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);
}

void Bullet::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

void Bullet::update(float deltaTime)
{
    position += direction * speed * deltaTime;
    shape.setPosition(position);
}

bool Bullet::hasHitTarget(const Enemy& enemy) const
{
    float distance = sqrt(pow(position.x - enemy.getPosition().x, 2) + pow(position.y - enemy.getPosition().y, 2));
    return distance < shape.getRadius() + enemy.getSize() / 2;
}

bool Bullet::operator==(const Bullet& other) const
{
    return position == other.position && target == other.target;
}

bool Bullet::isPiercing() const {
    return piercing;
}

bool Bullet::isSplashDamage() const {
    return splashDamage;
}

void Bullet::applyAreaDamage(std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        float distance = std::sqrt(std::pow(position.x - enemy.getPosition().x, 2) + std::pow(position.y - enemy.getPosition().y, 2));
        if (distance <= areaDamageRadius && !hasAlreadyHit(enemy)) {
            enemy.takeDamage(damage);
            registerHit(enemy);
        }
    }
}

bool Bullet::isSlowSpeed() const {
    return slowSpeed;
}

float Bullet::getSlowRatio() const {
    return slowRatio;
}

int Bullet::getDamage() const {
    return damage;
}

void Bullet::registerHit(const Enemy& enemy) {
    hitEnemies.insert(enemy.getId());
}
    
bool Bullet::hasAlreadyHit(const Enemy& enemy) const {
    return hitEnemies.find(enemy.getId()) != hitEnemies.end();
}

