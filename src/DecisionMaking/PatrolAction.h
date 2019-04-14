#pragma once
#include "IDecisionTreeNode.h"
#include "Action.h"
#include "../Movement/IMovementAlgorithm.h"
#include "../Physics/Kinematic.h"

namespace AIForGames
{
	class AIController;

	namespace DecisionMaking
	{
		//forward declaration
		class Action;

		class PatrolAction : public Action
		{
		public:
			PatrolAction() : Action() {};
			PatrolAction(float i_expiryTime, float i_priority) : Action(i_expiryTime, i_priority) {}
			PatrolAction(Physics::Kinematic* i_object);
			void AddPatrolPoint(ofVec2f i_point);			
			virtual void Update() override;
			virtual bool IsComplete() override;
			virtual void Restart() override;

		private:
			
			AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
			Physics::Kinematic* m_pOwnerObject;
			Physics::Kinematic* m_pTargetObject;
			std::vector<ofVec2f> m_pPatrolPoints;
			int pointIndex;
			bool bComplete;
		};
	}
}
