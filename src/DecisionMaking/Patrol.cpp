#pragma once
#include "Patrol.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			Patrol::Patrol(uint8_t i_id, uint8_t i_Points): ITask(i_id), m_patrolPointsCount(i_Points)
			{	}
			
			Patrol::~Patrol()
			{

			}

			void Patrol::AddPatrolPoint(Node* i_point)
			{
				m_pPatrolPoints.emplace_back(i_point);
				m_patrolPointsCount++;
			}	

			uint8_t Patrol::GetCount()
			{
				return m_patrolPointsCount;
			}

			void Patrol::SetAction(Action * i_pAction)
			{
				m_pAction = i_pAction;
			}


			BTStatus Patrol::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Patrol::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Patrol::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Patrol::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus Patrol::OnExecute(Tick* i_tick)
			{
				i_tick->GetBlackBoard()->SetTask("RunnigTask", this, m_id, m_id);
				i_tick->GetBlackBoard()->SetAction("ActiveAction", m_pAction, 1, m_id);
				return SUCCESS;
			}

			Action* Patrol::GetAction()
			{
				return m_pAction;
			}

			BTStatus Patrol::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				return OnExecute(i_tick);				
			}
		}
	}
}