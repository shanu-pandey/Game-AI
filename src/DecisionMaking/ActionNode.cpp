#pragma once
#include "ActionNode.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		IDecisionTreeNode * ActionNode::MakeDecision()
		{
			return this;
		}

		Action * ActionNode::GetAction()
		{
			return m_pAction;
		}
	}
}