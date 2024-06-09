#include <stdio.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle = 0;
int x=100,y=0,x11=450,y11=300,x22=600,y22=300;
int r=0,op,a,a1,a2,b,i,j,width=650,height=700,first=0;
int mouseX = 0, mouseY = 0; 
static int submenu;
static int mainmenu;
#define MAX_PTS 1000
int ptListX[MAX_PTS]; // X coordinate ot the input points 
int ptListY[MAX_PTS]; // Y coordinate of the input points
int noOfPts = 0;      // number of input points
int closed = 0;       // marke polygon "closed"

void init(){
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void drawhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawsubhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void mouse(int button, int state, int x, int y){
    mouseX = x;
    mouseY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if (closed || noOfPts >= MAX_PTS - 1)
            noOfPts = 0; // restart the polygon
        closed = 0;
        ptListX[noOfPts] = mouseX; 
        ptListY[noOfPts] = mouseY;
        noOfPts ++;
    }
    if ( button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN )
        closed = 1;
}
void front(){
    char cn[] = "CANARA ENGINEERING COLLEGE";
        drawhead(-445, 800, 0, cn);
        char pn[] = "                  Mangaluru";
        drawsubhead(-275, 750, 0, pn);
        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawhead(-675, 550, 0, dn);
        char prn[] = "A Mini Project On";
        drawsubhead(-175, 350, 0, prn);
        char pro[] = "Line Art using OpenGL";
        drawhead(-275, 250, 0, pro);
        char pb[] = "PROJECT BY: ";
        drawhead(-715, -200, 0, pb);
        char p1[] = "SHREYAS S";
        drawhead(-625, -350, 0, p1);
        char p1u[] = "4CB20CS106";
        drawsubhead(-625, -400, 0, p1u);
        char p2[] = "SHARATH M";
        drawhead(-625, -500, 0, p2);
        char p2u[] = "4CB20CS094";
        drawsubhead(-625, -550, 0, p2u);
        char in[] = "Click right mouse button for menu";
        drawhead(-375, -800, 0, in);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(0, 0, 0.1, 0.9);
    if (r == 0){        //Front Page
        front();
        glutSwapBuffers();
    }
    if(r==1){
        system("./animate.out");
        r=0;     
    }
    if(r==3){ 
        system("./draw.out");
        r=0;
    }
    glutPostRedisplay();
    glutSwapBuffers();
}


void menu(int op){
    if(op==1)
        r=1;
    if(op==2)
        r=2;
    if(op==3)
        r=3;
    if(op==4)
        exit(0);
}
void menuFunction(){
    char subMenu = glutCreateMenu(menu);
  
    glutCreateMenu(menu);
    glutAddMenuEntry("Random Lines",1);
   
    glutAddMenuEntry("Draw",3);
    glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(300,10);
    glutInitWindowSize(650, 700);
    glutCreateWindow("CG Mini Project : Line Art");
    init();
    glutDisplayFunc(display);
    menuFunction();
    glutMainLoop();
    return 0;
}








The program defines the following output primitive functions:

glRasterPos3f(x, y, z) - This function sets the raster position for pixel operations. It specifies the coordinates of the raster position in three-dimensional space. It is used in the drawhead() and drawsubhead() functions to position the text on the screen.

glutBitmapCharacter(font, character) - This function renders a bitmap character from a specified font at the current raster position. It is used in the drawhead() and drawsubhead() functions to render text characters on the screen.

glClear(GL_COLOR_BUFFER_BIT) - This function clears the color buffer. It is used in the display() function to clear the screen before drawing new frames.

glClearColor(red, green, blue, alpha) - This function sets the clear color for the color buffer. It is used in the display() function to set the background color of the screen.

glutSwapBuffers() - This function swaps the front and back buffers of the current window. It is used in the display() function to update the displayed image with the newly rendered frame.

glutPostRedisplay() - This function marks the current window as needing to be redisplayed. It is used in the display() function to request a redisplay of the window.

glutCreateMenu(menu) - This function creates a new pop-up menu. It is used in the menuFunction() function to create a menu that can be attached to the right mouse button.

glutAddMenuEntry(label, value) - This function adds an entry to the current menu. It is used in the menuFunction() function to add menu entries for different options.

glutAttachMenu(button) - This function attaches the current menu to a mouse button. It is used in the menuFunction() function to attach the menu to the right mouse button.

glutInitWindowPosition(x, y) - This function sets the initial position of the window. It is used in the main() function to set the initial position of the application window.

glutInitWindowSize(width, height) - This function sets the initial size of the window. It is used in the main() function to set the initial size of the application window.

glutCreateWindow(title) - This function creates a top-level window with the specified title. It is used in the main() function to create the application window.

glutInit(&argc, argv) - This function initializes the GLUT library and processes any command-line arguments. It is used in the main() function to initialize GLUT.

glutDisplayFunc(func) - This function sets the display callback for the current window. It is used in the main() function to specify the function that will be called whenever the window needs to be redrawn.

glutMainLoop() - This function enters the GLUT event processing loop. It is used in the main() function to start the main event loop and handle user input.

exit(status) - This function terminates the program with the specified exit status. It is used in the menu() function to exit the program when the "Exit" menu option is selected.




















glColor3f() - Sets the current color for drawing.
glRasterPos3f() - Sets the current raster position for bitmap operations.
glutBitmapCharacter() - Renders a bitmap character using the specified font.