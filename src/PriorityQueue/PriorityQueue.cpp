#pragma once
#include "PriorityQueue.h"

namespace AIForGames
{
	void PriorityQueue::Push(NodeRecord i_record)
	{
		m_length++;
	}

	void PriorityQueue::Pop()
	{
		m_length--;
	}
	void PriorityQueue::Remove(NodeRecord i_record)
	{

	}

	bool PriorityQueue::IfExists(NodeRecord i_record)
	{
		bool result = true;

		return result;
	}

	int PriorityQueue::Length()
	{
		return m_length;
	}

	NodeRecord PriorityQueue::GetSmallest()
	{
		NodeRecord smallest = NodeRecord();
		return smallest;
	}

	bool PriorityQueue::Contains(Node i_node)
	{
		bool result = true;

		return result;
	}

	NodeRecord PriorityQueue::Find(Node i_node)
	{
		NodeRecord record = NodeRecord();
		return record;
	}
}