#pragma once
#include "Action.h"
#include "ITask.h"
#include <map>

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Blackboard
			{
			public:
				Blackboard();
				~Blackboard();
				void SetAction(char* i_key, Action* i_value, uint8_t i_treeId, uint8_t i_taskID);
				void SetTask(char* i_key, ITask* i_value, uint8_t i_treeId, uint8_t i_taskID);
				Action* GetAction(char* i_key, uint8_t treeID, uint8_t i_taskID);
				ITask* GetTask(char* i_key, uint8_t treeID);
			private:
				Action* m_activeAction;
				ITask* m_runningTask;
				uint8_t m_taskID;
				uint8_t m_treeID;
				char* m_key;
				std::map<char*, ITask*> m_TaskMap;
				std::map<char*, Action*> m_ActionMap;
			};
		}

	}
}