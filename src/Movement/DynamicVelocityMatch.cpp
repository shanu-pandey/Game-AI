#pragma once
#include "DynamicVelocityMatch.h"
#include "../Physics/Kinematic.h"


namespace AIForGames
{
	namespace Movement
	{
		DynamicVelocityMatch::DynamicVelocityMatch(Physics::Kinematic* i_character, Physics::Kinematic*  i_target, float i_maxAcc, float i_timeToTarget)
		{			
			m_pCharacter = i_character;			
			m_pTarget = i_target;
			m_MaxAcceleration = i_maxAcc;
			m_timeToTarget = i_timeToTarget;
		}
			
		float DynamicVelocityMatch::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput DynamicVelocityMatch::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;
			return output;
		}

		DynamicSteeringOutput DynamicVelocityMatch::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);
			output.linear = m_pTarget->GetVelocity() - m_pCharacter->GetVelocity();
			output.linear /= m_timeToTarget;
			if (output.linear.length() > m_MaxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_MaxAcceleration;
			}
			return output;
		}
	}
}