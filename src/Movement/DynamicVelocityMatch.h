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
			DynamicVelocityMatch(Physics::Kinematic* i_character, std::vector<Physics::Kinematic*>  i_targets, float i_maxAcc, float i_timeToTarget);			
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
		private:
			Physics::Kinematic* m_pCharacter;
			std::vector<Physics::Kinematic*> m_pTargets;
			float m_MaxAcceleration;
			float m_timeToTarget;
		};
	}
}

