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
    // ofDrawRectangle(10, 10, 200, 50);
    
    // We notice the coordinate system used by OF: (0,0) is top-left,
    // and everything is measured in pixels
    
    // cout << "hello there ! " << endl; // this is a CONSOLE OUTPUT - it sends messages from inside our application to a debug console . it will print text inside quotes "hello" and also variables eg; currentTime, myCount etc - we pipe together different things to be output using the << symbols and end the line to be out put with  'endl'
    
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
    
    // 6: COLOR: we can change the colour that our DRAW commands use
    // with the ofSetColor(red,green,blue)  where each part (red,green,blue) needs to be a value between 0-255
    // 0 is no colour and 255 is full color ** note the american spelling **
    // this means that
    // ofSetColor(0, 0, 0); // will draw in black
    // ofSetColor(255, 255, 255); // will draw in white
    // ofSetColor(255, 0, 0); // will draw in maximum red
    // ofSetColor(0, 255, 0); // will draw in maximum blue
    // ofSetColor(0, 0, green); // will draw in maximum green
    // ofSetColor(100, 100, 100); // will draw in a mid grey

    // uncomment the line below to try it out, change the color values to find a color you like.
    // ofSetColor(100, 100, 100);
    // there are many resources that can hekp you find the RGB value for a colour you want
    // https://rgbcolorcode.com is one of many websites that will give colour values in many different formats
    
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
    //
    
    // We have learned simple ways to *****OUTPUT***** things to the console and the screen from inside our program.
    // We could also output things to speakers, printers, files on your hard-drive, electric motors or controllers or even send things over the internet
    
    // NEXT STAGES:
    // Getting ****INPUT**** to your program
    
    // here we will be getting input from outside your program and using it to add interactivity to your project
    // uncomment the line below to use the mouseX function to get the X position of the mouse
    // cout << mouseX << endl;
    // get the x and y position of the mouse
    // cout << "mouseX: " << mouseX << " mouseY: " << mouseY << endl;
    
    // we can find out lots of things about the environment your application runs in - from the width of an attached screen to the date and time, the state of any keyboard or mouse and data from a camera, microphone or other peripheral attached to your computer.
    // this means we can take many kinds of INPUT, decide on what do do wth that information and then OUTPUT it where we like.
    // this could be using a microphone input to control video output to a projector. Or input from the mouse to create sound output to attached speakers or many more complex examples.
    
    // here we use the mouse ****input**** to alter our drawing ***output*****
    // ofDrawRectangle(10, 10, mouseX, mouseY);
    
    // try some of these below and think of one of your own to add
    // ofSetColor(mouseX, mouseY, 100);
    // ofDrawCircle(500, 500, mouseY);
    
    
    // Conclusion:
    // here we use the mouseX and mouseY to set the position of where we draw a circle
    // ofDrawCircle(mouseX, mouseY, 100);
    // this gives us INPUT to and  OUTPUT from our application or system.
    // all our applications with work like this.
    // in future work we will try different inputs and outputs
    // we will look at what our applications can do to transform our input information into
    // new creative types of outputs

    // HINT:
    // if you look in the 'Bin' folder of your project you will find the completed 'executable' file that you have compiled. you could copy this and send it to your friends or keep it in another folder as a record of the finished programs you have made
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
