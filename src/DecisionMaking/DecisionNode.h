#pragma once
#include "IDecisionTreeNode.h"
#include "../GameObject/GameObject.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class DecisionNode : public IDecisionTreeNode
		{
		public:
			DecisionNode() : IDecisionTreeNode() {}
			IDecisionTreeNode* MakeDecision();
			void AddTrurNode(IDecisionTreeNode* i_node);
			void AddFalseNode(IDecisionTreeNode* i_node);
			void SetOwner(AIForGames::GameObject* i_obj);
			
		private:
			bool IsTrue();
			IDecisionTreeNode* GetBranch();
			IDecisionTreeNode * m_pTrueNode;
			IDecisionTreeNode * m_pFalseNode;
			AIForGames::GameObject* m_pMyOwnerCharacter;
		};
	}
}
