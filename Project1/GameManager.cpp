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

void GameManager::SetPosition(float fAnchorX, float fAnchorY, float fRatioX, float fRatioY, sf::Shape& oShape)
{
    sf::FloatRect oRect = oShape.getLocalBounds();

    float fOriginX = fAnchorX * oRect.width;
    float fOriginY = fAnchorY * oRect.height;

    float fPosX = fRatioX * fWidth;
    float fPosY = fRatioY * fHeight;

    oShape.setOrigin(fOriginX, fOriginY);
    oShape.setPosition(fPosX, fPosY);
}

sf::Vector2f GameManager::Normalize(const sf::Vector2f& vectorBase)
{
    float length = sqrt((vectorBase.x * vectorBase.x) + (vectorBase.y * vectorBase.y));

    if (length != 0)
        return sf::Vector2f(vectorBase.x / length, vectorBase.y / length);
    else
        return vectorBase;
}
