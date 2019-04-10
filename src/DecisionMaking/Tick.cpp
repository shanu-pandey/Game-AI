#pragma once
#include "Tick.h"


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Tick::Tick()
			{

			}
			Tick::~Tick()
			{

			}
			void Tick::CloseTask(Task* i_task)
			{

			}
			void Tick::OpenTask(Task* i_task)
			{
				m_openTasks.emplace_back(i_task);
			}
		}
	}
}