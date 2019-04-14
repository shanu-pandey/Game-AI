#pragma once
#include "Sequencer.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Sequencer::Sequencer(uint8_t i_id) : ITask(i_id)
			{	}

			Sequencer::~Sequencer()
			{	}

			BTStatus Sequencer::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Sequencer::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Sequencer::OnOpen(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetChild("RunnigChild", 0, m_id);
				return SUCCESS;
			}

			BTStatus Sequencer::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Sequencer::OnExecute(Tick* i_tick)
			{
				uint8_t runningChild = i_tick->GetBlackBoard()->GetChild("RunnigChild", m_id);
				for (int i = runningChild; i < m_length; i++)
				{
					ITask* childTask = GetChildren()[i];
					BTStatus childStatus = childTask->Run(i_tick);
					if (childStatus != SUCCESS)
					{
						if (childStatus == RUNNING)
						{
							i_tick->GetBlackBoard()->SetChild("RunningChild", i, m_id);
						}
						return childStatus;
					}
				}
				return SUCCESS;
			}

			Action* Sequencer::GetAction()
			{
				return nullptr;
			}

			BTStatus Sequencer::Run(Tick* i_tick)
			{
				OnOpen(i_tick);
				return OnExecute(i_tick);
			}
		}
	}
}