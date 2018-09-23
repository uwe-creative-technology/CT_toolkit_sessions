#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // Example 1: draw a circle using openframeworks ("ofDrawCircle")
    // at the given coordinates (x=400, y=400) and a given radius (r=60)
    ofDrawCircle(400, 400, 60);
    
    // 2: Draw a rectangle ("ofDrawRectangle")
    // at the given coordinates (x = 10 and y = 10)
    // and with a width of w = 200 and a height = 50
    ofDrawRectangle(10, 10, 200, 50);
    
    // We notice the coordinate system used by OF: (0,0) is top-left,
    // and everything is measured in pixels
    
    
    
    // 3: TASK Draw a line, from one point to another
    // We use ofLine (x1, y1, x2, y2)
    // where the point x1,y1 is the from point
    // and x2, y2 is the to-point
    //
    // example: draw a line from (600,600) to (700,700)
    
    
    // 4: TASK:  draw a square using four lines
    //    tip:   determine where the 4 corners should be,
    //           then draw lines from corner 1 to corner 2,
    //          corner 2 to corner 3, 3 to 4 and 4 to 1.
    
    
    
    
    // 5: TASK: draw a diagonal cross on the screen
    //    TIP:  To get the current width & height of the window to find the points
    //            you can use "ofGetWidth()" to get the width
    //            and use "ofGetHeight()" to get the height
    
    
    
    // SUMMARY:
    // - Every line of code should end with a semicolon ";"
    //
    // - Locations are depicted by using two numbers: the pixels on the X-axis and Y-axis.
    //   Comma's should be used to show the system those are two different numbers
    //
    // - The coordinate system used is (0,0) for top left, x increasing
    //   to right and y increasing downwards.
    //
    // - You can draw simple shapes in the draw() section of the cpp file
    //
    // - Some simple shapes to draw:
    //      ofDrawLine draws a line
    //      ofDrawCircle draws a circle
    //      ofDrawRectangle draws a rectangle
    //      ofDrawRectRounded draws a rounded rectangleµ
    //      ofDrawTriangle draws a triangle
    //      ofDrawEllipse draws an ellipse
    //      ofDrawCurve Draws a bezier curve 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
