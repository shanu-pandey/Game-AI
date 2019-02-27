#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class Align : public IMovementAlgorithm
		{
		public:
			Align(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_radius, float i_timeToTarget);
			Align(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxRotation, float i_maxAngularAcc,
				float i_slowAngleThreshold, float i_targetAngleThreshold, float i_timeToTarget);
			Align(MovementInputs* i_pInput);
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();
			DynamicSteeringOutput GeneratePath(std::list<DirectedWeightedEdge>& i_path);
		private:
			MovementInputs * m_pInputs;
		};
	}
}
