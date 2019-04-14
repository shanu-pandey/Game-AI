#pragma once
#include "Tick.h"


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Tick::Tick(IDecisionMakingTechnique* i_pTree, Blackboard* i_pBlackboard)
			{
				m_pTree = i_pTree;
				m_pBlackboard = i_pBlackboard;
			}
			Tick::~Tick()
			{
				if (this)
					delete(this);
			}
			void Tick::CloseTask(ITask* i_task)
			{

			}
			void Tick::OpenTask(ITask* i_task)
			{
				m_openTasks.emplace_back(i_task);
			}
		}
	}
}