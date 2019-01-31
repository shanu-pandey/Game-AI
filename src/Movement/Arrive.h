#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class Arrive : public IMovementAlgorithm
		{
		public:
			Arrive(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_radius, float i_timeToTarget);
			Arrive(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_maxAcc, float i_targetRadius, float i_slowRadius, float i_timeToTarget);
			Arrive(MovementInputs* i_pInput);
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
		private:
			MovementInputs * m_pInputs;
		};
	}
}
