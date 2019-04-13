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
				virtual void OnEnter(Tick* i_tick) override;
				virtual void OnExit(Tick* i_tick) override;
				virtual void OnOpen(Tick* i_tick) override;
				virtual void OnClose(Tick* i_tick) override;
				virtual void OnExecute(Tick* i_tick) override;												
				virtual Action* GetAction() override;
				virtual void Run(Tick* i_tick) override;
			private :
				Action* m_pAction;		
			};
		}
	}
}