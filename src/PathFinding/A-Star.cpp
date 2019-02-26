#pragma once
#include "A-Star.h"
#include "../PriorityQueue/PriorityQueue.h"
namespace AIForGames
{
	namespace PathFinding
	{
		std::vector<DirectedWeightedEdge> AStar::FindPath(Node i_startNode, Node i_goalNode, Graph* i_graph)
		{
			std::vector<DirectedWeightedEdge> o_path;

			NodeRecord startRecord = NodeRecord();
			startRecord.node = i_startNode;
			startRecord.incomingEdge = DirectedWeightedEdge();
			startRecord.costSoFar = 0;
			startRecord.estimatedTotalCost = i_graph->GetHeuristics()->GetEstimate(i_startNode, i_goalNode);

			PriorityQueue open;
			open.PushEstimatedCost(&startRecord);
			PriorityQueue closed;
			NodeRecord current; 

			while (open.Length() > 0)
			{
				current = open.GetSmallest();
				if (current.node.index == i_goalNode.index)
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
						//NodeRecord endNodeRecord = NodeRecord(endNode, )
						if (closed.Contains(endNode))
						{
							NodeRecord endNodeRecord = closed.Find(endNode);
							if (endNodeRecord.costSoFar <= endNodeCost)
							{
								continue;
							}
							else
							{
								closed.Remove(endNodeRecord);
								float endNodeHeuristics = endNodeRecord.incomingEdge.cost - endNodeRecord.costSoFar;
							}
						}
						else if (open.Contains(endNode))
						{
							NodeRecord endNodeRecord = open.Find(endNode);
							if (endNodeRecord.costSoFar <= endNodeCost)
							{
								continue;
							}
							float endNodeHeuristics = i_graph->GetHeuristics()->GetEstimate(endNode, i_goalNode);
						}
						else
						{
							NodeRecord* endNodeRecord = new NodeRecord();
							endNodeRecord->node = endNode;
							float endNodeHeuristics = i_graph->GetHeuristics()->GetEstimate(endNode, i_goalNode);
							endNodeRecord->incomingEdge = *(*it);
							endNodeRecord->costSoFar = endNodeCost;
							endNodeRecord->estimatedTotalCost = endNodeCost + endNodeHeuristics;

							open.PushEstimatedCost(endNodeRecord);
						}
						open.Remove(current);
						NodeRecord* p = new NodeRecord(current.node, current.incomingEdge, current.costSoFar, current.estimatedTotalCost);
						closed.PushEstimatedCost(p);
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