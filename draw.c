The program you provided is an example of a simple line drawing application using OpenGL. It allows the user to draw lines on the 
screen by clicking and dragging the mouse. It also provides menu options for undoing the last drawn line, clearing the entire drawing, and exiting the program.

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


const int MAX_ITEMS = 1000;
struct ItemData {
   double x1, y1;
   double x2, y2;
};

struct ItemData items[MAX_ITEMS]; 
int itemCt = 0;  
int width;   
int height;  
bool dragging = false;  
int dragModifiers;      
void handleStartDraw(double x, double y, int modifiers) {
   if (itemCt == MAX_ITEMS) {
      printf("Line draw limit has been reached..!\n");
      return;
   }
   dragging = true;   
   dragModifiers = modifiers;
   items[itemCt].x1 = x;   
   items[itemCt].y1 = y;   
   items[itemCt].x2 = x;   
   items[itemCt].y2 = y;   
   itemCt++;
}

void handleContinueDraw(double x, double y) {
   if (!dragging)
      return;
   int current = itemCt - 1;                         
   bool shifted = ((dragModifiers & GLUT_ACTIVE_SHIFT) != 0);
   if (shifted) {  
      if (abs(x - items[current].x1) > abs(y - items[current].y1))
         y = items[current].y1;
      else
         x = items[current].x1;
   }
   items[current].x2 = x;  
   items[current].y2 = y;
   glutPostRedisplay();    
}

void handleFinishDraw(double x, double y) {
   if (!dragging)
      return;
   dragging = false;   
   int current = itemCt - 1;  
   if (items[current].x1 == items[current].x2 &&
      items[current].y1 == items[current].y2) {
         itemCt--;
   }
   glutPostRedisplay();  
}

void menu(int op){
   if(op==1){
      itemCt--;
      glutPostRedisplay();
   }
   if(op==2){
      itemCt=0;
      glutPostRedisplay();
   }
   if(op==3)
      exit(0);
}

void menuFunction(){
    glutCreateMenu(menu);
    glutAddMenuEntry("Undo",1);
    glutAddMenuEntry("Clear",2);
    glutAddMenuEntry("Home",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(){
}

void drawItems() {
   glColor3f(1,1,1);  
   for (int i = 0; i < itemCt; i++) {
      glBegin(GL_LINES);
         glVertex2f(items[i].x1, items[i].y1);
         glVertex2f(items[i].x2, items[i].y2);
      glEnd();
   }
}

void initTransformation(double x1, double x2, double y1, double y2) {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(x1,x2,y1,y2);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void display(){
   glClearColor(0,0,0,1);  
   glClear(GL_COLOR_BUFFER_BIT);   
   glViewport(0,0,width-0,height);
   initTransformation(0,1,0,1);
   drawItems();
   glViewport(0,0,0,height);  
   initTransformation(0,0,0,height);
   glutSwapBuffers();  
}

void reshape(int new_width, int new_height){
   height = new_height;
   width = new_width;
   glViewport(0,0,width,height);
}

void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON) {
      double wx, wy;  
      wx = (double)(x-0)/(width-0);
      wy = (double)(height-y)/height;
      if (state == GLUT_DOWN)
         handleStartDraw(wx,wy,glutGetModifiers());
      else
         handleFinishDraw(wx,wy);
   }
}

void motion(int x, int y) {
   if (dragging) {
      double wx, wy;  
      wx = (double)(x-0)/(width-0);
      wy = (double)(height-y)/height;
      handleContinueDraw(wx,wy);      
   }
}

int main(int argc, char **argv) {
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
   glutInitWindowSize(650,700);       
   glutInitWindowPosition(300,10);    
   glutCreateWindow("CG Mini Project : Line Art"); 
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);       
   glutMotionFunc(motion);     
   menuFunction();
   init();
   glutMainLoop();
}


The output primitive function used in this program is:

1. `glBegin(GL_LINES)` and `glEnd()` - Defines the beginning and end of a group of line segments to be drawn.
2. `glVertex2f(x, y)` - Specifies the coordinates of a vertex for a line segment.

These functions are used to draw lines on the screen based on the user's input.








The attribute functions used in this program are:

1. `glClearColor()` - Sets the clear color for the color buffer.
2. `glClear()` - Clears buffers to preset values, in this case, clears the color buffer.
3. `glViewport()` - Sets the viewport transformation, which maps the normalized device coordinates to window coordinates.
4. `glMatrixMode()` - Sets the current matrix mode.
5. `glLoadIdentity()` - Replaces the current matrix with the identity matrix.
6. `gluOrtho2D()` - Defines a 2D orthographic projection matrix.
7. `glBegin()` - Starts the definition of a primitive.
8. `glEnd()` - Ends the definition of a primitive.
9. `glVertex2f()` - Specifies a 2D vertex.
10. `glutPostRedisplay()` - Marks the current window as needing to be redisplayed.
11. `glutSwapBuffers()` - Swaps the buffers of the current window.

These functions are used to set up the display, handle mouse input, draw lines, and manage the menu options. They manipulate the OpenGL state and control the 
rendering of lines on the screen.



The program you provided is an example of a simple line drawing application using OpenGL. It allows the user to draw lines on the screen by clicking and dragging the mouse. It also provides menu options for undoing the last drawn line, clearing the entire drawing, and exiting the program.

Here's a breakdown of the geometric transformations used in the program:

1. Translation: There is no explicit translation transformation in this program. The translation of mouse coordinates to world coordinates is handled in the `mouse()` function.

2. Rotation: There is no rotation transformation in this program.

3. Scaling: There is no scaling transformation in this program.

4. Shearing: There is no shearing transformation in this program.

5. Reflection: There is no reflection transformation in this program.

6. Projection: The function `initTransformation()` is used to set up the projection transformation using `gluOrtho2D()`. It maps the world coordinates to the viewport coordinates to ensure that the drawn lines are displayed correctly on the screen.



glViewport(x, y, width, height): This function sets the viewport, which determines the mapping of the normalized device coordinates to the window coordinates. It specifies the rectangular region of the window where the drawing will occur. In the program, glViewport() is called in the display() function and the reshape() function to set the viewport dimensions.

glMatrixMode(GL_PROJECTION): This function sets the current matrix mode to GL_PROJECTION, which indicates that subsequent matrix operations will be applied to the projection matrix stack.

glLoadIdentity(): This function replaces the current matrix with the identity matrix. It is used to reset the current matrix to an initial state.

gluOrtho2D(left, right, bottom, top): This function sets up a two-dimensional orthographic viewing region. It defines a 2D orthographic projection matrix using the specified left, right, bottom, and top coordinates. In the program, gluOrtho2D() is called in the initTransformation() function to set the orthographic projection for different viewports.

glMatrixMode(GL_MODELVIEW): This function sets the current matrix mode to GL_MODELVIEW, indicating that subsequent matrix operations will be applied to the modelview matrix stack.

These viewing functions are used to define the projection and transformation matrices for different viewports in the program.  
They control how the objects are displayed on the screen and allow for different views of the scene             







handleStartDraw(double x, double y, int modifiers): Handles the start of drawing a line by storing the initial coordinates of the line.

handleContinueDraw(double x, double y): Handles the continuation of drawing a line by updating the end coordinates based on the current mouse position. It also considers the SHIFT key modifier to constrain the line to horizontal or vertical.

handleFinishDraw(double x, double y): Handles the completion of drawing a line by updating the end coordinates and checking if the line is zero-length. If the line is zero-length, it is discarded.

menu(int op): Handles the menu options selected by the user. If option 1 is selected, it removes the last drawn line. If option 2 is selected, it clears all the drawn lines. If option 3 is selected, it exits the program.

menuFunction(): Creates a menu and attaches it to the right mouse button. It adds menu entries for undoing, clearing, and going back to the home state.

drawItems(): Draws the lines stored in the items array using OpenGL's GL_LINES primitive.

initTransformation(double x1, double x2, double y1, double y2): Initializes the projection and modelview matrices for different viewports.

display(): Handles the display of the window. It clears the color buffer, sets up the viewports, calls drawItems() to draw the lines, and swaps the buffers.

reshape(int new_width, int new_height): Handles the window reshape event by updating the width and height variables and setting the viewport accordingly.

mouse(int button, int state, int x, int y): Handles mouse events. If the left button is pressed, it calls handleStartDraw() with the normalized mouse coordinates. If the left button is released, it calls handleFinishDraw() with the normalized mouse coordinates.

motion(int x, int y): Handles mouse motion events when the left button is held down. It calls handleContinueDraw() with the normalized mouse coordinates.











