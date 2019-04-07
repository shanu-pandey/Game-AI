#pragma once
#include <queue>
#include "Action.h"

using namespace std;

namespace AIForGames
{
	namespace DecisionMaking
	{
		struct ComparerFunctor {
			bool operator()(Action* i_left, Action* i_right) const {
				return !i_left->IsHigherPriority(i_right);
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
			void Update();

		private:
			std::priority_queue<Action*, std::vector<Action*>, ComparerFunctor> m_pending;
			std::priority_queue<Action*, std::vector<Action*>, ComparerFunctor> m_active;
		};
	}
}