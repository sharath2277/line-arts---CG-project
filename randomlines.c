#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
int width=650, height=700,X,Y,i=0,j=0,A,B;
void Init(){
	gluOrtho2D(0,650,0,700);
}
void menu(int op){
   if(op==1)
      exit(0);
}

void time();
void menuFunction(){
    glutCreateMenu(menu);
    glutAddMenuEntry("Home",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void mouse(int button, int state, int x, int y){
    int mouseX = x;
    int mouseY = 700- y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(3);
		glColor3f(1,1,1);
		glBegin(GL_POINTS);
		glVertex2i(mouseX,mouseY);
		glEnd();
		X=mouseX;
		Y=mouseY;
		A=mouseX;
		B=mouseY;
		glutTimerFunc(0,time,0);
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
}
void time(){
	if(A>B){
		if(X==650 && Y<700){
			i=1;
		}else if(X<650 && Y==700){
			i=2;
		}else if(X==0 && Y<700){
			i=3;
		}else if(X<650 && Y==0){
			i=0;
		}
		if(i==0){
			X++;
			Y++;
		}
		else if(i==1){
			X--;
			Y++;
		}
		else if(i==2){
			X--;
			Y--;
		}
		else if(i==3){
			X++;
			Y--;
		}
		glBegin(GL_POINTS);
		glVertex2i(X,Y);
		glEnd();
	}else if(A<B){
		if(X==650 && Y<700){
			j=1;
		}else if(X<650 && Y==700){
			j=2;
		}else if(X==0 && Y<700){
			j=0;
		}else if(X<650 && Y==0){
			j=3;
		}
		if(j==0){
			X++;
			Y++;
		}else if(j==1){
			X--;
			Y--;
		}else if(j==2){
			X++;
			Y--;
		}else if(j==3){
			X--;
			Y++;
		}
		glBegin(GL_POINTS);
		glVertex2i(X,Y);
		glEnd();
	}else{
		if(X==650 && Y==700){
			X++;
			Y++;
		}
		else if(X==0 && Y==0){
			X++;
			Y++;
		}
		glBegin(GL_POINTS);
		glVertex2i(X,Y);
		glEnd();
	}

	glutTimerFunc(1000/360,time,0);
	glutSwapBuffers();
}
int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(650,700);
	glutInitWindowPosition(300,10);
	glutCreateWindow("CG Mini Project : Line Art");
	Init();
	glutDisplayFunc(display);
    glutMouseFunc(mouse);
	menuFunction();
	glutMainLoop();
}












The output primitive function used in this program is glBegin(GL_POINTS) and glVertex2i(X, Y). These functions are responsible for drawing individual points on the screen.

Here's a summary of their usage in the code:

In the mouse() function, glBegin(GL_POINTS) is called to specify that points will be drawn. Then, glVertex2i(mouseX, mouseY) is used to specify the coordinates of the point to be drawn based on the mouse click position.

In the time() function, glBegin(GL_POINTS) is used to specify that points will be drawn. Then, glVertex2i(X, Y) is used to specify the updated coordinates of the point to be drawn based on the motion logic.

Overall, these functions are used to draw points on the screen to create the line art effect.









gluOrtho2D() - Defines a 2D orthographic projection matrix.
glClear() - Clears buffers to preset values, in this case, clears the color buffer.
glPointSize() - Sets the size of rasterized points.
glColor3f() - Sets the current color for drawing.
glBegin() - Starts the definition of a primitive.
glEnd() - Ends the definition of a primitive.
glVertex2i() - Specifies a 2D vertex with integer coordinates.
glutTimerFunc() - Registers a timer callback function to be triggered after a specified time interval.
glutSwapBuffers() - Swaps the buffers of the current window.
glutInit() - Initializes the GLUT library.
glutInitDisplayMode() - Sets the initial display mode.
glutInitWindowSize() - Sets the initial window size.
glutInitWindowPosition() - Sets the initial window position.
glutCreateWindow() - Creates a top-level window.
glutDisplayFunc() - Sets the display callback for the current window.
glutMouseFunc() - Sets the mouse callback for the current window.
glutMainLoop() - Enters the GLUT event processing loop.
These functions are used to set up the display, handle mouse input, draw points, and manage the menu option. They manipulate the OpenGL state and 
control the rendering of points on the screen.








In the program you provided, there are no explicit geometric transformations applied using OpenGL. However, there is some movement
and animation of points on the screen based on specific conditions. Let's break down the movement and transformations present in
the program:

Translation: There is no translation transformation explicitly defined in the program.

Rotation: There is no rotation transformation explicitly defined in the program.

Scaling: There is no scaling transformation explicitly defined in the program.

Shearing: There is no shearing transformation explicitly defined in the program.

Reflection: There is no reflection transformation explicitly defined in the program.

Projection: The gluOrtho2D() function is used in the Init() function to set up an orthographic projection, defining the coordinate
system for the scene. It maps the scene's coordinate range to the screen's coordinate range.










