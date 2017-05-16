#ifndef CELOWNIK_H
#define CELOWNIK_H
#include <SFML/Graphics.hpp>

class celownik
{
    public:
    sf::Vector2i position;
    sf::Texture cel_text;
    sf::Sprite cel_sprite;
    float x_0;

    celownik();
    void draw(sf::RenderWindow &, float);
};

#endif // CELOWNIK_H
