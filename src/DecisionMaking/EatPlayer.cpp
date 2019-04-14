#pragma once
#include "EatPlayer.h"
#include "Tick.h"
#include "../WorldData/WorldManager.h"
#include "../AI/AIController.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			EatPlayer::EatPlayer(uint8_t i_id) : ITask(i_id)
			{	}

			EatPlayer::~EatPlayer()
			{

			}

			BTStatus EatPlayer::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus EatPlayer::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus EatPlayer::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus EatPlayer::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus EatPlayer::OnExecute(Tick* i_tick)
			{
				AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
				float health = m_pWorldManager.GetPlayerCharacter()->GetHealth();
				health -= m_damage;
				
				
				//works as sanity check
				if (health < 0)
				{
					return FAILURE;
				}		
				else
				{
					m_pWorldManager.GetPlayerCharacter()->SetHealth(health);
					return SUCCESS;
				}
				
			}

			void EatPlayer::SetMyController(AIController* i_controller)
			{
				m_pMyController = i_controller;
			}

			void EatPlayer::SetDamage(float i_damage)
			{
				m_damage = i_damage;
			}

			BTStatus EatPlayer::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				i_tick->GetBlackBoard()->SetTask("RunningTask", this, m_id, m_id);
				return OnExecute(i_tick);
			}

			Action* EatPlayer::GetAction()
			{
				return nullptr;
			}
		}
	}
}