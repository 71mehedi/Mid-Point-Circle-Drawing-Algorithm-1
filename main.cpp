#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

int r, pk;
int x = 0, y;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void drawMidpointCircle(GLint radius)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);

    x = 0;
    y = radius;
    pk = 1 - radius;

    while (x <= y)
    {
        if (pk < 0)
        {
            x = x + 1;
            y = y;
            pk = pk + (2 * x) + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            pk = pk + (2 * x) + 1 - (2 * y);
        }

        glVertex2i(x, y);
        glVertex2i(y, x);
        glVertex2i(x, -y);
        glVertex2i(y, -x);
        glVertex2i(-x, -y);
        glVertex2i(-y, -x);
        glVertex2i(-x, y);
        glVertex2i(-y, x);
    }
    glEnd();
    glutSwapBuffers();
}

void display(void)
{

    drawMidpointCircle(r);
}

int main(int argc, char **argv)
{
    printf("Enter the radius: ");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Circle Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
