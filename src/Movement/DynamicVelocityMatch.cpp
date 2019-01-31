#pragma once
#include "DynamicVelocityMatch.h"
#include "../Physics/Kinematic.h"


namespace AIForGames
{
	namespace Movement
	{
		DynamicVelocityMatch::DynamicVelocityMatch(Physics::Kinematic* i_character, std::vector<Physics::Kinematic*>  i_targets, float i_maxAcc, float i_timeToTarget)
		{			
			m_pCharacter = i_character;
			/*for (std::vector<Physics::Kinematic*>::iterator it = i_targets.begin(); it != i_targets.end(); ++it)
			{
				Physics::Kinematic* target = new Physics::Kinematic((*it)->);				
				m_pTargets.push_back(target);
			}*/
			//m_pTargets = i_targets;
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
			for (std::vector<AIForGames::Physics::Kinematic*>::iterator it = m_pTargets.begin(); it != m_pTargets.end(); ++it)
			{
				DynamicSteeringOutput temp;
				temp.linear = (*it)->GetVelocity() - m_pCharacter->GetVelocity();
				temp.linear /= m_timeToTarget;
				output.linear += temp.linear;
			}
			

			if (output.linear.length() > m_MaxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_MaxAcceleration;
			}
			return output;
		}
	}
}