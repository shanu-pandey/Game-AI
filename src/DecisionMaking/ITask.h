#pragma once
#include <stdint.h>
#include <vector>
#include "../GameStructs.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		//forward declaration
		class Action;

		namespace BehaviorTrees
		{
			//forward Declaration
			class Tick;

			class ITask
			{
			public:
				ITask(uint8_t i_id) { m_id = i_id; }
				virtual BTStatus OnEnter(Tick* i_tick) = 0;
				virtual BTStatus OnExit(Tick* i_tick) = 0;
				virtual BTStatus OnOpen(Tick* i_tick) = 0;
				virtual BTStatus OnClose(Tick* i_tick) = 0;
				virtual BTStatus OnExecute(Tick* i_tick) = 0;
				void AddChild(ITask* i_task) { m_childList.emplace_back(i_task); m_length++; }
				uint8_t Length() { return m_length; }
				std::vector<ITask*> GetChildren() { return m_childList; }
				uint8_t ID() { return m_id; }
				virtual Action* GetAction() = 0;
				virtual BTStatus Run(Tick* i_tick) = 0;

			protected:
				uint8_t m_id;
				std::vector<ITask*> m_childList;
				uint8_t m_length;
				
			};
		}
	}
}