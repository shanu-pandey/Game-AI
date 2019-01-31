#pragma once
#include "Face.h"
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

			float rotation = m_pInputs->destination->GetOrientation() - m_pInputs->source->GetOrientation();

			//Map rotation to [-3.14, 3.14]
			if (rotation < 0 && rotation < -3.14)
				rotation += 6.28;
			else if (rotation > 0 && rotation > 3.14)
				rotation -= 6.28;

			float rotationSize = std::abs(rotation);

			if (rotationSize < m_pInputs->targetAngleThreshold)
				return output;

			float targetRotation = 0;
			if (rotationSize > m_pInputs->slowAngleThreshold)
				targetRotation = m_pInputs->maxRotation;
			else
				targetRotation = m_pInputs->maxRotation * rotationSize / m_pInputs->slowAngleThreshold;

			targetRotation *= rotation / rotationSize;

			output.angular = m_pInputs->destination->GetRotation() - m_pInputs->source->GetRotation();
			output.angular /= m_pInputs->timeToTarget;

			float angularAcc = std::abs(output.angular);
			if (angularAcc > m_pInputs->maxAngularAcceleration)
			{
				output.angular /= angularAcc;
				output.angular *= m_pInputs->maxAngularAcceleration;
			}

			//m_pInputs->source->SetRotation(output.angular);
			return output;
		}
	}
}