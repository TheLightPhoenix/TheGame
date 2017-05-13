#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>

class level
{
    public:
    int middle_sprite_x;
    private:
    sf::Texture *background_text;
    sf::Sprite *background_sprite_middle, *background_sprite_left, *background_sprite_right;

    public:
    level(int number);
    ~level();
    void draw(sf::RenderWindow &);
    void move_sprites_right();
    void move_sprites_left();

};

#endif // LEVEL_H
