#pragma once

#include "ofMain.h"

class particle {
    
    
public:
    
    // our new particle class
    // with each object containing an x and y position,
    // and a vector direction as vx and vy and a size
    
    
    float x, y, vx, vy, size;
    
    // we also define two methods that the particle object understands
    void update();
    void draw();
    
    // and define a particle contructor and a destructor (the destructor is denoted by the tilde (~) character prefix
    // the contructor is expecting to be passed an initial x and y co-ordinate for the new particle
    particle(int x, int y);
    ~particle();
};

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void mouseDragged(int x, int y, int button);
        
    // define a vector containing our new particle class objects
    vector<particle> particles;
    
};
