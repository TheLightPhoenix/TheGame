#include "celownik.h"

celownik::celownik()
{
    x_0 = 0;
    position = sf::Mouse::getPosition();
    cel_position.x = position.x;
    cel_position.y = position.y;
    cel_text.loadFromFile("celownik.png");
    cel_sprite.setTexture(cel_text);
    cel_sprite.setOrigin(85, 85);
    cel_sprite.setPosition(position.x, position.y);
}

void celownik::draw(sf::RenderWindow &game_window, float view_x)
{
    #ifdef KAMERKA
    cam.update();
    position.x = cam.getPosition().x;
    position.y = cam.getPosition().y;
    #else
    position = sf::Mouse::getPosition();
    #endif
    cel_sprite.setPosition(position.x + view_x, position.y);
    cel_position.x = position.x + view_x;
    cel_position.y = position.y;
    game_window.draw(cel_sprite);
    return;
}
