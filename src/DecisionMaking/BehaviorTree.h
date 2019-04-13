#pragma once
#include "IDecisionMakingTechnique.h"
#include "ITask.h"
#include "Blackboard.h"

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
				BehaviorTree(ITask * i_pRoot);
				~BehaviorTree();
				virtual Action* GetAction() override;
				ITask* GetRoot() const;
				void SetRoot(ITask* i_root);
				void Update();
				uint8_t ID() { return m_id; }

			private:
				uint8_t m_id;
				ITask * m_pRoot;		
				Blackboard* m_pBlackBoard;
			};
		}

	}
}