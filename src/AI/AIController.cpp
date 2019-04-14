#pragma once
#include "AIController.h"
#include "../DecisionMaking/DecisionTree.h"
#include "../DecisionMaking/WanderAction.h"
#include "../DecisionMaking/Chase.h"
#include "../DecisionMaking/ActionNode.h"
#include "../DecisionMaking/DistanceFromPlayer.h"
#include "../DecisionMaking/BehaviorTree.h"
#include "../DecisionMaking/WanderTask.h"
#include "../DecisionMaking/ChaseTask.h"
#include "../DecisionMaking/Patrol.h"
#include "../DecisionMaking/PatrolAction.h"
#include "../DecisionMaking/Selector.h"
#include "../DecisionMaking/Sequencer.h"
#include "../DecisionMaking/UntilFail.h"
#include "../DecisionMaking/BT_DistanceFromPlayer.h"
#include "../DecisionMaking/Invertor.h"
#include "../DecisionMaking/PlayerHealthCheck.h"
#include "../DecisionMaking/EatPlayer.h"

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
		if (m_pDecisionTechnique->GetAction())
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
		
#pragma region Chase
		AIForGames::DecisionMaking::Chase* pChaseAction = new AIForGames::DecisionMaking::Chase(m_pOwner->GetKinematic(), m_pWorldManager.GetPlayerCharacter()->GetKinematic());
		AIForGames::DecisionMaking::BehaviorTrees::ChaseTask* pChaseTask = new AIForGames::DecisionMaking::BehaviorTrees::ChaseTask(1, pChaseAction);
#pragma endregion

#pragma region Chase Distance From Player
		AIForGames::DecisionMaking::BehaviorTrees::BT_DistanceFromPlayer* pChaseDistanceCheck = new AIForGames::DecisionMaking::BehaviorTrees::BT_DistanceFromPlayer(1);
		pChaseDistanceCheck->SetDistanceToCheck(100.0f);
		pChaseDistanceCheck->SetMyController(this);
#pragma endregion

#pragma region Eat Distance From Player
		AIForGames::DecisionMaking::BehaviorTrees::BT_DistanceFromPlayer* pEatDistanceCheck = new AIForGames::DecisionMaking::BehaviorTrees::BT_DistanceFromPlayer(1);
		pEatDistanceCheck->SetDistanceToCheck(10.0f);
		pEatDistanceCheck->SetMyController(this);
#pragma endregion

#pragma region Player Health Check
		AIForGames::DecisionMaking::BehaviorTrees::PlayerHealthCheck* pPlayerHealthCheck = new AIForGames::DecisionMaking::BehaviorTrees::PlayerHealthCheck(1);		
		pPlayerHealthCheck->SetMyController(this);
#pragma endregion

#pragma region Eat Player
		AIForGames::DecisionMaking::BehaviorTrees::EatPlayer* pEatPlayer = new AIForGames::DecisionMaking::BehaviorTrees::EatPlayer(1);
		pEatPlayer->SetMyController(this);
		pEatPlayer->SetDamage(0.1f);
#pragma endregion

#pragma region Invertor
		AIForGames::DecisionMaking::BehaviorTrees::Invertor* pInvertor = new AIForGames::DecisionMaking::BehaviorTrees::Invertor(1);
		pInvertor->AddChild(pChaseDistanceCheck);
#pragma endregion

#pragma region Eat Until Fail
		AIForGames::DecisionMaking::BehaviorTrees::UntilFail* pUntilFail = new AIForGames::DecisionMaking::BehaviorTrees::UntilFail(1);
		pUntilFail->AddChild(pPlayerHealthCheck);
		pUntilFail->AddChild(pEatDistanceCheck);				
		pUntilFail->AddChild(pEatPlayer);
#pragma endregion

#pragma region Eat Selector
		AIForGames::DecisionMaking::BehaviorTrees::Selector* pEatSelector = new AIForGames::DecisionMaking::BehaviorTrees::Selector(1);
		pEatSelector->AddChild(pUntilFail);
		pEatSelector->AddChild(pChaseTask);	
#pragma endregion

#pragma region Chase Sequencer
		AIForGames::DecisionMaking::BehaviorTrees::Sequencer* pChaseSequencer = new AIForGames::DecisionMaking::BehaviorTrees::Sequencer(1);
		pChaseSequencer->AddChild(pChaseDistanceCheck);
		pChaseSequencer->AddChild(pEatSelector);
#pragma endregion

#pragma region Root Selector
		AIForGames::DecisionMaking::BehaviorTrees::Selector* pRootSelector = new AIForGames::DecisionMaking::BehaviorTrees::Selector(1);
		pRootSelector->AddChild(pChaseSequencer);
		pRootSelector->AddChild(pPatrol);
#pragma endregion
		
		m_pDecisionTechnique = new AIForGames::DecisionMaking::BehaviorTrees::BehaviorTree(pRootSelector);
	}

	void AIController::DecisionTreeLearning()
	{

	}
}
