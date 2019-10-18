#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int maxBoxes;
    maxBoxes = 1000; // we set a value here so we can see what's going on easily rather than filling our code with 'magic' numbers
    
    for (int i=0; i<maxBoxes; i++){
        box newBox; // we create a new 'box' object using our custom class we defined in the header file
        boxes.push_back(newBox);  // we push our new 'box' into the end of our vector list of all the boxes we make
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
 for (int i =0; i < boxes.size(); i++){
     boxes[i].wobble(); // we loop through all the box objects in our boxes vector and tell each one in turn to 'wobble'
 }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i =0; i < boxes.size(); i++){
        boxes[i].draw(); // we loop through all the box objects in our boxes vector and tell each one in turn to draw itself
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------

box::box(){
    // constructor  - here we construct a box setting it's basic parameters inside it.
    width = 20;
    height = 20;
    x = ofRandom(ofGetWidth());
    y = ofRandom(ofGetHeight());
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

//--------------------------------------------------------------
box::~box(){
    // destructor
}

//--------------------------------------------------------------
void box::draw(){
    ofSetColor(color);
    ofDrawRectangle(x, y, width, height);
}

//--------------------------------------------------------------

void box::wobble(){
    width = ofRandom(15,25);
    height = ofRandom(15,25);
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}
