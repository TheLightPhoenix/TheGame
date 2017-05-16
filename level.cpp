#include "level.h"

level::level(int number)
{
    sprite_1_x = 0;
    sprite_2_x = 0;
    sprite_3_x = 0;
    sprite_4_x = 0;
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

        background_sprite_middle[0].setScale(1.1, 1);
        background_sprite_middle[0].setPosition(-96, 0);
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
    game_window.draw(background_sprite_middle[0]);
    for(int i = 1; i < 5; i++)
    {
        game_window.draw(background_sprite_middle[i]);
        game_window.draw(background_sprite_left[i]);
        game_window.draw(background_sprite_right[i]);
    }
}

void level::move_sprites(float player_x)
{
    if(player_x - sprite_1_x >= 1920)
    {
        background_sprite_middle[1].move(1920, 0);
        background_sprite_right[1].move(1920, 0);
        background_sprite_left[1].move(1920, 0);
        sprite_1_x += 1920;
    }
    if(player_x - sprite_2_x >= 1920)
    {
        background_sprite_middle[2].move(1920, 0);
        background_sprite_right[2].move(1920, 0);
        background_sprite_left[2].move(1920, 0);
        sprite_2_x += 1920;
    }
    if(player_x - sprite_3_x >= 1920)
    {
        background_sprite_middle[3].move(1920, 0);
        background_sprite_right[3].move(1920, 0);
        background_sprite_left[3].move(1920, 0);
        sprite_3_x += 1920;
    }
    if(player_x - sprite_4_x >= 1920)
    {
        background_sprite_middle[4].move(1920, 0);
        background_sprite_right[4].move(1920, 0);
        background_sprite_left[4].move(1920, 0);
        sprite_4_x += 1920;
    }
    if(player_x - sprite_1_x <= 0)
    {
        background_sprite_middle[1].move(-1920, 0);
        background_sprite_right[1].move(-1920, 0);
        background_sprite_left[1].move(-1920, 0);
        sprite_1_x -= 1920;
    }
    if(player_x - sprite_2_x <= 0)
    {
        background_sprite_middle[2].move(-1920, 0);
        background_sprite_right[2].move(-1920, 0);
        background_sprite_left[2].move(-1920, 0);
        sprite_2_x -= 1920;
    }
    if(player_x - sprite_3_x <= 0)
    {
        background_sprite_middle[3].move(-1920, 0);
        background_sprite_right[3].move(-1920, 0);
        background_sprite_left[3].move(-1920, 0);
        sprite_3_x -= 1920;
    }
    if(player_x - sprite_4_x <= 0)
    {
        background_sprite_middle[4].move(-1920, 0);
        background_sprite_right[4].move(-1920, 0);
        background_sprite_left[4].move(-1920, 0);
        sprite_4_x -= 1920;
    }
}

void level::parallax(float speed)
{
    sprite_1_x += speed * 15 / 16;
    sprite_2_x += speed * 7 / 8;
    sprite_3_x += speed / 2;
    background_sprite_middle[0].move(speed, 0);
    background_sprite_middle[1].move(speed * 15 / 16, 0);
    background_sprite_right[1].move(speed * 15 / 16, 0);
    background_sprite_left[1].move(speed * 15 / 16, 0);
    background_sprite_middle[2].move(speed * 7 / 8, 0);
    background_sprite_right[2].move(speed * 7 / 8, 0);
    background_sprite_left[2].move(speed * 7 / 8, 0);
    background_sprite_middle[3].move(speed / 2, 0);
    background_sprite_right[3].move(speed / 2, 0);
    background_sprite_left[3].move(speed / 2, 0);
}
