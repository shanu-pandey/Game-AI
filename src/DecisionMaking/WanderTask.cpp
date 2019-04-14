#pragma once
#include "WanderTask.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{			
			WanderTask::~WanderTask()
			{

			}

			BTStatus WanderTask::OnEnter(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetAction("ActiveAction", m_pAction, 1, m_id);
				return SUCCESS;
			}

			BTStatus WanderTask::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus WanderTask::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus WanderTask::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus WanderTask::OnExecute(Tick* i_tick)
			{
				return SUCCESS;
			}

			Action* WanderTask::GetAction()
			{
				return m_pAction;
			}

			BTStatus WanderTask::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				return OnExecute(i_tick);

			}
		}
	}
}