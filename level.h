#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>

class level
{
    private:
        sf::Texture *background_text;
        sf::Sprite *background_sprite_middle, *background_sprite_left, *background_sprite_right;

    public:
        float sprite_1_x, sprite_2_x, sprite_3_x, sprite_4_x;
        int middle_sprite_x;

        level(int number);
        ~level();
        void draw(sf::RenderWindow &);
        void parallax(float);
        void move_sprites(float);
};

#endif // LEVEL_H
