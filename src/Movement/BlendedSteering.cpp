#pragma once
#include "BlendedSteering.h"


namespace AIForGames
{
	namespace Movement
	{
		BlendedSteering::BlendedSteering(std::vector<BehaviorAndWeight*> i_behaviors, float i_maxAcc, float i_maxRotation)
		{
			m_pBehaviors = i_behaviors;
			m_maxAcceleration = i_maxAcc;
			m_maxRotation = i_maxRotation;
		}
	
		float BlendedSteering::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput BlendedSteering::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;
			return output;
		}

		DynamicSteeringOutput BlendedSteering::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			for (std::vector<BehaviorAndWeight*>::iterator it = m_pBehaviors.begin(); it != m_pBehaviors.end(); ++it)
			{
				DynamicSteeringOutput temp;
				output.linear += (*it)->weight * (*it)->p_behavior->GetDynamicSteering().linear;
				output.angular += (*it)->weight * (*it)->p_behavior->GetDynamicSteering().angular;	
			}

			if (output.linear.length() > m_maxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_maxAcceleration;
			}

			if (output.linear.length() > m_maxAcceleration)
			{
				output.linear.normalize();
				output.linear *= m_maxAcceleration;
			}

			if (output.angular < -3.14)
				output.angular += 6.28;
			else if (output.angular > 3.14)
				output.angular -= 6.28;
			
			return output;
		}
		
	}
}