#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set the width and height for our mesh and initial rendering values
    width = 50;
    height = 50;
    bmessyMesh = false;
    bdrawWireFrame = true;
    
    ofBackground(255); // set the window background to white
    
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
    if (bmessyMesh) {
        for (int i = 0; i < mainMesh.getNumVertices(); i++){ // find the total of all the vertices in the mesh and loop through them
            ofVec3f newPosition = mainMesh.getVertex(i); // get the current x,y,z position of this vertex
            newPosition.z = ofRandom(-1.0, 1.0); // set the z value of it to a new random number
            mainMesh.setVertex(i, newPosition); // update the position of the vertex with the new co-ordinates
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    mainCam.begin(); 
    
    if (bdrawWireFrame){ // choose to draw our mesh as wireframe or point cloud
        mainMesh.drawWireframe();
    } else {
        mainMesh.drawVertices();
    }
    mainCam.end();
    
    //draw the controls as text on the screen
    ofSetColor(100);
    string msg = "f: toggle full screen, spacebar: random zvalue in meshvertices, w: draw wireframe or point cloud";
    ofDrawBitmapString(msg, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key) { // use a switch statement to evaluate which key is pressed
        case 'f':
            ofToggleFullscreen();
            break;
            
        case ' ':
            bmessyMesh = !bmessyMesh;
            break;
            
        case 'w':
            bdrawWireFrame = !bdrawWireFrame;
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

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
