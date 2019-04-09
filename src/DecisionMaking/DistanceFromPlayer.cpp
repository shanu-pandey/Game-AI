#pragma once
#include "DistanceFromPlayer.h"
#include "../WorldData/WorldManager.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		DistanceFromPlayer::DistanceFromPlayer(AIForGames::GameObject * i_owner, float i_distance)
		{
			m_pMyOwnerCharacter = i_owner;
			m_distance = i_distance;
		}

		IDecisionTreeNode* DistanceFromPlayer::MakeDecision()
		{
			return (GetBranch()->MakeDecision());
		}

		bool DistanceFromPlayer::IsTrue()
		{
			AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
			float sqDistance = pow((m_pWorldManager.GetPlayerLocation().x - m_pMyOwnerCharacter->GetKinematic()->GetPosition().x), 2) +
				pow((m_pWorldManager.GetPlayerLocation().y - m_pMyOwnerCharacter->GetKinematic()->GetPosition().y), 2);
			if (sqDistance < pow(m_distance, 2))
				return true;
			else
				return false;
		}

		void DistanceFromPlayer::SetDistance(float i_distance)
		{
			m_distance = i_distance;
		}

		IDecisionTreeNode* DistanceFromPlayer::GetBranch()
		{
			return (IsTrue() ? m_pTrueNode : m_pFalseNode);
		}

		void DistanceFromPlayer::AddTrurNode(IDecisionTreeNode* i_node)
		{
			m_pTrueNode = i_node;
		}

		void DistanceFromPlayer::AddFalseNode(IDecisionTreeNode* i_node)
		{
			m_pFalseNode = i_node;
		}

		void DistanceFromPlayer::SetOwner(AIForGames::GameObject* i_obj)
		{
			m_pMyOwnerCharacter = i_obj;
		}
	}
}