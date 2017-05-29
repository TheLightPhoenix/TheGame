#ifndef OPCJE_H
#define OPCJE_H
#define MAX_NUMBER_OF_ITEMS 3
#include "SFML/Graphics.hpp"


class Opcje
{
public:
	Opcje(float width, float height);
	~Opcje();

	void draw(sf::RenderWindow &window);
	void MoveeUp();
	void MoveeDown();


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text opcje[MAX_NUMBER_OF_ITEMS];

};

#endif // OPCJE_H

