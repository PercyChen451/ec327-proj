#include "globals.h"
#include <iostream>

std::vector<sf::CircleShape> otherCircles;
std::set<Tower::Type> allowedTowers;

std::map<Tower::Type, sf::SoundBuffer> fireSoundBuffers;
std::map<Tower::Type, sf::Sound> fireSounds;

void loadSounds() {
    fireSoundBuffers[Tower::Type::Circle].loadFromFile("assets/fire1.wav");
    fireSounds[Tower::Type::Circle].setBuffer(fireSoundBuffers[Tower::Type::Circle]);
    fireSounds[Tower::Type::Circle].setVolume(10); 

    fireSoundBuffers[Tower::Type::Square].loadFromFile("assets/fire2.wav");
    fireSounds[Tower::Type::Square].setBuffer(fireSoundBuffers[Tower::Type::Square]);
    fireSounds[Tower::Type::Square].setVolume(50); 

    fireSoundBuffers[Tower::Type::Triangle].loadFromFile("assets/fire3.wav");
    fireSounds[Tower::Type::Triangle].setBuffer(fireSoundBuffers[Tower::Type::Triangle]);
    fireSounds[Tower::Type::Triangle].setVolume(10); 

    fireSoundBuffers[Tower::Type::Star].loadFromFile("assets/fire4.wav");
    fireSounds[Tower::Type::Star].setBuffer(fireSoundBuffers[Tower::Type::Star]);
    fireSounds[Tower::Type::Star].setVolume(25); 
}

void drawGame(sf::RenderWindow& window, const sf::Text& levelTitle, const sf::Text& waveTitle, const sf::RectangleShape& mapBackground, const sf::Text& backButton, const sf::Text& moneyText, const Home& home, const std::vector<sf::RectangleShape>& roads, const std::vector<sf::CircleShape>& otherCircles, const std::vector<sf::CircleShape>& mapElements, const std::vector<Tower>& towers, const std::vector<Enemy>& enemies, const std::vector<Bullet>& bullets, const sf::CircleShape& spawnPoint)
{
    window.draw(levelTitle);
    window.draw(waveTitle);
    window.draw(mapBackground);
    window.draw(backButton);
    window.draw(moneyText);

    for (const auto& road : roads)
        window.draw(road);

    for (const auto& circle : otherCircles)
        window.draw(circle);

    home.draw(window);

    for (const auto& element : mapElements)
        window.draw(element);

    window.draw(spawnPoint);

    // 绘制塔，敌人和子弹
    for (const auto& tower : towers)
        tower.draw(window);

    for (const auto& enemy : enemies)
        enemy.draw(window);

    for (const auto& bullet : bullets)
        bullet.draw(window);
}

std::vector<sf::Vector2f> createPathLevel1()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 1 * 70, 100 + 1 * 70), sf::Vector2f(15 + 2 * 70, 100 + 1 * 70), sf::Vector2f(15 + 3 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 4 * 70, 100 + 1 * 70), sf::Vector2f(15 + 5 * 70, 100 + 1 * 70), sf::Vector2f(15 + 6 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 1 * 70), sf::Vector2f(15 + 8 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 2 * 70), sf::Vector2f(15 + 9 * 70, 100 + 3 * 70), sf::Vector2f(15 + 8 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 3 * 70), sf::Vector2f(15 + 6 * 70, 100 + 3 * 70), sf::Vector2f(15 + 5 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 4 * 70, 100 + 3 * 70), sf::Vector2f(15 + 3 * 70, 100 + 3 * 70), sf::Vector2f(15 + 2 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 3 * 70), sf::Vector2f(15 + 1 * 70, 100 + 4 * 70), sf::Vector2f(15 + 1 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 2 * 70, 100 + 5 * 70), sf::Vector2f(15 + 3 * 70, 100 + 5 * 70), sf::Vector2f(15 + 4 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 5 * 70, 100 + 5 * 70), sf::Vector2f(15 + 6 * 70, 100 + 5 * 70), sf::Vector2f(15 + 7 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 8 * 70, 100 + 5 * 70), sf::Vector2f(15 + 9 * 70, 100 + 5 * 70), sf::Vector2f(15 + 10 * 70, 100 + 5 * 70)
    };
    return path;
}

std::vector<sf::Vector2f> createPathLevel2()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 1 * 70, 100 + 1 * 70), sf::Vector2f(15 + 1 * 70, 100 + 2 * 70), sf::Vector2f(15 + 1 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 4 * 70), sf::Vector2f(15 + 1 * 70, 100 + 5 * 70), sf::Vector2f(15 + 2 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 5 * 70), sf::Vector2f(15 + 4 * 70, 100 + 5 * 70), sf::Vector2f(15 + 4 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 4 * 70, 100 + 3 * 70), sf::Vector2f(15 + 5 * 70, 100 + 3 * 70), sf::Vector2f(15 + 6 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 3 * 70), sf::Vector2f(15 + 7 * 70, 100 + 2 * 70), sf::Vector2f(15 + 7 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 8 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 3 * 70), sf::Vector2f(15 + 9 * 70, 100 + 4 * 70), sf::Vector2f(15 + 9 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 10 * 70, 100 + 5 * 70)
    };
    return path;
}

std::vector<sf::Vector2f> createPathLevel3()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 1 * 70, 100 + 6 * 70), sf::Vector2f(15 + 1 * 70, 100 + 5 * 70), sf::Vector2f(15 + 1 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 3 * 70), sf::Vector2f(15 + 1 * 70, 100 + 2 * 70), sf::Vector2f(15 + 2 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 2 * 70), sf::Vector2f(15 + 4 * 70, 100 + 2 * 70), sf::Vector2f(15 + 4 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 5 * 70, 100 + 1 * 70), sf::Vector2f(15 + 6 * 70, 100 + 1 * 70), sf::Vector2f(15 + 7 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 8 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 3 * 70), sf::Vector2f(15 + 8 * 70, 100 + 3 * 70), sf::Vector2f(15 + 7 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 6 * 70, 100 + 3 * 70), sf::Vector2f(15 + 5 * 70, 100 + 3 * 70), sf::Vector2f(15 + 5 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 5 * 70, 100 + 5 * 70), sf::Vector2f(15 + 6 * 70, 100 + 5 * 70), sf::Vector2f(15 + 7 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 8 * 70, 100 + 5 * 70), sf::Vector2f(15 + 9 * 70, 100 + 5 * 70), sf::Vector2f(15 + 10 * 70, 100 + 5 * 70),
    };
    return path;
}

std::vector<sf::Vector2f> createPathLevel4()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 1 * 70, 100 + 6 * 70), sf::Vector2f(15 + 1 * 70, 100 + 5 * 70), sf::Vector2f(15 + 1 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 3 * 70), sf::Vector2f(15 + 1 * 70, 100 + 2 * 70), sf::Vector2f(15 + 1 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 2 * 70, 100 + 1 * 70), sf::Vector2f(15 + 3 * 70, 100 + 1 * 70), sf::Vector2f(15 + 3 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 3 * 70), sf::Vector2f(15 + 4 * 70, 100 + 3 * 70), sf::Vector2f(15 + 5 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 5 * 70, 100 + 4 * 70), sf::Vector2f(15 + 5 * 70, 100 + 5 * 70), sf::Vector2f(15 + 6 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 5 * 70), sf::Vector2f(15 + 8 * 70, 100 + 5 * 70), sf::Vector2f(15 + 8 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 8 * 70, 100 + 3 * 70), sf::Vector2f(15 + 8 * 70, 100 + 2 * 70), sf::Vector2f(15 + 8 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 2 * 70), sf::Vector2f(15 + 10 * 70, 100 + 2 * 70),
    };
    return path;
}

std::vector<sf::Vector2f> createPathLevel5()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 0 * 70, 100 + 5 * 70), sf::Vector2f(15 + 1 * 70, 100 + 5 * 70), sf::Vector2f(15 + 2 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 5 * 70), sf::Vector2f(15 + 4 * 70, 100 + 5 * 70), sf::Vector2f(15 + 5 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 6 * 70, 100 + 5 * 70), sf::Vector2f(15 + 7 * 70, 100 + 5 * 70), sf::Vector2f(15 + 7 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 3 * 70), sf::Vector2f(15 + 7 * 70, 100 + 2 * 70), sf::Vector2f(15 + 6 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 5 * 70, 100 + 2 * 70), sf::Vector2f(15 + 5 * 70, 100 + 3 * 70), sf::Vector2f(15 + 4 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 3 * 70), sf::Vector2f(15 + 2 * 70, 100 + 3 * 70), sf::Vector2f(15 + 1 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 2 * 70), sf::Vector2f(15 + 1 * 70, 100 + 1 * 70), sf::Vector2f(15 + 2 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 1 * 70), sf::Vector2f(15 + 4 * 70, 100 + 1 * 70), sf::Vector2f(15 + 5 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 6 * 70, 100 + 1 * 70), sf::Vector2f(15 + 7 * 70, 100 + 1 * 70), sf::Vector2f(15 + 8 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 2 * 70), sf::Vector2f(15 + 9 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 4 * 70), sf::Vector2f(15 + 9 * 70, 100 + 5 * 70), sf::Vector2f(15 + 9 * 70, 100 + 6 * 70),
    };
    return path;
}

std::vector<sf::Vector2f> createPathLevel6()
{
    std::vector<sf::Vector2f> path = {
        sf::Vector2f(15 + 1 * 70, 100 + 0 * 70), sf::Vector2f(15 + 1 * 70, 100 + 1 * 70), sf::Vector2f(15 + 1 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 1 * 70, 100 + 3 * 70), sf::Vector2f(15 + 1 * 70, 100 + 4 * 70), sf::Vector2f(15 + 2 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 3 * 70, 100 + 4 * 70), sf::Vector2f(15 + 4 * 70, 100 + 4 * 70), sf::Vector2f(15 + 4 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 4 * 70, 100 + 2 * 70), sf::Vector2f(15 + 4 * 70, 100 + 1 * 70), sf::Vector2f(15 + 5 * 70, 100 + 1 * 70),
        sf::Vector2f(15 + 6 * 70, 100 + 1 * 70), sf::Vector2f(15 + 7 * 70, 100 + 1 * 70), sf::Vector2f(15 + 7 * 70, 100 + 2 * 70),
        sf::Vector2f(15 + 7 * 70, 100 + 3 * 70), sf::Vector2f(15 + 6 * 70, 100 + 3 * 70), sf::Vector2f(15 + 6 * 70, 100 + 4 * 70),
        sf::Vector2f(15 + 6 * 70, 100 + 5 * 70), sf::Vector2f(15 + 7 * 70, 100 + 5 * 70), sf::Vector2f(15 + 8 * 70, 100 + 5 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 5 * 70), sf::Vector2f(15 + 9 * 70, 100 + 4 * 70), sf::Vector2f(15 + 9 * 70, 100 + 3 * 70),
        sf::Vector2f(15 + 9 * 70, 100 + 2 * 70), sf::Vector2f(15 + 9 * 70, 100 + 1 * 70), sf::Vector2f(15 + 9 * 70, 100 + 0 * 70),
    };
    return path;
}

void createRoads(int selectedLevel, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles)
{
    roads.clear();
    otherCircles.clear();
    std::vector<std::pair<int, int>> roadPositions;

    if (selectedLevel == 1) {
        roadPositions = {
            {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9}, {2, 9}, 
            {3, 9}, {3, 8}, {3, 7}, {3, 6}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {3, 1}, {4, 1},
            {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 10}
        };
    } else if (selectedLevel == 2) {
        roadPositions = {
            {1, 0}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {4, 4}, {3, 4}, 
            {3, 5}, {3, 6}, {3, 7}, {2, 7}, {1, 7}, {1, 8}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, 
            {5, 9}, {5, 10}
        };
    } else if (selectedLevel == 3) {
        roadPositions = {
            {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {1, 4}, {1, 5}, {1, 6}, 
            {1, 7}, {1, 8}, {1, 9}, {2, 9}, {3, 9}, {3, 8}, {3, 7}, {3, 6}, {3, 5}, {4, 5}, 
            {5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 10}
        };
    } else if (selectedLevel == 4) {
        roadPositions = {
            {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {3, 4}, 
            {3, 5}, {4, 5}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, 
            {1, 9}, {2, 9}, {2, 10}
        };
    } else if (selectedLevel == 5) {
        roadPositions = {
            {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, 
            {2, 6}, {2, 5}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {3, 1}, {2, 1}, {1, 1}, {1, 2}, 
            {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}
        };
    } else if (selectedLevel == 6) {
        roadPositions = {
            {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, 
            {1, 5}, {1, 6}, {1, 7}, {2, 7}, {3, 7}, {3, 6}, {4, 6}, {5, 6}, {5, 7}, {5, 8}, 
            {5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}
        };
    }

    for (const auto& pos : roadPositions) {
        sf::RectangleShape road(sf::Vector2f(70, 70));
        road.setFillColor(sf::Color(144, 144, 144)); // 深灰色
        road.setPosition(15 + pos.second * 70, 100 + pos.first * 70);
        roads.push_back(road);
    }

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (std::find(roadPositions.begin(), roadPositions.end(), std::make_pair(i, j)) == roadPositions.end()) {
                sf::CircleShape circle(25);
                circle.setFillColor(sf::Color(206, 206, 206));
                circle.setPosition(25 + j * 70, 110 + i * 70);
                otherCircles.push_back(circle);
            }
        }
    }
}

void spawnEnemies(int selectedLevel, float& spawnTimer, float totalTimer, std::vector<Enemy>& enemies, sf::CircleShape& spawnPoint, std::vector<sf::Vector2f>& path, int& enemyIdCounter, sf::Text& waveTitle, bool& isLevelScreen, bool& isYouWinScreen)
{
    if (selectedLevel == 1) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 150, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 350, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 500, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 750, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 1000, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 75) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    } else if (selectedLevel == 2) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 200, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 250, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 600, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 1050, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Wave 5");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 850, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 78) && (totalTimer < 90))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 1100, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 90) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    } else if (selectedLevel == 3) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 250, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 275, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 800, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 1050, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Wave 5");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 900, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 78) && (totalTimer < 90))
        {   
            waveTitle.setString("Wave 6");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 1200, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 93) && (totalTimer < 98))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 1.5f)
            {
                enemies.emplace_back(3, 50.0f, 50.0f, 15000, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 99) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    } else if (selectedLevel == 4) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 250, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 200, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 750, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 950, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Wave 5");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 900, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 78) && (totalTimer < 90))
        {   
            waveTitle.setString("Wave 6");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 1300, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 93) && (totalTimer < 105))
        {   
            waveTitle.setString("Wave 7");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 2700, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 108) && (totalTimer < 113))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 1.5f)
            {
                enemies.emplace_back(3, 50.0f, 50.0f, 18000, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 120) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    } else if (selectedLevel == 5) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 250, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 200, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.65f)
            {
                enemies.emplace_back(1, 150.0f, 75.0f, 750, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 950, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Wave 5");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 900, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 78) && (totalTimer < 90))
        {   
            waveTitle.setString("Wave 6");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 75.0f, 1300, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 93) && (totalTimer < 105))
        {   
            waveTitle.setString("Wave 7");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 2700, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 108) && (totalTimer < 113))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 1.5f)
            {
                enemies.emplace_back(3, 50.0f, 100.0f, 18000, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 120) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    } else if (selectedLevel == 6) {
        if ((totalTimer > 3) && (totalTimer < 15))
        {
           if (spawnTimer >= 0.6f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 250, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }
        }
        else if ((totalTimer > 18) && (totalTimer < 30))
        {   
            waveTitle.setString("Wave 2");
            if (spawnTimer >= 0.5f)
            {
                enemies.emplace_back(2, 300.0f, 75.0f, 200, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 33) && (totalTimer < 45))
        {   
            waveTitle.setString("Wave 3");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 750, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 48) && (totalTimer < 60))
        {   
            waveTitle.setString("Wave 4");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(1, 150.0f, 50.0f, 950, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 63) && (totalTimer < 75))
        {   
            waveTitle.setString("Wave 5");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 75.0f, 900, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 78) && (totalTimer < 90))
        {   
            waveTitle.setString("Wave 6");
            if (spawnTimer >= 0.45f)
            {
                enemies.emplace_back(2, 300.0f, 50.0f, 1300, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 93) && (totalTimer < 105))
        {   
            waveTitle.setString("Wave 7");
            if (spawnTimer >= 0.65f)
            {
                enemies.emplace_back(1, 150.0f, 75.0f, 2700, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 108) && (totalTimer < 113))
        {   
            waveTitle.setString("Final Wave");
            if (spawnTimer >= 1.5f)
            {
                enemies.emplace_back(3, 50.0f, 100.0f, 18000, spawnPoint.getPosition(), path, enemyIdCounter++, false);
                spawnTimer = 0;
            }                
        }
        else if ((totalTimer > 120) && (enemies.empty()))
        {   
            isLevelScreen = false;
            isYouWinScreen = true;
        }
    }
}

void resetGame(int selectedLevel, std::vector<Tower>& towers, std::vector<Enemy>& enemies, std::vector<Bullet>& bullets, std::vector<int>& enemiesToRemove, Home& home, sf::CircleShape& spawnPoint, sf::Text& levelTitle, sf::Text& waveTitle, sf::Text& moneyText, int& money, int& enemyIdCounter, float& spawnTimer, float& totalTimer, std::vector<sf::Vector2f>& path, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles)
{
    towers.clear();
    enemies.clear();
    bullets.clear();
    enemiesToRemove.clear();
    home = Home(sf::Vector2f(20 + 10 * 70, 105 + 5 * 70), 100); // 重置家的位置和生命值
    waveTitle.setString("Wave 1");
    money = 100;
    moneyText.setString("Money: " + std::to_string(money));
    enemyIdCounter = 0;
    spawnTimer = 0;
    totalTimer = 0;

    allowedTowers.clear();
    allowedTowers.insert(Tower::Type::Circle); // All levels allow the first type
    if (selectedLevel == 2) {
        allowedTowers.insert(Tower::Type::Square);
    } else if (selectedLevel == 3) {
        allowedTowers.insert(Tower::Type::Square);
        allowedTowers.insert(Tower::Type::Triangle);
    } else if (selectedLevel >= 4) {
        allowedTowers.insert(Tower::Type::Square);
        allowedTowers.insert(Tower::Type::Triangle);
        allowedTowers.insert(Tower::Type::Star);
    }

    switch (selectedLevel) {
        case 1:
            path = createPathLevel1();
            levelTitle.setString("Level 1");
            spawnPoint.setPosition(sf::Vector2f(20 + 0 * 70, 105 + 1 * 70)); 
            home = Home(sf::Vector2f(20 + 10 * 70, 105 + 5 * 70), 100); 
            break;
        case 2:
            path = createPathLevel2();
            levelTitle.setString("Level 2");
            spawnPoint.setPosition(sf::Vector2f(20 + 0 * 70, 105 + 1 * 70)); 
            home = Home(sf::Vector2f(20 + 10 * 70, 105 + 5 * 70), 100); 
            break;
        case 3:
            path = createPathLevel3();
            levelTitle.setString("Level 3");
            spawnPoint.setPosition(sf::Vector2f(20 + 1 * 70, 105 + 6 * 70));
            home = Home(sf::Vector2f(20 + 10 * 70, 105 + 5 * 70), 100);  
            break;
        case 4:
            path = createPathLevel4();
            levelTitle.setString("Level 4");
            spawnPoint.setPosition(sf::Vector2f(20 + 1 * 70, 105 + 6 * 70)); 
            home = Home(sf::Vector2f(20 + 10 * 70, 105 + 2 * 70), 100); 
            break;
        case 5:
            path = createPathLevel5();
            levelTitle.setString("Level 5");
            spawnPoint.setPosition(sf::Vector2f(20 + 0 * 70, 105 + 5 * 70)); 
            home = Home(sf::Vector2f(20 + 9 * 70, 105 + 6 * 70), 100); 
            break;
        case 6:
            path = createPathLevel6();
            levelTitle.setString("Level 6");
            spawnPoint.setPosition(sf::Vector2f(20 + 1 * 70, 105 + 0 * 70));
            home = Home(sf::Vector2f(20 + 9 * 70, 105 + 0 * 70), 100); 
            break;
    }

    createRoads(selectedLevel, roads, otherCircles);
}

void loadGuideContent(int selectedLevel, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text, bool isTowerGuide)
{
    std::string imagePath;
    std::string guideContent;

    if (isTowerGuide)
    {
        guideContent = "";
        switch (selectedLevel)
        {
            case 1:
                imagePath = "assets/Tower 1.png";
                guideContent += "Percy:\n\nCost: 40\n\nFire rate: 0.5s\n\nDamage: 60\n\nNo special skills\n\nClick Grey Circle and\nPress 1 to place Percy";
                break;
            case 2:
                imagePath = "assets/Tower 2.png";
                guideContent += "Jimmy:\n\nCost: 60\n\nFire rate: 0.8s\n\nDamage: 80\n\nArea damage\n\nClick Grey Circle and\nPress 2 to place Jimmy";
                break;
            case 3:
                imagePath = "assets/Tower 3.png";
                guideContent += "Ink:\n\nCost: 100\n\nFire rate: 1.25s\n\nDamage: 180\n\nPiercing damage\n\nClick Grey Circle and\nPress 3 to place Ink";
                break;
            case 4:
                imagePath = "assets/Tower 4.png";
                guideContent += "Ella:\n\nCost: 80\n\nFire rate: 0.25s\n\nDamage: 40\n\nSlow down the enemy\n\nClick Grey Circle and\nPress 4 to place Ella";
                break;
        }
    }
    else
    {
        guideContent = "";
        switch (selectedLevel)
        {
            case 1:
                imagePath = "assets/Enemy 1.png";
                guideContent += "Matlab Monster:\n\nSpeed: 150\n\nHealth: Medium\n\nCommon monsters";
                break;
            case 2:
                imagePath = "assets/Enemy 2.png";
                guideContent += "VSCode Monster:\n\nSpeed: 300\n\nHealth: Low\n\nQuick monsters";
                break;
            case 3:
                imagePath = "assets/Enemy 3.png";
                guideContent += "ChatGPT Monster:\n\nSpeed: 50\n\nHealth: Extremely High\n\nBoss";
                break;
        }
    }

    texture = sf::Texture();
        
    texture.loadFromFile(imagePath);
    sf::Vector2u textureSize = texture.getSize();
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
    sprite.setPosition(70, 100);
    sprite.setScale(300.f / textureSize.x, 300.f / textureSize.y);
    sprite.setColor(sf::Color::White);
    text.setString(guideContent);
}

void drawButtons(sf::RenderWindow& window, const sf::Font& font, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts)
{
    for (size_t i = 0; i < buttons.size(); ++i)
    {
        window.draw(buttons[i]);
        window.draw(buttonTexts[i]);
    }
}