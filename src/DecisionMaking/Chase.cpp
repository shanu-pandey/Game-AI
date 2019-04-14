#pragma once
#include "Chase.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		Chase::Chase(Physics::Kinematic* i_object, Physics::Kinematic* i_target)
		{
			m_pOwnerObject = i_object;
			m_pTargetObject = i_target;
			m_pMovementAlgo = new AIForGames::Movement::Seek(m_pOwnerObject, m_pTargetObject, 200);
			bComplete = false;
		}

		void Chase::Update()
		{
			//game code goes here

			
			float sqDistance = pow((m_pTargetObject->GetPosition().x - m_pOwnerObject->GetPosition().x), 2) +
				pow((m_pTargetObject->GetPosition().y - m_pOwnerObject->GetPosition().y), 2);
			if (sqDistance < pow(250, 2))
			{
				//m_pOwnerObject->Update(m_pMovementAlgo->GetKinematicSteering());
				std::list<DirectedWeightedEdge> path;
				m_pOwnerObject->Update(m_pMovementAlgo->GeneratePath(path));

			}


			
		}

		bool Chase::IsComplete()
		{
			return bComplete;
		}

		void Chase::Restart()
		{
			bComplete = false;
		}
	}
}