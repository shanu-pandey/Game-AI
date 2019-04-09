#pragma once
#include "DecisionNode.h"
#include "../WorldData/WorldManager.h"
namespace AIForGames
{
	namespace DecisionMaking
	{
		IDecisionTreeNode* DecisionNode::MakeDecision()
		{
			return (GetBranch()->MakeDecision());
		}

		bool DecisionNode::IsTrue()
		{
			AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
			float sqDistance = pow((m_pWorldManager.GetPlayerLocation().x - m_pMyOwnerCharacter->GetKinematic()->GetPosition().x),2) +
				pow((m_pWorldManager.GetPlayerLocation().y - m_pMyOwnerCharacter->GetKinematic()->GetPosition().y),2);
			if (sqDistance < 10000.0f)
				return true;
			else
				return false;
		}		

		IDecisionTreeNode* DecisionNode::GetBranch()
		{
			return (IsTrue() ? m_pTrueNode : m_pFalseNode);			
		}	

		void DecisionNode::AddTrurNode(IDecisionTreeNode* i_node)
		{
			m_pTrueNode = i_node;
		}
		
		void DecisionNode::AddFalseNode(IDecisionTreeNode* i_node)
		{
			m_pFalseNode = i_node;
		}

		void DecisionNode::SetOwner(AIForGames::GameObject* i_obj)
		{
			m_pMyOwnerCharacter = i_obj;
		}
	}
}