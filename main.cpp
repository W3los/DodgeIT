#include <SFML/Graphics.hpp>
#include <iostream>
#include "funkcje.cpp"


int main()
{
    if(!charactertxt.loadFromFile("Graphics/chodzenie.png"))
        std::cout<<"Error loading character image!"<<std::endl;
    const int charwidth = 145;
    sf::IntRect charrect(0,0,charwidth,245);
    sf::IntRect charrectupright(0,0,charwidth,232);
    sf::Sprite character(charactertxt,charrect);
    CharacterSize = charactertxt.getSize();



 
    sf::Clock clock;
    sf::Clock GameTimer;

    int timersecondsint = 0;
    int timerMiliint = 0;

    
    window.setFramerateLimit(120);
    if(!fireball.loadFromFile("Graphics/fireball.png"))
        std::cout<<"Error loading background image!"<<std::endl;
    for(int i=0;i<N;i++)
    {
        vx[i] = rand() % 10;
        vy[i] = rand() % 10;
        if (vx[i] == 0)
            vx[i]=1;
        if (vy[i] == 0)
            vy[i]=1;
        if (vx[i]%2 == 0)
            vx[i]*=-1;
        if (vy[i]%2 == 0)
            vy[i]*=-1;
        projectilesx[i] = sf::CircleShape(15);
        if(rand() % 2)
            projectilesx[i].setPosition(rand()%20-20,height*(rand()/(float)RAND_MAX));
        else
            projectilesx[i].setPosition(rand()%20+width,height*(rand()/(float)RAND_MAX));
        projectilesx[i].setTexture(&fireball);

        projectilesy[i] = sf::CircleShape(15);
        if(rand() % 2)
            projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20-20);
        else
            projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20+height);
        projectilesy[i].setTexture(&fireball);
    }
    ballSize = fireball.getSize();


    while (window.isOpen())
    {
        eventcheck(window);
        window.clear(sf::Color::Black);
        if(drawSelector == 0)
        {
            menu();
            WindowSize = window.getSize();
            float Scalecharx = (float) WindowSize.x / CharacterSize.x;
            float Scalechary = (float) WindowSize.y / CharacterSize.y; 
            float Scaleballx = (float) WindowSize.x / ballSize.x;
            float Scalebally = (float) WindowSize.y / ballSize.y; 
            for(int i=0;i<N;i++){
            projectilesx[i].setScale(Scaleballx/28, Scalebally/28);
            projectilesy[i].setScale(Scaleballx/28, Scalebally/28);
            }
            character.setScale(Scalecharx-0.5, Scalechary-0.2);
            character.setPosition(WindowSize.x/2-charwidth/2,WindowSize.y/2-245/2);
            character.setTextureRect(charrect);
            for(int i=0;i<N;i++){
                if(rand() % 2)
                    projectilesx[i].setPosition(rand()%20-20,height*(rand()/(float)RAND_MAX));
                else
                    projectilesx[i].setPosition(rand()%20+width,height*(rand()/(float)RAND_MAX));
                if(rand() % 2)
                    projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20-20);
                else
                    projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20+height);
            
            }
            lives = 3;
            GameTimer.restart();
        }
        if(drawSelector == 1)
        {    
            gameplay(character,charwidth);
            charactermodel(character,charwidth);
            livesimg();
            //gamemusic();
            if(keyup==1) movement(character,clock,charrectupright,charwidth,0,-height/100,0,246);
            if(keydown==1) movement(character,clock,charrect,charwidth,0,height/100,0,0);
            if(keyright==1) movement(character,clock,charrectupright,charwidth,width/150,0,0,480);
            if(keyleft==1) movement(character,clock,charrect,charwidth,-width/150,0,0,714);
            timersecondsint,timerMiliint = timer(GameTimer,timersecondsint,timerMiliint);
        }
        if(drawSelector == 2)
            pause();
        if(drawSelector == 3)
        {
            losescreen(timersecondsint,timerMiliint);
            GameTimer.restart();

        }
        if(drawSelector == 4)
            controls();
        if(drawSelector == 5)
            options();
        if(drawSelector == 6)
            workiprogress();
        if(drawSelector == 7)
            workiprogress();
        window.display();
        
    }

    return 0;
}