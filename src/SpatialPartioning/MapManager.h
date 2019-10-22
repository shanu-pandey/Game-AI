#pragma once
#include <map>
#include <list>
#include "../GameObject/GameObject.h"
namespace CollisionCheck
{
	class MapManager
	{
	public:
		MapManager();
		~MapManager();
		void CreateWorld(int i_width, int i_height);
		void ClearBuckets();
		void RegisterGameObject(AIForGames::GameObject* i_obj);
		std::list<int> GetIDsToAdd(AIForGames::GameObject* i_obj);
		void AddBucket(ofVec2f i_pos, float i_width, std::list<int>& i_bucket);
		std::list<AIForGames::GameObject*> GetNearby(AIForGames::GameObject* i_obj);


	private:
		int m_width;
		int m_height;
		const uint8_t CELLSIZE = 10;
		std::map<int, std::list<AIForGames::GameObject*>> m_buckets;
	};
}