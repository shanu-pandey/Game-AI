#pragma once
#include "PriorityQueue.h"

namespace AIForGames
{
	void PriorityQueue::PushCostSoFar(NodeRecord* i_record)
	{
		bool bInsert = false;

		if (m_length > 0)
		{
			int index = 0;
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if ((*it)->costSoFar < i_record->costSoFar)
				{
					m_Queue.insert(it, i_record);
					bInsert = true;
					break;
				}
			}
		}
		else
		{
			m_Queue.emplace_back(i_record);
			bInsert = true;
		}

		if (!bInsert)
			m_Queue.emplace_back(i_record);

		m_length++;
	}

	void PriorityQueue::PushEstimatedCost(NodeRecord* i_record)
	{
		bool bInsert = false;

		if (m_length > 0)
		{
			int index = 0;
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if ((*it)->estimatedTotalCost < i_record->estimatedTotalCost)
				{
					m_Queue.insert(it, i_record);
					bInsert = true;
					break;
				}
			}
		}
		else
		{
			m_Queue.emplace_back(i_record);
			bInsert = true;
		}

		if (!bInsert)
			m_Queue.emplace_back(i_record);

		m_length++;
	}

	void PriorityQueue::Pop()
	{
		if (m_length > 0)
		{
			m_Queue.pop_front();
		}
		m_length--;
	}

	void PriorityQueue::Remove(NodeRecord i_record)
	{
		if (m_length > 0)
		{
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if (*(*it) == i_record)
				{
					it = m_Queue.erase(it);
					m_length--;
					break;
				}
			}
		}
	}

	bool PriorityQueue::IfExists(NodeRecord i_record)
	{
		bool result = false;

		if (m_length > 0)
		{
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if (*(*it) == i_record)
				{
					result = true;
					break;
				}
			}
		}
		return result;
	}

	int PriorityQueue::Length()
	{
		return m_length;
	}

	NodeRecord PriorityQueue::GetSmallest()
	{
		NodeRecord* smallest = m_Queue.back();
		return *smallest;

		//NodeRecord smallest = NodeRecord();
		//return smallest;
	}

	bool PriorityQueue::Contains(Node i_node)
	{
		bool result = false;

		if (m_length > 0)
		{
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if ((*it)->node == i_node)
				{
					result = true;
					break;
				}
			}
		}
		return result;
	}

	NodeRecord* PriorityQueue::Find(Node i_node)
	{
		NodeRecord* record = new NodeRecord();

		if (m_length > 0)
		{
			for (std::list<NodeRecord*>::iterator it = m_Queue.begin(); it != m_Queue.end(); ++it)
			{
				if ((*it)->node == i_node)
				{
					record = (*it);
					break;
				}
			}
		}
		return record;

		/*NodeRecord smallest = NodeRecord();
		return smallest;*/
	}
}