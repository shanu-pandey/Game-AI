#pragma once
#include "Action.h"


namespace AIForGames
{
	namespace DecisionMaking
	{
		Action::Action()
		{
			m_queuedTime = 0.0f;
			m_expiryTime = 1.0f;
			m_priority = 1.0f;
		}
		
		Action::Action(float i_expiryTime, float i_priority)
		{
			m_queuedTime = 0.0f;
			m_expiryTime = i_expiryTime;
			m_priority = i_priority;
		}

		Action::~Action()
		{

		}

		bool Action::CanInterruptAction(Action* i_action)
		{
			return true;
		}

		bool Action::CanDoBoth(Action* i_action)
		{
			return true;
		}

		bool Action::IsComplete()
		{
			return true;
		}

		bool Action::IsHigherPriority(const Action& i_action) const
		{
			return m_priority > i_action.m_priority;
		}
	}
}

