#include "game.h"
#include "character.h"

game::game()
{
    w_prawo = 0;
    w_lewo = 0;
    space = 0;
    background.loadFromFile("tlo.png");
    tlo.setTexture(background);
}

void game::start(unsigned int window_width, unsigned int window_height, unsigned int style)
{
    character bohater;
    game_window.create(sf::VideoMode(window_width, window_height, 32), "Gra", style);
    game_window.setFramerateLimit(60);

    while(game_window.isOpen())
    {
        sf::Event zdarzenie;
        while(game_window.pollEvent(zdarzenie))
        {
            if( zdarzenie.type == sf::Event::Closed )
                game_window.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                game_window.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::D && w_prawo == 0)
                w_prawo = 1;
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::D && w_prawo == 1)
                w_prawo = 0;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::A && w_lewo == 0)
                w_lewo = 1;
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::A && w_lewo == 1)
                w_lewo = 0;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space && space == 0)
            {
                space = 1;
                jump_start = jump_clock.getElapsedTime();
            }

        }

        game_window.clear( sf::Color( 0, 0, 0 ) );
        game_window.draw(tlo);

        if(space)
        {
            jump_on_air = jump_clock.getElapsedTime();
            space = bohater.jump(jump_on_air - jump_start);
        }

        if(w_prawo && !w_lewo)
        {
            bohater.run_right();
            game_window.draw(bohater.draw());
        }
        else if(w_lewo && !w_prawo)
        {
            bohater.run_left();
            game_window.draw(bohater.draw());
        }
        else
        {
            bohater.idle();
            game_window.draw(bohater.draw());
        }



        game_window.display();




    }
}
