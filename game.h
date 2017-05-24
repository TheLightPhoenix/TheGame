#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "character.h"
#include "level.h"
#include "celownik.h"
#include "Menu.h"

class game
{
    sf::Clock clock;
    sf::Time jump_start, jump_on_air, running_right_start, running_left_start, current_time, breaking_time;

    bool w_prawo, w_lewo, space, hamuj;

    sf::RenderWindow game_window;

    public:
    game();
    void start(unsigned int window_width, unsigned int window_height, unsigned int style);
};


#endif // GAME_H
