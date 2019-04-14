#pragma once
#include "ITask.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Invertor : public ITask
			{
			public:
				Invertor(uint8_t i_id);
				~Invertor();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual Action* GetAction() override;
				virtual BTStatus Run(Tick* i_tick) override;
				void AddChild(ITask* i_task);
				uint8_t Length();
				std::vector<ITask*> GetChildren();

			private:
				std::vector<ITask*> m_childList;
				uint8_t m_length = 0;
			};
		}
	}
}