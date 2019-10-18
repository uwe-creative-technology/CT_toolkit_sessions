#pragma once

#include "ofMain.h"

class box { // this is our custom class
public:
    int width;
    int height;
    int x;
    int y;
    ofColor color;
    
    void draw();
    void wobble();
    box(); // constructor
    ~box(); // destructor
};

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        
    vector<box> boxes; // here we make a vector list to contain our new 'box' objects
};
