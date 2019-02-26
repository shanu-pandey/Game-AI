#pragma once
#include "IHeuristics.h"

namespace AIForGames
{
	class ManhattanHeuristics : public IHeuristics
	{
	public:
		int GetEstimate(Node i_start, Node i_end);
	};
}
