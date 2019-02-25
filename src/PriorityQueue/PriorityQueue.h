#pragma once
#include "../GameStructs.h"

namespace AIForGames
{
	class PriorityQueue
	{
	public:
		void Push(NodeRecord i_record);
		void Pop();
		void Remove(NodeRecord i_record);
		bool IfExists(NodeRecord i_record);
		int Length();
		NodeRecord GetSmallest();
		bool Contains(Node i_node);
		NodeRecord Find(Node i_node);
				
	private:
		std::vector<NodeRecord*> m_Queue;
		int m_length = 0;
	};
}