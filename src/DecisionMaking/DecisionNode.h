#pragma once
#include "IDecisionTreeNode.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class DecisionNode : public IDecisionTreeNode
		{
		public:
			DecisionNode() : IDecisionTreeNode() {}
			IDecisionTreeNode* MakeDecision();
			
		private:
			bool IsTrue();
			IDecisionTreeNode* GetBranch();
			IDecisionTreeNode * m_pTrueNode;
			IDecisionTreeNode * m_pFalseNode;
		};
	}
}
