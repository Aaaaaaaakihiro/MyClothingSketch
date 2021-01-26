#include "ClickRect.h"
//�Z�`�̏�����
void ClickRect::setUp(float x, float y, float width, float height, int selectedBoneNum, string text) {
	_xPos = x;
	_yPos = y;
	_width = width;
	_height = height;
	_boneNum = selectedBoneNum;
	_rectText = text;
	//_font.load("fonts/arial.ttf", 5);
	//���{��t�H���g�ݒ�

	ofTrueTypeFontSettings settings("fonts/VL-Gothic-Regular.ttf", 10);
	settings.antialiased = true;
	settings.addRanges(ofAlphabet::Japanese);
	_font.load(settings);

	std::cout << "CRwindow_" << _boneNum << " : _xPos + _width = " << _xPos + _width << " , _yPos + _height = " << _yPos + _width << endl;
}

//�Z�`�̕`��
void ClickRect::draw() {
	ofFill();
	ofSetColor(227, 227, 227);
	ofDrawRectangle(_xPos, _yPos, _width, _height);

	//�N���b�N���ꂽ��O�g���Ԃ��Ȃ�
	if (_isClicked) {
		ofNoFill();
		ofSetColor(235, 64, 52);
		ofDrawRectangle(_xPos, _yPos, _width, _height);
	}
	else {
		ofNoFill();
		ofSetColor(0);
		ofDrawRectangle(_xPos, _yPos, _width, _height);
	}

	//ofSetColor(ofColor::black);
	//ofDrawBitmapString(_rectText, _xPos + _width * 0.5, _yPos + _height * 0.5);
	ofSetColor(77, 77, 77);
	_font.drawString(_rectText, _xPos + _width * 0.2,
		_yPos + _height * 0.5);
}

void ClickRect::mouseReleased(int x, int y, int button) {
	std::cout << "CRWindow_"<< _boneNum << " NotMouseReleased " <<
	"x : " << x << " , y : " << y << endl;

	if (!_isClicked && _xPos <= x &&
		_yPos <= y &&
		x <= _xPos + _width &&
		y <= _yPos + _height) 
	{
		_isClicked = true;
		std::cout << "CRWindow_" << _boneNum << " MouseReleased!! "
		<< "x : " << x << " , y : " << y << endl;
	}
}

void ClickRect::update() {
	
}

void ClickRect::setIsClickedFalse() {
	_isClicked = false;
}

void ClickRect::setIsClickedTrue() {
	_isClicked = true;
}
