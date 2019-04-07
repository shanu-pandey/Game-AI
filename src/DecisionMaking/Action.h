#pragma once

namespace AIForGames
{
	namespace DecisionMaking
	{
		class Action
		{
		public:
			Action();
			Action(float i_expiryTime, float i_priority);
			~Action();
			bool CanInterrupt();
			bool CanInterruptAction(Action* i_action);
			bool CanDoBoth(Action* i_action);
			bool IsComplete();
			void Update();
			bool IsHigherPriority(Action* i_action);

		private:
			float m_queuedTime;
			float m_expiryTime;
			float m_priority;
		};
	}
}

