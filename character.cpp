#include "character.h"

character::character()
{
    x = 500;
    y = 725;
    running_speed = 14;
    jump_speed = 20;
    gravity = 200;

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

    run_right_sprite = new sf::Sprite[14];
    run_left_sprite = new sf::Sprite[14];
    jump_sprite = new sf::Sprite[12];
    right_idle_sprite = new sf::Sprite[12];
    left_idle_sprite = new sf::Sprite[12];

    for(int i = 0; i < 14; i++)
    {
        run_right_sprite[i].setTexture(run_text[i]);
        run_right_sprite[i].setPosition(x - 150, y);
        run_right_sprite[i].setScale(0.5, 0.5);
        run_left_sprite[i].setTexture(run_text[i]);
        run_left_sprite[i].setPosition(x + 225, y);
        run_left_sprite[i].setScale(-0.5, 0.5);

    }

    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].setTexture(idle_text[i]);
        right_idle_sprite[i].setPosition(x, y);
        right_idle_sprite[i].setOrigin(190, 0);
        right_idle_sprite[i].setScale(0.5, 0.5);

        left_idle_sprite[i].setTexture(idle_text[i]);
        left_idle_sprite[i].setPosition(x, y);
        left_idle_sprite[i].setOrigin(190, 0);
        left_idle_sprite[i].setScale(-0.5, 0.5);
    }


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
    for(int i = 0; i<14; i++)
    {
        run_right_sprite[i].move(running_speed, 0);
        run_left_sprite[i].move(running_speed, 0);
    }
    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].move(running_speed, 0);
        left_idle_sprite[i].move(running_speed, 0);
    }

    b_right = true;
    b_left = false;
    b_idle = false;
    was_running_left = false;
}



void character::run_left()
{
    x = x - running_speed;
    for(int i = 0; i<14; i++)
    {
        run_right_sprite[i].move(-running_speed, 0);
        run_left_sprite[i].move(-running_speed, 0);
    }
    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].move(-running_speed, 0);
        left_idle_sprite[i].move(-running_speed, 0);
    }
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

bool character::jump(sf::Time dt)
{
    b_jump = true;
    if((y - jump_speed + gravity * dt.asSeconds() * dt.asSeconds()) <= 725)
    {
    y = y - jump_speed + gravity * dt.asSeconds() * dt.asSeconds();
    for(int i = 0; i<14; i++)
    {
        run_right_sprite[i].move(0, -jump_speed + gravity * dt.asSeconds() * dt.asSeconds());
        run_left_sprite[i].move(0, -jump_speed + gravity * dt.asSeconds() * dt.asSeconds());
    }
    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].move(0, -jump_speed + gravity * dt.asSeconds() * dt.asSeconds());
        left_idle_sprite[i].move(0, -jump_speed + gravity * dt.asSeconds() * dt.asSeconds());
    }
    return 1;
    }
    else
    {
        y = 725;
        for(int i = 0; i<14; i++)
        {
            run_right_sprite[i].setPosition(x - 150, y);
            run_left_sprite[i].setPosition(x + 225, y);
        }
        for(int i = 0; i < 12; i++)
        {
            right_idle_sprite[i].setPosition(x, y);
            left_idle_sprite[i].setPosition(x, y);
        }

        return 0;
    }

}

sf::Sprite character::draw()
{
    if(b_idle)
    {

        if(idle_animation_counter < 33)
        {
            idle_animation_counter++;
        }
        else
        {
            idle_animation_counter = 0;
        }
        run_right_animation_counter = 0;
        run_left_animation_counter = 0;
        if(was_running_left)
            return left_idle_sprite[(idle_animation_counter-1)/3];
        else
            return right_idle_sprite[(idle_animation_counter-1)/3];
    }
    if(b_right)
    {

        if(run_right_animation_counter < 39)
        {
            run_right_animation_counter++;
        }
        else
        {
            run_right_animation_counter = 0;
        }
        idle_animation_counter = 0;
        run_left_animation_counter = 0;
        return run_right_sprite[(run_right_animation_counter-1)/3];
    }
    if(b_left)
    {
        if(run_left_animation_counter < 39)
        {
            run_left_animation_counter++;
        }
        else
        {
            run_left_animation_counter = 0;
        }
        idle_animation_counter = 0;
        run_right_animation_counter = 0;
        return run_left_sprite[(run_left_animation_counter-1)/3];
    }


}

