#pragma once
#include "UntilFail.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			UntilFail::UntilFail(uint8_t i_id) : ITask(i_id)
			{	}

			UntilFail::~UntilFail()
			{	}

			BTStatus UntilFail::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus UntilFail::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus UntilFail::OnOpen(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetChild("RunnigChild", 0, m_id);
				return SUCCESS;
			}

			BTStatus UntilFail::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus UntilFail::OnExecute(Tick* i_tick)
			{
				uint8_t runningChild = i_tick->GetBlackBoard()->GetChild("RunnigChild", m_id);
				for (int i = runningChild; i < m_length; i++)
				{
					ITask* childTask = GetChildren()[i];
					BTStatus childStatus = childTask->Run(i_tick);
					if (childStatus != SUCCESS)
					{
						i_tick->GetBlackBoard()->SetAction("ActiveAction", nullptr, 1, m_id);
						return FAILURE;
					}
					i_tick->GetBlackBoard()->SetChild("RunningChild", i, m_id);
					return childStatus;
				}
				return SUCCESS;
			}

			Action* UntilFail::GetAction()
			{
				return nullptr;
			}

			BTStatus UntilFail::Run(Tick* i_tick)
			{
				OnOpen(i_tick);
				return OnExecute(i_tick);
			}
		}
	}
}