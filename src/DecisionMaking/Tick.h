#pragma once
#include "Task.h"
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
				void CloseTask(Task* i_task);
				void OpenTask(Task* i_task);

			private:
				IDecisionMakingTechnique* m_pTree;
				Blackboard* m_pBlackboard;
				std::vector<Task*> m_openTasks;			

			};
		}

	}
}

