#pragma once
#include "WanderAction.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		WanderAction::WanderAction(Physics::Kinematic* i_object)
		{
			m_pOwnerObject = i_object;
			m_pMovementAlgo = new AIForGames::Movement::Wander(i_object, 100, 6.8);
		}

		void WanderAction::Update()
		{
			//game code goes here
			m_pOwnerObject->Update(m_pMovementAlgo->GetKinematicSteering());
		}
	}
}