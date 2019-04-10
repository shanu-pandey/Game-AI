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
				Tick();
				~Tick();
				void CloseTask(ITask* i_task);
				void OpenTask(ITask* i_task);

			private:
				IDecisionMakingTechnique* m_pTree;
				Blackboard* m_pBlackboard;
				std::vector<ITask*> m_openTasks;			

			};
		}

	}
}

