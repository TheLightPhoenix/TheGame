#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include "character.h"



int main()
{
    bool w_prawo=0, w_lewo=0;
    sf::RenderWindow okno_aplikacji(sf::VideoMode(1920, 1080, 32), "Gra", sf::Style::Fullscreen);
    okno_aplikacji.setVerticalSyncEnabled(true);

    sf::Texture background;
    background.loadFromFile("tlo.png");

    sf::Sprite tlo1;
    tlo1.setTexture(background);

    character bohater;

    while(okno_aplikacji.isOpen())
    {
        sf::Clock clock;
        sf::Time t1 = clock.getElapsedTime();

        sf::Event zdarzenie;
        while(okno_aplikacji.pollEvent(zdarzenie))
        {
            if( zdarzenie.type == sf::Event::Closed )
                okno_aplikacji.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 okno_aplikacji.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::D && w_prawo == 0)
                w_prawo = 1;
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::D && w_prawo == 1)
                w_prawo = 0;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::A && w_lewo == 0)
                w_lewo = 1;
            if( zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::A && w_lewo == 1)
                w_lewo = 0;

        }

        okno_aplikacji.clear( sf::Color( 0, 0, 0 ) );
        okno_aplikacji.draw(tlo1);

        if(w_prawo)
            okno_aplikacji.draw(bohater.run_right());
        else if(w_lewo)
            okno_aplikacji.draw(bohater.run_left());
        else
            okno_aplikacji.draw(bohater.idle());



        okno_aplikacji.display();

        while(t1.asSeconds() < 0.045)
        {
            t1 = clock.getElapsedTime();
        }


    }
    return 0;
}
