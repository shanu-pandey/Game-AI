#pragma once
#include "ActionManager.h"

namespace AIForGames 
{
	namespace DecisionMaking
	{
		ActionManager::ActionManager()
		{

		}

		ActionManager::~ActionManager()
		{

		}

		void ActionManager::AddToPending(Action* i_action)
		{
			m_pending.emplace(i_action);
		}
		
		void ActionManager::RemoveFromPending(Action* i_action)
		{
			m_pending.pop();
		}

		void ActionManager::AddToActive(Action* i_action)
		{
			m_active.emplace(i_action);
		}

		void ActionManager::RemoveFromActive(Action* i_action)
		{
			m_active.pop();
		}

		void ActionManager::Update()
		{

		}
	}
}