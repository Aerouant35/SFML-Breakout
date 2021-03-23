#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

private:


public: 

	float fWidth = 1024;
	float fHeight = 720;

	/// <summary>
	/// Set origin and position of the shape in the screen
	/// </summary>
	/// <param name="fAnchorX">Shape's anchor in x (between 0 and 1)</param>
	/// <param name="fAnchorY">Shape's anchor in y (between 0 and 1)</param>
	/// <param name="fRatioX">Shape position on screen in x (between 0 and 1)</param>
	/// <param name="fRatioY">Shape position on screen in y (between 0 and 1)</param>
	/// <param name="oShape">Shape</param>
	void SetPosition(float fAnchorX, float fAnchorY, float fRatioX, float fRatioY, sf::Shape& oShape);

	sf::Vector2f Normalize(const sf::Vector2f& vectorBase);
};

