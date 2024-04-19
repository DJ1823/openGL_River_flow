#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float riverOffset = 0.0; // Initial offset for river animation

void sun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void)
{
    glClearColor(0.0, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Ground Color
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 300);
    glVertex2d(0, 300);
    glEnd();

    // River
    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(250, 150 - riverOffset); // Adjust Y coordinate based on offset
    glVertex2d(400, 150 - riverOffset); // Adjust Y coordinate based on offset
    glVertex2d(450, 300);
    glEnd();

    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(300, 150 - riverOffset); // Adjust Y coordinate based on offset
    glVertex2d(250, 0 - riverOffset);   // Adjust Y coordinate based on offset
    glVertex2d(400, 0 - riverOffset);   // Adjust Y coordinate based on offset
    glVertex2d(450, 150 - riverOffset); // Adjust Y coordinate based on offset
    glEnd();

    glColor3ub(100, 149, 237);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 200);
    glVertex2d(0, 300);
    glVertex2d(500, 300);
    glVertex2d(500, 200);
    glEnd();

    // Hills 1
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(-40, 300);
    glVertex2d(200, 300);
    glVertex2d(100, 450);
    glEnd();

    // Hills 2
    glColor3ub(218, 165, 40);
    glBegin(GL_POLYGON);
    glVertex2d(150, 300);
    glVertex2d(350, 300);
    glVertex2d(250, 400);
    glEnd();

    // Hills 3
    glColor3ub(184, 134, 11);
    glBegin(GL_POLYGON);
    glVertex2d(300, 300);
    glVertex2d(520, 300);
    glVertex2d(400, 450);
    glEnd();

    // House Tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(50, 150);
    glVertex2d(70, 150);
    glVertex2d(70, 300);
    glVertex2d(50, 300);
    glEnd();

    // Tree leaf
    glColor3ub(0, 128, 0);
    sun(30, 40, 35, 320);
    glColor3ub(0, 128, 0);
    sun(30, 40, 85, 320);
    glColor3ub(0, 128, 0);
    sun(25, 30, 45, 370);
    glColor3ub(0, 128, 0);
    sun(30, 30, 70, 370);
    glColor3ub(0, 128, 0);
    sun(25, 30, 55, 400);
    //sun design
    glColor3ub(255, 215, 0);
    sun(25, 30, 175, 400);

    glFlush();
    glutSwapBuffers();
}

void animate(int value)
{
    riverOffset += 0.5; // Adjust the speed of animation as needed
    if (riverOffset > 300) // Reset the river offset if it goes beyond the screen
        riverOffset = 0.0;

    glutPostRedisplay(); // Request continuous redisplay for animation
    glutTimerFunc(50, animate, 0); // Call animate function after 50 milliseconds
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Scenery");
    init();
    glutDisplayFunc(display);
    animate(5); // Start the animation loop
    glutMainLoop();
    return 0;
}