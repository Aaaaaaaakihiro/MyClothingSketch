#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�i�̐ݒ�
	ofBackground(255, 255, 255);

	//�{�[���̍��W�̏�����
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::head), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_shoulder), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_shoulder), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::chest), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::waist), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_leg), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_leg), ofVec2f(0, 0)));
	//�N���b�N�|�C���g�̏�����
	/*for (int i = 0; i < NUM; i++)
	{
		_pos[i].x = 0;
		_pos[i].y = 0;
	}*/
	
	//gui�̃Z�b�g�A�b�v
	//3D���f�����\���������E���W�̐ݒ�
	_minPos = ofVec2f(0, 0);
	_maxPos = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
	//3d���f���̉�]���E�p��ݒ�
	_minRotate = ofVec2f(-180, -180);
	_maxRotate = ofVec2f(180, 180);
	//������]�p
	_neutralRotate = ofVec2f(0, 0);
	//GUI�O���[�v�̏�����
	_groupGui.setup("", "", ofGetWindowWidth() - 200, _verticalPadding);
	//GUI�̑��
	//��
	_groupGui.add(_model_0_Pos.setup("Cap_Pos", 
		_bonePointArray.at(static_cast<int>(boneName::head)), 
		_minPos, _maxPos));
	_groupGui.add(_model_0_Rotate.setup("Cap_Rotate", _neutralRotate, _minRotate,_maxRotate));
	_groupGui.add(_model_0_Size.setup("Cap_Size",0.5, 0, 1.0));
	//�g�b�v�X
	_groupGui.add(_model_1_Pos.setup("Tops_Pos", 
		_pos[1], 
		_minPos, _maxPos));
	_groupGui.add(_model_1_Rotate.setup("Tops_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_1_Size.setup("Tops_Size", 0.5, 0, 1.0));
	//�{�g���X
	_groupGui.add(_model_2_Pos.setup("Bottoms_Pos", 
		_pos[2], 
		_minPos, _maxPos));
	_groupGui.add(_model_2_Rotate.setup("Bottoms_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_2_Size.setup("Bottoms_Size", 0.5, 0, 1.0));
	//�V���[�Y
	_groupGui.add(_model_3_Pos.setup("Shoes_Pos", 
		_pos[3], 
		_minPos, _maxPos));
	_groupGui.add(_model_3_Rotate.setup("Shoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_3_Size.setup("Shoes_Size", 0.5, 0, 1.0));

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
		_cWWidth - 60, _windowHeight - _horizontalPadding - _clickWindowHeight);
	//���f���E�B���h�E��map����Ăяo����setUp����
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).setUp(_horizontalPadding, _verticalPadding
			+ i * _mWHeight + (i * _arrayPadding), _mWWidth, _mWHeight);
	}
	//�p�����[�^�E�B���h�E��setUp
	_parameterWindow.setUp(ofGetWindowWidth() - _pWWidth, _verticalPadding, 
		_pWWidth, _windowHeight);

	
	
	//3D���f���̃��C�g�̏�����
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
		ofSetColor(0, 0, 255);
		ofFill();
		ofCircle(_bonePointArray.at(i).x, _bonePointArray.at(i).y, 10);
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
