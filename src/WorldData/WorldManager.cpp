#pragma once
#include "WorldManager.h"

namespace AIForGames
{
	namespace WorldData
	{

		WorldManager& WorldManager::Get()
		{
			static WorldManager instance;
			return instance;
		}

		WorldManager::WorldManager()
		{

		}
		
		WorldManager::~WorldManager()
		{

		}

		void WorldManager::RegisterPlayerCharacter(AIForGames::GameObject* i_player)
		{
			m_pPlayerCharacter = i_player;
		}

		void WorldManager::RegisterNPC(AIForGames::GameObject * i_NPC)
		{
			m_pNPCList.emplace_back(i_NPC);
		}

		void WorldManager::SetWorldMap(AIForGames::PathFinding::TileMap * i_pWorldMap)
		{
			m_pWorldMap = i_pWorldMap;
		}

		AIForGames::PathFinding::TileMap* WorldManager::GetWorldMap()
		{
			return m_pWorldMap;
		}

		ofVec2f WorldManager::GetPlayerLocation()
		{
			return m_pPlayerCharacter->GetKinematic()->GetPosition();
		}

		AIForGames::GameObject* WorldManager::GetPlayerCharacter()
		{
			return m_pPlayerCharacter;
		}
	}
}