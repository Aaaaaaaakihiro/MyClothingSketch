#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�i�̐ݒ�
	ofBackground(255, 255, 255);

	//�{�[���̍��W
	_bonePointArray.insert(std::make_pair(boneName::head, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::r_shoulder, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::l_shoulder, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::chest, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::waist, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::r_leg, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(boneName::l_leg, ofVec2f(0, 0)));

	//gui�̃Z�b�g�A�b�v
	_minPos = ofVec2f(0, 0);
	_maxPos = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
	_minRotate = ofVec2f(-180, -180);
	_maxRotate = ofVec2f(180, 180);
	_neutralRotate = ofVec2f(0, 0);
	_groupGui.setup("", "", ofGetWindowWidth() - 200, _verticalPadding);
	_groupGui.add(_model_0_Pos.setup("Model_1_Pos", _pos[0], _minPos, _maxPos));
	_groupGui.add(_model_0_Rotate.setup("Model_1_Rotate", _neutralRotate, _minRotate,_maxRotate));
	_groupGui.add(_model_0_Size.setup("Model_1_Size",0.5, 0, 1.0));
	_groupGui.add(_model_1_Pos.setup("Model_2_Pos", _pos[1], _minPos, _maxPos));
	_groupGui.add(_model_1_Rotate.setup("Model_2_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_1_Size.setup("Model_2_Size", 0.5, 0, 1.0));
	//mWindowArray��mWindow��ǉ�
	_mWindowArray.insert(std::make_pair(0, _mWindow0));
	_mWindowArray.insert(std::make_pair(1, _mWindow1));
	_mWindowArray.insert(std::make_pair(2, _mWindow2));
	_mWindowArray.insert(std::make_pair(3, _mWindow3));
	_mWindowArray.insert(std::make_pair(4, _mWindow4));
	//DDRect��������
	//�L�����E�B���h�E
	_characterWindow.setUp(ofGetWindowWidth() * 0.5 - _cWWidth * 0.5 ,
		/*ofGetWindowHeight() * 0.5 - _windowHeight * 0.5*/_verticalPadding, 
		_cWWidth, _windowHeight);
	//���f���E�B���h�E��map����Ăяo����setUp����
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).setUp(_horizontalPadding, _verticalPadding
			+ i * _mWHeight + (i * _arrayPadding), _mWWidth, _mWHeight);
	}
	//�p�����[�^�E�B���h�E��setUp
	_parameterWindow.setUp(ofGetWindowWidth() - _pWWidth, _verticalPadding, 
		_pWWidth, _windowHeight);
	//�N���b�N�|�C���g�̏�����
	for (int i = 0; i < NUM; i++) 
	{
		_pos[i].x = 0;
		_pos[i].y = 0;
	}
	//myModel.setScale(0.5, 0.5, 0.5);
	//myModel.setRotation(0, 90, 1, 0, 0);
	
	_light.setPosition(0, 0, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
	//myModel.update();
	_camera.lookAt(ofVec3f(0, 0, 0));
	_camera.setPosition(500 * cos(ofGetElapsedTimef() / 10), 200,
		500 * sin(ofGetElapsedTimef() / 10));
}

//--------------------------------------------------------------
void ofApp::draw(){
	//3D���f���p�����[�^(ofxGui)�̕`��
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	_groupGui.draw();
	//D&D�E�B���h�E�̕`��
	_characterWindow.draw();
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).draw();
	}
	_parameterWindow.draw();
	//�{�[���|�C���g�̕`��
	for (int i = 0; i < NUM; i++) 
	{
		ofCircle(_pos[i].x, _pos[i].y, 4);
	}
	//3D���f���̕`��
	ofEnableDepthTest();
	_light.enable();
		ofPushMatrix();
			//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			_camera.begin();
				//ofRotateX(-90);
				//ofSetLineWidth(1);
				//myModel.drawFaces();
			_camera.end();
		ofPopMatrix();

		_light.disable();

	ofDisableDepthTest();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	_characterWindow.keyReleased();

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//�}�E�X�{�^���������ė������Ƃ��ɃN���b�N�|�C���g�̍��W��0�`�S�Ԃ̏��ōX�V�����
	//4�Ԃ܂ōX�V���I������A�܂�0�Ԃ���X�V����
	_pos[_cCoutnerNum].x = x;
	_pos[_cCoutnerNum].y = y;
	_cCoutnerNum = ++_cCoutnerNum;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
	//�h���b�O�A���h�h���b�v����E�B���h�E�̃h���b�O�C�x���g�N��
	//picRect1.dragEvent(dragInfo);
}
