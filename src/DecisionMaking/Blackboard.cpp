#pragma once
#include "Blackboard.h"


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Blackboard::Blackboard()
			{

			}

			Blackboard::~Blackboard()
			{

			}

			void Blackboard::SetAction(char* i_key, Action* i_value, uint8_t i_treeId, uint8_t i_taskID)
			{
				auto it = m_ActionMap.find(i_key);
				if (it != m_ActionMap.end())
					m_ActionMap[i_key] = i_value;
				else
					m_ActionMap.insert(std::make_pair(i_key, i_value));

				/*m_key = i_key;
				m_activeAction = i_value;
				m_treeID = i_treeId;
				m_taskID = i_taskID;*/
			}

			Action* Blackboard::GetAction(char* i_key, uint8_t treeID, uint8_t i_taskID)
			{
				auto it = m_ActionMap.find(i_key);
				if (it != m_ActionMap.end())
					return it->second;
				else
					return nullptr;
			}

			void Blackboard::SetTask(char* i_key, ITask* i_value, uint8_t i_treeId, uint8_t i_taskID)
			{
				auto it = m_TaskMap.find(i_key);
				if (it != m_TaskMap.end())
					m_TaskMap[i_key] = i_value;
				else
					m_TaskMap.insert(std::make_pair(i_key, i_value));

				/*m_key = i_key;
				m_runningTask = i_value;
				m_treeID = i_treeId;
				m_taskID = i_taskID;*/
			}

			ITask* Blackboard::GetTask(char* i_key, uint8_t treeID)
			{
				auto it = m_TaskMap.find(i_key);
				if (it != m_TaskMap.end())
					return it->second;
				else
					return nullptr;
			}

			void Blackboard::SetChild(char* i_key, uint8_t i_value, uint8_t i_treeId)
			{
				m_runningChild = i_value;
			}

			uint8_t Blackboard::GetChild(char* i_key, uint8_t i_treeId)
			{
				return m_runningChild;
			}			
		}
	}
}