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
			//std::push_heap(begin(m_pending), end(m_pending), ComparerFunctor());
		}
		
		void ActionManager::RemoveFromPending(Action* i_action)
		{
			m_pending.pop_back();
		}

		void ActionManager::AddToActive(Action* i_action)
		{
			i_action->Restart();
			m_active.push_back(i_action);
			//std::push_heap(begin(m_active), end(m_active), ComparerFunctor());
		}

		void ActionManager::RemoveFromActive(Action* i_action)
		{
			m_active.pop_back();
		}

		void ActionManager::Update(float i_dt)
		{
			//PendingQueueUpdate(i_dt);
			//ActiveQueueUpdate(i_dt);

			auto &it1 = m_pending.begin();
			while (it1 != m_pending.end())
			{
				(*it1)->IncrementQueuedTime(i_dt);
				float topRunningPriority = -1;
				if (m_active.size() > 0)
					float topRunningPriority = m_active[0]->GetPriority();

				if (topRunningPriority > (*it1)->GetPriority())
				{
					break;
				}

				if ((*it1)->CanInterrupt())
				{
					m_active.clear();
					AddToActive(*it1);
					it1 = m_pending.erase(it1);
				}
			}

			auto &it = m_pending.begin();
			while (it != m_pending.end())
			{
				if ((*it)->GetQueuedTime() > (*it)->GetExpiryTime())
				{
					it = m_pending.erase(it);
				}

				for (auto &itActive : m_active)
				{
					if (!(*it)->CanDoBoth(itActive))
					{
						++it;
						continue;
					}
					m_pending.erase(it);
					AddToActive(*it);
				}
			}

			auto &it2 = m_active.begin();
			while (it2 != m_active.end())
			{
				if ((*it2)->IsComplete())
				{
					it2 = m_active.erase(it2);
					//++it;
				}
				else
				{
					(*it2)->Update();
					++it2;
				}
			}
		}

		void ActionManager::PendingQueueUpdate(float i_dt)
		{
			float topRunningPriority = -1;

			auto &it = m_pending.begin();
			while (it != m_pending.end())
			{
				(*it)->IncrementQueuedTime(i_dt);
				if (m_active.size() > 0)
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
					++it;
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
					it = m_active.erase(it);
					//++it;
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