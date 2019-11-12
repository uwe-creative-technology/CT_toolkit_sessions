#include "ofApp.h"


// Dan Buzzo 2019 -
// http://buzzo.com
// https://github.com/danbz
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2019-20
// https://github.com/uwe-creative-technology
// http://uwecreativetechnology.com
// timelapse video of Stoke's Croft, Bristol, UK ©dan buzzo


//--------------------------------------------------------------
void ofApp::setup(){
    // load a video file from disk from the bin/data folder
    // put your own file here and change the filename
    vidPlayer.load("stokes-croft-timelapse.m4v");
    vidPlayer.setLoopState(OF_LOOP_NORMAL); // set our initial loop style
    loopStyle = "Normal";
    b_playing = true;
    speed = 1.0;
    vidPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    vidPlayer.update(); // update the frames from the video file
}

//--------------------------------------------------------------
void ofApp::draw(){
    string elapsedTime;
    int elapsedPercent;
    
    
    vidPlayer.draw(10, 10); // draw the currnet video frame to screen
   
    elapsedPercent =   vidPlayer.getPosition() * 100; // get the current position of the video 'playhead'
    elapsedTime = ofToString( elapsedPercent );
    ofSetColor(255);
    
    // draw a white bar showing play position
    ofDrawRectangle(10, vidPlayer.getHeight()+10, ofMap(vidPlayer.getPosition(), 0, 1, 0, vidPlayer.getWidth()), 12);
    ofSetColor(0);
    // draw a the percentage played at the end of the play bar
    ofDrawBitmapString(elapsedTime + "%", ofMap(vidPlayer.getPosition(), 0, 1, 0, vidPlayer.getWidth()) - 20 ,  vidPlayer.getHeight() + 20);
    ofSetColor(255);
    // draw some onscreen information about speed and loop style
    ofDrawBitmapString("speed: " + ofToString( speed ) + " x, Loopstyle: " + ofToString( loopStyle) , 10, ofGetHeight() -10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            vidPlayer.setLoopState(OF_LOOP_NORMAL); // change the video looping style
            loopStyle = "normal";
            break;
            
        case '2':
            vidPlayer.setLoopState(OF_LOOP_PALINDROME); // change the video looping style
            loopStyle = "palindrome";
            break;
            
        case '3':
            vidPlayer.setLoopState(OF_LOOP_NONE); // change the video looping style
            loopStyle = "none";
            break;
            
        case ' ':
            if (b_playing){ // if our video is playing then pause
                vidPlayer.setPaused(true);
                b_playing=!b_playing;
            } else { // if our video is paused then play
                vidPlayer.setPaused(false);
                b_playing=!b_playing;
            }
            break;
            
        case '+':
        case '=':
            speed +=0.1; // increase the playback speed of the video
            vidPlayer.setSpeed(speed); // a speed change causes the video to play
            vidPlayer.setPaused(!b_playing); // so we reset video to playing or paused
            break;
            
        case '-':
        case '_':
            speed -=0.1; // decrease the playback speed of the video
            vidPlayer.setSpeed(speed); // a speed change causes the video to play
            vidPlayer.setPaused(!b_playing); // so we reset video to playing or paused
            break;
            
        case 'f':
            ofToggleFullscreen();
        default:
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
    ofRectangle vidRect;
    vidRect.set(10, 10, vidPlayer.getWidth(), vidPlayer.getHeight());
    
    // get the mouse position and 'scrub' the video as we drag left and right inside the videorectangle
    if (vidRect.inside(x,y)){ // check to see if mouse press xy is inside the video rectangle
        vidPlayer.setPosition( ofMap(x, 0, vidPlayer.getWidth(), 0, 1.0) );
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofRectangle vidRect;
    vidRect.set(10, 10, vidPlayer.getWidth(), vidPlayer.getHeight());
    
    if (vidRect.inside(x,y)){ // check to see if mouse press xy is inside the video rectangle
        if (b_playing){ // if our video is playing then pause
            vidPlayer.setPaused(true);
            b_playing=!b_playing;
        } else { // if our video is paused then play
            vidPlayer.setPaused(false);
            b_playing=!b_playing;
        }
    }
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
