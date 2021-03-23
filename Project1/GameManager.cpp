#include <SFML/Graphics.hpp>

#include "GameManager.h"

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
