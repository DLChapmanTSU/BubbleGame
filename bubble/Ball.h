#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    sf::Color m_color;
    sf::CircleShape m_shape;
    bool m_isActive;
    bool m_isInWall;
    size_t m_id;
    bool m_isPlayerOneBall;
public:
    Ball(sf::Vector2f p, sf::Vector2f v, sf::Color c, bool a, size_t i, bool w = true);
    void Update();
    void Render(sf::RenderWindow& w);
    bool GetIsActive();
    sf::Vector2f& GetPosition();
    sf::Color& GetColor();
    bool GetIsInWall();
    size_t GetID();
    bool GetIsPlayerOneBall();
    void SetVelocity(float x, float y);
    void SetIsActive(bool a);
    void SetPosition(float x, float y);
    void SetIsInWall(bool w);
    void SetColor(sf::Color& c);
    void SetIsPlayerOneBall(bool p);
    bool CheckCollision(std::vector<Ball>& b);
    int WallCombo(std::vector<Ball>& b);
};