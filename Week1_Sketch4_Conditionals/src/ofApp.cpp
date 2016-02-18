#include "ofApp.h"

//our circle variables
int circlePositionX;
int circlePositionY;


//This part runs only once in the beginning of the app
void ofApp::setup(){
	//set circle position
	circlePositionX = 50;
	circlePositionY = ofGetHeight() / 2; //to start in the center

	// set background
	ofSetBackgroundColor(ofColor(0, 0, 0));
	
	// we want nice looking circles
	ofSetCircleResolution(100);
}

//This is whwere we place non-drawing related code, it executes before the draw() 
void ofApp::update(){
	//change circle position 3 pixels to the right
	circlePositionX = circlePositionX + 3;


	// TASK: how do we know if the circle 'fell off' the screen?
	// in words, we would say something like:
	// is the x position is larger then the screen width?

	// TASK: what do we do when this happens?  
	// in words: this would be something like
	// IF the x position is larger then screen width; reset the position 

	// We can almost translate this literally to code
	// if (circlePositionX > ofGetWidth() ) {
	//	circlePositionX = 0;
	// }
	
	
	// This is called a conditional statement; or simply 'if condition'. 
	// It is one of many 'control structures'.
	// We add the { } brackets to indicate 'what code' should be executed
	// if the condition has been fulfilled.  This can be multiple lines.


	// TASK:  When the circle re-appears, make it higher or lower.


	// Notice we added this behavior without touching the drawing code!

	// TASK: the circle only passes the border half before jumping to 
	//       the beginning.  How to make it completely dissapear 'outside' 
	//		 the screen, and re-appear before the screen?

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//pick a color
	ofSetColor(255, 0, 255);

	//draw our circle at location X & Y
	ofDrawCircle(circlePositionX, circlePositionY, 50);
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
