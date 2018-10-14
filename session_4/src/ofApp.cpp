#include "ofApp.h"


// Dan Buzzo 2018 - github.com/uwe-creative-technology/
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2018-19
// http://uwecreativetechnology.com


// NB on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
// use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.

//--------------------------------------------------------------
void ofApp::setup(){

    synth.load("ghostpad.aif");  // load sound files from data folder into sound objects
    beats.load("percussion.aif");
    synth.setVolume(0.75f); // set the parameters for sound objects
    beats.setVolume(0.75f);
    beats.setMultiPlay(false);
    synth.setMultiPlay(true);
    
    // use the inbuild OS speech commands to 'say' text to speech - tested in osx
    system("say 'this is a quick test' &");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    string helpText;
    helpText  = "press 1 for system speech, 2 for beats, 3 for synth. Click on left or right of screen to play at different speeds/pans" ;
    ofDrawBitmapString(helpText, 50,ofGetHeight()-50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case '1':
            system("say 'i'm sorry dave, i can't do that' & ");
            break;
        case '2':
            beats.play();
            break;
            
        case '3':
            synth.play();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    float widthStep = ofGetWidth() / 2.0f;
    if (x < widthStep){
        synth.play();
        system("say 'synth' &");
        synth.setSpeed( 0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*10);
        synth.setPan(ofMap(x, 0, widthStep, -1, 1, true));
    } else if (x >= widthStep && x < widthStep*2){
        beats.play();
        system("say 'beats' &");
        beats.setSpeed( 0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*10);
        beats.setPan(ofMap(x, 0, widthStep, -1, 1, true));
    }
}
