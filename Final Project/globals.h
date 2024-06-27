#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <set>
#include "Tower.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Home.h"

extern std::vector<sf::CircleShape> otherCircles;
extern std::set<Tower::Type> allowedTowers;

extern std::map<Tower::Type, sf::SoundBuffer> fireSoundBuffers;
extern std::map<Tower::Type, sf::Sound> fireSounds;

void loadSounds();
void drawGame(sf::RenderWindow& window, const sf::Text& levelTitle, const sf::Text& waveTitle, const sf::RectangleShape& mapBackground, const sf::Text& backButton, const sf::Text& moneyText, const Home& home, const std::vector<sf::RectangleShape>& roads, const std::vector<sf::CircleShape>& otherCircles, const std::vector<sf::CircleShape>& mapElements, const std::vector<Tower>& towers, const std::vector<Enemy>& enemies, const std::vector<Bullet>& bullets, const sf::CircleShape& spawnPoint);
void createRoads(int selectedLevel, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles);
void spawnEnemies(int selectedLevel, float& spawnTimer, float totalTimer, std::vector<Enemy>& enemies, sf::CircleShape& spawnPoint, std::vector<sf::Vector2f>& path, int& enemyIdCounter, sf::Text& waveTitle, bool& isLevelScreen, bool& isYouWinScreen);
void resetGame(int selectedLevel, std::vector<Tower>& towers, std::vector<Enemy>& enemies, std::vector<Bullet>& bullets, std::vector<int>& enemiesToRemove, Home& home, sf::CircleShape& spawnPoint, sf::Text& levelTitle, sf::Text& waveTitle, sf::Text& moneyText, int& money, int& enemyIdCounter, float& spawnTimer, float& totalTimer, std::vector<sf::Vector2f>& path, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles);
void loadGuideContent(int selectedLevel, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text, bool isTowerGuide);
void drawButtons(sf::RenderWindow& window, const sf::Font& font, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts);

std::vector<sf::Vector2f> createPathLevel1();
std::vector<sf::Vector2f> createPathLevel2();
std::vector<sf::Vector2f> createPathLevel3();
std::vector<sf::Vector2f> createPathLevel4();
std::vector<sf::Vector2f> createPathLevel5();
std::vector<sf::Vector2f> createPathLevel6();

#endif // GLOBALS_H
