#pragma once
#include "IDecisionTreeNode.h"
#include "../GameObject/GameObject.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class DistanceFromPlayer : public IDecisionTreeNode
		{
		public:
			DistanceFromPlayer() : IDecisionTreeNode() {}
			DistanceFromPlayer(AIForGames::GameObject* i_owner, float i_distance);
			IDecisionTreeNode* MakeDecision();
			void AddTrurNode(IDecisionTreeNode* i_node);
			void AddFalseNode(IDecisionTreeNode* i_node);
			void SetOwner(AIForGames::GameObject* i_obj);
			void SetDistance(float i_dis);

		private:
			bool IsTrue();
			IDecisionTreeNode* GetBranch();
			IDecisionTreeNode * m_pTrueNode;
			IDecisionTreeNode * m_pFalseNode;
			AIForGames::GameObject* m_pMyOwnerCharacter;
			float m_distance;
		};
	}
}
