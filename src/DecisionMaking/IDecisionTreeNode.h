#pragma once

namespace AIForGames
{
	namespace DecisionMaking
	{
		class IDecisionTreeNode
		{
		public:
			virtual IDecisionTreeNode* MakeDecision() = 0;
		};
	}
}
