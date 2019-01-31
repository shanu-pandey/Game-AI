#include "../ofApp.h"
#include "TargetRenderer.h"

namespace AIForGames
{
	void Renderer::TargetRenderer::Draw()
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(0, 0, 10);		
	}

	void Renderer::TargetRenderer::Draw(float i_x, float i_y)
	{
		ofSetColor(0, 0, 0);
		ofDrawCircle(i_x, i_y, 30);		
	}

	void Renderer::TargetRenderer::Draw(float i_x, float i_y, float i_orientation)
	{
		ofSetColor(0, 0, 0);
		ofDrawCircle(i_x, i_y, 30);		
	}

	void Renderer::TargetRenderer::Draw(ofVec2f i_position)
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(i_position, 10);		
	}

	void Renderer::TargetRenderer::Draw(ofVec2f i_position, float i_orientation)
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(i_position, 10);	
	}

	void Renderer::TargetRenderer::Draw(float i_radius, ofVec2f i_position, float i_orientation)
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(i_position, i_radius);
	}
}