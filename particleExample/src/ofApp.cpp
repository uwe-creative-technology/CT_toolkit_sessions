#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // look through all the 'particle' objects in the 'particles' vector and instruct each one to 'update' itself
    for (int i=0; i<particles.size();i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    // look through all the 'particle' objects in the 'particles' vector and instruct each one to 'draw' itself
    for (int i=0; i<particles.size();i++){
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    // when the mouse is clicked and dragged make a new particle object
    // and set it's initial x,y position to the mouse x,y position by
    // passing the mouseX and mouseY to the constructor routine as parameters

    particle newParticle( mouseX, mouseY);
    // push the new particle we just made onto the back of the vector 'particles'
    particles.push_back(newParticle);
}

//--------------------------------------------------------------

particle::particle(int startX, int startY){
    // this is the constructor routine, called when we make a new object of our particle class defined in the header
    x = startX;
    y = startY;
    vx = ofRandom( -2, 2);
    vy = ofRandom( -2, 2);
    size =2;
}
//--------------------------------------------------------------

particle::~particle(){
    // destructor
}
//--------------------------------------------------------------

void particle::update(){
    // update the particle x,y position by incrementing each by the velocity vx and vy
    x = x + vx;
    y = y + vy;
}

//--------------------------------------------------------------

void particle::draw(){
    ofDrawCircle(x, y, size);
}
