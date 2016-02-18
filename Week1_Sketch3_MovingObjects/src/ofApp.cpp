#include "ofApp.h"

// In C++, and in programming in general, whenever you have a 
// value that you want to change, you create a "variable".
// Variables come in different shapes and sizes depending on 
// what they represent, such as decimal numbers, whole numbers, 
// a letter, or a bunch of letters. In this case, we want to create 
// variables that can stand in for coordinates in our ofDrawCircle 
// function, so we will use 2 numbers: the x position and y position.

// we place them outside the draw method because we want them to 
// 'remember' their value; even after the draw method

// finally, each variable is defined by its type (a number, a word, etc)
// We start using 'integers', meaning regular numbers. 

int circlePositionX;
int circlePositionY;

// notice we do not give them initial values!


//--------------------------------------------------------------
void ofApp::setup(){
	// Remember, this is only called once, so it is an ideal place to 
	// set our starting position
	// This is called an assignment: we assign a value to a variable
	circlePositionX = 50;
	circlePositionY = ofGetHeight() / 2; //to start in the center

	// because we do not want to set the background color each time; 
	// we also do it here
	ofSetBackgroundColor(ofColor(0, 0, 0));
	
	// we want nice looking circles so we type
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//pick a color
	ofSetColor(255, 0, 255);

	//draw our circle at location X & Y
	ofDrawCircle(circlePositionX, circlePositionY, 50);

	// now if we want to move the circle, we have to change the position
	// each time we draw it
	circlePositionX = circlePositionX + 1;
	// this line reads: the new circlePositionX becomes our circlePositionX plus one
	// This is incremental + 1, and happens often in code, so you can make this
	// more readable using the shorthand: "circlePositionX++;"
	
	// however, this has nothing to do with drawing things, so this should not
	// be placed here (so you can avoid obfuscating your code).
	// a better place to manipulate variabls would be the update() method
	// which is called prior to drawing

	// TASK: make the circle move faster

	// TASK: make it drop down

	// TASK:  the circle just moves outside the screen; and continious into oblivion.
	// We thus want to reset the position of the circle every once in a while.
	// Openframeworks gives easy acces to the keyboard, using the keypressed method below
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// TASK: every code here runs when a key is pressed.
	// What should we write to reset the position of the circle?

	
	
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
