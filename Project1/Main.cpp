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
    sf::RenderWindow window(sf::VideoMode(gameManager.fWidth, gameManager.fHeight), "SFML window");

    #pragma region CreateElements
    /*
        // Load a sprite to display
        sf::Texture texture;
        if (!texture.loadFromFile("cute_image.jpg"))
            return EXIT_FAILURE;
        sf::Sprite sprite(texture);
        // Load a music to play
        sf::Music music;
        if (!music.openFromFile("nice_music.ogg"))
            return EXIT_FAILURE;
        // Play the music
        music.play();
        // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 50);
    */

    //define radius
    float fRadius = 30;
    //create circle
    sf::CircleShape circle(fRadius);
    // change la couleur de la forme pour du vert
    circle.setFillColor(sf::Color(100, 250, 50));
    //set pos
    circle.setPosition(gameManager.fWidth/2- fRadius, gameManager.fHeight - fRadius*2);

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