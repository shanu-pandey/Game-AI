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
			WorldManager();
			~WorldManager();
			void RegisterPlayerCharacter(AIForGames::GameObject* i_player);
			void RegisterNPC(AIForGames::GameObject* i_NPC);
			ofVec2f GetPlayerLocation();

		private:
			AIForGames::GameObject* m_pPlayerCharacter;
			AIForGames::PathFinding::TileMap* m_pWorldMap;
			std::vector<AIForGames::GameObject*> m_pNPCList;
		};
	}
}