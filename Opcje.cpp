#include "Opcje.h"
#include "game.h"

Opcje::Opcje(float width, float height)
{
	if (!font.loadFromFile("czcionka2.ttf"))
	{
		// handle error
	}

	opcje[0].setFont(font);
	opcje[0].setColor(sf::Color::Red);
	opcje[0].setString("POWROT");
	opcje[0].setPosition(sf::Vector2f(width / 2, height / 2));


	selectedItemIndex = 0;
}


Opcje::~Opcje()
{
}


void Opcje::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(opcje[i]);
	}
}

void Opcje::MoveeUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		opcje[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		opcje[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Opcje::MoveeDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		opcje[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		opcje[selectedItemIndex].setColor(sf::Color::Red);
	}
}
