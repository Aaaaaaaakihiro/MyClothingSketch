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
	//�E�B���h�E�̃L���b�V��
	ofRectangle _cachedhWindowRect;

	//�h���b�O�A���h�h���b�v�E�B���h�E
	DrawDragAndDropRect _characterWindow, _mWindow0, 
		_mWindow1, _mWindow2, _mWindow3, _mWindow4, _parameterWindow;
	std::map<int, DrawDragAndDropRect> _mWindowArray;

	//�N���b�N�E�B���h�E
	ClickRect _clickWindow0, _clickWindow1, _clickWindow2, _clickWindow3,
		_clickWindow4, _clickWindow5;
	std::map<int, ClickRect> _clickWindowArray;
	std::map<int, string> _boneNameList;

	//�{�[���|�C���g�̍��W
	ofVec2f  _minPos, _maxPos;
	std::map<int, ofVec2f> _bonePointArray;
	ofVec2f _bPointArray[NUM] = {};
	//3D���f���̉�]
	ofVec3f _neutralRotate, _maxRotate, _minRotate;

	//3D���f���̃��[�_�[
	//ofxAssimpModelLoader myModel;
	
	//3D���f���p�J����
	ofCamera _camera;
	
	//3D���f�����C�g
	ofLight _light;
	
	//ofxGui�֘A
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

	//�^�C�}�[�p�̃t�H���g
	//ofTrueTypeFont _timerFont;

	//�X�N���[���V���b�g�֘A
	ofImage _screenShotImage;

	//�ߕ�Model�̐�
	int _modelNum = 5;
	
	//�{�[���|�C���g�̐�
	int _cCoutnerNum = 0;
	int _boneNum = 6;
	
	
	//UI�̃p�f�B���O�Ɋւ���ϐ�
	int  _verticalPadding = 20, _horizontalPadding = 10,
		_arrayPadding = 32, 
		_cWWidth = 724, _windowHeight = 728,
		_mWWidth = 130, _mWHeight = 120,
		_pWWidth = 200, _clickWindowWidth = 50, _clickWindowHeight = 50;
	
	//�L���b�V�����ꂽ�e��E�B���h�E�̃T�C�Y
	ofRectangle _cachedCharacterWindow;

	//3D���f���̍��W
	float _mPosX, _mPosY;
	bool _isCharacterAdded = false, isAllBoneSetted = false, isBoneTypeSelected = false,
		_isBone0Selected = false, _isBone1Selected = false, _isBone2Selected = false,
		_isBone3Selected = false, _isBone4Selected = false, _isBone5Selected = false/*,
		_isSelectingBone = false*/;
	std::map<int, bool>_clickWindowBoolArray;
	
	//�{�[���w�胂�[�h�̒l
	int _selectedBoneNum = 0;
};
