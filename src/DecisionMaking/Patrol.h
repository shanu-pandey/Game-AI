#pragma once
#include "ITask.h"

namespace AIForGames
{
	class AIController;

	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Patrol : public ITask
			{
			public:
				Patrol(uint8_t i_id, uint8_t i_Points);
				~Patrol();
				void AddPatrolPoint(Node* i_point);
				uint8_t GetCount();
				void SetAction(Action * i_pAction);
				void SetMyController(AIForGames::AIController* i_controller);
				virtual BTStatus OnEnter(Tick* i_tick) override;
				virtual BTStatus OnExit(Tick* i_tick) override;
				virtual BTStatus OnOpen(Tick* i_tick) override;
				virtual BTStatus OnClose(Tick* i_tick) override;
				virtual BTStatus OnExecute(Tick* i_tick) override;
				virtual Action* GetAction() override;
				virtual BTStatus Run(Tick* i_tick) override;

			private:
				AIForGames::AIController* m_pMyController;
				std::vector<Node*> m_pPatrolPoints;
				uint8_t m_patrolPointsCount;
				Action* m_pAction;
				float m_distance = 100.0f;
			};
		}
	}
}