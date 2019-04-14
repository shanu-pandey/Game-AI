#pragma once
#include "Selector.h"


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
				return SUCCESS;
			}

			BTStatus Selector::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Selector::OnExecute(Tick* i_tick)
			{ 
				return SUCCESS;
			}

			Action* Selector::GetAction()
			{ 
				return m_pAction;
			}

			BTStatus Selector::Run(Tick* i_tick)
			{
				return SUCCESS;
			}
		}
	}
}