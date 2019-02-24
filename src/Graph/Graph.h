#pragma once
#include "../GameStructs.h"
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
			DirectedWeightedEdge GetOutgoingEdge(int i_node);

		private:
			std::vector<DirectedWeightedEdge* > m_edges;
		};
	}
}