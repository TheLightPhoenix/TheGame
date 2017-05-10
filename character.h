#ifndef CHARACTER_H
#define CHARACTER_h
#include <SFML/Graphics.hpp>


class character
{
    float x, y, running_speed, jump_speed, gravity;

    bool b_right, b_left, b_idle, was_running_left, b_jump;
    int idle_animation_counter, run_right_animation_counter, run_left_animation_counter;
    sf::Sprite run_right_sprite, run_left_sprite, idle_sprite, jump_sprite;
    sf::Texture *idle_text, *jump_text, *run_text;

    public:

    character();
    ~character();


    void run_right();
    void run_left();
    void jump();
    void idle();
    sf::Sprite draw();


};





#endif // CHARACTER_H
