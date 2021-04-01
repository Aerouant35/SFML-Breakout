#include <SFML/Graphics.hpp>

#include "GameManager.h"

float GameManager::fWidth = 1024;
float GameManager::fHeight = 720;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

/// <summary>
/// Set position of a sprite in screen
/// </summary>
/// <param name="fAnchorX">Ratio about sprite origin (between 0 and 1)</param>
/// <param name="fAnchorY">Ratio about sprite origin (between 0 and 1)</param>
/// <param name="fRatioX">Ratio about sprite position on screen (between 0 and 1)</param>
/// <param name="fRatioY">Ratio about sprite position on screen (between 0 and 1)</param>
/// <param name="oSprite">Sprite</param>
void GameManager::SetPosition(float fAnchorX, float fAnchorY, float fRatioX, float fRatioY, sf::Sprite& oSprite)
{
    sf::FloatRect oRect = oSprite.getLocalBounds();

    float fOriginX = fAnchorX * oRect.width;
    float fOriginY = fAnchorY * oRect.height;

    float fPosX = fRatioX * fWidth;
    float fPosY = fRatioY * fHeight;

    oSprite.setOrigin(fOriginX, fOriginY);
    oSprite.setPosition(fPosX, fPosY);
}

/// <summary>
/// Normalize a vector2f
/// </summary>
/// <param name="vectorBase">Vector to normalize</param>
/// <returns>Vector2f normalized or vectorBase</returns>
sf::Vector2f GameManager::Normalize(const sf::Vector2f& vectorBase)
{
    float length = sqrt((vectorBase.x * vectorBase.x) + (vectorBase.y * vectorBase.y));

    if (length != 0)
        return sf::Vector2f(vectorBase.x / length, vectorBase.y / length);
    else
        return vectorBase;
}
