#ifndef ARROW_H
#define ARROW_H
#include <SFML/Graphics.hpp>

class arrow
{
    public:
    sf::Texture arrow_text;
    sf::Sprite arrow_sprite;
    sf::Vector2f position;
    float angle;


    arrow();
};



#endif // ARROW_H
