#pragma once
//#include "../GameObject/GameObject.h"
#include "ofVec2f.h"



namespace AIForGames
{
	class GameObject; 

	namespace Movement
	{
		static class MovementAlgorithms
		{
		public:	
			static float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);			
		};
	}
}
