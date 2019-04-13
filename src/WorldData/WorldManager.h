#pragma once
#include "../GameObject/GameObject.h"
#include "../Graph/TileMap.h"
#include "ofVec2f.h"
#include <vector>

using namespace std;

namespace AIForGames
{
	namespace WorldData
	{
		class WorldManager
		{
		public:
			WorldManager(const WorldManager&) = delete;
			~WorldManager();
			static WorldManager& Get();
			void RegisterPlayerCharacter(AIForGames::GameObject* i_player);
			void RegisterNPC(AIForGames::GameObject* i_NPC);
			void SetWorldMap(AIForGames::PathFinding::TileMap* i_pWorldMap);
			AIForGames::PathFinding::TileMap* GetWorldMap();
			ofVec2f GetPlayerLocation();
			AIForGames::GameObject* GetPlayerCharacter();


		private:
			WorldManager();
			AIForGames::GameObject* m_pPlayerCharacter;
			AIForGames::PathFinding::TileMap* m_pWorldMap;
			std::vector<AIForGames::GameObject*> m_pNPCList;
		};
	}
}