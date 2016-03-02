#include "ofxDraggableNode.h"

ofxDraggableNode::ofxDraggableNode(float _radius) {
	draggingNode = false;
}

void ofxDraggableNode::init(float _radius, ofPoint _pos, ofColor _color, string _text, ofEasyCam* cam) {
	this->cam = cam;
	ofRegisterMouseEvents(this);
	gui = new ofxPanel();
	gui->setup("Node setup");
	gui->add(radius.set("Radius", _radius, 1, 200));
	gui->add(position.set("position", _pos, ofPoint(-500, -500, -500), ofPoint(500, 500, 500)));
	gui->add(color.set("color", _color));
	gui->add(draggingNode.set("show this", false));
	text = _text;
	//sphere.setParent(*this);
}

void ofxDraggableNode::connectToNode(ofxDraggableNode* node) {
	connectedNodes.push_back(node);
}

void ofxDraggableNode::customDraw()
{

	setGlobalPosition(position);
	sphere.setRadius(radius);
	sphere.rotate(0.5, 0.0, 1.0, 0.0);
	material.setShininess(120);
	ofColor col = color;
	material.setSpecularColor(col);
	material.setAmbientColor(col);
	material.begin();
	ofDrawSphere(radius);// sphere.draw();
	material.end();
	ofSetColor(0);
	//sphere.drawWireframe();

}

void ofxDraggableNode::drawText()
{
	ofPoint screenCenter = cam->worldToScreen(this->getGlobalPosition());
	ofDrawBitmapStringHighlight(text, screenCenter.x, screenCenter.y);
}



void ofxDraggableNode::drawLines()
{
	ofPushStyle();
	ofSetLineWidth(10);
	for (auto& lineTo : connectedNodes) {

		ofPoint v1 = getGlobalPosition();
		ofPoint v2 = lineTo->getGlobalPosition();
		ofPoint v2r = v2 - v1;
		ofVec3f z(0, 1, 0);
		ofVec3f ax = z.getCrossed(v2r);
		float l = sqrt(v2r.dot(v2r));
		float angle = 180.0 / PI * acos(z.dot(v2r) / l);

		ofCylinderPrimitive c;

		c.setGlobalPosition(getGlobalPosition()/ 2. + lineTo->getGlobalPosition() / 2.);
		c.rotate(angle, ax.x, ax.y, ax.z);
		c.set(10, getGlobalPosition().distance(lineTo->getGlobalPosition()));

		material.setSpecularColor(ofColor::darkGray);
		material.setAmbientColor(ofColor::black);
		material.begin();
		c.draw();	
		material.end();

	}
	ofPopStyle();
}

void ofxDraggableNode::drawGui() {
	if (draggingNode) {
		gui->draw();
	}
	else {
	}
}

bool ofxDraggableNode::isInside(ofPoint p) const {
	ofPoint screenCenter = cam->worldToScreen(this->getGlobalPosition());
	ofPoint screenCenterRadius = cam->worldToScreen(this->getGlobalPosition() + cam->getUpDir() * radius);
	float r = screenCenter.distance(screenCenterRadius); //radius on screen
	return p.distance(screenCenter) < r;
}

void ofxDraggableNode::mousePressed(ofMouseEventArgs & args) {
	if (isInside(ofPoint(args.x, args.y)) && args.button == GLFW_MOUSE_BUTTON_RIGHT) {
		draggingNode = !draggingNode;
		if (draggingNode) {
			cam->disableMouseInput();

			ofPoint screenCenter = cam->worldToScreen(this->getGlobalPosition());
			gui->setPosition(screenCenter.x, screenCenter.y);
		}
		else
			cam->enableMouseInput();
	}

}
void ofxDraggableNode::mouseReleased(ofMouseEventArgs & args) {

}

void ofxDraggableNode::mouseDragged(ofMouseEventArgs& action) {

}

