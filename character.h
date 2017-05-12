#ifndef CHARACTER_H
#define CHARACTER_h
#include <SFML/Graphics.hpp>


class character
{
    float x, y, running_speed, jump_speed, current_jump_speed, gravity;

    bool b_right, b_left, b_idle, was_running_left;
    int idle_animation_counter, run_right_animation_counter, run_left_animation_counter, jump_animation_counter;
    sf::Sprite *run_right_sprite, *run_left_sprite, *right_idle_sprite, *left_idle_sprite, *right_jump_sprite, *left_jump_sprite;
    sf::Texture *idle_text, *jump_text, *run_text;

    public:

    character();
    ~character();


    void run_right();
    void run_left();
    bool jump(sf::Time);
    void idle();
    sf::Sprite draw();


};





#endif // CHARACTER_H
