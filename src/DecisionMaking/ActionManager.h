#pragma once
#include <queue>
#include "Action.h"
//#include "../PriorityQueue/PriorityQueue.h"

using namespace std;

namespace AIForGames
{
	namespace DecisionMaking
	{
		struct ComparerFunctor {
			bool operator()(const Action& i_left, const Action& i_right) const {
				return (i_left.IsHigherPriority(i_right));
			}
		};

		class ActionManager
		{
		public:
			ActionManager();
			~ActionManager();
			void AddToPending(Action* i_action);
			void RemoveFromPending(Action* i_action);
			void AddToActive(Action* i_action);
			void RemoveFromActive(Action* i_action);
			void Update(float i_dt);

		private:
			void PendingQueueUpdate(float i_dt);
			void ActiveQueueUpdate(float i_dt);
			//std::priority_queue<Action*, std::vector<Action*>, ComparerFunctor> m_pending;
			std::vector<Action*> m_pending;
			std::vector<Action*> m_active;
			//std::priority_queue<Action*, std::vector<Action*>, ComparerFunctor> m_active;
		};
	}
}