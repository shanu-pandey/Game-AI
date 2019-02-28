#pragma once
#include <vector>
#include "ofVec2f.h"
#include "Graph.h"
#include "Tile.h"

namespace AIForGames
{
	namespace PathFinding
	{
		class TileMap
		{
		public:
			TileMap();
			TileMap(int i_numberOfObstacles, std::vector<ofVec2f> m_obstaclePos, std::vector<float> m_obstacleWidth, std::vector<float> m_obstacleHeight);
			~TileMap();		
			int GetTileIndex(ofVec2f i_worldPosition);
			ofVec2f GetWorldPoint(int i_tileNumber);
			Tile* GetTile(int i_index);
			Graph* GetGraph();

		private:			
			void SetObstaclesTiles(int i_numberOfObstacles, std::vector<ofVec2f> m_obstaclePos, std::vector<float> m_obstacleWidth, std::vector<float> m_obstacleHeight);
			void GenerateGraph();
			int m_tileWidth = 16;
			int m_tileHeight = 16;
			int m_totalTiles;
			std::vector<Tile*> m_Tiles;
			AIForGames::PathFinding::Graph* m_pGraph;
		};
	}
}