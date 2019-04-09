#pragma once
#include "Action.h"
#include "../Movement/IMovementAlgorithm.h"
#include "../Movement/Wander.h"
#include "../Physics/Kinematic.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class WanderAction : public Action
		{
		public:
			WanderAction() : Action() {};
			WanderAction(Physics::Kinematic* i_object);
			WanderAction(float i_expiryTime, float i_priority) : Action(i_expiryTime, i_priority) {}
			~WanderAction() {};
			//bool CanInterrupt() { return m_bInterrupt; }
			//bool CanInterruptAction(Action* i_action);
			//bool CanDoBoth(Action* i_action);
			//bool IsComplete();
			virtual void Update() override;
			//bool IsHigherPriority(Action* i_action);
			//float GetQueuedTime() { return m_queuedTime; }
			//float GetExpiryTime() { return m_expiryTime; }
			//float GetPriority() { return m_priority; }
			//void IncrementQueuedTime(float i_dt) { m_queuedTime += i_dt; }
			//void IncrementExpiryTime(float i_dt) { m_expiryTime += i_dt; }
			//void DecrementQueuedTime(float i_dt) { m_queuedTime -= i_dt; }
			//void DecrementExpiryTime(float i_dt) { m_expiryTime -= i_dt; }

		private:
			AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
			Physics::Kinematic* m_pOwnerObject;
			/*float m_queuedTime;
			float m_expiryTime;
			float m_priority;
			bool m_bInterrupt;*/
		};
	}
}

