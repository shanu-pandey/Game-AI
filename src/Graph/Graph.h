#pragma once
#include "../GameStructs.h"
#include "../Graph/IHeuristics.h"
#include <vector>
namespace AIForGames
{
	namespace PathFinding
	{
		class Graph
		{
		public:
			Graph();
			~Graph();			
			std::vector<DirectedWeightedEdge*> GetConnections(Node i_nodeRecord);
			AIForGames::IHeuristics* GetHeuristics();
		private:
			std::vector<DirectedWeightedEdge*> m_edges;
			AIForGames::IHeuristics* m_pHeuristics;

		};
	}
}