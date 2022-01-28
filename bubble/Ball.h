#include <SFML/Graphics.hpp>

class Ball{
private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    sf::Color m_color;
    sf::CircleShape m_shape;
    bool m_isActive;
public:
    Ball(sf::Vector2f p, sf::Vector2f v, sf::Color c, bool a);
    void Update();
    void Render(sf::RenderWindow& w);
};