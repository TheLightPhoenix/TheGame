#include "celownik.h"

celownik::celownik()
{
    x_0 = 0;
    position = sf::Mouse::getPosition();
    cel_text.loadFromFile("celownik.png");
    cel_sprite.setTexture(cel_text);
    cel_sprite.setPosition(position.x, position.y);
}

void celownik::draw(sf::RenderWindow &game_window, float view_x)
{
    position = sf::Mouse::getPosition();
    cel_sprite.setPosition(position.x + view_x, position.y);
    game_window.draw(cel_sprite);
    return;
}
