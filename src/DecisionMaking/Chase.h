#pragma once
#include "Action.h"
#include "../Movement/IMovementAlgorithm.h"
#include "../Movement/Seek.h"
#include "../Physics/Kinematic.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class Chase : public Action
		{
		public:
			Chase() : Action() {};
			Chase(float i_expiryTime, float i_priority) : Action(i_expiryTime, i_priority) {}
			Chase(Physics::Kinematic* i_object, Physics::Kinematic* i_target);
			~Chase() {};
			virtual void Update() override;
			virtual bool IsComplete() override;
			virtual void Restart() override;

		private:
			AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
			Physics::Kinematic* m_pOwnerObject;
			Physics::Kinematic* m_pTargetObject;
			bool bComplete;
		};
	}
}

