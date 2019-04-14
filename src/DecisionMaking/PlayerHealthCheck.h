#pragma once
#include "ITask.h"

namespace AIForGames
{
	class AIController;
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class PlayerHealthCheck : public ITask
			{
			public:
				PlayerHealthCheck(uint8_t i_id);
				~PlayerHealthCheck();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual BTStatus Run(Tick* i_tick) override;
				virtual Action* GetAction() override;
				void SetMyController(AIController* i_controller);				

			private:
				AIForGames::AIController* m_pMyController;
				
			};
		}
	}
}