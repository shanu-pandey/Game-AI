#pragma once
#include "../GameStructs.h"


namespace AIForGames
{
	class IHeuristics
	{
	public:
		virtual int GetEstimate(Node i_start, Node i_end) = 0;
	};
}
