#pragma once
#include "PlayerHealthCheck.h"
#include "Tick.h"
#include "../WorldData/WorldManager.h"
#include "../AI/AIController.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			PlayerHealthCheck::PlayerHealthCheck(uint8_t i_id) : ITask(i_id)
			{	}

			PlayerHealthCheck::~PlayerHealthCheck()
			{

			}

			BTStatus PlayerHealthCheck::OnEnter(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus PlayerHealthCheck::OnExit(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus PlayerHealthCheck::OnOpen(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus PlayerHealthCheck::OnClose(Tick* i_tick)
			{
				return SUCCESS;
			}

			BTStatus PlayerHealthCheck::OnExecute(Tick* i_tick)
			{
				AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
				float health = m_pWorldManager.GetPlayerCharacter()->GetHealth();
					
				if (health > 0)
					return SUCCESS;		

				return FAILURE;
			}

			void PlayerHealthCheck::SetMyController(AIController* i_controller)
			{
				m_pMyController = i_controller;
			}

			BTStatus PlayerHealthCheck::Run(Tick* i_tick)
			{
				OnEnter(i_tick);
				i_tick->GetBlackBoard()->SetTask("RunningTask", this, m_id, m_id);
				return OnExecute(i_tick);
			}

			Action* PlayerHealthCheck::GetAction()
			{
				return nullptr;
			}
		}
	}
}