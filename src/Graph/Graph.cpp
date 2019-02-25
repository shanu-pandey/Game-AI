#pragma once
#include "Graph.h"
#include "../Graph/EuclidianHeuristics.h"

namespace AIForGames
{
	namespace PathFinding
	{
		Graph::Graph()
		{
			m_pHeuristics = new AIForGames::EuclidianHeuristics();
		}
		
		Graph::~Graph()
		{

		}
		
		std::vector<DirectedWeightedEdge*> Graph::GetConnections(Node i_nodeRecord)
		{
			std::vector<DirectedWeightedEdge*> o_Connections;

			for (std::vector<DirectedWeightedEdge*>::iterator it = m_edges.begin(); it != m_edges.end(); ++it)
			{
				if ((*it)->source.index == i_nodeRecord.index)
				{
					o_Connections.emplace_back(*it);
				}
			}
			return o_Connections;
		}

		AIForGames::IHeuristics* Graph::GetHeuristics()
		{
			return m_pHeuristics;
		}

	}
}