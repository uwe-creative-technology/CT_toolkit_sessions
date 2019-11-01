#include "ofApp.h"

// Dan Buzzo 2019 -
// http://buzzo.com
// https://github.com/danbz
// for UWE Bristol, Creative Technology MSc, Creative Technology Toolkit module 2019-20
// https://github.com/uwe-creative-technology
// http://uwecreativetechnology.com


//--------------------------------------------------------------
void ofApp::setup(){
    
    //set the width and height for our mesh and initial rendering values
    width = 50;
    height = 50;
    // set our rendering styles to false
    b_messyMesh = false;
    b_perlinMesh = false;
    b_drawWireFrame = true;
    // set the initial values to use for our perlinNoise
    perlinRange =1.0;
    perlinHeight = 5.0;
    
    ofBackground(255); // set the window background to white
    mainCam.setPosition(0, 0, 80); // set initial position for our easyCam 3D viewer
    
    // here we make the points inside our mesh
    // add one vertex to the mesh across our width and height
    // we use these x and y values to set the x and y co-ordinates of the mesh, adding a z value of zero to complete the 3d location of each vertex
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x<width; x++){
            mainMesh.addVertex(ofPoint(x-width/2,y-height/2,0));    // mesh index = x + y*width
            // this replicates the pixel array within the camera bitmap...
            mainMesh.addColor(ofFloatColor(0,0,0));  // placeholder for colour data, we'll get this from the camera
        }
    }
    
    // here we loop through and join the vertices together as indices to make rows of triangles to make the wireframe grid
    for (int y = 0; y<height-1; y++){
        for (int x=0; x<width-1; x++){
            mainMesh.addIndex(x+y*width);                // 0
            mainMesh.addIndex((x+1)+y*width);            // 1
            mainMesh.addIndex(x+(y+1)*width);            // 10
            
            mainMesh.addIndex((x+1)+y*width);            // 1
            mainMesh.addIndex((x+1)+(y+1)*width);        // 11
            mainMesh.addIndex(x+(y+1)*width);            // 10
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // change the z value for each vertex in our mesh
    if (b_messyMesh) {
        for (int i = 0; i < mainMesh.getNumVertices(); i++){ // find the total of all the vertices in the mesh and loop through them
            ofVec3f newPosition = mainMesh.getVertex(i); // get the current x,y,z position of this vertex
            newPosition.z = ofRandom(-1.0, 1.0); // set the z value of it to a new random number
            mainMesh.setVertex(i, newPosition); // update the position of the vertex with the new co-ordinates
            
        }
    }
    
    if (b_perlinMesh){
        // distort the z value of each point in our mesh with perlinNoise
        int i=0;
        for (int y = 0; y<height; y++){
            for (int x=0; x<width; x++){
                ofVec3f newPosition = mainMesh.getVertex(i);
                // use the ofMap function to map our x,y inputs to a variable outpur range so we can see different levels of complexity / density in the perlinNoise. then multiply the z distortion by our perlinHeight value to get amplitude of distortion.
                newPosition.z = ofNoise(ofMap(x, 0, width, 0, perlinRange),  ofMap(y, 0, height, 0, perlinRange) ) * perlinHeight;
                mainMesh.setVertex(i, newPosition); // update the position of the vertex with the new
                i++;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    mainCam.begin();
    
    if (b_drawWireFrame){ // choose to draw our mesh as wireframe or point cloud
        mainMesh.drawWireframe();
    } else {
        mainMesh.drawVertices();
    }
    mainCam.end();
    
    //draw the controls as text on the screen
    ofSetColor(100);
    string msg = "f: toggle full screen, spacebar: random z-value in meshvertices, w: draw wireframe or point cloud \np: use PerlinNoise for z-value in meshvertices\nUp-key Down-key: increase/decrease PerlinNoise input range \nRight-key Left-key: increase/decrease amplitude of Perlin Noise distortion \nclick and drag in window to move camera";
    ofDrawBitmapString(msg, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key) { // use a switch statement to evaluate which key is pressed
        case 'f':
            ofToggleFullscreen();
            break;
            
        case ' ':
            b_messyMesh = !b_messyMesh;
            break;
            
        case 'w':
            b_drawWireFrame = !b_drawWireFrame;
            break;
            
        case 'p':
            b_perlinMesh = !b_perlinMesh;
            break;
            
        case OF_KEY_UP: // increase or decrease the range/detail of the perlinNoise value
            perlinRange +=0.1;
            break;
            
        case OF_KEY_DOWN: // increase or decrease the range/detail of the perlinNoise value
            if (perlinRange > 0.1){
                perlinRange -=0.1;
            }
            break;
            
        case OF_KEY_RIGHT: // increase or decrease the height of the perlinNoise distortion
            perlinHeight +=0.1;
            break;
            
        case OF_KEY_LEFT: // increase or decrease the height of the perlinNoise distortion
            if (perlinHeight > 0.1){
                perlinHeight -=0.1;
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

