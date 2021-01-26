#pragma once
#include "ofMain.h"

class ClickRect
{
	public:
		void setUp(float x, float y, float width, float height, int selectedBoneNum, string text);
		void draw();
		void keyReleased();
		void dragEvent(ofDragInfo dragInfo);
		void setBonePosition(int x, int y);
		void update();

	private:
		ofImage _img;
		ofTrueTypeFont text;
		string _rectText;
		float _xPos, _yPos, _width, _height;
		int _bpx, _bpy = -500;
		bool _boneSetted = false;
		int _boneNum = 0;
};

