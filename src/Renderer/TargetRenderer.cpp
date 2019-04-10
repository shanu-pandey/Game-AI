#include "../ofApp.h"
#include "TargetRenderer.h"

namespace AIForGames
{
	void Renderer::TargetRenderer::SetColor(float i_R, float i_G, float i_B)
	{
		R = i_R;
		G = i_G;
		B = i_B;
	}

	void Renderer::TargetRenderer::Draw()
	{
		ofSetColor(R, G, B);
		ofDrawCircle(0, 0, 10);		
	}

	void Renderer::TargetRenderer::Draw(float i_x, float i_y)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_x, i_y, 30);		
	}

	void Renderer::TargetRenderer::Draw(float i_x, float i_y, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_x, i_y, 30);		
	}

	void Renderer::TargetRenderer::Draw(ofVec2f i_position)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_position, 10);		
	}

	void Renderer::TargetRenderer::Draw(ofVec2f i_position, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_position, 10);	
	}

	void Renderer::TargetRenderer::Draw(float i_radius, ofVec2f i_position, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_position, i_radius);
	}
}