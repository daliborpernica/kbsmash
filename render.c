#include <GL/freeglut.h>
#include "shape.h"

void onRender(void *data)
{
    shape *shp = (shape*)data;
    float r = shp->r;
    float a, b, c, d, e, f, g, h;

    glColor4f(shp->R, shp->G, shp->B, shp->A);
    glPushMatrix();
    glTranslatef(shp->x, shp->y, 0);
    glRotatef(shp->angle, 0, 0, 1);

    switch (shp->type)
    {
        case triangle:
            a = -r * 0.5f;
            b = r * 0.86602540378443864676f;
            glBegin(GL_TRIANGLES);
                glVertex2f(r,  0);
                glVertex2f(a , b);
                glVertex2f(a, -b);
            glEnd();
            glScalef(0.5f, 0.5f, 1.0f);
            glBegin(GL_TRIANGLES);
                glVertex2f(-r,  0);
                glVertex2f(-a , -b);
                glVertex2f(-a, b);
            glEnd();
            break;
        case square:
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(r, 0);
                glVertex2f(0, r);
                glVertex2f(-r, 0);
                glVertex2f(0, -r);
            glEnd();
            glBegin(GL_TRIANGLES);
                glVertex2f(r, 0);
                glVertex2f(0, r);
                glVertex2f(-r, 0);
            glEnd();
            break;
        case pentagon:
            a = r * 0.30901699437494742410f;
            b = r * 0.9510565162951535721f;
            c = -r * 0.80901699437494742410f;
            d = r * 0.58778525229247312916f;
            glBegin(GL_POLYGON);
                glVertex2f(r, 0);
                glVertex2f(a, b);
                glVertex2f(c, d);
                glVertex2f(c, -d);
                glVertex2f(a, -b);
                glVertex2f(r, 0);
            glEnd();
            glScalef(0.5f, 0.5f, 1.0f);
            glBegin(GL_POLYGON);
                glVertex2f(r, 0);
                glVertex2f(a, b);
                glVertex2f(c, d);
                glVertex2f(c, -d);
                glVertex2f(a, -b);
                glVertex2f(r, 0);
            glEnd();
            break;
        case circle:
            a = r * 0.5f;
            b = r * 0.98480775301220805936f;
            c = r * 0.17364817766693034885f;
            d = r * 0.93969262078590838406f;
            e = r * 0.34202014332566873304f;
            f = r * 0.86602540378443864676f;
            g = r * 0.76604444311897803522f;
            h = r * 0.64278760968653932633f;
            glBegin(GL_POLYGON);
                glVertex2f(r, 0);
                glVertex2f(b, c);
                glVertex2f(d, e);
                glVertex2f(f, a);
                glVertex2f(g, h);
                glVertex2f(h, g);
                glVertex2f(a, f);
                glVertex2f(e, d);
                glVertex2f(c, b);
                glVertex2f(0, r);
                glVertex2f(-c, b);
                glVertex2f(-e, d);
                glVertex2f(-a, f);
                glVertex2f(-h, g);
                glVertex2f(-g, h);
                glVertex2f(-f, a);
                glVertex2f(-d, e);
                glVertex2f(-b, c);
                glVertex2f(-r, 0);
                glVertex2f(-b, -c);
                glVertex2f(-d, -e);
                glVertex2f(-f, -a);
                glVertex2f(-g, -h);
                glVertex2f(-h, -g);
                glVertex2f(-a, -f);
                glVertex2f(-e, -d);
                glVertex2f(-c, -b);
                glVertex2f(0, -r);
                glVertex2f(c, -b);
                glVertex2f(e, -d);
                glVertex2f(a, -f);
                glVertex2f(h, -g);
                glVertex2f(g, -h);
                glVertex2f(f, -a);
                glVertex2f(d, -e);
                glVertex2f(b, -c);
                glVertex2f(r, 0);
            glEnd();
            glScalef(0.5f, 0.5f, 1.0f);
            glBegin(GL_POLYGON);
                glVertex2f(r, 0);
                glVertex2f(d, e);
                glVertex2f(g, h);
                glVertex2f(a, f);
                glVertex2f(c, b);
                glVertex2f(-c, b);
                glVertex2f(-a, f);
                glVertex2f(-g, h);
                glVertex2f(-d, e);
                glVertex2f(-r, 0);
                glVertex2f(-d, -e);
                glVertex2f(-g, -h);
                glVertex2f(-a, -f);
                glVertex2f(-c, -b);
                glVertex2f(c, -b);
                glVertex2f(a, -f);
                glVertex2f(g, -h);
                glVertex2f(d, -e);
                glVertex2f(r, 0);
            glEnd();            
            break;
        case star:
            a = r * 0.5f;
            b = r * 0.86602540378443864676f;
            glBegin(GL_TRIANGLES);
                glVertex2f(r,  0);
                glVertex2f(-a , b);
                glVertex2f(-a, -b);

                glVertex2f(-r,  0);
                glVertex2f(a , -b);
                glVertex2f(a, b);
            glEnd();
            break;
        case star2:
            a = r * 0.4f;
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(r, 0);
                glVertex2f(0, a);
                glVertex2f(-r, 0);
                glVertex2f(0, -a);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(0, r);
                glVertex2f(a, 0);
                glVertex2f(0, -r);
                glVertex2f(-a, 0);
            glEnd();        
            break;
        case plus:
            a = r * 0.5f;
            b = r * 0.86602540378443864676f;
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(b, a);
                glVertex2f(b, -a);
                glVertex2f(-b, -a);
                glVertex2f(-b, a);
            glEnd();
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(a, b);
                glVertex2f(-a, b);
                glVertex2f(-a, -b);
                glVertex2f(a, -b);
            glEnd();
            break;
        default:
            break;
    }

    glPopMatrix();
}
