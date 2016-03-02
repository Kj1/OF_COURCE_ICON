#include "ofApp.h"

map<string, Node> nodes;

void ofApp::setup(){
	ofSetCircleResolution(50);
	loadXml();
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto &n : nodes)
		n.second.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor(100), ofColor(20));
	for (auto &n : nodes)
		n.second.drawLines();
	for (auto &n : nodes)
		n.second.drawCirles();
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


void ofApp::exit() {
	ofXml graphsxml;
	graphsxml.load("graph.xml"); // now get the buffer as a string and make XML
	graphsxml.setTo("graphml");
	for (int i = 0; i < graphsxml.getNumChildren(); i++) {
		graphsxml.setToChild(i);
		for (int nodesandedges = 0; nodesandedges < graphsxml.getNumChildren(); nodesandedges++) {
			graphsxml.setToChild(nodesandedges);
			if (graphsxml.getName() == "node") {
				string id = graphsxml.getAttribute("id");
				graphsxml.removeContents();
				graphsxml.addValue("locationX", ofToString(nodes[id].location.x));
				graphsxml.addValue("locationY", ofToString(nodes[id].location.y));
				graphsxml.addValue("colorR", ofToString((int)nodes[id].color.r));
				graphsxml.addValue("colorG", ofToString((int)nodes[id].color.g));
				graphsxml.addValue("colorB", ofToString((int)nodes[id].color.b));
				graphsxml.addValue("colorA", ofToString((int)nodes[id].color.a));
				graphsxml.addValue("radius", ofToString(nodes[id].radius));
			}
			graphsxml.setToParent();
		}
		graphsxml.setToParent();
	}
	graphsxml.save("graph.xml");
}

void ofApp::loadXml() {
	ofFile graphs;
	graphs.open("graph.xml");
	ofBuffer buffer = graphs.readToBuffer(); // read to a buffer
	ofXml graphsxml;
	graphsxml.loadFromBuffer(buffer.getText()); // now get the buffer as a string and make XML
	graphsxml.setTo("graphml");
	ofLog() << graphsxml.getName();

	for (int i = 0; i < graphsxml.getNumChildren(); i++) {
		graphsxml.setToChild(i);
		string idGraph = graphsxml.getAttribute("id");
		string edgedefault = graphsxml.getAttribute("edgedefault");
		ofLog() << "\t" << graphsxml.getName() << " ID: " << idGraph << ", edgedefault: " << edgedefault;

		//first do nodes
		for (int nodesandedges = 0; nodesandedges < graphsxml.getNumChildren(); nodesandedges++) {
			graphsxml.setToChild(nodesandedges);
			if (graphsxml.getName() == "node") {
				string id = graphsxml.getAttribute("id");
				ofLog() << "\t\t" << graphsxml.getName() << " ID: " << id;

				nodes[id].location.x = graphsxml.getValue("locationX", ofRandomWidth());
				nodes[id].location.y = graphsxml.getValue("locationY", ofRandomHeight());
				nodes[id].color = ofColor(0);

				nodes[id].color.r = (int)graphsxml.getValue("colorR", ofRandom(128, 255));
				nodes[id].color.g = (int)graphsxml.getValue("colorG", ofRandom(128, 255));
				nodes[id].color.b = (int)graphsxml.getValue("colorB", ofRandom(128, 255));
				nodes[id].color.a = (int)graphsxml.getValue("colorA", ofRandom(128, 255));
				nodes[id].radius = graphsxml.getValue("radius", ofRandom(30, 60));
				nodes[id].text = id;
			}
			graphsxml.setToParent();
		}

		//then do connections
		for (int nodesandedges = 0; nodesandedges < graphsxml.getNumChildren(); nodesandedges++) {
			graphsxml.setToChild(nodesandedges);
			if (graphsxml.getName() == "edge") {
				string src = graphsxml.getAttribute("source");
				string target = graphsxml.getAttribute("target");
				ofLog() << "\t\t" << graphsxml.getName() << " src: " << src << ", target: " << target;
				nodes[src].connectToNode(&nodes[target]);
			}
			graphsxml.setToParent();
		}

		graphsxml.setToParent();
	}
}