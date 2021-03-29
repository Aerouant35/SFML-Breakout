#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

private:
	bool bIsMoving;

public: 

	static float fWidth;
	static float fHeight;

	inline bool GetIsMoving() { return bIsMoving; };
	inline void const SetIsMoving(const bool newBool) { bIsMoving = newBool; };


	/// <summary>
	/// Set origin and position of the sprite in the screen
	/// </summary>
	/// <param name="fAnchorX">Sprite's anchor in x (between 0 and 1)</param>
	/// <param name="fAnchorY">Sprite's anchor in y (between 0 and 1)</param>
	/// <param name="fRatioX">Sprite position on screen in x (between 0 and 1)</param>
	/// <param name="fRatioY">Sprite position on screen in y (between 0 and 1)</param>
	/// <param name="oShape">Sprite</param>
	static void SetPosition(float fAnchorX, float fAnchorY, float fRatioX, float fRatioY, sf::Sprite& oSprite);

	static sf::Vector2f Normalize(const sf::Vector2f& vectorBase);
};

