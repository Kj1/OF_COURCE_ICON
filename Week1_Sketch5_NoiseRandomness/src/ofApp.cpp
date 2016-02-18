#include "ofApp.h"

//our circle variables
int circlePositionX;
int circlePositionY;


//--------------------------------------------------------------
void ofApp::setup(){
	//set circle position
	circlePositionX = 50;
	circlePositionY = ofGetHeight() / 2; //to start in the center

	// set background
	ofSetBackgroundColor(ofColor(0, 0, 0));
	
	// we want nice looking circles
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
	//change circle position 2 pixels to the right
	circlePositionX = circlePositionX + 2.;

	// Make it return to start
	if (circlePositionX > ofGetWidth() + 50) {
		circlePositionX = -50;
	}



	//TASK: make the height random
	// we use ofRandom(minimum, maximum) to generate a random number between both values
	circlePositionY = ofRandom(0, ofGetHeight());
	// any guesses to how this will look?


	// So we want our Y-value not to be completely random.  
	// For this, we can use ofNoise().
	// ofNoise() generates a random number between 0 and 1, 
	// but it correlates to previous values.  
	// IE it is far more likely after value 0 to have something like 0.1
	// ofNoise() also takes 1 or more parameters; to determine the output value.
	// for this we need a 'unique' parameter which changes each draw function.
	// What is ideal?  Time!
	//   The function ofGetElapsedTimef() returns the time since the program 
	//   opened in seconds
	// 
	// If we want to randomize our Y position, we get:
	// circlePositionY = ofNoise(ofGetElapsedTimef());

	//	nothing happens?   Remember: ofNoise returns a value between 0 & 1, so
	//  we have to multiply this by the screen height to get nice results.
	//  TASK: randomize our Y position over the screen height, we get:
	
	//  circlePositionY = ofGetHeight() * ofNoise(ofGetElapsedTimef());
	
	//TASK: make it go slower or faster by manipulating the time
		

	//now the circle 'stutters'.  This is due to rounding of integers.
	// remember: circlePositions are "ints" or integers.
	// They represent numbers such as 0, 10, -3, etc, but not decimals!
	// 
	// to use decimal numbers, one has to use 'float' or floating point numbers:
	// 0.345, -23.45, ...
	//
	// Your computer interpretes all fixed values without decimal as integer,
	// and values with a '.' are floats.
	// If you add an int with a float, the float is converted automatically to
	// an integer by dropping everyting after the digit (no rounding!).
	// thus: 
	// 1 + 1 = 2
	// 1 + 0.9 = 1
	// 1 - 0.1 = 0
	// 1.0 + 0.9 = 1.9
	// 1.0 - 0.1 = 0.9
	
	// TASK: change all variables to float values
	//

	// We thusfar learned two variables: float & int
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
