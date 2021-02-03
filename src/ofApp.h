#pragma once

#include "ofMain.h"
#include "DrawDragAndDropRect.h"
#include "ClickRect.h"
//#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "map"
#define NUM 6

//enum class boneName
//{
//	head,
//	r_shoulder,
//	l_shoulder,
//	chest,
//	waist,
//	r_leg,
//	l_leg
//};

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
	void takeScreenShot();
	void setBone0();
	void setBone1();
	void setBone2();
	void setBone3();
	void setBone4();
	void setBone5();
	void setModel0BonePosition(ofVec2f &position);
	void setModel1BonePosition(ofVec2f &position);
	void setModel2BonePosition(ofVec2f &position);
	void setModel3BonePosition(ofVec2f &position);
	void setModel4BonePosition(ofVec2f &position);
	void setModel0Rotation(ofVec3f &rotaion);
	void setModel1Rotation(ofVec3f &rotation);
	void setModel2Rotation(ofVec3f &rotation);
	void setModel3Rotation(ofVec3f &rotation);
	void setModel4Rotation(ofVec3f &rotation);
	void setModel0Size(float &size);
	void setModel1Size(float &size);
	void setModel2Size(float &size);
	void setModel3Size(float &size);
	void setModel4Size(float &size);


private:
	//ウィンドウのキャッシュ
	ofRectangle _cachedhWindowRect;

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
	ofVec2f  _minPos, _maxPos;
	std::map<int, ofVec2f> _bonePointArray;
	ofVec2f _bPointArray[NUM] = {};
	//3Dモデルの回転
	ofVec3f _neutralRotate, _maxRotate, _minRotate;

	//3Dモデルのローダー
	//ofxAssimpModelLoader myModel;
	
	//3Dモデル用カメラ
	ofCamera _camera;
	
	//3Dモデルライト
	ofLight _light;
	
	//ofxGui関連
	ofxGuiGroup _groupGui, _buttonGroup;
	ofxVec2Slider _model_0_Pos, _model_1_Pos, _model_2_Pos,
		_model_3_Pos, _model_4_Pos;
	ofxVec3Slider _model_0_Rotate, _model_1_Rotate, _model_2_Rotate, 
		_model_3_Rotate, _model_4_Rotate;
	ofxFloatSlider _model_0_Size, _model_1_Size, _model_2_Size,
		_model_3_Size, _model_4_Size;
	ofxButton _screenShotButton, _buttonNo0, _buttonNo1, _buttonNo2, _buttonNo3, _buttonNo4, _buttonNo5;
	
	ofxPanel _guiGroup;
	ofParameter<ofVec2f> _model0PosSlider, _model1PosSlider, _model2PosSlider, 
		_model3PosSlider, _model4PosSlider;
	ofParameter<ofVec3f> _model0RotateSlider, _model1RotateSlider, _model2RotateSlider, 
		_model3RotateSlider, _model4RotateSlider;

	//タイマー用のフォント
	//ofTrueTypeFont _timerFont;

	//スクリーンショット関連
	ofImage _screenShotImage;

	//衣服Modelの数
	int _modelNum = 5;
	
	//ボーンポイントの数
	int _cCoutnerNum = 0;
	int _boneNum = 6;
	
	
	//UIのパディングに関する変数
	int  _verticalPadding = 20, _horizontalPadding = 10,
		_arrayPadding = 32, 
		_cWWidth = 724, _windowHeight = 728,
		_mWWidth = 130, _mWHeight = 120,
		_pWWidth = 200, _clickWindowWidth = 50, _clickWindowHeight = 50;
	
	//キャッシュされた各種ウィンドウのサイズ
	ofRectangle _cachedCharacterWindow;

	//3Dモデルの座標
	float _mPosX, _mPosY;
	bool _isCharacterAdded = false, isAllBoneSetted = false, isBoneTypeSelected = false,
		_isBone0Selected = false, _isBone1Selected = false, _isBone2Selected = false,
		_isBone3Selected = false, _isBone4Selected = false, _isBone5Selected = false/*,
		_isSelectingBone = false*/;
	std::map<int, bool>_clickWindowBoolArray;
	
	//ボーン指定モードの値
	int _selectedBoneNum = 0;
};
