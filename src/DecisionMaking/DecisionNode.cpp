#pragma once
#include "DecisionNode.h"

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
			//game world check
			return true;
		}		

		IDecisionTreeNode* DecisionNode::GetBranch()
		{
			return (IsTrue() ? m_pTrueNode : m_pFalseNode);			
		}	
	}
}