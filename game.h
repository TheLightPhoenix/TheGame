#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class game
{
    sf::Clock clock, jump_clock;
    sf::Time t1, jump_start, jump_on_air;

    bool w_prawo, w_lewo, space;

    sf::RenderWindow game_window;

    sf::Texture background;

    sf::Sprite tlo;



    public:
    game();
    void start(unsigned int window_width, unsigned int window_height, unsigned int style);
};


#endif // GAME_H
