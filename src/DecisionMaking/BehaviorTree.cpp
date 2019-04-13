#pragma once
#include "BehaviorTree.h"
#include "Tick.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			BehaviorTree::BehaviorTree()
			{
				m_pBlackBoard = new Blackboard();
			}

			BehaviorTree::BehaviorTree(ITask * i_pRoot)
			{
				m_pBlackBoard = new Blackboard();
				m_pRoot = i_pRoot;
			}

			BehaviorTree::~BehaviorTree()
			{

			}

			Action* BehaviorTree::GetAction()
			{
				Update(); 
				Action* action = m_pBlackBoard->GetAction("ActiveAction", m_id, m_pRoot->ID());
				return action;
			}

			ITask* BehaviorTree::GetRoot() const
			{
				return m_pRoot;
			}

			void BehaviorTree::SetRoot(ITask* i_root)
			{
				m_pRoot = i_root;
			}

			void BehaviorTree::Update()
			{
				Tick* pTick = new Tick(this, m_pBlackBoard);
				m_pRoot->Run(pTick);
			}
		}
	}
}