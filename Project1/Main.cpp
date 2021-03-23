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

    sf::Vector2f ballNorm;
    #pragma endregion CreateElement


    // Start the game loop
    while (window.isOpen())
    {
        time = clock.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    ballNorm = cannon.BallMove(*ball, (sf::Vector2f)sf::Mouse::getPosition(window));
                }
            }
        }
        
        ball->GetShape().move(ballNorm * ball->GetVelocity() * time.asSeconds());
        
        // Clear screen
        window.clear();
        
        #pragma region DisplayElement 
        /*
            // Draw the sprite
            window.draw(sprite);
            // Draw the string
            window.draw(text);
        */
        window.draw(circle);

        //Draw Bricks from Level
        for (int i=0; i < level.TabBrick.size(); i++)
        {
            window.draw(*level.TabBrick[i]->Shape);
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