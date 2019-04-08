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
			m_pending.push_back(i_action);
			std::push_heap(begin(m_pending), end(m_pending), ComparerFunctor());
		}
		
		void ActionManager::RemoveFromPending(Action* i_action)
		{
			m_pending.pop_back();
		}

		void ActionManager::AddToActive(Action* i_action)
		{
			m_active.push_back(i_action);
			std::push_heap(begin(m_active), end(m_active), ComparerFunctor());
		}

		void ActionManager::RemoveFromActive(Action* i_action)
		{
			m_active.pop_back();
		}

		void ActionManager::Update(float i_dt)
		{
			PendingQueueUpdate(i_dt);
			ActiveQueueUpdate(i_dt);
		}

		void ActionManager::PendingQueueUpdate(float i_dt)
		{
			float topRunningPriority = -1;

			auto &it = m_pending.begin();
			while (it != m_pending.end())
			{
				(*it)->IncrementQueuedTime(i_dt);
				if (m_active[0] != nullptr)
					float topRunningPriority = m_active[0]->GetPriority();

				if (topRunningPriority > (*it)->GetPriority())
				{
					++it;
					//continue;
				}
				else if ((*it)->CanInterrupt())
				{
					m_active.clear();
					AddToActive(*it);
					++it;
				}
			}

			it = m_pending.begin();
			while (it != m_pending.end())
			{
				if ((*it)->GetQueuedTime() > (*it)->GetExpiryTime())
				{
					m_pending.erase(it);
				}
				else
				{
					for (auto &itActive : m_active)
					{
						if (!(*it)->CanDoBoth(itActive))
						{
							++itActive;
							continue;
						}
					}
					AddToActive(*it);
					m_pending.erase(it);
				}
			}
		}

		void ActionManager::ActiveQueueUpdate(float i_dt)
		{
			auto &it = m_active.begin();
			while (it != m_active.end())
			{
				if ((*it)->IsComplete())
				{
					m_active.erase(it);
				}
				else
				{
					(*it)->Update();
					++it;
				}
			}
		}

	}
}