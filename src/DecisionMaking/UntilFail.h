#pragma once
#include "ITask.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class UntilFail : public ITask
			{
			public:
				UntilFail(uint8_t i_id);
				~UntilFail();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual Action* GetAction() override;
				virtual BTStatus Run(Tick* i_tick) override;

				void AddChild(ITask* i_task) { m_childList.emplace_back(i_task); m_length++; }
				uint8_t Length() { return m_length; }
				std::vector<ITask*> GetChildren() { return m_childList; }

			private:
				std::vector<ITask*> m_childList;
				uint8_t m_length = 0;
			};
		}
	}
}