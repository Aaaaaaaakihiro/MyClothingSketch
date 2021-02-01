#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//�A�v���̐ݒ�
	ofSetWindowTitle(u8"�����ւ��A�v��");

	
	//�E�B���h�E�T�C�Y�̃L���b�V��
	_cachedhWindowRect.set(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	
	//�w�i�̐ݒ�
	ofBackground(255, 255, 255);


	//�{�[���̖��O�̗���(��ɃN���b�N�{�b�N�X�p)
	_boneNameList.insert(std::make_pair(0, u8"��"));
	_boneNameList.insert(std::make_pair(1, u8"����"));
	_boneNameList.insert(std::make_pair(2, u8"�E��"));
	_boneNameList.insert(std::make_pair(3, u8"��"));
	_boneNameList.insert(std::make_pair(4, u8"����"));
	_boneNameList.insert(std::make_pair(5, u8"�E��"));

	//�{�[���̍��W�̏�����
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::head), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_shoulder), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_shoulder), ofVec2f(0, 0)));
	//_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::chest), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::waist), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_leg), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_leg), ofVec2f(0, 0)));

	//�N���b�N�|�C���g�̏�����
	/*for (int i = 0; i < NUM; i++)
	{
		_pos[i].x = 0;
		_pos[i].y = 0;
	}*/

	//�L�����N�^�[�E�B���h�E�̃L���b�V��
	_cachedCharacterWindow.set(_cachedhWindowRect.getWidth() * 0.5 - _cWWidth * 0.5,
		_verticalPadding,
		_cWWidth - 60, _windowHeight - _horizontalPadding - _clickWindowHeight);


	//gui�̃Z�b�g�A�b�v
	//3D���f�����\���������E���W�̐ݒ�
	_minPos = ofVec2f(_cachedCharacterWindow.getX(), _cachedCharacterWindow.getY());
	_maxPos = ofVec2f(_cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());
	//3d���f���̉�]���E�p��ݒ�
	_minRotate = ofVec3f(-180, -180, -180);
	_maxRotate = ofVec3f(180, 180, 180);
	//������]�p
	_neutralRotate = ofVec3f(0, 0, 0);
	
	//GUI�O���[�v�̏�����
	_groupGui.setup("", "", _cachedhWindowRect.getWidth() - 200, _verticalPadding);
	
	//GUI�̑��
	//�w�A�A�N�Z
	_groupGui.add(_model_0_Pos.setup("Cap_Pos", 
		_bonePointArray.at(0), 
		_minPos, _maxPos));
	_groupGui.add(_model_0_Rotate.setup("Cap_Rotate", _neutralRotate, _minRotate,_maxRotate));
	_groupGui.add(_model_0_Size.setup("Cap_Size",0.5, 0, 1.0));
	
	//�g�b�v�X
	_groupGui.add(_model_1_Pos.setup("Tops_Pos", 
		_bonePointArray.at(1), 
		_minPos, _maxPos));
	_groupGui.add(_model_1_Rotate.setup("Tops_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_1_Size.setup("Tops_Size", 0.5, 0, 1.0));
	
	//�{�g���X
	_groupGui.add(_model_2_Pos.setup("Bottoms_Pos", 
		_bonePointArray.at(3), 
		_minPos, _maxPos));
	_groupGui.add(_model_2_Rotate.setup("Bottoms_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_2_Size.setup("Bottoms_Size", 0.5, 0, 1.0));
	
	//�V���[�Y(��)
	_groupGui.add(_model_3_Pos.setup("LeftShoes_Pos", 
		_bonePointArray.at(4), 
		_minPos, _maxPos));
	_groupGui.add(_model_3_Rotate.setup("LeftShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_3_Size.setup("LeftShoes_Size", 0.5, 0, 1.0));
	
	//�V���[�Y(�E)
	_groupGui.add(_model_4_Pos.setup("RightShoes_Pos",
		_bonePointArray.at(5),
		_minPos, _maxPos));
	_groupGui.add(_model_4_Rotate.setup("RightShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_4_Size.setup("RightShoes_Size", 0.5, 0, 1.0));


	//mWindowArray��mWindow��ǉ�
	_mWindowArray.insert(std::make_pair(0, _mWindow0));
	_mWindowArray.insert(std::make_pair(1, _mWindow1));
	_mWindowArray.insert(std::make_pair(2, _mWindow2));
	_mWindowArray.insert(std::make_pair(3, _mWindow3));
	_mWindowArray.insert(std::make_pair(4, _mWindow4));

	//clickWindowArray��window������ǉ�
	_clickWindowArray.insert(std::make_pair(0, _clickWindow0));
	_clickWindowArray.insert(std::make_pair(1, _clickWindow1));
	_clickWindowArray.insert(std::make_pair(2, _clickWindow2));
	_clickWindowArray.insert(std::make_pair(3, _clickWindow3));
	_clickWindowArray.insert(std::make_pair(4, _clickWindow4));
	_clickWindowArray.insert(std::make_pair(5, _clickWindow5));


	//DDRect��������
	//�L�����E�B���h�E
	_characterWindow.setUp(_cachedCharacterWindow.getX() ,
		_cachedCharacterWindow.getY(), 
		_cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());

	//���f���E�B���h�E��map����Ăяo����setUp����
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).setUp(_horizontalPadding, _verticalPadding
			+ i * _mWHeight + (i * _arrayPadding), _mWWidth, _mWHeight);
	}

	//�p�����[�^�E�B���h�E��setUp
	_parameterWindow.setUp(ofGetWindowWidth() - _pWWidth, _verticalPadding, 
		_pWWidth, _windowHeight);

	//�N���b�N�E�B���h�E��setUp
	for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).setUp(
			ofGetWindowWidth() * 0.5
			- (_horizontalPadding * 0.5)
			- (2.0 * _horizontalPadding)
			- (3.0 * _clickWindowWidth)
			+ i * (_clickWindowWidth + _horizontalPadding),
			_verticalPadding + 668 + 10,
			_clickWindowWidth, _clickWindowHeight, i,_boneNameList.at(i));
	}


	//3D���f���̃��C�g�̏�����
	_light.setPosition(0, 0, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
	//myModel.update();
	/*_camera.lookAt(ofVec3f(0, 0, 0));
	_camera.setPosition(500 * cos(ofGetElapsedTimef() / 10), 200,
		500 * sin(ofGetElapsedTimef() / 10));*/
	
	/*
	* ���ׂẴ{�[���I���E�B���h�E��isclickedBool���Ď��D
	* ����isClickedBool��true�ɂȂ�����isSelectingBone��true�ɂ��C�{�[���w��ȊO�̃N���b�N��������b�N�D
	* �{�[���̎w�肪�I���΃��b�N����������D
	*/
	for (int i = 0; i < _boneNum; i++) {
		if(!_isSelectingBone && _clickWindowArray.at(i).getIsClickedBool())
		{
			_isSelectingBone = true;
		}
	}

	/*
	* ���ׂẴ{�[�����ݒ肳��Ă��Ȃ����C�{�[�����ǂꂾ���ݒ�T��Ă��邩���m�F���āC
	* ���ׂẴ{�[�����ݒ肳��Ă��鎞�ɏ��߂�isAllBoneSetted��true�ɂ���
	*/
	if (!isAllBoneSetted) {
		//int bCounter = 0;
		for (int i = 0; i < _boneNum; i++) {
			if (_bonePointArray.at(i) == ofVec2f(0, 0)) break;
		}
		std::cout << "All Bone Setted!" << endl;
		//���ׂẴ{�[�����ݒ肳�ꂽ��GUI�Ƀ{�[���̍��W�𗬂�����
		//�g�b�v�X�Ɋւ��Ă͍������W�ƉE�����W�Ԃ̐����̌X����model1��Rotate�ɑ������K�v����
		_model_0_Pos = _bonePointArray.at(0);
		_model_1_Pos = _bonePointArray.at(1).getMiddle(_bonePointArray.at(2));
		_model_2_Pos = _bonePointArray.at(3);
		_model_3_Pos = _bonePointArray.at(4);
		_model_4_Pos = _bonePointArray.at(5);
		isAllBoneSetted = true;
		//if (bCounter == _boneNum) isAllBoneSetted = true;
	}

	//���f���E�B���h�E�ɂЂ�������W�𗬂�������
	if (!isAllBoneSetted) {
		for (int i = 0; i < _modelNum; i++) {
			_mWindowArray.at(i).update(_bonePointArray.at(i),ofVec3f(0,0,0),0.5);
		}
	}else if (isAllBoneSetted) 
	{
		for (int i = 0; i < _modelNum; i++) {
			switch (i)
			{
			case 0:
				_mWindowArray.at(i).update(ofVec2f(_model_0_Pos), ofVec3f(_model_0_Rotate),_model_0_Size);
				break;
			case 1:
				_mWindowArray.at(i).update(ofVec2f(_model_1_Pos), ofVec3f(_model_1_Rotate), _model_1_Size);
				break;
			case 2:
				_mWindowArray.at(i).update(ofVec2f(_model_2_Pos), ofVec3f(_model_2_Rotate), _model_2_Size);
				break;
			case 3:
				_mWindowArray.at(i).update(ofVec2f(_model_3_Pos), ofVec3f(_model_3_Rotate), _model_3_Size);
				break;
			case 4:
				_mWindowArray.at(i).update(ofVec2f(_model_4_Pos), ofVec3f(_model_4_Rotate), _model_4_Size);
				break;
			default:
				break;
			}
		}
	}
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
	//_parameterWindow.draw();
	for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).draw();
	}

	//�{�[���|�C���g�̕`��
	for (int i = 0; i < _boneNum; i++) 
	{
		/*int x = _bonePointArray.at(i).x;
		int y = _bonePointArray.at(i).y;*/
		if (!isAllBoneSetted && _bonePointArray.at(i).x != 0 && _bonePointArray.at(i).y != 0) {
			ofSetColor(0, 0, 255);
			ofFill();
			ofCircle(_bonePointArray.at(i).x, _bonePointArray.at(i).y, 10);
		}
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
	//_characterWindow.keyReleased();
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
	/*_pos[_cCoutnerNum].x = x;
	_pos[_cCoutnerNum].y = y;
	_cCoutnerNum = ++_cCoutnerNum;*/

	//�N���b�N�E�B���h�E���Ń}�E�X�{�^���������[�X���ꂽ�炻�̃E�B���h�E�Ɋ��蓖�Ă�ꂽ�{�[���w�胂�[�h�ɓ���
	/*_clickWindow0.mouseReleased(x, y, button);
	_clickWindow1.mouseReleased(x, y, button);
	_clickWindow2.mouseReleased(x, y, button);
	_clickWindow3.mouseReleased(x, y, button);
	_clickWindow4.mouseReleased(x, y, button);
	_clickWindow5.mouseReleased(x, y, button);*/

	//�{�[���I�𒆂łȂ��������{�[���w�胂�[�h��؂�ւ��邱�Ƃ��ł���
	if (!_isSelectingBone) {
		for (int i = 0; i < _boneNum; i++) {
			_clickWindowArray.at(i).mouseReleased(x, y, button);
		}
	}

	//�{�[���I�𒆂̂݃L�����N�^�[�E�B���h�E�Ń{�[���̎w�肪�s����
	if (_isSelectingBone && ofGetWindowWidth() * 0.5 - _cWWidth * 0.5 <= x &&
		_verticalPadding <= y &&
		x <= ofGetWindowWidth() * 0.5 - _cWWidth * 0.5 + _cWWidth - 60 &&
		y <= _verticalPadding + _windowHeight - _horizontalPadding - _clickWindowHeight)
	{
		_bonePointArray.at(_selectedBoneNum) = ofVec2f(x, y);
		_isSelectingBone = false;
		std::cout << "CharacterWindow MouseReleased!! "
			<< "x : " << x << " , y : " << y << endl;
	}
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
	//���ׂẴ{�[�����ݒ肳��Ă��Ȃ��Ԃƃ{�[���I�𒆂łȂ��Ƃ������L�����N�^�[�摜��D&D�ł���
	if(!_isSelectingBone || !isAllBoneSetted)
	_characterWindow.dragEvent(dragInfo);

	//���ׂẴ{�[����ݒ肵����ɂ���3D���f�����h���b�O���h���b�v�ł���
	if (isAllBoneSetted) 
	{
		for (int i = 0; i < _modelNum; i++) {
			_mWindowArray.at(i).dragEvent(dragInfo);
		}
	}

	//�h���b�O�A���h�h���b�v����E�B���h�E�̃h���b�O�C�x���g�N��
	//picRect1.dragEvent(dragInfo);
}