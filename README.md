FUNDAMENTALS OF COMPUTER GRAPHICS -  PROJECT 3 REPORT

Author: Valentin KAO <valentin.kao@epitech.eu>
		张有请 - 2017280242
		
The purpose of this project is to implement an OpenGl program in which a
colored cube is drawn with lighting effects. 
- The cube rotates anticlockwise around the X axis.
- The cube sides are different colors.
- The center of the cube is (2, 4, 5)
- Variety of light : including ambient light, specular light, etc.

---------------------------------------------------------------------------
VIDEO CAPTURE
---------------------------------------------------------------------------

The video capture of my program named screenrecord.mp4, is available from
the root of the folder.
From 0s to 13s, the program is running without any user input.
From 13s to the end, the user tries various features of the program :
- turning the light on/off
- changing the light0 position.

---------------------------------------------------------------------------
REQUIREMENTS
---------------------------------------------------------------------------
•	GCC 5 or later
•	CMake 3.9 or later
•	OpenGL, GLUT and SOIL libraries.

The code hasn't been tested on Windows but should work on Visual Studio
2015 and later.

---------------------------------------------------------------------------
BUILD AND USAGE
---------------------------------------------------------------------------
From the folder in which you found this report, please enter the following
command lines.
1.		mkdir build && cd build
2.		cmake ..
3.		make

Once the compilated was successful, you can execute the program. 
Here is the usage of the program.

	./assignment3 [--width=x] [--height=y] [--title=”Assignment 3”]
	
---------------------------------------------------------------------------
FLAGS – OPTIONS	DESCRIPTION	DEFAULT
---------------------------------------------------------------------------
width, w	Set the width of the window	900
height, h	Set the height of the window	900
title, t	Set the title of the window	“Assignment 3”

---------------------------------------------------------------------------
SOFTWARE DESIGN
---------------------------------------------------------------------------
In order to implement future project easily, I define a simple application
design. Those three classes are singletons avoiding any multiple instances.

- Application class
- GraphicalCore class
- Engine class

---------------------------------------------------------------------------
ALGORITHM IMPLEMENTED
---------------------------------------------------------------------------

The Engine constructor will initialize few options of OpenGL : normalizing,
depth, and lightning. Moreover, you will setup two lights.

Then, the function Engine::Update is called at each frame : 
- First, it updates the position of the 2 lights.
- It changes camera position to (1, 2, 2.5) thanks to the function 
  gluLookAt to see the cube in position (2, 4, 5).
- Then, it draws face by face, the cube by changing the face's material each
  time.

---------------------------------------------------------------------------
FUNCTIONNALITIES
---------------------------------------------------------------------------
- By pressing the key ESC, you close the program properly.
- The lights 0 and 1 can switch on/off by pressing the key '1' and the key '2'
- With arrows of your keyboard, you can move the light0 position. 
