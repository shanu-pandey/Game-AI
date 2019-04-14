#pragma once
#include "Action.h"
#include "ITask.h"
#include <map>
#include <string>

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
				void SetChild(char* i_key, uint8_t i_value, uint8_t i_treeId);
				Action* GetAction(char* i_key, uint8_t treeID, uint8_t i_taskID);
				ITask* GetTask(char* i_key, uint8_t treeID);
				uint8_t GetChild(char* i_key, uint8_t i_treeId);

			private:
				Action* m_activeAction;
				uint8_t m_runningChild;
				uint8_t m_taskID;
				uint8_t m_treeID;
				char* m_key;
				std::map<std::string, ITask*> m_TaskMap;
				std::map<std::string, Action*> m_ActionMap;
			};
		}

	}
}