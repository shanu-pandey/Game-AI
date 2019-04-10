#pragma once
#include "IDecisionMakingTechnique.h"
#include "ITask.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class BehaviorTree : public IDecisionMakingTechnique
			{
			public:
				BehaviorTree();
				~BehaviorTree();
				virtual Action* GetAction() override;
				ITask* GetRoot() const;
				void SetRoot(ITask* i_root);

			private:
				ITask * m_pRoot;			
			};
		}

	}
}