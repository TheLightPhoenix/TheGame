#include "character.h"

character::character()
{
    run_animation_counter = 0;
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

    idle_counter = 0;
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

    run_sprite.setTexture(run_text[0]);
    run_sprite.setPosition(0, 500);

    idle_sprite.setTexture(idle_text[0]);
    idle_sprite.setPosition(200, 500);

}
character::~character()
{
    delete [] run_text;
    delete [] idle_text;
}

sf::Sprite character::run_right()
{
    if(run_animation_counter > 13)
    {
        run_animation_counter = 0;
        run_sprite.setTexture(run_text[run_animation_counter]);
        return run_sprite;
    }
    else
    {
        run_sprite.setTexture(run_text[run_animation_counter]);
        run_animation_counter++;
        run_sprite.move(10, 0);
        idle_sprite.move(10, 0);

        return run_sprite;
    }
}

sf::Sprite character::idle()
{
    if(idle_counter > 11)
    {
        idle_counter = 0;
        idle_sprite.setTexture(idle_text[idle_counter]);
        return idle_sprite;
    }
    else
    {
        idle_sprite.setTexture(idle_text[idle_counter]);
        idle_counter++;
        return idle_sprite;
    }
}

sf::Sprite character::run_left()
{
    if(run_animation_counter > 13)
    {
        run_animation_counter = 0;
        run_sprite.setTexture(run_text[run_animation_counter]);
        return run_sprite;


    }
    else
    {
        run_sprite.setTexture(run_text[run_animation_counter]);
        run_animation_counter++;
        run_sprite.move(-10, 0);
        idle_sprite.move(-10, 0);

        return run_sprite;
    }
}
