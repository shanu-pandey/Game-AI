#pragma once
#include "Action.h"
#include "../Movement/IMovementAlgorithm.h"
#include "../Physics/Kinematic.h"
#include "../GameStructs.h"

namespace AIForGames
{
	namespace PathFinding
	{
		class TileMap;
		class Tile;
	}
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
			AIForGames::PathFinding::TileMap* m_pTileMap;
			AIForGames::PathFinding::Tile* t1;
			AIForGames::PathFinding::Tile* t2;
			DynamicSteeringOutput output;
		};
	}
}

