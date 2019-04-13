#pragma once
#include <stdint.h>
#include <vector>

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
				virtual void OnEnter(Tick* i_tick) = 0;
				virtual void OnExit(Tick* i_tick) = 0;
				virtual void OnOpen(Tick* i_tick) = 0;
				virtual void OnClose(Tick* i_tick) = 0;
				virtual void OnExecute(Tick* i_tick) = 0;
				void AddChild(ITask* i_task) { m_childList.emplace_back(i_task); m_length++; }
				uint8_t Length() { return m_length; }
				std::vector<ITask*> GetChildren() { return m_childList; }
				uint8_t ID() { return m_id; }
				virtual Action* GetAction() = 0;
				virtual void Run(Tick* i_tick) = 0;

			protected:
				uint8_t m_id;
				std::vector<ITask*> m_childList;
				uint8_t m_length;
				
			};
		}
	}
}