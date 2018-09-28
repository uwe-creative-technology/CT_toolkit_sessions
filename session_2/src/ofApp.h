#pragma once

#include "ofMain.h"

// This example is  based on the Processing "ASCII Video" example by Ben Fry
// and it is designed to demonstrate how to re-interpret live video as text
// to make it look like some good old ASCII art!
//
// For more information regarding this example take a look at the README.md.

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // here we declare a new instance of the ofVideoGrabber object and call it vidGrabber
    ofVideoGrabber vidGrabber;
    
    // we set up two variables of type integer (int), these are whole numbers, as opposed to type float that are floating point numbers with decimal places.
    // These variables are set up in our header file so have program 'scope'. That means that every part of our program we write in the ofApp.cpp file can look inside these variables and put and get the numbers there.
    
    int camWidth;
    int camHeight;
    
    // these parts are used in our super cool ASCII video hack.
    //    // uncomment them to declare a new variable or type 'string' and also to set the typeface we are using
    //     string asciiCharacters;
    //     ofTrueTypeFont font;
    
    
    //    // these parts are for our inverted video hack
    //    // a pixels object to contain our inverted pixels
    //     ofPixels videoInverted;
    //     // a texture object
    //     ofTexture videoTexture;
};
