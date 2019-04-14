#pragma once
#include "Selector.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Selector::Selector(uint8_t i_id) : ITask(i_id)
			{	}

			Selector::~Selector()
			{	}

			void Selector::SetAction(Action * i_pAction)
			{
				
			}

			BTStatus Selector::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Selector::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Selector::OnOpen(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetChild("RunnigChild", 0, m_id);
				return SUCCESS;
			}

			BTStatus Selector::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Selector::OnExecute(Tick* i_tick)
			{ 
				uint8_t runningChild = i_tick->GetBlackBoard()->GetChild("RunnigChild", m_id);
				for (int i = runningChild; i < m_length; i++)
				{
					ITask* childTask = GetChildren()[i];
					BTStatus childStatus = childTask->Run(i_tick);
					if (childStatus != FAILURE)
					{
						if (childStatus == RUNNING)
						{
							i_tick->GetBlackBoard()->SetChild("RunningChild", i, m_id);
						}
						return childStatus;
					}
				}
				return FAILURE;	
			}

			Action* Selector::GetAction()
			{ 
				return m_pAction;
			}

			BTStatus Selector::Run(Tick* i_tick)
			{
				OnOpen(i_tick);
				return OnExecute(i_tick);
			}
		}
	}
}