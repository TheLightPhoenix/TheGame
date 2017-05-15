#include "game.h"
#include "character.h"
#include "level.h"

game::game()
{
    w_prawo = 0;
    w_lewo = 0;
    space = 0;
    hamuj = 0;
}

void game::start(unsigned int window_width, unsigned int window_height, unsigned int style)
{
    float view_x = 0;
    character bohater;
    game_window.create(sf::VideoMode(window_width, window_height, 32), "Gra", style);
    game_window.setFramerateLimit(60);
    game_window.setVerticalSyncEnabled(true);
    level mapa(1);
    sf::View view(sf::FloatRect(0, 0, 1920, 1080));
    game_window.setView(view);

    while(game_window.isOpen())
    {
        sf::Event zdarzenie;
        while(game_window.pollEvent(zdarzenie))
        {
            if( zdarzenie.type == sf::Event::Closed )
                game_window.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                game_window.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::D)
            {
                w_prawo = 1;
                w_lewo = 0;
                running_right_start = clock.getElapsedTime();
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::A)
            {
                w_lewo = 1;
                w_prawo = 0;
                running_left_start = clock.getElapsedTime();
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space && space == 0)
            {
                space = 1;
                jump_start = clock.getElapsedTime();
            }
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::A && w_lewo)
            {
                w_lewo = 0;
                hamuj = 1;
                breaking_time = clock.getElapsedTime();
            }
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::D && w_prawo)
            {
                w_prawo = 0;
                hamuj = 1;
                breaking_time = clock.getElapsedTime();
            }
        }

        if(bohater.x - view_x > 1000)
        {
            view.move(bohater.current_running_speed, 0);
            view_x += bohater.current_running_speed;

        }
        if(bohater.x - mapa.middle_sprite_x >= 1920)
            mapa.move_sprites_right();

        if(bohater.x - view_x < 300)
        {
            view.move(bohater.current_running_speed, 0);
            view_x += bohater.current_running_speed;
        }
        if(bohater.x - mapa.middle_sprite_x < 0)
            mapa.move_sprites_left();


        if(space)
        {
            current_time = clock.getElapsedTime();
            space = bohater.jump(current_time - jump_start);
        }
        if(w_prawo && !hamuj)
        {
            current_time = clock.getElapsedTime();
            bohater.run_right(current_time - running_right_start);
        }
        else if(w_lewo && !hamuj)
        {
            current_time = clock.getElapsedTime();
            bohater.run_left(current_time - running_left_start);
        }
        else
        {
            current_time = clock.getElapsedTime();
            hamuj = bohater.hamuj(current_time - breaking_time);
        }

        game_window.clear( sf::Color( 0, 0, 0 ) );
        mapa.draw(game_window);
        bohater.draw(game_window);
        game_window.setView(view);
        game_window.display();
    }
}
