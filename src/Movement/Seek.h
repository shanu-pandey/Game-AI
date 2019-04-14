#pragma once
#include "ofVec2f.h"
#include "IMovementAlgorithm.h"

namespace AIForGames
{
	namespace Movement
	{
		class Seek : public IMovementAlgorithm
		{
		public:
			Seek(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed);			
			Seek(MovementInputs* i_pInput);
			float CalculateNewOrientation(float i_orientation, ofVec2f i_velocity);
			KinematicSteeringOutput GetKinematicSteering();
			DynamicSteeringOutput GetDynamicSteering();			
			DynamicSteeringOutput GeneratePath(std::list<DirectedWeightedEdge>& i_path);

		private:
			MovementInputs * m_pInputs;
			Physics::Kinematic* m_pSourceBody;
			Physics::Kinematic* m_pDestinationBody;
			std::list<DirectedWeightedEdge> o_path;
			Node n1;
			Node n2;
		};
	}
}
