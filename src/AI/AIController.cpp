#pragma once
#include "AIController.h"

namespace AIForGames
{
	AIController::AIController()
	{
		m_pOwner = new GameObject();
		m_pDecisionTechnique = nullptr;
	}

	AIController::AIController(GameObject * i_owner, AIForGames::DecisionMaking::IDecisionMakingTechnique * i_decision, AIForGames::DecisionMaking::ActionManager* i_ActionManager)
	{
		m_pOwner = i_owner;
		m_pDecisionTechnique = i_decision;
		m_pActionManager = i_ActionManager;
	}

	AIController::~AIController()
	{	

	}

	GameObject * AIController::GetOwner() const
	{
		return m_pOwner;
	}

	void AIController::Update()
	{
		m_pActionManager->AddToPending(m_pDecisionTechnique->GetAction());
	}	
}
