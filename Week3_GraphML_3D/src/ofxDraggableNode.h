#include "ofMain.h"
#include "ofNode.h"
#include "ofxGui.h"


class ofxDraggableNode : public ofNode {
public:
	ofSpherePrimitive sphere;

	ofxDraggableNode(float radius = 50.0f);
	void init(float radius, ofPoint pos, ofColor color, string _text, ofEasyCam* cam);
	ofEasyCam* cam;

	void customDraw();
	void drawGui();
	void drawLines();

	ofMaterial material;

	bool isInside(ofPoint p) const;

	void drawText();

	void mouseDragged(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args); 
	void mouseReleased(ofMouseEventArgs & args);
	void mouseScrolled(ofMouseEventArgs & args) {}
	void mouseEntered(ofMouseEventArgs & args) {}
	void mouseExited(ofMouseEventArgs & args) {}
	void mouseMoved(ofMouseEventArgs & args) {}

	ofParameter<float> radius;
	ofParameter<ofVec3f> position;
	ofParameter<ofColor> color;
	string text;

	vector<ofxDraggableNode*> connectedNodes;

	void connectToNode(ofxDraggableNode* node);
protected:
	ofxPanel* gui;
	ofParameter<bool> draggingNode;
	bool viewFromHere;
};