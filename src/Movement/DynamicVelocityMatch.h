#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class DynamicVelocityMatch : public IMovementAlgorithm
		{
		public:
			DynamicVelocityMatch(Physics::Kinematic* i_character, Physics::Kinematic*  i_target, float i_maxAcc, float i_timeToTarget);			
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
		private:
			Physics::Kinematic* m_pCharacter;
			Physics::Kinematic* m_pTarget;
			float m_MaxAcceleration;
			float m_timeToTarget;
		};
	}
}

