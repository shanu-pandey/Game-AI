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
			bool CanInterrupt() { return m_bInterrupt; }
			bool CanInterruptAction(Action* i_action);
			bool CanDoBoth(Action* i_action);
			bool IsComplete();
			virtual void Update() = 0;
			bool IsHigherPriority(const Action& i_action) const;
			float GetQueuedTime() { return m_queuedTime; }
			float GetExpiryTime() { return m_expiryTime; }
			float GetPriority() { return m_priority; }
			void IncrementQueuedTime(float i_dt) { m_queuedTime += i_dt; }
			void IncrementExpiryTime(float i_dt) { m_expiryTime += i_dt; }
			void DecrementQueuedTime(float i_dt) { m_queuedTime -= i_dt; }
			void DecrementExpiryTime(float i_dt) { m_expiryTime -= i_dt; }

		private:
			float m_queuedTime;
			float m_expiryTime;
			float m_priority;
			bool m_bInterrupt;
		};
	}
}

