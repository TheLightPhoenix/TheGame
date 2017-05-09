#ifndef CHARACTER_H
#define CHARACTER_h
#include <SFML/Graphics.hpp>


class character
{
    int run_animation_counter, idle_counter;
    sf::Sprite run_sprite;
    sf::Texture *run_text;
    sf::Texture *idle_text;
    sf::Sprite idle_sprite;


    public:
    character();
    ~character();
    sf::Sprite run_right();
    sf::Sprite run_left();
    sf::Sprite idle();
    void spawn();

};





#endif // CHARACTER_H
