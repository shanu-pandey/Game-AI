#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class DynamicSeparation : public IMovementAlgorithm
		{
		public:
			DynamicSeparation(Physics::Kinematic* i_character, std::vector<Physics::Kinematic*>  i_targets, float i_threshold, float i_decayCofficient, float i_MaxAcc);		
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
		private:
			Physics::Kinematic* m_pCharacter;
			std::vector<Physics::Kinematic*> m_pTargets;
			float m_threshold;
			float m_decayCofficient;
			float m_maxAcceleration;
		};
	}
}
