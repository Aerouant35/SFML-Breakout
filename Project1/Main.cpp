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
    sf::Clock clock;
    sf::Time time;

    //create ball
    Ball *ball = new Ball();
    level.TabBall.push_back(ball);
    level.TabGameObject.push_back(ball);


    //Canon
    Cannon cannon;

    sf::Vector2f ballDir;
    #pragma endregion CreateElement

    sf::FloatRect ballBound = ball->sprite->getGlobalBounds();

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
                    // Normalize function for move the ball 
                    ballDir = cannon.BallDir(*ball, (sf::Vector2f)sf::Mouse::getPosition(window));
                    gameManager.SetIsMoving(true);
                }
            }
        }
        

        //Update All Gameobjects
        level.Update();

        //Update Ball Movement
        ball->sprite->move(ballDir * ball->GetVelocity() * fDeltaTime);//new ( use Sprite )    
        
        //Update ball bound
        ballBound = ball->sprite->getGlobalBounds();

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
            GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *ball->sprite);
            gameManager.SetIsMoving(false);
        }

        // Clear screen
        window.clear();
        
        #pragma region DisplayElement 

        //draw background
        window.draw(*level.Background);

        //draw ball
        //window.draw(*ball->sprite);//new ( sprite )

        //Draw all GameObject from Level
        for (int i = 0; i < level.TabGameObject.size(); i++)
        {
            window.draw(*level.TabGameObject[i]->sprite);
        }


        #pragma endregion DisplayElement

        // Update the window
        window.display();
    }



    return EXIT_SUCCESS;
}