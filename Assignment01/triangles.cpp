/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/

float fill = 1;

float roofHeight = 0.18;

float leftWall = 0.07;
float rightWall = 0.65;
float floorHeight = 0.81;

float doorHeight = 0.5;
float leftDoor = 0.27;
float rightDoor = 0.4;

float windowHeight = 0.25;



//Roof
Triangle(-0.04, roofHeight, 0.72, roofHeight, 0.35, -0.45, fill, 0, 0);


//BottomLeft blue
Triangle(leftWall, roofHeight, rightWall, floorHeight, leftWall, floorHeight, 0, 0, fill);
Triangle(leftWall, roofHeight, rightWall, floorHeight, rightWall, roofHeight, 0, 0, fill);


//bottomLeft yellow door
Triangle(leftDoor, doorHeight, rightDoor, floorHeight, leftDoor, floorHeight, fill, fill, 0);
//Topright door
Triangle(leftDoor, doorHeight, rightDoor, floorHeight, rightDoor, doorHeight, fill, fill, 0);




//bottomLeft left window
Triangle(0.17, 0.27, 0.27, 0.42, 0.17, 0.42, fill, fill, 0);
//topRight left window
Triangle(0.17, 0.27, 0.27, 0.42, 0.27, 0.27, fill, fill, 0);

//bottomleft right window
Triangle(0.45, 0.26, 0.56, 0.4, 0.45, 0.4, fill, fill, 0);
//topRight right window
Triangle(0.45, 0.26, 0.56, 0.4, 0.56, 0.26, fill, fill, 0);