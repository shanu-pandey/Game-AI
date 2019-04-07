#pragma once
#include "Action.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class IDecisionMakingTechnique
		{
		public:
			virtual Action* GetAction() = 0;
		};
	}
}