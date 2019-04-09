#pragma once
#include "IDecisionTreeNode.h"
#include "Action.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class ActionNode : public IDecisionTreeNode
		{
		public:
			ActionNode(Action * i_pAction);
			virtual IDecisionTreeNode* MakeDecision() override;
			Action* GetAction();

		private:
			Action * m_pAction;
		};
	}
}
