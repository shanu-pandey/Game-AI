#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class Wander : public IMovementAlgorithm
		{
		public:
			Wander(Physics::Kinematic* i_character, float i_maxSpeed, float i_maxRotation);
			Wander(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_maxAcc, float i_wanderOffset, float i_wanderRadius, float i_wanderRate);
			Wander(MovementInputs* i_pInput);
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
			void SetWanderParameters(float i_wanderOffset, float i_wanderRadius, float i_wanderRate);
			DynamicSteeringOutput GeneratePath(std::list<DirectedWeightedEdge>& i_path);

		private:
			MovementInputs * m_pInputs;
		};
	}
}
