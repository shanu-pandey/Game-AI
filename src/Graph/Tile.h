#pragma once
#include "ofVec2f.h"


namespace AIForGames
{
	namespace PathFinding
	{
		class Tile
		{
		public:
			Tile()
			{
				m_index = 0;
				m_position = ofVec2f(0, 0);
				bIsWalkable = false;
			}
			Tile(int i_index, ofVec2f i_pos, bool i_bWalkable) : 
				m_index(i_index),
				m_position(i_pos),
				bIsWalkable(i_bWalkable)
			{				
			}
			~Tile() {}
			int GetIndex() { return m_index; }
			ofVec2f GetPosition() { return m_position; }
			bool IsWalkable() { return bIsWalkable; }
			void SetWalkable(bool i_bWalkable) { bIsWalkable = i_bWalkable; }

		private:
			int m_index;
			ofVec2f m_position;
			bool bIsWalkable;
		};
	}
}
