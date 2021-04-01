#pragma once
#include <SFML/Graphics.hpp>

#pragma region Forward Declarations
	class Level;
#pragma endregion Forward Declarations

//Debug
#include <iostream>
using namespace std;
using namespace sf;

class GameObject
{
	public :
		GameObject();
		~GameObject();

	protected :

		#pragma region ProtectedVariables
			float fVelocity;
			Level* level;
		#pragma endregion ProtectedVariables

	public :

		#pragma region Enum
			enum EnumCollision
			{
				none,
				top,
				bot,
				right,
				left
			};
		#pragma endregion Enum

		#pragma region PublicVarialbes
			string strName = "GameObject";
			string strTag = "none";

			Texture* texture;
			Sprite* sprite;

			EnumCollision enumCollision;
			bool bIgnoreCollision = false;
		#pragma endregion PublicVarialbes

		#pragma region Functions
			virtual void Start();
			virtual void Update(float* deltaTime);

			virtual bool CheckCollision(GameObject other);
			virtual void OnTriggerEnter(GameObject other);

			//Getter / Setter
			inline const float& GetVelocity() { return fVelocity; }
			
			inline Level* getLevel() { return level; }
			inline void setLevel(Level* _level) { level = _level; }
		#pragma endregion Functions



};

