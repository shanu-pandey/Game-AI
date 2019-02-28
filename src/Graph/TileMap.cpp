#pragma once
#include "TileMap.h"

namespace AIForGames
{
	namespace PathFinding
	{
		TileMap::TileMap()
		{

		}

		TileMap::TileMap(int i_numberOfObstacles, std::vector<ofVec2f> i_obstaclePos, std::vector<float> i_obstacleWidth, std::vector<float> i_obstacleHeight)
		{
			m_pGraph = new Graph();
			int index = 0;
			m_totalTiles = (1024 / m_tileWidth) * (768 / m_tileHeight);
			m_Tiles.reserve(m_totalTiles);

			for (int i = 0; i < 768; i = i+m_tileHeight)
			{
				for (int j = 0; j < 1024; j = j + m_tileWidth)
				{
					Tile* tile = new Tile(index, ofVec2f(j + m_tileWidth/2, i + m_tileHeight/2), true);
					m_Tiles.emplace_back(tile);
					index++;
				}
			}
			SetObstaclesTiles(i_numberOfObstacles, i_obstaclePos, i_obstacleWidth, i_obstacleHeight);
			GenerateGraph();
		}

		TileMap::~TileMap()
		{

		}

		int TileMap::GetTileIndex(ofVec2f i_worldPosition)
		{
			int o_tile = 0;
			int yDivisions = 768 / m_tileHeight;
			int xDivisions = 1024 / m_tileWidth;
			int xIndex = 0;
			int yIndex = 0;
			ofVec2f temp = i_worldPosition;

			while (temp.x - m_tileWidth > 0)
			{
				temp.x -= m_tileWidth;
				xIndex++;
			}

			while (temp.y - m_tileHeight > 0)
			{
				temp.y -= m_tileHeight;
				yIndex++;
			}

			o_tile = xDivisions * yIndex + xIndex;

			return o_tile;
		}

		ofVec2f TileMap::GetWorldPoint(int i_tileNumber)
		{
			ofVec2f o_tilePos = ofVec2f(0, 0);

			return o_tilePos;
		}

		Graph* TileMap::GetGraph()
		{
			return m_pGraph;
		}

		Tile* TileMap::GetTile(int i_index)
		{
			return m_Tiles[i_index];
		}


		void TileMap::SetObstaclesTiles(int i_numberOfObstacles, std::vector<ofVec2f> i_obstaclePos, std::vector<float> i_obstacleWidth, std::vector<float> i_obstacleHeight)
		{
			for (int i = 0; i < i_numberOfObstacles; i++)
			{
				float obstacleWidth = i_obstacleWidth[i];
				float obstacleHeight = i_obstacleHeight[i];
				ofVec2f obstaclePos = i_obstaclePos[i];
				int temp = 0;
				while (temp <= obstacleWidth)
				{
					if (obstaclePos.x >= 1024)
						break;

					Tile* tile = GetTile(GetTileIndex(obstaclePos));
					tile->SetWalkable(false);
					temp += m_tileWidth;
					obstaclePos.x += m_tileWidth;
				}

				obstaclePos = i_obstaclePos[i];
				temp = 0;
				while (temp <= obstacleHeight)
				{
					if (obstaclePos.y >= 728)
						break;

					Tile* tile = GetTile(GetTileIndex(obstaclePos));
					tile->SetWalkable(false);
					temp += m_tileHeight;
					obstaclePos.y += m_tileHeight;
				}
			}
		}

		void TileMap::GenerateGraph()
		{
			int yDivisions = 768 / m_tileHeight;
			int xDivisions = 1024 / m_tileWidth;
			bool bUpAdded = false;
			bool bDownAdded = false;

			for (int i = m_totalTiles - 1; i >= 0; i--)
			{
				bUpAdded = false;
				bDownAdded = false;
				//left node check
				if (m_Tiles[i]->IsWalkable())
				{
					if (m_Tiles[i]->GetPosition().x - m_tileWidth > 0)
					{
						//left exists
						//left DWE added
						if (m_Tiles[i - 1]->IsWalkable())
						{
							DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i - 1, m_Tiles[i - 1]->GetPosition()));
							m_pGraph->AddEdge(dwe);
						}
						//do up down check
						if (m_Tiles[i]->GetPosition().y - m_tileHeight > 0)
						{
							//up exists
							//up DWE added
							if (m_Tiles[i - yDivisions]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i - yDivisions, m_Tiles[i - yDivisions]->GetPosition()));
								m_pGraph->AddEdge(dwe);
								bUpAdded = true;
							}
							//up-left DWE added
							if (m_Tiles[i - yDivisions -1]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(6, Node(i, m_Tiles[i]->GetPosition()), Node(i - yDivisions - 1, m_Tiles[i - yDivisions - 1]->GetPosition()));
								m_pGraph->AddEdge(dwe);
							}
						}

						if (m_Tiles[i]->GetPosition().y + m_tileHeight < 768)
						{
							//down exists						
							//down DWE added
							if (m_Tiles[i + yDivisions]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i + yDivisions, m_Tiles[i + yDivisions]->GetPosition()));
								m_pGraph->AddEdge(dwe);
								bDownAdded = true;
							}
							//down-left DWE added
							if (m_Tiles[i + yDivisions - 1]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(6, Node(i, m_Tiles[i]->GetPosition()), Node(i + yDivisions - 1, m_Tiles[i + yDivisions - 1]->GetPosition()));
								m_pGraph->AddEdge(dwe);
							}
						}

					}

					//right node check
					if (m_Tiles[i]->GetPosition().x + m_tileWidth < 1024)
					{
						//right exists
						//right DWE added
						if (m_Tiles[i + 1]->IsWalkable())
						{
							DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i + 1, m_Tiles[i + 1]->GetPosition()));
							m_pGraph->AddEdge(dwe);
						}
						//do up down check
						if (m_Tiles[i]->GetPosition().y - m_tileHeight > 0)
						{
							//up exists
							//up DWE added
							if (!bUpAdded)
							{
								if (m_Tiles[i - yDivisions]->IsWalkable())
								{
									DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i - yDivisions, m_Tiles[i - yDivisions]->GetPosition()));
									m_pGraph->AddEdge(dwe);
								}
							}

							//up-right DWE added
							if (m_Tiles[i - yDivisions +1]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(6, Node(i, m_Tiles[i]->GetPosition()), Node(i - yDivisions + 1, m_Tiles[i - yDivisions + 1]->GetPosition()));
								m_pGraph->AddEdge(dwe);
							}
						}

						if (m_Tiles[i]->GetPosition().y + m_tileHeight < 768)
						{
							//down exists
							//up DWE added
							if (!bDownAdded)
							{
								if (m_Tiles[i + yDivisions]->IsWalkable())
								{
									DirectedWeightedEdge* dwe = new DirectedWeightedEdge(4, Node(i, m_Tiles[i]->GetPosition()), Node(i + yDivisions, m_Tiles[i + yDivisions]->GetPosition()));
									m_pGraph->AddEdge(dwe);
								}
							}

							//down-right DWE added
							if (m_Tiles[i + yDivisions +1]->IsWalkable())
							{
								DirectedWeightedEdge* dwe = new DirectedWeightedEdge(6, Node(i, m_Tiles[i]->GetPosition()), Node(i + yDivisions + 1, m_Tiles[i + yDivisions + 1]->GetPosition()));
								m_pGraph->AddEdge(dwe);
							}
						}
					}
				}
			}

		}
	}
}