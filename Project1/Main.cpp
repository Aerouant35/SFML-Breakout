//SFML classes
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//Custom classes
#include "GameManager.h"
#include "Level.h"
#include "Cannon.h"
// for debugs
#include <iostream> 

#pragma region Forward Declarations
//class GameObject;
#pragma endregion Forward Declarations


int main()
{
    // Create main Class window 
    GameManager gameManager;

    // Create Level
    Level level;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(gameManager.fWidth, gameManager.fHeight), "SFML - BreakOut");

    #pragma region CreateElements
        //time
        sf::Clock clock;
        sf::Time time;

        //Canon
        Cannon* cannon = new Cannon(&window);
        level.TabGameObject.push_back(cannon);

        //create ball
        //Ball* ball = new Ball();
        //level.TabBall.push_back(ball);
        //level.TabGameObject.push_back(ball);
    #pragma endregion CreateElements

    sf::Vector2f ballDir;
    //sf::FloatRect ballBound = ball->sprite->getGlobalBounds();
    sf::FloatRect ballBound = sf::Rect<float>{ 486.399994,622.400024, 51.1999817, 51.1999817 };

    float fBallLeftBound = 0;
    float fBallRightBound = 0;
    float fBallTopBound = 0;
    float fBallBotBound = 0;

    // Start the game loop (Update)
    while (window.isOpen())
    {
        //Update timer
        float fDeltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            //Mouse left button
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left && gameManager.GetIsMoving() != true)
                {
                    cannon->Fire(&level);
                    // Normalize function for move the ball 
                    //ballDir = cannon->BallDir(*ball, (sf::Vector2f)sf::Mouse::getPosition(window));
                    ballDir = cannon->BallDir(*level.TabBall[0], (sf::Vector2f)sf::Mouse::getPosition(window));
                    gameManager.SetIsMoving(true);
                }
            }
        }
        

        //Update All Gameobjects
        level.Update();


        if (!level.TabBall.empty())
        {
            //Update Ball Movement
            level.TabBall[0]->sprite->move(ballDir * level.TabBall[0]->GetVelocity() * fDeltaTime);//new ( use Sprite )  

            //Update ball bound
            ballBound = level.TabBall[0]->sprite->getGlobalBounds();

            fBallLeftBound = ballBound.left;
            fBallRightBound = ballBound.left + ballBound.width;
            fBallTopBound = ballBound.top;
            fBallBotBound = ballBound.top + ballBound.height;

            //wall collision
            if (fBallLeftBound <= 0.f || fBallRightBound >= GameManager::fWidth)
            {
                ballDir.x *= -1.f;
            }
            else if (fBallTopBound <= 0.f)
                ballDir.y *= -1.f;
            //reset ball when falling bottom wall
            else if (fBallTopBound > GameManager::fHeight)
            {
                ballDir.x = 0;
                ballDir.y = 0;
                //GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *level.TabBall[0]->sprite);
                gameManager.SetIsMoving(false);


                //remoove refrences
                //Get reference to the object to delete
                GameObject *objectRef = level.TabBall[0];
                //get index element 
                int nbToDelete;
                for (int i = 0; i < level.TabGameObject.size(); i++)
                {
                    if (level.TabBall[0] == level.TabGameObject[i])
                    {
                        nbToDelete = i;
                        break;
                    }
                }
                //remoove from tab go
                //cout << level.TabGameObject.size() << endl; //debug
                level.TabGameObject.erase(level.TabGameObject.begin() + nbToDelete);
                //cout << level.TabGameObject.size() << endl << endl; //debug
                //remoove from tab ball
                level.TabBall.clear();
                //delete element
                delete objectRef;


                //reset Canon
                cannon->Load();
            }
        }



        // Clear screen
        window.clear();
        
        #pragma region DisplayElement 

        //draw background
        window.draw(*level.Background);

        //Draw all GameObject from Level
        for (int i = 0; i < level.TabGameObject.size(); i++)
        {
            if (level.TabGameObject[i]->sprite) //if the gameobject got a sprite
            {
                window.draw(*level.TabGameObject[i]->sprite);
            }
            else
            {
                //throw Error
                cout << "No sprite assign to : " + level.TabGameObject[i]->strName << endl;
            }

        }


        #pragma endregion DisplayElement

        // Update the window
        window.display();
    }



    return EXIT_SUCCESS;
}