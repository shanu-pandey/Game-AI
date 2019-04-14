#pragma once
#include "AIController.h"
#include "../DecisionMaking/DecisionTree.h"
#include "../DecisionMaking/WanderAction.h"
#include "../DecisionMaking/Chase.h"
#include "../DecisionMaking/ActionNode.h"
#include "../DecisionMaking/DistanceFromPlayer.h"
#include "../DecisionMaking/BehaviorTree.h"
#include "../DecisionMaking/WanderTask.h"
#include "../DecisionMaking/Patrol.h"
#include "../DecisionMaking/PatrolAction.h"
#include "../DecisionMaking/Selector.h"

namespace AIForGames
{
	AIController::AIController()
	{
		//pWorldManager = AIForGames::WorldData::WorldManager::Get();
		m_pOwner = new GameObject();
		m_pDecisionTechnique = nullptr;
		m_pActionManager = new AIForGames::DecisionMaking::ActionManager();
	}

	AIController::AIController(GameObject * i_owner)
	{
		m_pOwner = i_owner;
		m_pActionManager = new AIForGames::DecisionMaking::ActionManager();	
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

	void AIController::Update(float i_dt)
	{
		m_pActionManager->AddToPending(m_pDecisionTechnique->GetAction());
		m_pActionManager->Update(i_dt);
	}	

	void AIController::CreateDecisionTree()
	{
		AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();

		AIForGames::DecisionMaking::WanderAction* pWanderAction = new AIForGames::DecisionMaking::WanderAction(m_pOwner->GetKinematic());
		AIForGames::DecisionMaking::Chase* pChaseAction = new AIForGames::DecisionMaking::Chase(m_pOwner->GetKinematic(), m_pWorldManager.GetPlayerCharacter()->GetKinematic());
		AIForGames::DecisionMaking::ActionNode* wanderNode = new AIForGames::DecisionMaking::ActionNode(pWanderAction);
		AIForGames::DecisionMaking::ActionNode* chaseNode = new AIForGames::DecisionMaking::ActionNode(pChaseAction);
		AIForGames::DecisionMaking::DistanceFromPlayer* pDistanceNode = new AIForGames::DecisionMaking::DistanceFromPlayer(m_pOwner, 100.0f);
		pDistanceNode->AddFalseNode(wanderNode);
		pDistanceNode->AddTrurNode(chaseNode);

		m_pDecisionTechnique = new AIForGames::DecisionMaking::DecisionTree(pDistanceNode);
		//m_pActionManager->AddToPending(m_pDecisionTechnique->GetAction());
	}

	void AIController::CreateBehaviorTree()
	{
		AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();		

#pragma region Patrol
		AIForGames::DecisionMaking::BehaviorTrees::Patrol* pPatrol = new AIForGames::DecisionMaking::BehaviorTrees::Patrol(1, 4);
		pPatrol->SetMyController(this);
		AIForGames::DecisionMaking::PatrolAction* pPatrolAction = new AIForGames::DecisionMaking::PatrolAction(m_pOwner->GetKinematic());				
		pPatrolAction->AddPatrolPoint(ofVec2f(550, 30));
		pPatrolAction->AddPatrolPoint(ofVec2f(550, 300));
		pPatrolAction->AddPatrolPoint(ofVec2f(980, 300));
		pPatrolAction->AddPatrolPoint(ofVec2f(980, 30));
		pPatrol->SetAction(pPatrolAction);
#pragma endregion 

#pragma region Wander
		AIForGames::DecisionMaking::WanderAction* pWanderAction = new AIForGames::DecisionMaking::WanderAction(m_pOwner->GetKinematic());		
		AIForGames::DecisionMaking::BehaviorTrees::WanderTask* pWanderTask = new AIForGames::DecisionMaking::BehaviorTrees::WanderTask(1, pWanderAction);
#pragma endregion

#pragma region Selector
		AIForGames::DecisionMaking::BehaviorTrees::Selector* pSelector = new AIForGames::DecisionMaking::BehaviorTrees::Selector(1);
		pSelector->AddChild(pPatrol);
		pSelector->AddChild(pWanderTask);	
#pragma endregion



		m_pDecisionTechnique = new AIForGames::DecisionMaking::BehaviorTrees::BehaviorTree(pSelector);
	}

	void AIController::DecisionTreeLearning()
	{

	}
}
