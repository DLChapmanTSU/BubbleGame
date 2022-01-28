#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>

#include "Ball.h"

#define BUBBLE_SIZE 20
#define CANNON_H  60
#define CANNON_W  20
#define MAX_ANGLE 80
#define MIN_ANGLE 280
#define VELOCITY  7
#define WINDOW_H  600
#define WINDOW_W  1200

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Bubble");
    window.setFramerateLimit(60);

    const sf::Color colours[5] = {
        sf::Color::Red,
        sf::Color(127, 192, 127),
        sf::Color::Blue,
        sf::Color(192, 192, 127),
        sf::Color(127, 192, 192),
    };

    std::vector<Ball> bubbles;
    for (size_t i = 1; i < 11; i++) {
        for (size_t j = 0; j < (WINDOW_W / 2) / 40 - (i % 2); j++) {
            sf::CircleShape bubble(BUBBLE_SIZE);
            bubble.setPosition(sf::Vector2f(BUBBLE_SIZE * 2 * j + (i % 2) * BUBBLE_SIZE, i * 33));
            int points = rand() % 5;
            bubble.setFillColor(colours[points]);
            bubbles.push_back(Ball(sf::Vector2f(BUBBLE_SIZE * 2 * j + (i % 2) * BUBBLE_SIZE, i * 33), sf::Vector2f(0.0f, 0.0f), colours[points], true));
        }
    }

    sf::RectangleShape cannon1(sf::Vector2f(CANNON_W, CANNON_H));
    cannon1.setOrigin(CANNON_W / 2, CANNON_H);
    sf::Vector2f p1_pos(WINDOW_W / 4, (WINDOW_H));
    cannon1.setOrigin(CANNON_W / 2, CANNON_H);
    cannon1.setPosition(p1_pos);
    float angle1{ 0 };
    bool isCannon1Ready{ true };

    sf::RectangleShape cannon2(sf::Vector2f(CANNON_W, CANNON_H));
    cannon2.setOrigin(CANNON_W / 2, CANNON_H);
    sf::Vector2f p2_pos(3 * WINDOW_W / 4, (WINDOW_H));
    cannon2.setPosition(p2_pos);
    float angle2 = 0;
    bool isCannon2Ready{ true };

    sf::RectangleShape wall(sf::Vector2f(1, WINDOW_H));
    wall.setPosition(WINDOW_W / 2, 0);

    sf::CircleShape ball1(BUBBLE_SIZE);
    ball1.setOrigin(BUBBLE_SIZE, BUBBLE_SIZE);
    ball1.setPosition(p1_pos);
    ball1.setFillColor(colours[rand() % 5]);
    float dx1{ 0 };
    float dy1{ 0 };

    sf::CircleShape ball2(BUBBLE_SIZE);
    ball2.setOrigin(BUBBLE_SIZE, BUBBLE_SIZE);
    ball2.setPosition(p2_pos);
    ball2.setFillColor(colours[rand() % 5]);
    float dx2{ 0 };
    float dy2{ 0 };

    sf::Font font;
    if (!font.loadFromFile("PressStart2P.ttf"))
    {
        return 1;
    }
    sf::Text score("0 0", font);
    score.setCharacterSize(30);
    score.setPosition(WINDOW_W / 2 - 44, 10);
    int score1 = 0;
    int score2 = 0;

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        angle1 = cannon1.getRotation();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (angle1 > MIN_ANGLE + 1 || angle1 < MAX_ANGLE + 1))
            cannon1.rotate(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (angle1 > MIN_ANGLE - 1 || angle1 < MAX_ANGLE - 1))
            cannon1.rotate(1);
        angle2 = cannon2.getRotation();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (angle2 > MIN_ANGLE + 1 || angle2 < MAX_ANGLE + 1))
            cannon2.rotate(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (angle2 > MIN_ANGLE - 1 || angle2 < MAX_ANGLE -1))
            cannon2.rotate(1);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isCannon1Ready)
        {
            angle1 = cannon1.getRotation();
            dx1 = -cos((angle1 + 90) * M_PI / 180) * VELOCITY;
            dy1 = -sin((angle1 + 90) * M_PI / 180) * VELOCITY;
            isCannon1Ready = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isCannon2Ready)
        {
            angle2 = cannon2.getRotation();
            dx2 = -cos((angle2 + 90) * M_PI / 180) * VELOCITY;
            dy2 = -sin((angle2 + 90) * M_PI / 180) * VELOCITY;
            isCannon2Ready = false;
        }

        if (dx1 != 0 && dy1 != 0)
        {
            ball1.move(dx1, dy1);
            sf::Vector2f pos = ball1.getPosition();
            if (pos.x < BUBBLE_SIZE || pos.x > WINDOW_W / 2 - BUBBLE_SIZE) {
                dx1 = -dx1;
            }
        }

        if (dx2 != 0 && dy2 != 0)
        {
            ball2.move(dx2, dy2);
            sf::Vector2f pos = ball2.getPosition();
            if (pos.x < WINDOW_W / 2 + BUBBLE_SIZE || pos.x > WINDOW_W - BUBBLE_SIZE) {
                dx2 = -dx2;
            }
        }

        window.clear();
        window.draw(cannon1);
        window.draw(cannon2);
        window.draw(wall);
        window.draw(score);
        window.draw(ball1);
        window.draw(ball2);
        for (Ball& b : bubbles) {
            b.Render(window);
        }
        window.display();
    }
    return 0;
}
