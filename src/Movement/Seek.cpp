#pragma once
#include "Seek.h"
#include "../Physics/Kinematic.h"


namespace AIForGames
{
	namespace Movement
	{
		Seek::Seek(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxSpeed = i_maxSpeed;			
		}

		Seek::Seek(MovementInputs* i_pInput)
		{
			m_pInputs = new MovementInputs();
			m_pInputs = i_pInput;
		}

		float Seek::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput Seek::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			output.velocity = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			output.velocity.normalize();
			output.velocity *= m_pInputs->maxSpeed;
			
			m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.velocity));
			return output;
		}

		DynamicSteeringOutput Seek::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			output.linear = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			output.linear.normalize();
			output.linear *= m_pInputs->maxSpeed;			

			//output.angular = CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear);
			//m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear));

			return output;
		}
	}
}