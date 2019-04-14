#pragma once
#include "BT_DistanceFromPlayer.h"
#include "Tick.h"
#include "../WorldData/WorldManager.h"
#include "../AI/AIController.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			BT_DistanceFromPlayer::BT_DistanceFromPlayer(uint8_t i_id) : ITask(i_id)
			{	}

			BT_DistanceFromPlayer::~BT_DistanceFromPlayer()
			{

			}

			BTStatus BT_DistanceFromPlayer::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus BT_DistanceFromPlayer::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus BT_DistanceFromPlayer::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus BT_DistanceFromPlayer::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus BT_DistanceFromPlayer::OnExecute(Tick* i_tick)
			{
				AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
				float sqDistance = pow((m_pWorldManager.GetPlayerLocation().x - m_pMyController->GetOwner()->GetKinematic()->GetPosition().x), 2) +
					pow((m_pWorldManager.GetPlayerLocation().y - m_pMyController->GetOwner()->GetKinematic()->GetPosition().y), 2);
				if (sqDistance > pow(m_distance, 2))
				{
					i_tick->GetBlackBoard()->SetAction("ActiveAction", nullptr, 1, m_id);
					return FAILURE;

				}
					
				
				return SUCCESS;
			}
		
			void BT_DistanceFromPlayer::SetMyController(AIController* i_controller)
			{
				m_pMyController = i_controller;
			}

			BTStatus BT_DistanceFromPlayer::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				i_tick->GetBlackBoard()->SetTask("RunningTask", this, m_id, m_id);
				return OnExecute(i_tick);
			}

			Action* BT_DistanceFromPlayer::GetAction()
			{
				return nullptr;
			}
		}
	}
}