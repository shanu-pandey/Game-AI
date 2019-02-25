#pragma once
#include "../Graph/Graph.h"
#include <vector>
#include "../GameStructs.h"

namespace AIForGames
{
	namespace PathFinding
	{
		class AStar
		{
		public:
			static std::vector<DirectedWeightedEdge> FindPath(Node i_startNode, Node i_goalNode, Graph* i_graph);
		};
	}
}
