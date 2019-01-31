#pragma once
#include "Arrive.h"
#include "../Physics/Kinematic.h"


namespace AIForGames
{
	namespace Movement
	{
		Arrive::Arrive(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_radius, float i_timeToTarget)
		{
			m_pInputs = new MovementInputs();			
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxSpeed = i_maxSpeed;
			m_pInputs->targetRadius = i_radius;
			m_pInputs->timeToTarget = i_timeToTarget;
		}

		Arrive::Arrive(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_maxAcc, float i_targetRadius, float i_slowRadius, float i_timeToTarget)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxSpeed = i_maxSpeed;
			m_pInputs->maxAcceleration = i_maxAcc;
			m_pInputs->targetRadius = i_targetRadius;
			m_pInputs->slowRadius = i_slowRadius;
			m_pInputs->timeToTarget = i_timeToTarget;
		}

		Arrive::Arrive(MovementInputs* i_pInput)
		{
			m_pInputs = new MovementInputs();
			m_pInputs = i_pInput;
		}

		float Arrive::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput Arrive::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			output.velocity = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();

			if (output.velocity.length() < m_pInputs->targetRadius)
			{
				output.velocity = ofVec2f(0, 0);
				output.rotation = 0;
				return output;
			}

			output.velocity /= m_pInputs->timeToTarget;

			if (output.velocity.length() > m_pInputs->maxSpeed)
			{
				output.velocity.normalize();
				output.velocity *= m_pInputs->maxSpeed;
			}

			m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.velocity));
			return output;
		}

		DynamicSteeringOutput Arrive::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;			
			output.linear = ofVec2f(0,0);

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			ofVec2f direction = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			float distance = direction.length();

			if (distance < m_pInputs->targetRadius)
				return output;

			float targetSpeed = 0;
			if (distance > m_pInputs->slowRadius)
				targetSpeed = m_pInputs->maxSpeed;
			else			
				targetSpeed = (m_pInputs->maxSpeed*distance) / m_pInputs->slowRadius;
			
			ofVec2f targetVelocity = direction.normalize() * targetSpeed;

			output.linear = targetVelocity - m_pInputs->source->GetVelocity();
			output.linear /= m_pInputs->timeToTarget;
			if (output.linear.length() > m_pInputs->maxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_pInputs->maxAcceleration;
			}
			//m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear));
			output.angular = (CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear));

			return output;
		}
	}
}