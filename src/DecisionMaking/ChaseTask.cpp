#pragma once
#include "ChaseTask.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			ChaseTask::~ChaseTask()
			{

			}

			BTStatus ChaseTask::OnEnter(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetAction("ActiveAction", m_pAction, 1, m_id);
				return SUCCESS;
			}

			BTStatus ChaseTask::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus ChaseTask::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus ChaseTask::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus ChaseTask::OnExecute(Tick* i_tick)
			{
				return SUCCESS;
			}

			Action* ChaseTask::GetAction()
			{
				return m_pAction;
			}

			BTStatus ChaseTask::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				return OnExecute(i_tick);

			}
		}
	}
}