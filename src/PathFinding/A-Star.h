#pragma once
#include "../Graph/Graph.h"
#include <list>
#include "../GameStructs.h"

namespace AIForGames
{
	namespace PathFinding
	{
		class AStar
		{
		public:
			static std::list<DirectedWeightedEdge> FindPath(Node i_startNode, Node i_goalNode, Graph* i_graph);
		};
	}
}
