#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // drunkards walk random path example
    // danbuzzo dan@buzzo.com Nov 2018
    // for UWE Creative Technology Toolkit MSc course
    
    ofVec2f newPoint(0,0); // create a new point with 0,0 x and y values
    drunkardsSteps.push_back(newPoint); // push the newpoint to the back out out vector-list of points
    
    staggerSize =60; // set how far to stagger when we add staggers to the walk of points
    
    b_drawGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // cam.begin();
    int prevStepX = ofGetWidth()/2; // set up initial values to start drawing from - this is the centre of the screen
    int prevStepY = ofGetHeight()/2;
    int curStepX = prevStepX;
    int curStepY = prevStepY;
    
    for (int i=0; i<drunkardsSteps.size();i++){ // iterate though all the values in our vector of steps/points
        curStepX = drunkardsSteps[i].x;
        curStepY = drunkardsSteps[i].y;
        
        ofSetColor(255);
        ofDrawLine(prevStepX, prevStepY,curStepX, curStepY); // draw a line between the last point and the current point
        
        if (b_drawGui){
        ofSetColor(0);
        ofDrawBitmapString(i, curStepX, curStepY); // number the point
        }
        
        prevStepX = curStepX; // update the value of the previous point
        prevStepY = curStepY;
    }
    
    // cam.end();
    
    if (b_drawGui){
        ofDrawBitmapString("drunkards walk random number demo \npress space to make a big step, 'm' to stagger a little bit", 10, 10);

    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case ' ':
            addStep();
            break;
            
        case 'm':
            addStagger();
            break;
            
        case 'n':
            addNoiseStep();
            break;
            
        case 'f':
            ofToggleFullscreen(); // toggle full screen display
            break;
            
        case 'g':
            b_drawGui = !b_drawGui; //toggle the guid overlay on and off
            break;
    }
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

//--------------------------------------------------------------

void ofApp::addStep(){
    // generate a new step that is up to half the width/height of the screen, centered
    ofVec2f newStep(ofRandom(ofGetWidth()/2) + ofGetWidth()/4,ofRandom(ofGetHeight()/2) + ofGetHeight()/4);
    drunkardsSteps.push_back(newStep);
}

//--------------------------------------------------------------

void ofApp::addStagger(){
    // generate a new small step/stagger that is within +/- our staggerSize distance of the lsst step
    
    ofVec2f lastStep = drunkardsSteps[drunkardsSteps.size()-1];
    ofVec2f newStep(lastStep.x + ofRandom(-staggerSize, staggerSize), lastStep.y + ofRandom(-staggerSize, staggerSize));
    drunkardsSteps.push_back(newStep);
    cout << ofToString(lastStep) << " " << ofToString(newStep) << endl;
}

//--------------------------------------------------------------

void ofApp::addNoiseStep(){
    // generate a new step based on perlin noise
    ofVec2f lastStep = drunkardsSteps[drunkardsSteps.size()-1];
    ofVec2f newStep(lastStep.x + (ofNoise(lastStep.x) -0.5f) * staggerSize, lastStep.y + (ofNoise(lastStep.y) -0.5f) *staggerSize);
    drunkardsSteps.push_back(newStep);
    cout << ofToString(lastStep) << " " << ofToString(newStep) << endl;
}
