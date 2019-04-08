#pragma once
#include "WorldManager.h"

namespace AIForGames
{
	namespace WorldData
	{
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

		ofVec2f WorldManager::GetPlayerLocation()
		{
			return m_pPlayerCharacter->GetKinematic()->GetPosition();
		}
	}
}