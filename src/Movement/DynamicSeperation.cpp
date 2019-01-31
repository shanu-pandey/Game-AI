#pragma once
#include "DynamicSeperation.h"
#include "../Physics/Kinematic.h"


namespace AIForGames
{
	namespace Movement
	{
		DynamicSeparation::DynamicSeparation(Physics::Kinematic* i_character, std::vector<Physics::Kinematic*>  i_targets, float i_threshold, float i_decayCofficient, float i_MaxAcc)
		{
			m_pCharacter = i_character;
			m_pTargets = i_targets;
			m_threshold = i_threshold;
			m_decayCofficient = i_decayCofficient;
			m_maxAcceleration = i_MaxAcc;
		}
				
		float DynamicSeparation::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput DynamicSeparation::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;		
			return output;
		}

		DynamicSteeringOutput DynamicSeparation::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			for (std::vector<AIForGames::Physics::Kinematic*>::iterator it = m_pTargets.begin(); it != m_pTargets.end(); ++it)
			{
				if ((*it) != m_pCharacter)
				{
					ofVec2f direction = m_pCharacter->GetPosition() - (*it)->GetPosition();
					float distance = direction.length();
					if (distance < m_threshold)
					{
						float strength = std::fmin(m_decayCofficient / (distance*distance), m_maxAcceleration);
						direction.normalize();
						output.linear += strength * direction;
					}
				}
			}

			if (output.linear.length() > m_maxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_maxAcceleration;
			}		
			return output;
		}
	}
}