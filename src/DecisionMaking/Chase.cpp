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
		}

		void Chase::Update()
		{
			//game code goes here
			m_pOwnerObject->Update(m_pMovementAlgo->GetKinematicSteering());
		}
	}
}