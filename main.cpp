#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    //1366, 768
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Menu", sf::Style::Fullscreen);

    Menu menu(1366, 768);

	menu.start(window);
    return 0;
}
