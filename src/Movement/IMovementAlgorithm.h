#pragma once
#include "ofVec2f.h"
#include "../GameStructs.h"

namespace AIForGames
{
	namespace Movement
	{
		class IMovementAlgorithm
		{
		public:
			virtual KinematicSteeringOutput GetKinematicSteering() = 0;
			virtual DynamicSteeringOutput GetDynamicSteering() = 0;
			virtual float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity) = 0;	
		private:
			MovementInputs * m_pInputs;
		};
	}
}
