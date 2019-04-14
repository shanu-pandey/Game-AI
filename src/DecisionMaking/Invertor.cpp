#pragma once
#include "Invertor.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Invertor::Invertor(uint8_t i_id) : ITask(i_id)
			{	}

			Invertor::~Invertor()
			{	}

			BTStatus Invertor::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Invertor::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Invertor::OnOpen(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetChild("RunningChild", 0, m_id);
				return SUCCESS;
			}

			BTStatus Invertor::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Invertor::OnExecute(Tick* i_tick)
			{
				BTStatus childStatus = m_childList[0]->Run(i_tick);
				if (childStatus == FAILURE)
					return SUCCESS;
				else
				{
					i_tick->GetBlackBoard()->SetAction("ActiveAction", nullptr, 1, m_id);
					return FAILURE;
				}
					
			}

			Action* Invertor::GetAction()
			{
				return nullptr;
			}

			BTStatus Invertor::Run(Tick* i_tick)
			{
				OnOpen(i_tick);
				return OnExecute(i_tick);
			}

			void Invertor::AddChild(ITask* i_task)
			{
				m_childList.emplace_back(i_task);
				m_length++;
			}

			uint8_t Invertor::Length()
			{
				return m_length;
			}

			std::vector<ITask*> Invertor::GetChildren()
			{
				return m_childList;
			}
		}
	}
}