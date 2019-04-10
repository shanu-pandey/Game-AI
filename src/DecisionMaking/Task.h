#pragma once


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			class Task
			{
			public:
				virtual void OnEnter() = 0;
				virtual void OnExit() = 0;
				virtual void OnOpen() = 0;
				virtual void OnClose() = 0;
				virtual void OnE() = 0;
			};
		}
	}
}