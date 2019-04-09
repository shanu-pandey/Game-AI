#pragma once
#include "AIController.h"
#include "../DecisionMaking/DecisionTree.h"
#include "../DecisionMaking/WanderAction.h"
#include "../DecisionMaking/ActionNode.h"

namespace AIForGames
{
	AIController::AIController()
	{
		m_pOwner = new GameObject();
		m_pDecisionTechnique = nullptr;
		m_pActionManager = new AIForGames::DecisionMaking::ActionManager();
	}

	AIController::AIController(GameObject * i_owner)
	{
		m_pOwner = i_owner;
		m_pActionManager = new AIForGames::DecisionMaking::ActionManager();		
		AIForGames::DecisionMaking::WanderAction* pWanderAction = new AIForGames::DecisionMaking::WanderAction(m_pOwner->GetKinematic());
		AIForGames::DecisionMaking::ActionNode* node = new AIForGames::DecisionMaking::ActionNode(pWanderAction);
		m_pDecisionTechnique = new AIForGames::DecisionMaking::DecisionTree(node);
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

	void AIController::SetDecisionTechniques(AIForGames::DecisionMaking::IDecisionMakingTechnique * i_decision)
	{
		m_pDecisionTechnique = i_decision;
	}

	void AIController::Update()
	{
		m_pActionManager->AddToPending(m_pDecisionTechnique->GetAction());		
	}	
}
