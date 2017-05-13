#include "level.h"

level::level(int number)
{
    middle_sprite_x = 0;
    if(number == 1)
    {
        background_text = new sf::Texture[5];
        background_text[0].loadFromFile(".\\Backgrounds\\Background 01\\PARALLAX\\layer_01_1920 x 1080.png");
        background_text[1].loadFromFile(".\\Backgrounds\\Background 01\\PARALLAX\\layer_02_1920 x 1080.png");
        background_text[2].loadFromFile(".\\Backgrounds\\Background 01\\PARALLAX\\layer_03_1920 x 1080.png");
        background_text[3].loadFromFile(".\\Backgrounds\\Background 01\\PARALLAX\\layer_04_1920 x 1080.png");
        background_text[4].loadFromFile(".\\Backgrounds\\Background 01\\PARALLAX\\layer_05_1920 x 1080.png");

        background_sprite_middle = new sf::Sprite[5];
        background_sprite_left = new sf::Sprite[5];
        background_sprite_right = new sf::Sprite[5];

        for(int i = 0; i < 5; i++)
        {
            background_sprite_middle[i].setTexture(background_text[i]);
            background_sprite_middle[i].setPosition(0, 0);

            background_sprite_left[i].setTexture(background_text[i]);
            background_sprite_left[i].setPosition(-1920, 0);

            background_sprite_right[i].setTexture(background_text[i]);
            background_sprite_right[i].setPosition(1920, 0);
        }
    }
}

level::~level()
{
    delete [] background_text;
    delete [] background_sprite_middle;
    delete [] background_sprite_left;
    delete [] background_sprite_right;
}

void level::draw(sf::RenderWindow &game_window)
{
    for(int i = 0; i < 5; i++)
    {
        game_window.draw(background_sprite_middle[i]);
        game_window.draw(background_sprite_left[i]);
        game_window.draw(background_sprite_right[i]);
    }
}

void level::move_sprites_right()
{
    middle_sprite_x += 1920;
    for(int i = 0; i < 5; i++)
    {
        background_sprite_middle[i].move(1920, 0);

        background_sprite_left[i].move(1920, 0);

        background_sprite_right[i].move(1920, 0);
    }
}

void level::move_sprites_left()
{
    middle_sprite_x -= 1920;
    for(int i = 0; i < 5; i++)
    {
        background_sprite_middle[i].move(-1920, 0);

        background_sprite_left[i].move(-1920, 0);

        background_sprite_right[i].move(-1920, 0);
    }
}
