#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setResolution(3);

	ofSetLineWidth(1);
	ofSetColor(ofColor(255, 0, 0));

	this->noise_value = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);

	ofSetColor(ofColor(230, 0, 0));
	ofSphere(98);
	ofSetColor(ofColor(230, 0, 0));

	float tmp_noise_value = this->noise_value;

	for (int i = 300; i > 100; i -= 5)
	{
		this->icoSphere.setRadius(i);
		vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();
		for (int i = 0; i < triangles.size(); i++) {
			ofVec3f avg = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
			ofVec3f tmp = avg.normalized() * 300;
			float noise = ofNoise(tmp_noise_value, tmp.x * 0.0025, tmp.y * 0.0025, tmp.z * 0.0025);

			if (noise > 0.65) {
				ofBox(avg, 4);

			}
		}

		tmp_noise_value += 0.025;
	}

	this->noise_value += 0.025;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

}
