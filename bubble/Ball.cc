#include "Ball.h"

#include <iostream>

Ball::Ball(sf::Vector2f p, sf::Vector2f v, sf::Color c, bool a, bool w) {
    m_position = p;
    m_velocity = v;
    m_color = c;
    m_isActive = a;
    m_isInWall = w;
    m_shape = sf::CircleShape(20);
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
    m_shape.setOrigin(20.0f, 20.0f);
}

void Ball::Update() {
    if (m_isActive == false) {
        return;
    }

    m_position += m_velocity;
}

void Ball::Render(sf::RenderWindow& w) {
    if (m_isActive == false) {
        return;
    }
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
    w.draw(m_shape);
}

bool Ball::GetIsActive() {
    return m_isActive;
}

sf::Vector2f& Ball::GetPosition()
{
    return m_position;
}

sf::Color& Ball::GetColor()
{
    return m_color;
}

bool Ball::GetIsInWall(){
    return m_isInWall;
}

void Ball::SetVelocity(float x, float y) {
    m_velocity = sf::Vector2f(x, y);
}

void Ball::SetIsActive(bool a) {
    m_isActive = a;
}

void Ball::SetPosition(float x, float y) {
    m_position = sf::Vector2f(x, y);
}

void Ball::SetIsInWall(bool w){
    m_isInWall = w;
}

bool Ball::CheckCollision(std::vector<Ball>& b)
{
    for (size_t i = 0; i < b.size(); i++)
    {
        if (b[i].GetIsActive() == false || b[i].GetIsInWall() == true) {
            continue;
        }

        sf::Vector2f diff = b[i].GetPosition() - m_position;
        float squaredLength = (diff.x * diff.x) + (diff.y * diff.y);
        float radiusSquared = 40 * 40;

        if (squaredLength <= radiusSquared) {
            m_velocity = sf::Vector2f(0.0f, 0.0f);
            //Snapping
            int yPosRemainder = (int)m_position.y % 33;
            int yPosDivisor = (int)m_position.y / 33;
            float roundedDownY = 33.0f * yPosDivisor;

            if (yPosRemainder <= 16) {
                m_position.y = roundedDownY;
            }
            else {
                m_position.y = roundedDownY + 33.0f;
            }

            if (m_position.x <= b[i].GetPosition().x){
                m_position.x = b[i].GetPosition().x - 20.0f;
            }
            else{
                m_position.x = b[i].GetPosition().x + 20.0f;
            }

            //Need to figure out a snap for the x axis
            //Loop in main for setting up the grid makes little sense

            if (b[i].GetColor() == m_color) {
                m_isActive = false;
                b[i].SetIsActive(false);
            }

            std::cout << "Hit Ball" << std::endl;

            return true;
        }
    }
    return false;
}