#pragma once
#include "ITask.h"

namespace AIForGames
{
	class AIController;
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class BT_DistanceFromPlayer : public ITask
			{
			public:
				BT_DistanceFromPlayer(uint8_t i_id);
				~BT_DistanceFromPlayer();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;				
				virtual BTStatus Run(Tick* i_tick) override;
				virtual Action* GetAction() override;
				void SetMyController(AIController* i_controller);
				void SetDistanceToCheck(float i_dis) { m_distance = i_dis; }

			private:
				AIForGames::AIController* m_pMyController;
				float m_distance = 100;
			};
		}
	}
}