#pragma once
#include "Face.h"
#include "Align.h"
#include "../Physics/Kinematic.h"
#include "../ofApp.h"

namespace AIForGames
{
	namespace Movement
	{
		Face::Face(Physics::Kinematic* i_character, Physics::Kinematic* i_target)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
		}

		Face::Face(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxRotation, float i_maxAngularAcc,
			float i_slowAngleThreshold, float i_targetAngleThreshold, float i_timeToTarget)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxRotation = i_maxRotation;
			m_pInputs->maxAngularAcceleration = i_maxAngularAcc;
			m_pInputs->slowAngleThreshold = i_slowAngleThreshold;
			m_pInputs->targetAngleThreshold = i_targetAngleThreshold;
			m_pInputs->timeToTarget = i_timeToTarget;
		}

		Face::Face(MovementInputs* i_pInput)
		{
			m_pInputs = new MovementInputs();
			m_pInputs = i_pInput;
		}

		float Face::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput Face::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;			
			return output;
		}

		DynamicSteeringOutput Face::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			/*if (m_pInputs->destination->GetPosition().x < -50)
				return output;*/

			ofVec2f direction = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			float newOrientation = 0;
			if (direction.length() == 0)
				return output;
			else
				newOrientation = std::atan2(direction.y, direction.x);

			Physics::Kinematic* i_newTarget = new Physics::Kinematic(m_pInputs->destination->GetPosition(), newOrientation);
			m_pInputs->destination = i_newTarget;
			Align* p_alignSteering = new Align(m_pInputs->source, m_pInputs->destination, 5.0, 1.5, 1.0, 0.2, 1);
			output = p_alignSteering->GetDynamicSteering();

			return output;
		}
	}
}