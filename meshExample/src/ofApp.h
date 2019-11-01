#pragma once

#include "ofMain.h"

// Dan Buzzo 2019 -
// http://buzzo.com
// https://github.com/danbz
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2019-20
// https://github.com/uwe-creative-technology
// http://uwecreativetechnology.com



class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);

    
    // make a new mesh object
    ofMesh mainMesh;
    ofEasyCam mainCam;
    int width, height;
    bool b_messyMesh, b_perlinMesh, b_drawWireFrame;
    float perlinRange, perlinHeight;
};
