#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"


namespace AIForGames
{
	namespace Movement
	{
		class BlendedSteering : public IMovementAlgorithm
		{
		public:
			BlendedSteering(std::vector<BehaviorAndWeight*> i_behaviors, float i_maxAcc, float i_maxRotation);
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();			
		private:
			std::vector<BehaviorAndWeight*> m_pBehaviors;
			float m_maxAcceleration;
			float m_maxRotation;
		};
	}
}
