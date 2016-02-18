#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// A color is a set of 4 channels: red, green, blue, alpha/transparancy
	// we use the helper class ofColor to work with colors
	// The default alpha is full on, meaning nothing transparent

	// each color channel is a number between 0 (off) and 255 (full on)
	// so red becomes R = 255, G = 0, B = 0, (A = 255)
	// This can be typed as "ofColor(255, 0, 0)" for red, 
	// and ofColor(0, 0, 0) for black.

	// example 1:  set background to black
	// to set our background to black, we use ofBackground(ofColor).
	ofBackground(ofColor(0, 0, 0));

	// example 2: we now draw a big red circle in the middle of the screen, 
	// for this we use ofSetColor(color), eg ofSetColor(ofColor(255, 0, 0));
	ofSetColor(ofColor(255, 0, 0));
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 300);
	//notice to find the middle part of the screen we get the width & height divided by 2
	
	
	// notice the circle being 'jagged'? 
	// Thats because a circle is just a set of lines.
	// we can improve this by using setCircleResolution.  Uncomment next line:
	// ofSetCircleResolution(100);
	// we only have to set this once, so we can move it to the setup above part.

	
	// TASK:  we draw another object, a square, somewhere on the screen outside the circle
	
	// Notice how the square also is the same color?
	// when we call "ofSetColor", it's like picking a crayon out of a box. 
	// Everything that gets drawn after that (below that line of code) 
	// will be drawn in that color until we call ofSetColor again.
	
	
	
	// TASK 3: now we want to add another, smaller circle, in a different color
	// We can also use 'predefined colors' by using the namespace identifier '::'
	ofSetColor(ofColor::blue);  
	
	
	
	
	// Both circles overlap, but we only see the blue in the center 
	// because of drawing order (first the red, then the blue).
	// However we can make a color that is a see-trough using alpha channels
	ofSetColor(ofColor(255, 255, 255, 128)); //128 indicates semi-transparent
	
	// TASK 4: draw a rectangle overlapping the middle part of the circles



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
