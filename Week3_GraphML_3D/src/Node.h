#pragma once

#include "ofMain.h"

class Node {

public:

	vector<Node*> connectedNodes;

	ofPoint location;
	ofColor color;
	float	radius;
	string	text;

	ofImage image;

	Node() {
		location = ofPoint(ofGetWidth(), ofGetHeight());
		color = ofColor(255);
		text = "";
		connectedNodes.clear();
		setupEvents();
	}

	void connectToNode(Node* node) {
		connectedNodes.push_back(node);
	}


	void update() {
	}

	void drawLines() {
		ofPushStyle();
		ofSetLineWidth(2);
		for (auto& lineTo : connectedNodes) {
			ofSetColor(255);
			ofLine(location, lineTo->location);
		}
		ofPopStyle();
	}

	void drawCirles() {
		ofPushMatrix();
		ofPushStyle();
		ofTranslate(location);
		ofFill();
		ofSetColor(color);
		ofCircle(0, 0, radius);
		ofNoFill();
		ofSetColor(255,255,255,220);
		ofCircle(0, 0, radius);
		ofSetColor(0);
		ofDrawBitmapString(text, 0, 0);
		ofPopMatrix();
		ofPopStyle();
	}





// EVENT SYSTEM
	bool mousePressedMoving;
	bool mousePressedMovingRadius;

	void setupEvents() {
		mousePressedMoving = false;
		mousePressedMovingRadius = false;
		ofRegisterMouseEvents(this);


	}
	void mouseMoved(ofMouseEventArgs & args) {

	}


	void mousePressed(ofMouseEventArgs & args) {
		if (args.button == OF_MOUSE_BUTTON_LEFT &&
			location.distance(ofPoint(ofGetMouseX(), ofGetMouseY())) < radius)
			mousePressedMoving = true;

		if (args.button == OF_MOUSE_BUTTON_RIGHT &&
			location.distance(ofPoint(ofGetMouseX(), ofGetMouseY())) < radius)
			mousePressedMovingRadius = true;
	}

	void mouseDragged(ofMouseEventArgs & args) {
		if (mousePressedMoving) {
			location.x = ofGetMouseX();
			location.y = ofGetMouseY();
		}
		if (mousePressedMovingRadius) {
			radius = location.distance(ofPoint(ofGetMouseX(), ofGetMouseY()));
		}
	}

	void mouseReleased(ofMouseEventArgs & args) {
		mousePressedMoving = false;
		mousePressedMovingRadius = false;
	}

	void mouseScrolled(ofMouseEventArgs & args) {

	}

	void mouseEntered(ofMouseEventArgs & args) {

	}

	void mouseExited(ofMouseEventArgs & args) {

	}
};
