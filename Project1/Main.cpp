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
        level.cannon = new Cannon(&window);
        level.TabGameObject.push_back(level.cannon);

        //create ball
        //Ball* ball = new Ball();
        //level.TabBall.push_back(ball);
        //level.TabGameObject.push_back(ball);
    #pragma endregion CreateElements

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
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (level.cannon->bIsLoaded)
                    {
                        level.cannon->Fire(&level);
                        // Normalize function for move the ball 
                        Vector2f vectorDiff = (sf::Vector2f)sf::Mouse::getPosition(window) - level.TabBall[0]->GetPos(); // modify ball to cannon
                        level.TabBall[0]->SetDirection(GameManager::Normalize(vectorDiff));
                        //GameManager::SetIsMoving(true);
                    }
                }
            }
        }
        

        //Update All Gameobjects
        level.Update(&fDeltaTime);

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