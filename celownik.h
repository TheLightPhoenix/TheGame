#ifndef CELOWNIK_H
#define CELOWNIK_H
#include <SFML/Graphics.hpp>

//#define KAMERKA

#ifdef KAMERKA
#include "kamerka.h"
#endif // KAMERKA


class celownik
{
    private:
        sf::Vector2i position;
        sf::Vector2f cel_position;
        sf::Texture cel_text;
        sf::Sprite cel_sprite;
        float x_0;

        #ifdef KAMERKA
        Kamerka cam;
        #endif // KAMERKA

    public:
        celownik();
        void draw(sf::RenderWindow &, float);
};

#endif // CELOWNIK_H
