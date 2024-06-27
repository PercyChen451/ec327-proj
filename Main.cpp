#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include "Tower.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Home.h"

extern std::vector<sf::CircleShape> otherCircles;
extern std::set<Tower::Type> allowedTowers;

extern std::map<Tower::Type, sf::SoundBuffer> fireSoundBuffers;
extern std::map<Tower::Type, sf::Sound> fireSounds;

extern void loadSounds();
extern void drawGame(sf::RenderWindow& window, const sf::Text& levelTitle, const sf::Text& waveTitle, const sf::RectangleShape& mapBackground, const sf::Text& backButton, const sf::Text& moneyText, const Home& home, const std::vector<sf::RectangleShape>& roads, const std::vector<sf::CircleShape>& otherCircles, const std::vector<sf::CircleShape>& mapElements, const std::vector<Tower>& towers, const std::vector<Enemy>& enemies, const std::vector<Bullet>& bullets, const sf::CircleShape& spawnPoint);
extern void createRoads(int selectedLevel, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles);
extern void spawnEnemies(int selectedLevel, float& spawnTimer, float totalTimer, std::vector<Enemy>& enemies, sf::CircleShape& spawnPoint, std::vector<sf::Vector2f>& path, int& enemyIdCounter, sf::Text& waveTitle, bool& isLevelScreen, bool& isYouWinScreen);
extern void resetGame(int selectedLevel, std::vector<Tower>& towers, std::vector<Enemy>& enemies, std::vector<Bullet>& bullets, std::vector<int>& enemiesToRemove, Home& home, sf::CircleShape& spawnPoint, sf::Text& levelTitle, sf::Text& waveTitle, sf::Text& moneyText, int& money, int& enemyIdCounter, float& spawnTimer, float& totalTimer, std::vector<sf::Vector2f>& path, std::vector<sf::RectangleShape>& roads, std::vector<sf::CircleShape>& otherCircles);
extern std::vector<sf::Vector2f> createPathLevel1();
extern std::vector<sf::Vector2f> createPathLevel2();
extern std::vector<sf::Vector2f> createPathLevel3();
extern std::vector<sf::Vector2f> createPathLevel4();
extern std::vector<sf::Vector2f> createPathLevel5();
extern std::vector<sf::Vector2f> createPathLevel6();
extern void loadGuideContent(int selectedLevel, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text, bool isTowerGuide);
extern void drawButtons(sf::RenderWindow& window, const sf::Font& font, std::vector<sf::RectangleShape>& buttons, std::vector<sf::Text>& buttonTexts);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Protect Your Professor!");

    loadSounds();

    // 加载字体
    sf::Font font;
    if (!font.loadFromFile("assets/times new roman bold.ttf")) 
    {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // 设置标题文本
    sf::Text title("Protect Your Professor!", font, 50);
    title.setFillColor(sf::Color::Black);
    title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 150);

    // 设置按钮
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Black);
    button.setPosition(800 / 2 - 100, 450);

    // 设置按钮文本
    sf::Text buttonText("Start", font, 30);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(button.getPosition().x + button.getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
                           -10 + button.getPosition().y + button.getSize().y / 2 - buttonText.getGlobalBounds().height / 2);

    bool isStartScreen = true;
    bool isLevelSelectScreen = false;
    bool isTowerGuideScreen = false;
    bool isEnemyGuideScreen = false;
    bool isLevelScreen = false;
    bool isSelectingTower = false; 
    bool isGameOverScreen = false;
    bool isYouWinScreen = false;
    int selectedLevel = 0;
    sf::Clock selectTowerClock; // 用于选择塔的计时
    sf::Vector2f selectedPosition; // 记录选择的位置

    // 设置关卡按钮
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    int buttonSize = 120;
    int spacing = 60;
    int startX = (800 - (buttonSize * 3 + spacing * 2)) / 2;
    int startY = (600 - (buttonSize * 2 + spacing)) / 2;

    for (int i = 0; i < 6; ++i) {
        sf::RectangleShape levelButton(sf::Vector2f(buttonSize, buttonSize));
        levelButton.setFillColor(sf::Color::Black);
        int x = startX + (i % 3) * (buttonSize + spacing);
        int y = startY + (i / 3) * (buttonSize + spacing);
        levelButton.setPosition(x, y);
        buttons.push_back(levelButton);

        sf::Text buttonText(std::to_string(i + 1), font, 40);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(x + buttonSize / 2 - buttonText.getGlobalBounds().width / 2,
                               -10 + y + buttonSize / 2 - buttonText.getGlobalBounds().height / 2);
        buttonTexts.push_back(buttonText);
    }

    // 引导元素
    sf::Texture guideTexture;
    sf::Sprite guideSprite;

    sf::Text guideText("", font, 20);
    guideText.setFillColor(sf::Color::Black);
    guideText.setPosition(450, 60);
    guideText.setCharacterSize(25); 

    sf::RectangleShape guideButton(sf::Vector2f(200, 50));
    guideButton.setFillColor(sf::Color::Black);
    guideButton.setPosition(800 / 2 - 100, 450);

    sf::Text guideButtonText("Next", font, 25);
    guideButtonText.setFillColor(sf::Color::White);
    guideButtonText.setPosition(guideButton.getPosition().x + guideButton.getSize().x / 2 - guideButtonText.getGlobalBounds().width / 2,
                                -7.5 + guideButton.getPosition().y + guideButton.getSize().y / 2 - guideButtonText.getGlobalBounds().height / 2);

    // 关卡元素
    sf::Text levelTitle("Level 1", font, 40);
    levelTitle.setFillColor(sf::Color::Black);
    levelTitle.setPosition(800 / 2 - levelTitle.getGlobalBounds().width / 2 - 62.5, 20);

    sf::Text waveTitle("Wave 1", font, 30);
    waveTitle.setFillColor(sf::Color::Black);
    waveTitle.setPosition(800 / 2 - waveTitle.getGlobalBounds().width / 2 + 62.5, 30);

    sf::RectangleShape mapBackground(sf::Vector2f(770, 490));
    mapBackground.setFillColor(sf::Color(211, 211, 211));  // 浅灰色
    mapBackground.setPosition(15, 100);

    sf::Text backButton("Back", font, 20);
    backButton.setFillColor(sf::Color::Black);
    backButton.setPosition(40, 60);

    sf::Text moneyText("Money: 100", font, 20);
    moneyText.setFillColor(sf::Color::Black);
    moneyText.setPosition(670, 60);

    int money = 100;

    // 创建地图元素
    std::vector<sf::CircleShape> mapElements;

    // 出怪点
    sf::CircleShape spawnPoint(30);
    spawnPoint.setFillColor(sf::Color(100, 100, 100));

    // 家
    Home home(sf::Vector2f(20 + 10 * 70, 105 + 5 * 70), 100); // 第六行第十一列

    // 道路
    std::vector<sf::RectangleShape> roads;
    std::vector<std::pair<int, int>> roadPositions = {
        {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9},
        {2, 9}, 
        {3, 9}, {3, 8}, {3, 7}, {3, 6}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {3, 1},
        {4, 1},
        {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}
    };

    for (const auto& pos : roadPositions) {
        sf::RectangleShape road(sf::Vector2f(70, 70));
        road.setFillColor(sf::Color(144, 144, 144)); // 深灰色
        road.setPosition(15 + pos.second * 70, 100 + pos.first * 70);
        roads.push_back(road);
    }

    // 存储塔和敌人
    std::vector<Tower> towers;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
    std::vector<int> enemiesToRemove;

    std::vector<sf::Vector2f> path = createPathLevel1();

    sf::Clock clock;
    float deltaTime = 0;
    float spawnTimer = 0;
    float totalTimer = 0;
    
    // 计数器，确保敌人唯一ID
    int enemyIdCounter = 0; 

    // Game Over
    sf::Text gameOverText("Game Over", font, 50);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(800 / 2 - gameOverText.getGlobalBounds().width / 2, 160);

    sf::RectangleShape gameOverBackButton(sf::Vector2f(180, 40));
    gameOverBackButton.setFillColor(sf::Color::Black);
    gameOverBackButton.setPosition(800 / 2 - 100, 340);

    sf::Text gameOverBackButtonText("Back", font, 25);
    gameOverBackButtonText.setFillColor(sf::Color::White);
    gameOverBackButtonText.setPosition(gameOverBackButton.getPosition().x + gameOverBackButton.getSize().x / 2 - gameOverBackButtonText.getGlobalBounds().width / 2,
                                       -7.5 + gameOverBackButton.getPosition().y + gameOverBackButton.getSize().y / 2 - gameOverBackButtonText.getGlobalBounds().height / 2);

    // You Win
    sf::Text youWinText("You Win !", font, 50);
    youWinText.setFillColor(sf::Color::Black);
    youWinText.setPosition(800 / 2 - youWinText.getGlobalBounds().width / 2, 160);

    sf::RectangleShape youWinBackButton(sf::Vector2f(180, 40));
    youWinBackButton.setFillColor(sf::Color::Black);
    youWinBackButton.setPosition(800 / 2 - 100, 340);

    sf::Text youWinBackButtonText("Back", font, 25);
    youWinBackButtonText.setFillColor(sf::Color::White);
    youWinBackButtonText.setPosition(youWinBackButton.getPosition().x + youWinBackButton.getSize().x / 2 - youWinBackButtonText.getGlobalBounds().width / 2,
                                       -7.5 + youWinBackButton.getPosition().y + youWinBackButton.getSize().y / 2 - youWinBackButtonText.getGlobalBounds().height / 2);

    // 主循环开始
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (isStartScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isStartScreen = false;
                        isLevelSelectScreen = true;
                    }
                }
            }
            else if (isLevelSelectScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    for (int i = 0; i < buttons.size(); ++i)
                    {
                        if (buttons[i].getGlobalBounds().contains(mousePos.x, mousePos.y))
                        {
                            selectedLevel = i + 1;
                            isLevelSelectScreen = false;
                            resetGame(selectedLevel, towers, enemies, bullets, enemiesToRemove, home, spawnPoint, levelTitle, waveTitle, moneyText, money, enemyIdCounter, spawnTimer, totalTimer, path, roads, otherCircles);

                            if (selectedLevel <= 4) {
                                isTowerGuideScreen = true;
                                loadGuideContent(selectedLevel, guideTexture, guideSprite, guideText, true);
                            } else {
                                isLevelScreen = true;
                            }
                            
                        }
                    }
                }
            }
            else if (isLevelScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isLevelScreen = false;
                        isLevelSelectScreen = true;
                    }
                    for (auto& circle : otherCircles)
                    {
                        if (circle.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        {
                            isSelectingTower = true;
                            selectedPosition = circle.getPosition();
                            selectTowerClock.restart();
                        }
                    }
                }
            }
            else if (isTowerGuideScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (guideButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isTowerGuideScreen = false;
                        isEnemyGuideScreen = true;
                        if (selectedLevel == 4) {
                            isEnemyGuideScreen = false;
                            isLevelScreen = true;
                        } else {
                            loadGuideContent(selectedLevel, guideTexture, guideSprite, guideText, false);
                        }
                    }
                }
            }
            else if (isEnemyGuideScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (guideButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isEnemyGuideScreen = false;
                        isLevelScreen = true;
                    }
                }
            }
            else if (isSelectingTower && event.type == sf::Event::KeyPressed)
            {
                Tower::Type selectedType;
                bool validSelection = false;
                switch (event.key.code)
                {
                case sf::Keyboard::Num1:
                    selectedType = Tower::Type::Circle;
                    validSelection = true;
                    break;
                case sf::Keyboard::Num2:
                    selectedType = Tower::Type::Square;
                    validSelection = true;
                    break;
                case sf::Keyboard::Num3:
                    selectedType = Tower::Type::Triangle;
                    validSelection = true;
                    break;
                case sf::Keyboard::Num4:
                    selectedType = Tower::Type::Star;
                    validSelection = true;
                    break;
                default:
                    break;
                }

                if (validSelection)
                {
                    int cost = Tower::getCost(selectedType);
                    bool canPlace = true;

                    for (const auto& tower : towers)
                    {   
                        if (tower.getPosition() == selectedPosition)
                        {
                            canPlace = false;
                            break;
                        }
                    }

                    if ((money >= cost) && (validSelection) && (allowedTowers.find(selectedType) != allowedTowers.end()))
                    {
                        towers.emplace_back(selectedType, selectedPosition);
                        money -= cost;
                        moneyText.setString("Money: " + std::to_string(money));
                    }
                    isSelectingTower = false;
                }
            }
            // Game Over 界面
            else if (isGameOverScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (gameOverBackButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isGameOverScreen = false;
                        isLevelSelectScreen = true;
                    }
                }
            }
            // You Win 界面
            else if (isYouWinScreen && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
                    if (youWinBackButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isYouWinScreen = false;
                        isLevelSelectScreen = true;
                    }
                }
            }
        }

        if (isSelectingTower && selectTowerClock.getElapsedTime().asSeconds() > 2.0f)
        {
            isSelectingTower = false;
        }

        if (isLevelScreen)
        {
            spawnTimer += deltaTime;
            totalTimer += deltaTime;

            // 生成敌人代码
            spawnEnemies(selectedLevel, spawnTimer, totalTimer, enemies, spawnPoint, path, enemyIdCounter, waveTitle, isLevelScreen, isYouWinScreen);
            
            // 敌人移动，死亡，到家代码
            for (auto& enemy : enemies)
            {
                enemy.update(deltaTime);

                if (enemy.isDead())
                {
                    money += 5;
                    moneyText.setString("Money: " + std::to_string(money));
                    enemiesToRemove.push_back(enemy.getId()); 
                }

                if (enemy.getPosition() == home.getPosition())
                {
                    home.takeDamage(10);
                    enemiesToRemove.push_back(enemy.getId()); 
                    if (home.isDestroyed())
                    {
                        // 游戏结束逻辑
                        isLevelScreen = false;
                        isGameOverScreen = true;
                    }
                }
            }

            // 移除死去的敌人
            enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&enemiesToRemove](const Enemy& enemy) {
                return std::find(enemiesToRemove.begin(), enemiesToRemove.end(), enemy.getId()) != enemiesToRemove.end();
            }), enemies.end());

            // 清空需要移除的敌人列表
            enemiesToRemove.clear(); 

            // 塔冷却，发射代码
            for (auto& tower : towers)
            {
                tower.update(deltaTime); // 更新塔的冷却时间

                if (!enemies.empty()) {
                    tower.shoot(bullets, enemies);
                }
            }

            // 子弹移动，击中代码
            for (auto& bullet : bullets)
            {
                bullet.update(deltaTime);

                for (auto& enemy : enemies)
                {   
                    if (bullet.hasHitTarget(enemy) && !bullet.hasAlreadyHit(enemy))
                    {  
                        if (bullet.isSplashDamage()) {
                            bullet.applyAreaDamage(enemies);
                        } else {
                            enemy.takeDamage(bullet.getDamage());
                        }

                        if (bullet.isSlowSpeed()) {
                            if (!enemy.isSlowed()) {
                                enemy.slower(bullet.getSlowRatio());
                            }
                        }

                        bullet.registerHit(enemy);
                    }
                }
            }

            // 移除非穿透型子弹
            bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [&enemies](const Bullet& bullet) {
                return !bullet.isPiercing() && std::any_of(enemies.begin(), enemies.end(), [&bullet](const Enemy& enemy) {
                    return bullet.hasHitTarget(enemy);
                });
            }), bullets.end());

            // Home 血量更新
            home.update();
        }

        // 开始绘制界面
        window.clear(sf::Color::White);

        if (isStartScreen)
        {
            window.draw(title);
            window.draw(button);
            window.draw(buttonText);
        }
        else if (isLevelSelectScreen)
        {
            drawButtons(window, font, buttons, buttonTexts);
        }
        else if (isLevelScreen)
        {
            drawGame(window, levelTitle, waveTitle, mapBackground, backButton, moneyText, home, roads, otherCircles, mapElements, towers, enemies, bullets, spawnPoint);
        }
        // Game Over 绘制
        else if (isGameOverScreen){
            window.draw(gameOverText);
            window.draw(gameOverBackButton);
            window.draw(gameOverBackButtonText);
        }
        // You Win 绘制
        else if (isYouWinScreen){
            window.draw(youWinText);
            window.draw(youWinBackButton);
            window.draw(youWinBackButtonText);
        }
        else if (isTowerGuideScreen || isEnemyGuideScreen)
        {
            window.draw(guideSprite);
            window.draw(guideText);
            window.draw(guideButton);
            window.draw(guideButtonText);
        }

        window.display();
    }

    return 0;
}