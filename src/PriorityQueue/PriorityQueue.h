#pragma once
#include "../GameStructs.h"
#include <list>

namespace AIForGames
{
	class PriorityQueue
	{
	public:
		void PushCostSoFar(NodeRecord* i_record);
		void PushEstimatedCost(NodeRecord* i_record);
		void Pop();
		void Remove(NodeRecord i_record);
		bool IfExists(NodeRecord i_record);
		int Length();
		NodeRecord GetSmallest();
		bool Contains(Node i_node);
		NodeRecord Find(Node i_node);
				
	private:
		std::list<NodeRecord*> m_Queue;
		int m_length = 0;
	};
}