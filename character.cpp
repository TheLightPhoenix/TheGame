#include "character.h"

character::character()
{
    floor = 690;
    x = 500;
    y = floor;
    running_speed = 15;
    jump_speed = 50;
    current_jump_speed = 0;
    current_running_speed = 0;
    gravity = 120;
    acceleration = 5;

    jump_animation_counter = 0;
    idle_animation_counter = 0;
    run_right_animation_counter = 0;
    run_left_animation_counter = 0;

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
    jump_text[10].loadFromFile(".\\Animations\\Jump On Air\\Jump On Air_000.png");
    jump_text[11].loadFromFile(".\\Animations\\Jump Fall\\Jump Fall_000.png");

    run_right_sprite = new sf::Sprite[14];
    run_left_sprite = new sf::Sprite[14];
    right_jump_sprite = new sf::Sprite[12];
    left_jump_sprite = new sf::Sprite[12];
    right_idle_sprite = new sf::Sprite[12];
    left_idle_sprite = new sf::Sprite[12];

    for(int i = 0; i < 14; i++)
    {
        run_right_sprite[i].setTexture(run_text[i]);
        run_right_sprite[i].setPosition(x - 150, y);
        run_right_sprite[i].setScale(0.5, 0.5);
        run_left_sprite[i].setTexture(run_text[i]);
        run_left_sprite[i].setPosition(x + 150, y);
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

        right_jump_sprite[i].setTexture(jump_text[i]);
        right_jump_sprite[i].setPosition(x - 150, y);
        right_jump_sprite[i].setScale(0.5, 0.5);

        left_jump_sprite[i].setTexture(jump_text[i]);
        left_jump_sprite[i].setPosition(x + 100, y);
        left_jump_sprite[i].setScale(-0.5, 0.5);
    }
}
character::~character()
{
    delete [] run_text;
    delete [] idle_text;
    delete [] jump_text;
    delete [] run_right_sprite;
    delete [] run_left_sprite;
    delete [] right_idle_sprite;
    delete [] left_idle_sprite;
    delete [] right_jump_sprite;
    delete [] left_jump_sprite;
}

void character::run_right(sf::Time dt)
{
    if(current_running_speed + dt.asSeconds() * acceleration < running_speed)
        current_running_speed += dt.asSeconds() * acceleration;
    else
        current_running_speed = running_speed;

    x = x + current_running_speed;
    for(int i = 0; i < 14; i++)
    {
        run_right_sprite[i].move(current_running_speed, 0);
        run_left_sprite[i].move(current_running_speed, 0);
    }
    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].move(current_running_speed, 0);
        left_idle_sprite[i].move(current_running_speed, 0);
        right_jump_sprite[i].move(current_running_speed, 0);
        left_jump_sprite[i].move(current_running_speed, 0);
    }
    if(current_running_speed > 0)
        was_running_left = false;
}

void character::run_left(sf::Time dt)
{
    if(current_running_speed - dt.asSeconds() * acceleration > -running_speed)
        current_running_speed -= dt.asSeconds() * acceleration;
    else
        current_running_speed = -running_speed;

    x = x + current_running_speed;
    for(int i = 0; i < 14; i++)
    {
        run_right_sprite[i].move(current_running_speed, 0);
        run_left_sprite[i].move(current_running_speed, 0);
    }
    for(int i = 0; i < 12; i++)
    {
        right_idle_sprite[i].move(current_running_speed, 0);
        left_idle_sprite[i].move(current_running_speed, 0);
        right_jump_sprite[i].move(current_running_speed, 0);
        left_jump_sprite[i].move(current_running_speed, 0);
    }
    if(current_running_speed < 0)
        was_running_left = true;
}

bool character::hamuj(sf::Time dt)
{
    if(current_running_speed >= 0)
    {
        if(current_running_speed - dt.asSeconds() * acceleration > 0)
        {
            current_running_speed -= dt.asSeconds() * acceleration;
            x = x + current_running_speed;
            for(int i = 0; i < 14; i++)
            {
                run_right_sprite[i].move(current_running_speed, 0);
                run_left_sprite[i].move(current_running_speed, 0);
            }
            for(int i = 0; i < 12; i++)
            {
                right_idle_sprite[i].move(current_running_speed, 0);
                left_idle_sprite[i].move(current_running_speed, 0);
                right_jump_sprite[i].move(current_running_speed, 0);
                left_jump_sprite[i].move(current_running_speed, 0);
            }
        }
        else
        {
            current_running_speed = 0;
        }
    }
    else
    {
        if(current_running_speed + dt.asSeconds() * acceleration < 0)
        {
            current_running_speed += dt.asSeconds() * acceleration;
            x = x + current_running_speed;
            for(int i = 0; i < 14; i++)
            {
                run_right_sprite[i].move(current_running_speed, 0);
                run_left_sprite[i].move(current_running_speed, 0);
            }
            for(int i = 0; i < 12; i++)
            {
                right_idle_sprite[i].move(current_running_speed, 0);
                left_idle_sprite[i].move(current_running_speed, 0);
                right_jump_sprite[i].move(current_running_speed, 0);
                left_jump_sprite[i].move(current_running_speed, 0);
            }
        }
        else
        {
            current_running_speed = 0;
        }
    }
    if(current_running_speed)
        return 1;
    else
        return 0;
}

bool character::jump(sf::Time dt)
{
    current_jump_speed = - jump_speed + gravity * dt.asSeconds();
    if(y + current_jump_speed < floor)
    {
        y = y + current_jump_speed;
        for(int i = 0; i < 14; i++)
        {
            run_right_sprite[i].move(0, current_jump_speed);
            run_left_sprite[i].move(0, current_jump_speed);
        }
        for(int i = 0; i < 12; i++)
        {
            right_idle_sprite[i].move(0, current_jump_speed);
            left_idle_sprite[i].move(0, current_jump_speed);
            right_jump_sprite[i].move(0, current_jump_speed);
            left_jump_sprite[i].move(0, current_jump_speed);
        }
        return 1;
    }
    else
    {
        y = floor;
        current_jump_speed = 0;
        for(int i = 0; i < 14; i++)
        {
            run_right_sprite[i].setPosition(x - 150, y);
            run_left_sprite[i].setPosition(x + 150, y);
        }
        for(int i = 0; i < 12; i++)
        {
            right_idle_sprite[i].setPosition(x, y);
            left_idle_sprite[i].setPosition(x, y);
            right_jump_sprite[i].setPosition(x - 150, y);
            left_jump_sprite[i].setPosition(x + 100, y);
        }
        return 0;
    }
}

void character::draw(sf::RenderWindow &game_window)
{

    if(current_jump_speed < 0)
    {
        if(jump_animation_counter < 10)
        {
            jump_animation_counter++;
            if(was_running_left)
                game_window.draw(left_jump_sprite[jump_animation_counter - 1]);
            else
                game_window.draw(right_jump_sprite[jump_animation_counter - 1]);
        }
        if(jump_animation_counter == 10)
        {
            if(was_running_left)
                game_window.draw(left_jump_sprite[10]);
            else
                game_window.draw(right_jump_sprite[10]);
        }
    }
    else if(current_jump_speed > 0)
    {
        jump_animation_counter = 0;
        current_jump_speed = 0;
        if(was_running_left)
            game_window.draw(left_jump_sprite[11]);
        else
            game_window.draw(right_jump_sprite[11]);
    }
    else if(current_running_speed > 0 && !current_jump_speed)
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
        game_window.draw(run_right_sprite[(run_right_animation_counter-1)/3]);
    }
    else if(current_running_speed < 0 && !current_jump_speed)
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
        game_window.draw(run_left_sprite[(run_left_animation_counter-1)/3]);
    }
    else
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
            game_window.draw(left_idle_sprite[(idle_animation_counter-1)/3]);
        else
            game_window.draw(right_idle_sprite[(idle_animation_counter-1)/3]);
    }
}
