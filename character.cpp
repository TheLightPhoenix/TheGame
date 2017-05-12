#include "character.h"

character::character()
{
    x = 500;
    y = 505;
    running_speed = 30;
    jump_speed = 60;
    gravity = 2;

    idle_animation_counter = 0;
    run_right_animation_counter = 0;
    run_left_animation_counter = 0;

    b_jump = 0;
    b_right = 0;
    b_left = 0;
    b_idle = 1;
    was_running_left = 0;

    run_text = new sf::Texture[14];
    run_text[0].loadFromFile(".\\Animations\\Run\\Run_000.png");
    run_text[1].loadFromFile(".\\Animations\\Run\\Run_001.png");
    run_text[2].loadFromFile(".\\Animations\\Run\\Run_002.png");
    run_text[3].loadFromFile(".\\Animations\\Run\\Run_003.png");
    run_text[4].loadFromFile(".\\Animations\\Run\\Run_004.png");
    run_text[5].loadFromFile(".\\Animations\\Run\\Run_005.png");
    run_text[6].loadFromFile(".\\Animations\\Run\\Run_006.png");
    run_text[7].loadFromFile(".\\Animations\\Run\\Run_007.png");
    run_text[8].loadFromFile(".\\Animations\\Run\\Run_008.png");
    run_text[9].loadFromFile(".\\Animations\\Run\\Run_009.png");
    run_text[10].loadFromFile(".\\Animations\\Run\\Run_010.png");
    run_text[11].loadFromFile(".\\Animations\\Run\\Run_011.png");
    run_text[12].loadFromFile(".\\Animations\\Run\\Run_012.png");
    run_text[13].loadFromFile(".\\Animations\\Run\\Run_013.png");

    idle_text = new sf::Texture[12];
    idle_text[0].loadFromFile(".\\Animations\\idle\\idle_000.png");
    idle_text[1].loadFromFile(".\\Animations\\idle\\idle_001.png");
    idle_text[2].loadFromFile(".\\Animations\\idle\\idle_002.png");
    idle_text[3].loadFromFile(".\\Animations\\idle\\idle_003.png");
    idle_text[4].loadFromFile(".\\Animations\\idle\\idle_004.png");
    idle_text[5].loadFromFile(".\\Animations\\idle\\idle_005.png");
    idle_text[6].loadFromFile(".\\Animations\\idle\\idle_006.png");
    idle_text[7].loadFromFile(".\\Animations\\idle\\idle_007.png");
    idle_text[8].loadFromFile(".\\Animations\\idle\\idle_008.png");
    idle_text[9].loadFromFile(".\\Animations\\idle\\idle_009.png");
    idle_text[10].loadFromFile(".\\Animations\\idle\\idle_010.png");
    idle_text[11].loadFromFile(".\\Animations\\idle\\idle_011.png");

    jump_text = new sf::Texture[12];
    jump_text[0].loadFromFile(".\\Animations\\Jump Start\\Jump Start_000.png");
    jump_text[1].loadFromFile(".\\Animations\\Jump Start\\Jump Start_001.png");
    jump_text[2].loadFromFile(".\\Animations\\Jump Start\\Jump Start_002.png");
    jump_text[3].loadFromFile(".\\Animations\\Jump Start\\Jump Start_003.png");
    jump_text[4].loadFromFile(".\\Animations\\Jump Start\\Jump Start_004.png");
    jump_text[5].loadFromFile(".\\Animations\\Jump Start\\Jump Start_005.png");
    jump_text[6].loadFromFile(".\\Animations\\Jump Start\\Jump Start_006.png");
    jump_text[7].loadFromFile(".\\Animations\\Jump Start\\Jump Start_007.png");
    jump_text[8].loadFromFile(".\\Animations\\Jump Start\\Jump Start_008.png");
    jump_text[9].loadFromFile(".\\Animations\\Jump Start\\Jump Start_009.png");
    jump_text[10].loadFromFile(".\\Animations\\Jump On Air\\Jump On Air_010.png");
    jump_text[11].loadFromFile(".\\Animations\\Jump Fall\\Jump Fall_011.png");

    idle_sprite.setPosition(x, y);
    idle_sprite.setOrigin(190, 0);
    run_right_sprite.setPosition(x - 300, y);
    run_left_sprite.setPosition(x + 450, y);
    jump_sprite.setPosition(x, y);

}
character::~character()
{
    delete [] run_text;
    delete [] idle_text;
    delete [] jump_text;
}

void character::run_right()
{
    x = x + running_speed;
    run_right_sprite.move(running_speed, 0);
    run_left_sprite.move(running_speed, 0);
    idle_sprite.move(running_speed, 0);
    jump_sprite.move(running_speed, 0);
    b_right = true;
    b_left = false;
    b_idle = false;
    was_running_left = false;
}



void character::run_left()
{
    x = x - running_speed;
    run_right_sprite.move(-running_speed, 0);
    run_left_sprite.move(-running_speed, 0);
    idle_sprite.move(-running_speed, 0);
    jump_sprite.move(-running_speed, 0);
    b_right = false;
    b_left = true;
    b_idle = false;
    was_running_left = true;
}

void character::idle()
{
    b_right = false;
    b_left = false;
    b_idle = true;
}

void character::jump(sf::Time dt, bool &space)
{
    b_jump = true;
    if((y - jump_speed + 300 * dt.asSeconds() * dt.asSeconds()) <= 505)
    {
    y = y - jump_speed + 300 * dt.asSeconds() * dt.asSeconds();
    jump_sprite.move(0, -jump_speed + 300 * dt.asSeconds() * dt.asSeconds());
    run_right_sprite.move(0, -jump_speed + 300 * dt.asSeconds() * dt.asSeconds());
    run_left_sprite.move(0, -jump_speed + 300 * dt.asSeconds() * dt.asSeconds());
    idle_sprite.move(0, -jump_speed + 300 * dt.asSeconds() * dt.asSeconds());
    }
    else
    {
        y = 505;
        jump_sprite.setPosition(x, y);
        run_right_sprite.setPosition(x - 300, y);
        run_left_sprite.setPosition(x + 450, y);
        idle_sprite.setPosition(x, y);
        space = 0;
    }
    return;
}

sf::Sprite character::draw()
{
    if(b_idle)
    {
        idle_sprite.setTexture(idle_text[idle_animation_counter]);
        if(was_running_left)
        {
            idle_sprite.setScale(-1, 1);
        }
        else
        {
            idle_sprite.setScale(1, 1);
        }

        if(idle_animation_counter < 11)
        {
            idle_animation_counter++;
        }
        else
        {
            idle_animation_counter = 0;
        }
        run_right_animation_counter = 0;
        run_left_animation_counter = 0;
        return idle_sprite;
    }
    if(b_right)
    {
        run_right_sprite.setTexture(run_text[run_right_animation_counter]);

        if(run_right_animation_counter < 13)
        {
            run_right_animation_counter++;
        }
        else
        {
            run_right_animation_counter = 0;
        }
        idle_animation_counter = 0;
        run_left_animation_counter = 0;
        return run_right_sprite;
    }
    if(b_left)
    {
        run_left_sprite.setTexture(run_text[run_left_animation_counter]);
        run_left_sprite.setScale(-1, 1);
        if(run_left_animation_counter < 13)
        {
            run_left_animation_counter++;
        }
        else
        {
            run_left_animation_counter = 0;
        }
        idle_animation_counter = 0;
        run_right_animation_counter = 0;
        return run_left_sprite;
    }


}

