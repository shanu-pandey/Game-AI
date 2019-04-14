#pragma once
#include "ITask.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class WanderTask : public ITask
			{
			public:			
				WanderTask(uint8_t i_id, Action* i_pAction) : ITask(i_id), m_pAction(i_pAction)
				{}
				~WanderTask();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual Action* GetAction() override;
				virtual BTStatus Run(Tick* i_tick) override;
			private :
				Action* m_pAction;		
			};
		}
	}
}