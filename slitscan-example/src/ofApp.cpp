#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth =  640;  // try to grab at this size from the camera.
    camHeight = 480;
    y = 0;
    
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
    vidGrabber.setDesiredFrameRate(60);
    // set the width and height of the camera
    vidGrabber.initGrabber(camWidth, camHeight);
    // set up our pixel object to be the same size as our camera object
    videoInverted.allocate(camWidth,camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100, 100, 100);
    vidGrabber.update();
    
    ofPixels & pixels = vidGrabber.getPixels();
    
    for (int x=0; x<camWidth; x++ ) { // loop through all the pixels on a line
        ofColor color = pixels.getColor( x,  y); // get the pixels on line y
        videoInverted.setColor(x, y, color);
        
    }
    videoTexture.loadData(videoInverted);
    
    if (y>=camHeight) {
        y=0; // if we are on the bottom line of the image then start at the top again
    } else {
        y+=1; // otherwise step on to the next line.
        // y+=2; // uncomment this instead to step on two lines at a time.

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber.draw(0, 0);
    videoTexture.draw( camWidth, 0, camWidth, camHeight);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // in fullscreen mode, on a pc at least, the
    // first time video settings the come up
    // they come up *under* the fullscreen window
    // use alt-tab to navigate to the settings
    // window. we are working on a fix for this...
    
    // Video settings no longer works in 10.7
    // You'll need to compile with the 10.6 SDK for this
    // For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
    // http://forum.openframeworks.cc/index.php?topic=10343
    if(key == 's' || key == 'S'){
        vidGrabber.videoSettings();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
