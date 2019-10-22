#pragma once
#include "MapManager.h"
#include "math\ofMath.h"
#include <algorithm>

CollisionCheck::MapManager::MapManager()
{
	CreateWorld(800, 600);
}

CollisionCheck::MapManager::~MapManager()
{
}

void CollisionCheck::MapManager::CreateWorld(int i_width, int i_height)
{
	int cols = i_width / CELLSIZE;
	int rows = i_height / CELLSIZE;

	/*for (int i = 0; i < cols*rows; i++)
	{
		m_buckets[i].insert(new std::list<AIForGames::GameObject>);
	}*/

}

void CollisionCheck::MapManager::ClearBuckets()
{
	int cols = m_width / CELLSIZE;
	int rows = m_height / CELLSIZE;

	for (int i = 0; i < cols*rows; i++)
		m_buckets[i].clear();	
}

void CollisionCheck::MapManager::RegisterGameObject(AIForGames::GameObject * i_obj)
{
	std::list<int> cellIds = GetIDsToAdd(i_obj);
	for (int id : cellIds)
		m_buckets[id].push_back(i_obj);
}

std::list<int> CollisionCheck::MapManager::GetIDsToAdd(AIForGames::GameObject * i_obj)
{
	std::list<int> result;

	ofVec2f min = ofVec2f(i_obj->GetKinematic()->GetPosition().x - i_obj->Getradius(),
		i_obj->GetKinematic()->GetPosition().y - i_obj->Getradius());

	ofVec2f max = ofVec2f(i_obj->GetKinematic()->GetPosition().x + i_obj->Getradius(),
		i_obj->GetKinematic()->GetPosition().y + i_obj->Getradius());

	float width = m_width / CELLSIZE;
	AddBucket(min, width, result);
	AddBucket(max, width, result);
	AddBucket(ofVec2f(min.x, max.y), width, result);
	AddBucket(ofVec2f(max.x, min.y), width, result);

	return result;
}

void CollisionCheck::MapManager::AddBucket(ofVec2f i_pos, float i_width, std::list<int>& i_bucket)
{
	int cellPos = (int)((floor(i_pos.x / CELLSIZE)) + ((floor(i_pos.y / CELLSIZE))*i_width));
	bool found = (std::find(i_bucket.begin(), i_bucket.end(), cellPos) != i_bucket.end());

	if (!found)
		i_bucket.push_back(cellPos);
}

std::list<AIForGames::GameObject*> CollisionCheck::MapManager::GetNearby(AIForGames::GameObject * i_obj)
{
	std::list<AIForGames::GameObject*> result;
	std::list<int> id = GetIDsToAdd(i_obj);
	for (int i : id)
	{
		for (AIForGames::GameObject* obj : m_buckets[i])
			result.push_back(obj);
	}
	return result;
}
