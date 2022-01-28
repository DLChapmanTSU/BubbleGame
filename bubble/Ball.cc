#include "Ball.h"

Ball::Ball(sf::Vector2f p, sf::Vector2f v, sf::Color c, bool a){
    m_position = p;
    m_velocity = v;
    m_color = c;
    m_isActive = a;
    m_shape = sf::CircleShape(20);
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
}

void Ball::Update(){
    if (m_isActive == false){
        return;
    }

    m_position += m_velocity;
}

void Ball::Render(sf::RenderWindow& w){
    m_shape.setFillColor(m_color);
    m_shape.setPosition(m_position);
    w.draw(m_shape);
}