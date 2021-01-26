#pragma once

#include "ofMain.h"
#include "DrawDragAndDropRect.h"
#include "ClickRect.h"
//#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "map"
#define NUM 7

enum class boneName
{
	head,
	r_shoulder,
	l_shoulder,
	chest,
	waist,
	r_leg,
	l_leg
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	//ドラッグアンドドロップウィンドウ
	DrawDragAndDropRect _characterWindow, _mWindow0, 
		_mWindow1, _mWindow2, _mWindow3, _mWindow4, _parameterWindow;
	std::map<int, DrawDragAndDropRect> _mWindowArray;

	//クリックウィンドウ
	ClickRect _clickWindow0, _clickWindow1, _clickWindow2, _clickWindow3,
		_clickWindow4, _clickWindow5;
	std::map<int, ClickRect> _clickWindowArray;
	std::map<int, string> _boneNameList;

	//ボーンポイントの座標
	ofVec2f _pos[NUM], _minPos, _maxPos, _neutralRotate, _maxRotate, _minRotate;
	std::map<int, ofVec2f> _bonePointArray;

	//3Dモデルのローダー
	//ofxAssimpModelLoader myModel;
	
	//3Dモデル用カメラ
	ofCamera _camera;
	
	//3Dモデルライト
	ofLight _light;
	
	//ofxGui関連
	ofxGuiGroup _groupGui;
	ofxVec2Slider _model_0_Pos, _model_1_Pos, _model_2_Pos,
		_model_3_Pos, _model_4_Pos, 
		_model_0_Rotate, _model_1_Rotate, _model_2_Rotate, 
		_model_3_Rotate, _model_4_Rotate;
	ofxFloatSlider _model_0_Size, _model_1_Size, _model_2_Size,
		_model_3_Size, _model_4_Size;


	//衣服Modelの数
	int _modelNum = 4;
	
	//ボーンポイントの数
	int _cCoutnerNum = 0;
	int _boneNum = 6;
	
	//UIのパディングに関する変数
	int  _verticalPadding = 20, _horizontalPadding = 10,
		_arrayPadding = 32, 
		_cWWidth = 724, _windowHeight = 728,
		_mWWidth = 130, _mWHeight = 120,
		_pWWidth = 200, _clickWindowWidth = 50, _clickWindowHeight = 50;
	
	//3Dモデルの座標
	float _mPosX, _mPosY;
	bool isCharacterCGDDed = false, isAllBoneSetted = false;
	
	//ボーン指定モードの値
	int _selectedBoneNum = 0;
};
