#pragma once
#include "ActionNode.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		ActionNode::ActionNode(Action * i_pAction)
		{
			m_pAction = i_pAction;
		}

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