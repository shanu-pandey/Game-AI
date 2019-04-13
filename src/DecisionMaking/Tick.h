#pragma once
#include "ITask.h"
#include "IDecisionMakingTechnique.h"
#include "Blackboard.h"
#include <vector>


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Tick
			{
			public:
				Tick() { m_pBlackboard = nullptr; }
				Tick(IDecisionMakingTechnique* i_pTree, Blackboard* i_pBlackboard);
				~Tick();
				void CloseTask(ITask* i_task);
				void OpenTask(ITask* i_task);
				Blackboard* GetBlackBoard() { return m_pBlackboard; }

			private:
				IDecisionMakingTechnique* m_pTree;
				Blackboard* m_pBlackboard;
				std::vector<ITask*> m_openTasks;			

			};
		}

	}
}

