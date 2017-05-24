#include "Menu.h"
#include "game.h"
int play = 0;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("czcionka2.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("GRAJ");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("OPCJE");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("WYJSCIE");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::start()
{

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");

	Menu menu(window.getSize().x, window.getSize().y);

	int play=0;

	while (window.isOpen())
	{

        sf::Sprite tloMenu;
        sf::Texture teksturaTla;
        teksturaTla.loadFromFile("menuu.jpg");
        tloMenu.setTexture(teksturaTla);


	    window.clear();

            if(play==1)
            {
                play=0;
                game gra;
                gra.start(1920, 1080, 0);
            }
            else if(play==2)
            {
                window.close();
            }
            else
            {

                sf::Event event;

                while (window.pollEvent(event))
                {
                    switch (event.type)
                    {
                    case sf::Event::KeyReleased:
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                            case 0:
                                    play=1;
                                break;
                            case 1:
                                    play=2;
                                break;
                            case 2:
                                window.close();
                                break;
                            }

                            break;
                        }

                        break;
                    case sf::Event::Closed:
                        window.close();

                        break;
                    }
                }
                window.draw(tloMenu);
                menu.draw(window);
                window.display();
            }




	}

}
