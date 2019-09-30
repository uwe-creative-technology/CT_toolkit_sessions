#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth =  640;  // try to grab at this size from the camera.
    camHeight = 480;
    xSteps = 0;
    
    // ask the video grabber for a list of attached camera devices.
    // put it into a vector of devices
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    // loop through and print out the devices to the console log
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    // set the ID of the camera we will use
    vidGrabber.setDeviceID(0);
    // set how fast we will grab frames from the camera
    vidGrabber.setDesiredFrameRate(30);
    // set the width and height of the camera
    vidGrabber.initGrabber(camWidth, camHeight);
    // set up our pixel object to be the same size as our camera object
    videoInverted.allocate(camWidth,camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    ofSetVerticalSync(true);
    
    ofBackground(100, 100, 100); // set the background colour to dark grey
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    ofPixels & pixels = vidGrabber.getPixels();
    
    for (int y=0; y<camWidth; y++ ) { // loop through all the pixels on a line
        ofColor color = pixels.getColor( xSteps, y); // get the pixels on line ySteps
        videoInverted.setColor(xSteps, y, color);
    }
    
    videoTexture.loadData(videoInverted);
    
    if ( xSteps >= camHeight ) {
        xSteps = 0; // if we are on the bottom line of the image then start at the top again
    }
    xSteps += 1; // step on to the next line. increase this number to make things faster
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    vidGrabber.draw(0, 0); // draw our plain image
    videoTexture.draw( camWidth, 0, camWidth, camHeight); // draw the video texture we have constructed
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'f' || key == 'F'){
        ofToggleFullscreen();
    }    
}
