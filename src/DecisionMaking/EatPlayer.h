#pragma once
#include "ITask.h"

namespace AIForGames
{
	class AIController;
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class EatPlayer : public ITask
			{
			public:
				EatPlayer(uint8_t i_id);
				~EatPlayer();
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual BTStatus Run(Tick* i_tick) override;
				virtual Action* GetAction() override;
				void SetMyController(AIController* i_controller);
				void SetDamage(float i_damage);

			private:
				AIForGames::AIController* m_pMyController;
				float m_damage = 0.1f;

			};
		}
	}
}