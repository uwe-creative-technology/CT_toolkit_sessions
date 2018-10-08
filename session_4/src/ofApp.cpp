#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofxEspeakSynth::ESParam es;
//    es.language="en";
//    es.gender=1;
//    es.age=85;
//    spk.setup(es);
//    
//    spk.speak("Dario. Pluto. Paperino. Kashimastro. Openframeworks. Opengl. Synth. Voice.");
    
//    log.start("/usr/bin/espeak");
   // log.start("say");
//
  //  log.LogAudio("Hello World");
    
    system("say 'this is a quick test' &");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if(key == ' ')
//        spk.speak("keyboard pressed!");
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
    string message;
    message ="mouse is at";
    system("say message &");

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
