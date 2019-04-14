#pragma once
#include "Patrol.h"
#include "Tick.h"
#include "../AI/AIController.h"

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
				//game logic
				AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
				float sqDistance = pow((m_pWorldManager.GetPlayerLocation().x - m_pMyController->GetOwner()->GetKinematic()->GetPosition().x), 2) +
					pow((m_pWorldManager.GetPlayerLocation().y - m_pMyController->GetOwner()->GetKinematic()->GetPosition().y), 2);
				if (sqDistance > pow(m_distance, 2))
				{
					i_tick->GetBlackBoard()->SetAction("ActiveAction", m_pAction, 1, m_id);
					return SUCCESS;
				}
				
				return FAILURE;
			}

			Action* Patrol::GetAction()
			{
				return m_pAction;
			}

			void Patrol::SetMyController(AIForGames::AIController* i_controller)
			{
				m_pMyController = i_controller;
			}

			BTStatus Patrol::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				i_tick->GetBlackBoard()->SetTask("RunningTask", this, m_id, m_id);
				return OnExecute(i_tick);				
			}
		}
	}
}