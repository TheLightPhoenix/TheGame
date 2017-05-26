#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>


class character
{
    private:
        bool is_jumping, was_running_left;
        int idle_animation_counter, run_right_animation_counter, run_left_animation_counter, jump_animation_counter;
        sf::Sprite *run_right_sprite, *run_left_sprite, *right_idle_sprite, *left_idle_sprite, *right_jump_sprite, *left_jump_sprite;
        sf::Texture *idle_text, *jump_text, *run_text;

    public:
        float x, y, running_speed, current_running_speed, acceleration, jump_speed, current_jump_speed, gravity, floor;

        character();
        ~character();
        void run_right(sf::Time);
        void run_left(sf::Time);
        bool jump(sf::Time);
        bool hamuj(sf::Time);
        void draw(sf::RenderWindow &);
};





#endif // CHARACTER_H
