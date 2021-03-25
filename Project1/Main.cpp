#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "Level.h"
#include "Cannon.h"

#include <iostream>

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

    Ball *ball = new Ball();
    Cannon cannon;

    sf::Vector2f ballDir;
    #pragma endregion CreateElement

    sf::FloatRect ballBound = ball->Sprite->getGlobalBounds();

    float fBallLeftBound = 0;
    float fBallRightBound = 0;
    float fBallTopBound = 0;
    float fBallBotBound = 0;

    // Start the game loop
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
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Normalize function for move the ball 
                    ballDir = cannon.BallDir(*ball, (sf::Vector2f)sf::Mouse::getPosition(window));
                }
            }
        }
        
        //ball->GetShape().move(ballDir * ball->GetVelocity() * fDeltaTime);    //old ( use circle )
        
        //Move ball (ballDir is a vector -> 0 = no movement)
        ball->Sprite->move(ballDir * ball->GetVelocity() * fDeltaTime);//new ( use Sprite )    
        
        //Update ball bound
        ballBound = ball->Sprite->getGlobalBounds();

        fBallLeftBound = ballBound.left;
        fBallRightBound = ballBound.left + ballBound.width;
        fBallTopBound = ballBound.top;
        fBallBotBound = ballBound.top + ballBound.height;

        //wall collision
        if (fBallLeftBound <= 0.f || fBallRightBound >= GameManager::fWidth)
        {
            ballDir.x *= -1.f;
        }
        else if (fBallTopBound <= 0.f || fBallBotBound >= GameManager::fHeight)
            ballDir.y *= -1.f;

        // Clear screen
        window.clear();
        
        #pragma region DisplayElement 
        /*
            // Draw the sprite
            window.draw(sprite);
            // Draw the string
            window.draw(text);
        */

        //draw background
        window.draw(*level.Background);

        //draw ball
        //window.draw(ball->GetShape()); //old ( circle )
        window.draw(*ball->Sprite);//new ( sprite )

        //Draw Bricks from Level
        for (int i=0; i < level.TabBrick.size(); i++)
        {
            //window.draw(*level.TabBrick[i]->Shape); //old ( rectangle )
            window.draw(*level.TabBrick[i]->Sprite); //new ( sprite )
            //std::cout << i << std::endl; // debug
        }
        
        //Brick TestBrick;
        //window.draw(*TestBrick.Shape);

        #pragma endregion DisplayElement

        // Update the window
        window.display();
    }



    return EXIT_SUCCESS;
}