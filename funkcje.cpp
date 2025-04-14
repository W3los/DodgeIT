#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>

int widthf()
{
std::fstream myfile;
myfile.open("Data/width.txt");
int width;
myfile>>width;
myfile.close();

return width;
}
int heightf()
{
std::fstream myfile2;
myfile2.open("Data/height.txt");
int height;
myfile2>>height;
myfile2.close();

return height;
}


int width = widthf();
int height = heightf();
int choice = 0;
int keyup = 0, keydown=0, keyleft=0, keyright=0;
int drawSelector = 0;
int pauseSelector = 0;
int controlsSelector = 0;
int optionsSelector = 0;
int lives = 3;

int vx[10];
int vy[10];
const int N = 10;
sf::RenderWindow window(sf::VideoMode(width, height), "DodgeIT",sf::Style::Titlebar|sf::Style::Close);
sf::Texture backgroundimg;
sf::Sprite background;
sf::Vector2u TextureSize;
sf::Vector2u WindowSize; 

sf::Texture charactertxt;
sf::Vector2u CharacterSize; 
sf::Vector2u ballSize;

sf::Texture livestxt;
sf::Sprite livesShow;
sf::Vector2u livesSize;

sf::CircleShape projectilesx[N];
sf::CircleShape projectilesy[N];
sf::Texture fireball;

sf::Text timertext;
std::string timerseconds;
std::string timerMili;
std::string timerfull;

// MENU SCREEN

void menu(){
// BACKGROUND IMAGE

if(!backgroundimg.loadFromFile("Graphics/Menubackground.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY);


sf::Font font;
font.loadFromFile("cartoon.ttf");


// PLAY
sf::RectangleShape playrect(sf::Vector2f(width/5.45,height/4.9));
playrect.setOrigin(playrect.getLocalBounds().width/2,playrect.getLocalBounds().height/2);
playrect.setPosition(width/5.9,height/1.28);

sf::Text play;

play.setFont(font); 
play.setString("Play");
play.setCharacterSize((height+width)/30); 
play.setStyle(sf::Text::Bold);
play.setOrigin(play.getLocalBounds().width/2,play.getLocalBounds().height/2);
play.setPosition(width/5.9,height/1.33);

// SHOP
sf::RectangleShape shoprect(sf::Vector2f(width/8,height/7.2));
shoprect.setOrigin(shoprect.getLocalBounds().width/2,shoprect.getLocalBounds().height/2);
shoprect.setPosition(width/2.82,height/1.76);

sf::Text shop;

shop.setFont(font); 
shop.setString("Shop");
shop.setCharacterSize((height+width)/40); 
shop.setStyle(sf::Text::Bold);
shop.setOrigin(shop.getLocalBounds().width/2,shop.getLocalBounds().height/2);
shop.setPosition(width/2.82,height/1.8);

// CONTROLS
sf::RectangleShape controlsrect(sf::Vector2f(width/11.7,height/11));
controlsrect.setOrigin(controlsrect.getLocalBounds().width/2,controlsrect.getLocalBounds().height/2);
controlsrect.setPosition(width/1.974,height/1.87);

sf::Text controls;

controls.setFont(font); 
controls.setString("Controls");
controls.setCharacterSize((height+width)/90); 
controls.setStyle(sf::Text::Bold);
controls.setOrigin(controls.getLocalBounds().width/2,controls.getLocalBounds().height/2);
controls.setPosition(width/1.974,height/1.89);

// CREDITS
sf::RectangleShape creditsrect(sf::Vector2f(width/10,height/8.9));
creditsrect.setOrigin(creditsrect.getLocalBounds().width/2,creditsrect.getLocalBounds().height/2);
creditsrect.setPosition(width/1.458,height/1.77);

sf::Text credits;

credits.setFont(font); 
credits.setString("Credits");
credits.setCharacterSize((height+width)/65); 
credits.setStyle(sf::Text::Bold);
credits.setOrigin(credits.getLocalBounds().width/2,credits.getLocalBounds().height/2);
credits.setPosition(width/1.461,height/1.8);

// OPTIONS
sf::RectangleShape optionsrect(sf::Vector2f(width/8.8,height/9.2));
optionsrect.setOrigin(optionsrect.getLocalBounds().width/2,optionsrect.getLocalBounds().height/2);
optionsrect.setPosition(width/1.865,height/1.385);

sf::Text options;

options.setFont(font); 
options.setString("Options");
options.setCharacterSize((height+width)/65); 
options.setStyle(sf::Text::Bold);
options.setOrigin(options.getLocalBounds().width/2,options.getLocalBounds().height/2);
options.setPosition(width/1.87,height/1.4);


// EXIT
sf::RectangleShape exitrect(sf::Vector2f(width/6.5,height/7.2));
exitrect.setOrigin(exitrect.getLocalBounds().width/2,exitrect.getLocalBounds().height/2);
exitrect.setPosition(width/1.83,height/1.11);

sf::Text exit;

exit.setFont(font); 
exit.setString("Exit");
exit.setCharacterSize((height+width)/30); 
exit.setStyle(sf::Text::Bold);
exit.setOrigin(exit.getLocalBounds().width/2,exit.getLocalBounds().height/2);
exit.setPosition(width/1.83,height/1.14);

// Moving along buttons

if(choice == 1){
    play.setFillColor(sf::Color::Red);
    play.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{play.setFillColor(sf::Color::Black);}

if(choice == 2){
    shop.setFillColor(sf::Color::Red);
    shop.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{shop.setFillColor(sf::Color::Black);}

if(choice == 3){
    controls.setFillColor(sf::Color::Red);
    controls.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{controls.setFillColor(sf::Color::Black);}

if(choice == 4){
    credits.setFillColor(sf::Color::Red);
    credits.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{credits.setFillColor(sf::Color::Black);}

if(choice == 5){
    options.setFillColor(sf::Color::Red);  
    options.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{options.setFillColor(sf::Color::Black);}

if(choice == 6){
    exit.setFillColor(sf::Color::Red);
    exit.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{exit.setFillColor(sf::Color::Black);}

if (playrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 1;
}
else if (shoprect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 2;
}
else if (controlsrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 3;
}
else if (creditsrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 4;
}
else if (optionsrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 5;
}
else if (exitrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    choice = 6;
}else {choice = 0;}

// DRAWING TO THE GAME

window.draw(background);
window.draw(play);
window.draw(shop);
window.draw(controls);
window.draw(credits);
window.draw(options);
window.draw(exit);


}

// CHANGING RESOLUTIONS
void changeresolution(int optionchoice)
{
    if(optionchoice == 1)
    {
        width = 800;
        std::ofstream fileszer;
        fileszer.open(("Data/width.txt"));
        fileszer<<width;
        fileszer.close();

        height = 600;
        std::ofstream filewys;
        filewys.open(("Data/height.txt"));
        filewys<<height;
        filewys.close();
        window.create(sf::VideoMode(width, height), "DodgeIT",sf::Style::Titlebar|sf::Style::Close);
    }

    if(optionchoice == 2)
    {
        width = 1280;
        std::ofstream fileszer;
        fileszer.open(("Data/width.txt"));
        fileszer<<width;
        fileszer.close();

        height = 720;
        std::ofstream filewys;
        filewys.open(("Data/height.txt"));
        filewys<<height;
        filewys.close();
        window.create(sf::VideoMode(width, height), "DodgeIT",sf::Style::Titlebar|sf::Style::Close);
    }

    if(optionchoice == 3)
    {
        width = 1440;
        std::ofstream fileszer;
        fileszer.open(("Data/width.txt"));
        fileszer<<width;
        fileszer.close();

        height = 1080;
        std::ofstream filewys;
        filewys.open(("Data/height.txt"));
        filewys<<height;
        filewys.close();
        window.create(sf::VideoMode(width, height), "DodgeIT",sf::Style::Titlebar|sf::Style::Close);
    }

    if(optionchoice == 4)
    {
        width = 1920;
        std::ofstream fileszer;
        fileszer.open(("Data/width.txt"));
        fileszer<<width;
        fileszer.close();

        height = 1080;
        std::ofstream filewys;
        filewys.open(("Data/height.txt"));
        filewys<<height;
        filewys.close();
        window.create(sf::VideoMode(width, height), "DodgeIT",sf::Style::Titlebar|sf::Style::Close);
    }

}
// CHECKING FOR EVENTS
void eventcheck( sf::RenderWindow &window){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) keyup=1; else keyup=0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) keydown=1; else keydown=0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) keyright=1; else keyright=0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) keyleft=1; else keyleft=0;



        if(choice == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){choice = 0; drawSelector=1;}
        if(drawSelector == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) drawSelector=2;
        if(pauseSelector == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){pauseSelector=0; drawSelector=1;}
        if(pauseSelector == 2 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {pauseSelector=0; drawSelector=0;}
        if(choice == 2 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){choice = 0; drawSelector=6;}
        if(choice == 3 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){choice = 0; drawSelector=4;}
        if(choice == 4 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){choice = 0; drawSelector=7;}
        if(choice == 5 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){choice = 0; drawSelector=5;}
        if(optionsSelector == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {optionsSelector=0; changeresolution(1);}
        if(optionsSelector == 2 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {optionsSelector=0; changeresolution(2);}
        if(optionsSelector == 3 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {optionsSelector=0; changeresolution(3);}
        if(optionsSelector == 4 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {optionsSelector=0; changeresolution(4);}
        if(optionsSelector == 5 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {optionsSelector=0; drawSelector=0;}
        if(choice == 6 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) window.close();

        if(event.type == sf::Event::Resized)
            window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
 
    }
}


// MOVEMENT

// sx - position x of graphic
// sy - position y of graphic

void movement(sf::Sprite &character,sf::Clock &clock,sf::IntRect rec, int charwidth,int lr,int ud,int sx, int sy)
{
    static int frame=0;
    character.move(lr,ud);
    if(clock.getElapsedTime().asSeconds() > 0.1)
    {
        frame++;
        if(frame > 3) frame=0;

        rec.left = sx;
        rec.top = sy;

        rec.left += charwidth * frame;
     
        character.setTextureRect(rec);
        clock.restart();
    }

}



// GAMEPLAY

void gameplay(sf::Sprite &character,int charwidth)
{
if(!backgroundimg.loadFromFile("Graphics/gameplay.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY);  

for (int i = 0; i < N; i++){

    projectilesx[i].move(vx[i],vy[i]);
    projectilesy[i].move(vx[i],vy[i]);
    if(rand()%2){
        if(projectilesx[i].getPosition().x < -50 || projectilesx[i].getPosition().x > width+50)
            projectilesx[i].setPosition(rand()%20-20,height*(rand()/(float)RAND_MAX));
        if(projectilesy[i].getPosition().y < -50 || projectilesy[i].getPosition().y > height+50)
            projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20-20);
    }
    else{
        if(projectilesx[i].getPosition().x < -40 || projectilesx[i].getPosition().x > width+40)
            projectilesx[i].setPosition(rand()%20+width,height*(rand()/(float)RAND_MAX));
        if(projectilesy[i].getPosition().y < -40 || projectilesy[i].getPosition().y > height+40)
            projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20+height);
    if(projectilesx[i].getGlobalBounds().intersects(character.getGlobalBounds()))
    {
        projectilesx[i].setPosition(rand()%20+width,height*(rand()/(float)RAND_MAX));
        lives--;
    }
    if(projectilesy[i].getGlobalBounds().intersects(character.getGlobalBounds()))
    {
        projectilesy[i].setPosition(width*(rand()/(float)RAND_MAX),rand()%20+height); 
       lives--;
    }
    }


}
if(lives == 0)
{
    drawSelector = 3;
}

window.draw(background);
for (int i = 0; i < N; i++){
    window.draw(projectilesx[i]);
    window.draw(projectilesy[i]);
}
}
void livesimg()
{
if(lives == 3){
    if(!livestxt.loadFromFile("Graphics/3lives.png"))
        std::cout<<"Error loading background image!"<<std::endl;
    livesSize = livestxt.getSize(); //Get size of texture.
    WindowSize = window.getSize();             

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    livesShow.setTexture(livestxt);
    livesShow.setScale(ScaleX-0.26, ScaleY-0.4);

    livesShow.setPosition(10,5);

    window.draw(livesShow);
    }

if(lives == 2){
    if(!livestxt.loadFromFile("Graphics/2lives.png"))
        std::cout<<"Error loading background image!"<<std::endl;
    livesSize = livestxt.getSize(); //Get size of texture.
    WindowSize = window.getSize();             

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    livesShow.setTexture(livestxt);
    livesShow.setScale(ScaleX-0.26, ScaleY-0.4);

    livesShow.setPosition(10,5);

    window.draw(livesShow);
    }

if(lives == 1){
    if(!livestxt.loadFromFile("Graphics/1lives.png"))
        std::cout<<"Error loading background image!"<<std::endl;
    livesSize = livestxt.getSize(); //Get size of texture.
    WindowSize = window.getSize();             

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    livesShow.setTexture(livestxt);
    livesShow.setScale(ScaleX-0.26, ScaleY-0.4);

    livesShow.setPosition(10,5);

    window.draw(livesShow);
    }
    
    
}

// TIMER
int timer(sf::Clock &GameTimer,int &timersecondsint,int &timerMiliint)
{

    sf::Time elapsedTime = GameTimer.getElapsedTime();


    timersecondsint = elapsedTime.asMilliseconds()/1000;
    timerMiliint = elapsedTime.asMilliseconds()%1000;


    return timersecondsint,timerMiliint;
}

//CHARACTER
void charactermodel(sf::Sprite &character,int charwidth)
{
    if(character.getPosition().x<0)
        character.setPosition(0,character.getPosition().y);
    else if(character.getPosition().x>width-charwidth/2)
        character.setPosition(width-charwidth/2,character.getPosition().y);
    if(character.getPosition().y<0)
        character.setPosition(character.getPosition().x,0);
    else if(character.getPosition().y>height-245/2)
        character.setPosition(character.getPosition().x,height-245/2);

        

    window.draw(character);
}


void pause()
{

if(!backgroundimg.loadFromFile("Graphics/pause.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY); 

sf::Font font;
font.loadFromFile("cartoon.ttf");

// RESUME
sf::RectangleShape resumerect(sf::Vector2f(width/5.347,height/12));
resumerect.setOrigin(resumerect.getLocalBounds().width/2,resumerect.getLocalBounds().height/2);
resumerect.setPosition(width/2,height/1.9);


sf::Text resume;

resume.setFont(font); 
resume.setString("Resume");
resume.setFillColor(sf::Color::White);
resume.setCharacterSize((height+width)/30); 
resume.setStyle(sf::Text::Bold);
resume.setOrigin(resume.getLocalBounds().width/2,resume.getLocalBounds().height/2);
resume.setPosition(width/2,height/2);

// MAIN MENU
sf::RectangleShape mainmenurect(sf::Vector2f(width/3.71,height/12));
mainmenurect.setOrigin(mainmenurect.getLocalBounds().width/2,mainmenurect.getLocalBounds().height/2);
mainmenurect.setPosition(width/2,height/1.45);


sf::Text mainmenu;

mainmenu.setFont(font); 
mainmenu.setString("Main menu");
mainmenu.setFillColor(sf::Color::White);
mainmenu.setCharacterSize((height+width)/30); 
mainmenu.setStyle(sf::Text::Bold);
mainmenu.setOrigin(mainmenu.getLocalBounds().width/2,mainmenu.getLocalBounds().height/2);
mainmenu.setPosition(width/2,height/1.5);


if(pauseSelector == 1){
    resume.setFillColor(sf::Color::Red);
    resume.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{resume.setFillColor(sf::Color::White);}

if(pauseSelector == 2){
    mainmenu.setFillColor(sf::Color::Red);
    mainmenu.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{mainmenu.setFillColor(sf::Color::White);}

if (resumerect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    pauseSelector = 1;
}
else if (mainmenurect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    pauseSelector = 2;
}
else {pauseSelector = 0;}


window.draw(background);
window.draw(resume);
window.draw(mainmenu);



}
// YOU LOST SCREEN
void losescreen(int &timersecondsint,int &timerMiliint)
{
if(!backgroundimg.loadFromFile("Graphics/losescreen.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY); 


sf::Font font;
font.loadFromFile("cartoon.ttf");

// MAIN MENU BUTTON
sf::RectangleShape mainmenurect(sf::Vector2f(width/3.71,height/12));
mainmenurect.setOrigin(mainmenurect.getLocalBounds().width/2,mainmenurect.getLocalBounds().height/2);
mainmenurect.setPosition(width/1.22,height/1.16);


sf::Text mainmenu;

mainmenu.setFont(font); 
mainmenu.setString("Main menu");
mainmenu.setFillColor(sf::Color::White);
mainmenu.setCharacterSize((height+width)/30); 
mainmenu.setStyle(sf::Text::Bold);
mainmenu.setOrigin(mainmenu.getLocalBounds().width/2,mainmenu.getLocalBounds().height/2);
mainmenu.setPosition(width/1.22,height/1.18);


if(pauseSelector == 2){
    mainmenu.setFillColor(sf::Color::Red);
    mainmenu.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{mainmenu.setFillColor(sf::Color::White);}

if (mainmenurect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    pauseSelector = 2;
}
else {pauseSelector = 0;}

sf::Text survived;

survived.setFont(font); 
survived.setString("You survived:");
survived.setFillColor(sf::Color::White);
survived.setCharacterSize((height+width)/30); 
survived.setStyle(sf::Text::Bold);
survived.setOrigin(survived.getLocalBounds().width/2,survived.getLocalBounds().height/2);
survived.setPosition(width/2,height/3.5);

std::string timerseconds = std::to_string(timersecondsint);
std::string timerMili = std::to_string(timerMiliint);
std::string timerfulltoint = timerseconds + "." + timerMili;
std::string timerfull = timerseconds + "." + timerMili + " seconds";
timertext.setFont(font); 
timertext.setString(timerfull);
timertext.setFillColor(sf::Color::Red);
timertext.setCharacterSize((height+width)/30); 
timertext.setStyle(sf::Text::Bold);
timertext.setOrigin(timertext.getLocalBounds().width/2,timertext.getLocalBounds().height/2);
timertext.setPosition(width/2,height/2.5);

float score = timersecondsint+(float)timerMiliint/1000;

std::fstream myfile3;
myfile3.open("Data/highscore.txt");
float highscore;
myfile3>>highscore;
myfile3.close();

if(highscore >= score){}
else
{
    std::ofstream file;
    file.open(("Data/highscore.txt"));
    file<<score;
    file.close();
    highscore = score;

}

sf::Text highscoretext;

highscoretext.setFont(font); 
highscoretext.setString("Highscore:");
highscoretext.setFillColor(sf::Color::White);
highscoretext.setCharacterSize((height+width)/30); 
highscoretext.setStyle(sf::Text::Bold);
highscoretext.setOrigin(highscoretext.getLocalBounds().width/2,highscoretext.getLocalBounds().height/2);
highscoretext.setPosition(width/2,height/1.7);

sf::Text highscorefloat;
std::string highscorestr = std::to_string(highscore);
highscorestr.pop_back();
highscorestr.pop_back();
highscorestr.pop_back();
highscorefloat.setFont(font); 
highscorefloat.setString(highscorestr);
highscorefloat.setFillColor(sf::Color::Yellow);
highscorefloat.setCharacterSize((height+width)/30); 
highscorefloat.setStyle(sf::Text::Bold);
highscorefloat.setOrigin(highscorefloat.getLocalBounds().width/2,highscorefloat.getLocalBounds().height/2);
highscorefloat.setPosition(width/2,height/1.45);

window.draw(background);
window.draw(mainmenu);
window.draw(timertext);
window.draw(survived);
window.draw(highscoretext);
window.draw(highscorefloat);
}

// CONTROLS

void controls()
{
if(!backgroundimg.loadFromFile("Graphics/controls.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY); 

sf::Font font;
font.loadFromFile("cartoon.ttf");

// MAIN MENU BUTTON
sf::RectangleShape mainmenurect(sf::Vector2f(width/3.71,height/12));
mainmenurect.setOrigin(mainmenurect.getLocalBounds().width/2,mainmenurect.getLocalBounds().height/2);
mainmenurect.setPosition(width/1.22,height/1.16);


sf::Text mainmenu;

mainmenu.setFont(font); 
mainmenu.setString("Main menu");
mainmenu.setFillColor(sf::Color::White);
mainmenu.setCharacterSize((height+width)/30); 
mainmenu.setStyle(sf::Text::Bold);
mainmenu.setOrigin(mainmenu.getLocalBounds().width/2,mainmenu.getLocalBounds().height/2);
mainmenu.setPosition(width/1.22,height/1.18);


if(pauseSelector == 2){
    mainmenu.setFillColor(sf::Color::Red);
    mainmenu.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{mainmenu.setFillColor(sf::Color::White);}

if (mainmenurect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    pauseSelector = 2;
}
else {pauseSelector = 0;}


window.draw(background);
window.draw(mainmenu);
}

// OPTIONS

void options()
{
if(!backgroundimg.loadFromFile("Graphics/options.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY); 


sf::Font font;
font.loadFromFile("cartoon.ttf");

// FIRST
sf::RectangleShape firstrect(sf::Vector2f(width/4.38,height/12));
firstrect.setOrigin(firstrect.getLocalBounds().width/2,firstrect.getLocalBounds().height/2);
firstrect.setPosition(width/3.2,height/1.9);

sf::Text first;

first.setFont(font); 
first.setString("800x600");
first.setFillColor(sf::Color::White);
first.setCharacterSize((height+width)/30); 
first.setStyle(sf::Text::Bold);
first.setOrigin(first.getLocalBounds().width/2,first.getLocalBounds().height/2);
first.setPosition(width/3.2,height/2);

// SECOND
sf::RectangleShape secondrect(sf::Vector2f(width/4.13,height/12));
secondrect.setOrigin(secondrect.getLocalBounds().width/2,secondrect.getLocalBounds().height/2);
secondrect.setPosition(width/1.5,height/1.9);

sf::Text second;

second.setFont(font); 
second.setString("1280x720");
second.setFillColor(sf::Color::White);
second.setCharacterSize((height+width)/30); 
second.setStyle(sf::Text::Bold);
second.setOrigin(second.getLocalBounds().width/2,second.getLocalBounds().height/2);
second.setPosition(width/1.5,height/2);

// THIRD
sf::RectangleShape thirdrect(sf::Vector2f(width/3.62,height/12));
thirdrect.setOrigin(thirdrect.getLocalBounds().width/2,thirdrect.getLocalBounds().height/2);
thirdrect.setPosition(width/3.2,height/1.48);


sf::Text third;

third.setFont(font); 
third.setString("1440x1080");
third.setFillColor(sf::Color::White);
third.setCharacterSize((height+width)/30); 
third.setStyle(sf::Text::Bold);
third.setOrigin(third.getLocalBounds().width/2,third.getLocalBounds().height/2);
third.setPosition(width/3.2,height/1.5);

// FOURTH

sf::RectangleShape fourthrect(sf::Vector2f(width/3.62,height/12));
fourthrect.setOrigin(fourthrect.getLocalBounds().width/2,fourthrect.getLocalBounds().height/2);
fourthrect.setPosition(width/1.5,height/1.48);


sf::Text fourth;

fourth.setFont(font); 
fourth.setString("1920x1080");
fourth.setCharacterSize((height+width)/30); 
fourth.setStyle(sf::Text::Bold);
fourth.setOrigin(fourth.getLocalBounds().width/2,fourth.getLocalBounds().height/2);
fourth.setPosition(width/1.5,height/1.5);

// MAIN MENU BUTTON
sf::RectangleShape mainmenurect(sf::Vector2f(width/3.71,height/12));
mainmenurect.setOrigin(mainmenurect.getLocalBounds().width/2,mainmenurect.getLocalBounds().height/2);
mainmenurect.setPosition(width/2,height/1.16);


sf::Text mainmenu;

mainmenu.setFont(font); 
mainmenu.setString("Main menu");
mainmenu.setCharacterSize((height+width)/30); 
mainmenu.setStyle(sf::Text::Bold);
mainmenu.setOrigin(mainmenu.getLocalBounds().width/2,mainmenu.getLocalBounds().height/2);
mainmenu.setPosition(width/2,height/1.18);



if(optionsSelector == 1){
    first.setFillColor(sf::Color::Red);
    first.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{first.setFillColor(sf::Color::White);}

if(optionsSelector == 2){
    second.setFillColor(sf::Color::Red);
    second.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{second.setFillColor(sf::Color::White);}

if(optionsSelector == 3){
    third.setFillColor(sf::Color::Red);
    third.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{third.setFillColor(sf::Color::White);}

if(optionsSelector == 4){
    fourth.setFillColor(sf::Color::Red);
    fourth.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{fourth.setFillColor(sf::Color::White);}

if(optionsSelector == 5){
    mainmenu.setFillColor(sf::Color::Red);
    mainmenu.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{mainmenu.setFillColor(sf::Color::White);}

if (firstrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    optionsSelector = 1;
}
else if (secondrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    optionsSelector = 2;
}
else if (thirdrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    optionsSelector = 3;
}
else if (fourthrect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    optionsSelector = 4;
}
else if (mainmenurect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    optionsSelector = 5;
}
else {optionsSelector = 0;}


window.draw(background);
window.draw(first);
window.draw(second);
window.draw(third);
window.draw(fourth);
window.draw(mainmenu);
}

void workiprogress()
{
if(!backgroundimg.loadFromFile("Graphics/workinp.png"))
    std::cout<<"Error loading background image!"<<std::endl;
TextureSize = backgroundimg.getSize(); //Get size of texture.
WindowSize = window.getSize();             //Get size of window.

float ScaleX = (float) WindowSize.x / TextureSize.x;
float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

background.setTexture(backgroundimg);
background.setScale(ScaleX, ScaleY); 

sf::Font font;
font.loadFromFile("cartoon.ttf");

// MAIN MENU BUTTON
sf::RectangleShape mainmenurect(sf::Vector2f(width/3.71,height/12));
mainmenurect.setOrigin(mainmenurect.getLocalBounds().width/2,mainmenurect.getLocalBounds().height/2);
mainmenurect.setPosition(width/1.22,height/1.16);


sf::Text mainmenu;

mainmenu.setFont(font); 
mainmenu.setString("Main menu");
mainmenu.setFillColor(sf::Color::White);
mainmenu.setCharacterSize((height+width)/30); 
mainmenu.setStyle(sf::Text::Bold);
mainmenu.setOrigin(mainmenu.getLocalBounds().width/2,mainmenu.getLocalBounds().height/2);
mainmenu.setPosition(width/1.22,height/1.18);


if(pauseSelector == 2){
    mainmenu.setFillColor(sf::Color::Red);
    mainmenu.setStyle(sf::Text::Bold | sf::Text::Underlined);
}else{mainmenu.setFillColor(sf::Color::White);}

if (mainmenurect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
{
    pauseSelector = 2;
}
else {pauseSelector = 0;}


window.draw(background);
window.draw(mainmenu);
}
