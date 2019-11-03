#include "ofApp.h"
 
// Dan Buzzo 2019 -
// http://buzzo.com
// https://github.com/danbz
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2019-20
// https://github.com/uwe-creative-technology
// http://uwecreativetechnology.com


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofBackground(255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    font.load("monospace", 24);
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
    //serial.setup(0, baud); //open the first device
    //serial.setup("COM4", baud); // windows example
    serial.setup("tty.usbserial-A9007QuL", baud); // mac osx example
    //serial.setup("/dev/ttyUSB0", baud); //linux example
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Simple if statement to inform user if Arduino is sending serial messages.
    if (serial.available() < 0) {
        sensorValue = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            //byte data is being writen into byteData as int.
            byteData = serial.readByte();
        
            //byteData is converted into a string for drawing later.
            sensorValue = "value: " + ofToString(byteData);
        }
    }
    cout << sensorValue << endl; // output the sensorValue
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    msg = "press key a, b or c to test serial:\n";
    font.drawString(msg, 50, 60);
    font.drawString("sensorValue: " + sensorValue, 50, 100);
  
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
    switch (key) {
        case 'a':
            serial.writeByte('a');
            cout << "flash green LED" << endl;;
            break;
            
        case 'b':
            serial.writeByte('b');
            cout << "flash red LED" << endl;
            break;
            
        case 'c':
            serial.writeByte('c');
            cout << "flash white LED" << endl;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
    
}
