#pragma once
#include "Dijkstra.h"
#include "../PriorityQueue/PriorityQueue.h"


namespace AIForGames
{
	namespace PathFinding
	{
		std::vector<DirectedWeightedEdge> Dijkstra::FindPath(Node i_startNode, Node i_goalNode, Graph* i_graph)
		{
			std::vector<DirectedWeightedEdge> o_path;

			NodeRecord startRecord = NodeRecord();
			startRecord.node = i_startNode;
			startRecord.incomingEdge = DirectedWeightedEdge();
			startRecord.costSoFar = 0;

			PriorityQueue open;
			open.PushCostSoFar(&startRecord);
			PriorityQueue closed;
			NodeRecord current;

			while (open.Length() > 0)
			{
				current = open.GetSmallest();
				if (current.node.index = i_goalNode.index)
				{
					break;				
				}
				else
				{
					std::vector<DirectedWeightedEdge*> connections = i_graph->GetConnections(current.node);
					for (std::vector<DirectedWeightedEdge*>::iterator it = connections.begin(); it != connections.end(); ++it)
					{
						Node endNode = (*it)->sink;
						float endNodeCost = current.costSoFar + (*it)->cost;
						if (closed.Contains(endNode))
						{
							continue;
						}
						else if (open.Contains(endNode))
						{
							NodeRecord endNodeRecord = open.Find(endNode);
							if (endNodeRecord.costSoFar <= endNodeCost)
							{
								continue;
							}
						}
						else
						{
							NodeRecord endNodeRecord = NodeRecord();
							endNodeRecord.node = endNode;
							endNodeRecord.costSoFar = endNodeCost;
							endNodeRecord.incomingEdge = *(*it);

							if (!(open.Contains(endNode)))
							{
								open.PushCostSoFar(&endNodeRecord);
							}
						}
						open.Remove(current);
						closed.PushCostSoFar(&current);
					}
				}
			}
			if (current.node.index != i_goalNode.index)
			{
			}
			else
			{
				while (current.node.index != i_startNode.index)
				{
					o_path.emplace_back(current.incomingEdge);
					current.node = current.incomingEdge.source;
				}
				return o_path;
			}
		}
	}
}
