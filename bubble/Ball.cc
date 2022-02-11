#include "Ball.h"

Ball::Ball(sf::Vector2f p, sf::Vector2f v, sf::Color c, bool a){
    m_position = p;
    m_velocity = v;
    m_color = c;
    m_isActive = a;
    m_shape = sf::CircleShape(20);
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
    m_shape.setOrigin(20.0f, 20.0f);
}

void Ball::Update(){
    if (m_isActive == false){
        return;
    }

    m_position += m_velocity;
}

void Ball::Render(sf::RenderWindow& w){
    if (m_isActive == false){
        return;
    }
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
    w.draw(m_shape);
}

bool Ball::GetIsActive(){
    return m_isActive;
}

void Ball::SetVelocity(float x, float y){
    m_velocity = sf::Vector2f(x, y);
}

void Ball::SetIsActive(bool a){
    m_isActive = a;
}

void Ball::SetPosition(float x, float y){
    m_position = sf::Vector2f(x, y);
}