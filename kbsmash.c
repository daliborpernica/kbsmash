#include <time.h>
#include <GL/freeglut.h>
#include "list.h"
#include "shape.h"
#include "render.h"

#define FULLSCREEN false
#define INITIAL_WINDOW_WIDTH 800
#define INITIAL_WINDOW_HEIGHT 600
#define FPS 40
#define SHAPE_TTL 20 * FPS
#define SHAPE_INITIAL_ALPHA 0.8f
#define SHAPE_ALPHA_DECREMENT 0.02f
#define SHAPE_RADIUS_DECREMENT 5

#define UNUSED(x) (void)(x)

list *shapes;
int screen_w = INITIAL_WINDOW_WIDTH;
int screen_h = INITIAL_WINDOW_HEIGHT;

void onResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
    screen_w = w;
    screen_h = h;
}

void onTimer(int value)
{
    node *n;
    shape *shp;

    list_init_get(shapes);
    while ((n = (node*)list_get(shapes)) != NULL)
    {
        shp = (shape*)(n->data);
        if (!shape_is_active(shp))
        {
            shape_fade_out(shp, SHAPE_RADIUS_DECREMENT, SHAPE_ALPHA_DECREMENT);
            if (!shape_is_visible(shp))
            {
                list_remove_with_data(shapes, n);
            }
        }
        else
        {
            if (shp->type != circle)
            {
                shape_rotate(shp);
            }
            if (shape_decrement_ttl(shp) <= 0)
            {
                shape_deactivate(shp);
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, onTimer, value);
}

void onDisplay(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    list_iterate_data(shapes, onRender);

    glFlush();
}

void onKeyboardDown(unsigned char key, int x, int y)
{
    int screen, rgb, radius;
    int r, s, t;
    float R, G, B;
    shape *shp;

    if (key > 0)
    {
        screen = rand();
        x = (screen_w >> 1) - ((screen & 0xFFFF0000) >> 16) % screen_w;
        y = (screen_h >> 1) - (screen & 0xFFFF) % screen_h;

        radius = rand();
        r = 100 + radius % 200;
        s = -5 + radius % 10;

        rgb = rand();
        R = (float)((rgb & 0xFF0000) >> 16) / 255;
        G = (float)((rgb & 0x00FF00) >> 8) / 255;
        B = (float)(rgb & 0x0000FF) / 255;

        t = rand() % (1 + (int)plus);
        shp = shape_create(key, x, y, (type)t, r, 0, s, R, G, B, SHAPE_INITIAL_ALPHA, SHAPE_TTL);
        list_push(shapes, shp);
    }
}

void onKeyboardUp(unsigned char key, int x, int y)
{
    shape *shp;

    UNUSED(x);
    UNUSED(y);

    list_init_get(shapes);
    while ((shp = (shape*)list_get_data(shapes)) != NULL)
    {
        if (shp->id == key)
        {
            shape_deactivate(shp);
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    shapes = list_create();

    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutCreateWindow("kbsmash");

    if (FULLSCREEN)
    {
        glutFullScreen();
    }
    else
    {
        glutReshapeWindow(INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT);
        glutPositionWindow(100, 100);
    }

    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onResize);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutKeyboardFunc(onKeyboardDown);
    glutKeyboardUpFunc(onKeyboardUp);
    glutTimerFunc(1000 / FPS, onTimer, 0);
    glutMainLoop();

    list_free_with_data(shapes);
    
    return 0;
}
