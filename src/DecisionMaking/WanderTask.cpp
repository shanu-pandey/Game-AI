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

			void WanderTask::OnEnter(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetAction("ActiveAction", m_pAction, 1, m_id);
			}

			void WanderTask::OnExit(Tick* i_tick)
			{

			}

			void WanderTask::OnOpen(Tick* i_tick)
			{

			}

			void WanderTask::OnClose(Tick* i_tick)
			{

			}

			void WanderTask::OnExecute(Tick* i_tick)
			{
				
			}

			Action* WanderTask::GetAction()
			{
				return m_pAction;
			}

			void WanderTask::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				OnExecute(i_tick);
			}
		}
	}
}