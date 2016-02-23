#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofSetBackgroundColor(0, 0, 0);
	ofSetFrameRate(60);
	ofSetWindowTitle("Cool drawing");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (ofGetKeyPressed(' ')) {
		ofBackground(0, 0, 0);
	}
	if (ofGetKeyPressed('c')) {
		int maxRadius = 60;  // Increase for a wider brush
		int radiusStepSize = 5;  // Decrease for more circles (i.e. a more opaque brush)
		int alpha = 3;  // Increase for a more opaque brush
		int maxOffsetDistance = 100;  // Increase for a larger spread of circles
									  // draw smaller and smaller circles and layering (increasing) opaqueness

		for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
			float angle = ofRandom(ofDegToRad(360.0));
			float distance = ofRandom(maxOffsetDistance);
			float xOffset = cos(angle) * distance;
			float yOffset = sin(angle) * distance;
			ofSetColor(255, 103, 0, alpha);
			ofDrawCircle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, radius);
		}
	}

	if (ofGetKeyPressed('l')) {
		int numLines = 30;
		int minRadius = 25;
		int maxRadius = 125;
		for (int i = 0; i < numLines; i++) {
			float angle = ofRandom(ofDegToRad(360.0));
			float distance = ofRandom(minRadius, maxRadius);
			float xOffset = cos(angle) * distance;
			float yOffset = sin(angle) * distance;
			float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);  // Make shorter lines more opaque
			ofSetColor(255, alpha);
			ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffset, ofGetMouseY() + yOffset);
		}
	}

	if (ofGetKeyPressed('t')) {
		ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

		int numTriangles = 3;
		int minOffset = 5;
		int maxOffset = 70;
		int alpha = 10;
		for (int t = 0; t<numTriangles; t++) {
			float offsetDistance = ofRandom(minOffset, maxOffset);

			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

			// Define a triangle at the origin (0,0) that points to the right
			ofVec2f p1(0, 15.0);
			ofVec2f p2(60, 0);
			ofVec2f p3(0, -15.0);

			float rotation = ofRandom(360); // The rotate function uses degrees!
			p1.rotate(rotation);
			p2.rotate(rotation);
			p3.rotate(rotation);

			// Shift the triangle to the mouse position
			p1 += mousePos;
			p2 += mousePos;
			p3 += mousePos;

			ofSetColor(255, 50);
			ofDrawTriangle(p1, p2, p3);
		}
	}
	ofSetColor(255);
	ofDrawBitmapStringHighlight("Press space to clear", 20, 20);
	ofDrawBitmapStringHighlight("Press c to draw circles", 20, 40);
	ofDrawBitmapStringHighlight("Press l to draw lines", 20, 60);
	ofDrawBitmapStringHighlight("Press t to draw triangles", 20, 80);
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
