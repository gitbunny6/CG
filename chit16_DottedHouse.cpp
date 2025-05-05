#include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void displayPoint(int x, int y){
    glColor3f(0,1,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
float x01, x2, y01, y2;
int ch;

void DottedLine(float x1, float x2, float y1, float y2){
    float dx , dy , p;
    int i;
    float incx, incy, inc1, inc2;
    float x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(dx<0) {
        dx=-dx;
    }
    if(dy<0) {
        dy=-dy;
    }
    if(x2<x1){
        incx = -1;
    }
    if(y2<y1){
        incy = -1;
    }
    x=x1;
    y=y1;
    if(dx>dy){
        p = 2*dy - dx;
        inc1 = 2*(dy-dx);
        inc2 =2*dy;
        for(i=0; i<dx ; i++){
            if (i%4 == 0){
                if(p>=0){
                    x = x + inc1;
                    y = y + inc2;
                    p = p + incx;
                }else{
                    x = x +incx;
                    p = p+inc2;
                }
                displayPoint(x,y);
            }
            else{
                if (p>=0){
                    x = x+incx;
                    y = y+incy;
                    p = p+inc1;
                }else{
                    x = x +incx;
                    p = p+inc2;
                }
            }
        }
    }else{
        p = 2*dy - dx;
        inc1 = 2*(dy-dx);
        inc2 =2*dy;
        for(i=0; i<dy; i++){
            if (i%4 ==0){
                if (p>=0){
                    x = x+incx;
                    y = y+incy;
                    p = p+inc1
                }else{
                    y = y+incy;
                    p = p+inc2;
                }
                displayPoint(x,y);
            }
            }
            else{
                if(p >= 0){
                    x = x+incx;
                    y = y+incy;
                    p = p+inc1;
                }
                else{
                    y = y+incy;
                    p = p+inc2;
                }
            }
            
        }
    }
    glFlush();
}
void myMouse(int button , int state, int x, int y){
    static int xst, yst, pt = 0;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if ( pt==0){
            xst = x;
            yst = y;
            pt = pt +1;
        }else{
            DottedLine(xst, yst, x, y);
            xst =x;
            yst = y;
            }
        }
        else if(button ==GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
            pt = 0;
        }
        glFlush();
    }
    void initialize(void){
        glClearColor(1.0, 1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        gluOrtho2D(0,600, 600, 0);
    }
    void primitives(void){
        glColor3f(1,0,0);
        glutMouseFunc(myMouse);
    }
    
    int main(int argc, char **argv){
        glutInit(&argv, argc);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(600,600);
        glutCreateWindow("DOTTED HOUSE");
        initialize();
        glutDisplayFunc(primitives);
        glutMainLoop();
        return 0;
    }
