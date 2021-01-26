#include "ClickRect.h"
//íZå`ÇÃèâä˙âª
void ClickRect::setUp(float x, float y, float width, float height, int selectedBoneNum, string text) {
	_xPos = x;
	_yPos = y;
	_width = width;
	_height = height;
	_boneNum = selectedBoneNum;
	_rectText = text;
}

//íZå`ÇÃï`âÊ
void ClickRect::draw() {
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(_xPos, _yPos, _width, _height);
	ofFill();
	ofSetColor(255);
	ofSetColor(ofColor::black);
	ofDrawBitmapString(_rectText, _xPos + _width * 0.5, _yPos + _height * 0.5);
}

