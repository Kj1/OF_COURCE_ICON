#include "ofApp.h"

ofBoxPrimitive box;
void ofApp::setup(){
	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	pointLight.setSpecularColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	pointLight2.setDiffuseColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	pointLight2.setSpecularColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	pointLight3.setDiffuseColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	pointLight3.setSpecularColor(ofFloatColor(0.5f, 0.5f, 0.5f));
	material.setShininess(120);
	material.setSpecularColor(ofColor(150, 150, 150, 255));
	ofSetSphereResolution(60);

	loadXml();
	ofSetFrameRate(60);
	box = ofBoxPrimitive(2000, 2000, 2000, 25, 25, 25);
	
}

//--------------------------------------------------------------
void ofApp::update(){

	pointLight.setPosition((5000*.5) + cos(ofGetElapsedTimef()*.5)*(5000*.3), 500 / 2, 500);
	pointLight2.setPosition((5000*.5) + cos(ofGetElapsedTimef()*.15)*(5000*.3),500*.5 + sin(ofGetElapsedTimef()*.7)*(5000), -300);
	pointLight3.setPosition(cos(ofGetElapsedTimef()*1.5) * 5000*.5,sin(ofGetElapsedTimef()*1.5f) * 5000*.5,cos(ofGetElapsedTimef()*.2) * 500);
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0);
	ofBackgroundGradient(ofColor(100), ofColor(20));
	ofEnableLighting();
		pointLight.enable();
		pointLight2.enable();
		pointLight3.enable();
		ofEnableDepthTest();
			cam.begin();
			box.drawWireframe();;
			//ofDrawGrid(500);
			//	ofDrawAxis(200);
			
				for (auto &n : nodes)
					n.second.draw();
				for (auto &n : nodes) 
					n.second.drawLines();
			cam.end();
		ofDisableDepthTest();
	ofDisableLighting();


	for (auto &n : nodes) n.second.drawText();
	for (auto &n : nodes) n.second.drawGui();
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
				graphsxml.addValue("locationX", ofToString(nodes[id].position.get().x));
				graphsxml.addValue("locationY", ofToString(nodes[id].position.get().y));
				graphsxml.addValue("locationZ", ofToString(nodes[id].position.get().z));
				graphsxml.addValue("colorR", ofToString((int)nodes[id].color.get().r));
				graphsxml.addValue("colorG", ofToString((int)nodes[id].color.get().g));
				graphsxml.addValue("colorB", ofToString((int)nodes[id].color.get().b));
				graphsxml.addValue("colorA", ofToString((int)nodes[id].color.get().a));
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
				ofPoint location;
				location.x = graphsxml.getValue("locationX", ofRandom(-500,500));
				location.y = graphsxml.getValue("locationY", ofRandom(-500, 500));
				location.z = graphsxml.getValue("locationZ", ofRandom(-500, 500));
				ofColor color = ofColor(0);

				color.r = (int)graphsxml.getValue("colorR", ofRandom(0, 255));
				color.g = (int)graphsxml.getValue("colorG", ofRandom(0, 255));
				color.b = (int)graphsxml.getValue("colorB", ofRandom(0, 255));
				color.a = (int)graphsxml.getValue("colorA", 255);
				float radius = graphsxml.getValue("radius", ofRandom(10, 30));
				string text = id;
				nodes[id].init(radius, location, color, text, &cam);
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