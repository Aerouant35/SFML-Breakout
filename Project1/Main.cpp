#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "Level.h"

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
    //define radius
    float fRadius = 30;
    //create circle
    sf::CircleShape circle(fRadius);
    // change la couleur de la forme pour du vert
    circle.setFillColor(sf::Color(100, 250, 50));
    //set origin and position for circle
    gameManager.SetPosition(0.5f, 1, 0.5f, 1, circle);

    #pragma endregion CreateElement


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
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
        window.draw(circle);

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