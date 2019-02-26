#pragma once
#include "ManhattanHeuristics.h"
#include <math.h>
namespace AIForGames
{
	int ManhattanHeuristics::GetEstimate(Node i_start, Node i_end)
	{
		float distance = std::abs(i_start.position.x - i_end.position.x);
		distance += std::abs(i_start.position.y - i_end.position.y);		
		return distance;
	}
}
