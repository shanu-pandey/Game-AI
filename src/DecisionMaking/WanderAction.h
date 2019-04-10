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
			WanderAction(float i_expiryTime, float i_priority) : Action(i_expiryTime, i_priority) {}
			WanderAction(Physics::Kinematic* i_object);
			~WanderAction() {};
			virtual void Update() override;
			
		private:
			AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
			Physics::Kinematic* m_pOwnerObject;
		};
	}
}

