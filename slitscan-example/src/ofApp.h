#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key); 
    
    // initiate a videograbber object and objects to put image pixel data into
    ofVideoGrabber vidGrabber;
    ofPixels videoInverted;
    ofTexture videoTexture;
    
    int camWidth, camHeight, xSteps;
    
};
