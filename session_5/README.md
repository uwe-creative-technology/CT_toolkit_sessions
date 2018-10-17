# UWE Bristol Creative Technology Toolkit session five

https://github.com/uwe-creative-technology/CT_toolkit_sessions


example code for the Creative Technology Toolkit module on Creative Technology MSc at UWE Bristol

http://uwecreativetechnology.com

Dan Buzzo, September 2018

https://github.com/danbz

https://buzzo.com



# Session 5

• Introduction to text processing
• Semantics
• Intelligence and algorithms
• Ambient systems


see also
• oF_root/examples/strings/sortingExample & regularExpressionExample
• oF_root/examples/input_output/loadTextFileExample & imageLoaderWebExample


* portions modified from oF sortingExample

### Learning Objectives

This example demonstrates how to sort a vector alphabetically, by word length or by word occurence. It shows you how to..
* load words from a file into a vector
* create custom sorting functions
* sort the vector using the function ```ofSort()```
* view text in 3D with easyCam
* load text from file using fileDialog
* load text from a remote URL on the web

also

This openFrameworks example demonstrates how to load a txt file from the web  

In this example, pay attention to the following code:

* Request to load an image using ```ofLoadURLAsync``` which passes the url, and a name for the request
* Handle the response from the request using ```void ofApp::urlResponse```
* Determine information about the fullfilled request by inspecting the status code ```response.status``` and the request name ```response.request.name```
* On exit of the application, unregister the application from being notified of the URL request completion using ```ofUnregisterURLNotification```
*

### Expected Behavior

When launching this app, you should see a screen with words circularly arranged on the right side.

Instructions for use:

* Press keys from ```1``` to ```4``` to switch sorting algorithms.
* press ```l``` to open file dialog to lad text file from disk
* press ```w``` to load a txt file from the web at a remote url
* press ```b``` to autorotate the circle in 3d

### Other classes used in this file

This Example uses the following classes:

* http://openframeworks.cc/documentation/graphics/ofTrueTypeFont/
* http://openframeworks.cc/documentation/utils/ofUtils/
