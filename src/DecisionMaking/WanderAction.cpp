#pragma once
#include "WanderAction.h"
#include "../WorldData/WorldManager.h"
#include "../PathFinding/A-Star.h"
#include "../Movement/Wander.h"
#include "../Movement/Arrive.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		WanderAction::WanderAction(Physics::Kinematic* i_object)
		{
			m_pTileMap = AIForGames::WorldData::WorldManager::Get().GetWorldMap();
			m_pOwnerObject = i_object;
			
			//m_pMovementAlgo = new AIForGames::Movement::Arrive(i_object, i_object, 20, 10, 2, 5, 1);

			m_pMovementAlgo = new AIForGames::Movement::Wander(i_object, 150, 50);
			t1 = m_pTileMap->GetTile(m_pOwnerObject->GetPosition());			
			t2 = t1;
			output.linear = ofVec2f(0, 0);
		}

		void WanderAction::Update()
		{
			//game code goes here
			m_pOwnerObject->Update(m_pMovementAlgo->GetKinematicSteering());
			
			//if (output.linear == ofVec2f(0, 0))
			//{
			//	int randSign = rand() % (3) -1;
			//	int randX = m_pOwnerObject->GetPosition().x + randSign * 16;
			//	int randY = m_pOwnerObject->GetPosition().y + randSign * 16;

			//	AIForGames::PathFinding::Tile* t1 = m_pTileMap->GetTile(m_pOwnerObject->GetPosition());
			//	Node n1 = Node(t1->GetIndex(), t1->GetPosition());

			//	AIForGames::PathFinding::Tile* t2 = m_pTileMap->GetTile(ofVec2f(randX, randY));
			//	Node n2 = Node(t2->GetIndex(), t2->GetPosition());

			//	//m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
			//	std::list<DirectedWeightedEdge> o_path = AIForGames::PathFinding::AStar::FindPath(n1, n2, m_pTileMap->GetGraph());
			//	output = m_pMovementAlgo->GeneratePath(o_path);
			//	m_pOwnerObject->Update(m_pMovementAlgo->GeneratePath(o_path));
			//}
		}
	}
}