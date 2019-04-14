#pragma once
#include "PatrolAction.h"
#include "Action.h"
#include "../Movement/Arrive.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		PatrolAction::PatrolAction(Physics::Kinematic* i_object)
		{
			m_pOwnerObject = i_object;
			m_pTargetObject = new AIForGames::Physics::Kinematic(800, 10);
			m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pOwnerObject, m_pTargetObject, 200, 20, 1);
			pointIndex = -1;
			bComplete = false;
		}

		void PatrolAction::AddPatrolPoint(ofVec2f i_point)
		{
			m_pPatrolPoints.emplace_back(i_point);	
		}

		void PatrolAction::Update()
		{
			KinematicSteeringOutput output = m_pMovementAlgo->GetKinematicSteering();
			if (output.velocity == ofVec2f(0, 0) || pointIndex < 0)
			{
				pointIndex++;
				if (pointIndex == 4)
				{
					pointIndex = 0;
					bComplete = true;
				}
					
				m_pTargetObject->SetPosition(m_pPatrolPoints[pointIndex]);
				

			}
			m_pOwnerObject->Update(m_pMovementAlgo->GetKinematicSteering());
		}

		bool PatrolAction::IsComplete()
		{
			return bComplete;
		}

		void PatrolAction::Restart()
		{
			bComplete = false;
		}
	}
}