#include "myglwidget.hpp"

MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget (parent)
{

}

void MyGLWidget::initializeGL()
{

    float a = normalize_0_1(RGB_MAX,RGB_MIN,RGB_MAX);

    initializeOpenGLFunctions();
    normalizeColors(r,g,b);
    glClearColor(0.0,0.0,0.0,a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyGLWidget::updateColors(const std::vector<int> &colors)
{
    r = static_cast<float>(colors[0]);
    g = static_cast<float>(colors[1]);
    b = static_cast<float>(colors[2]);
    normalizeColors(r,g,b);
    update();

}

void MyGLWidget::normalizeColors(float &r, float &g, float &b)
{
    r = normalize_0_1(r,RGB_MIN,RGB_MAX);
    g = normalize_0_1(g,RGB_MIN,RGB_MAX);
    b = normalize_0_1(b,RGB_MIN,RGB_MAX);
}

float MyGLWidget::normalize_0_1(float val, float min, float max) const
{
    return (val - min)/(max - min);
}

void MyGLWidget::draw()
{
    glBegin(GL_TRIANGLES);
      glColor3f(r,g,b);
      glVertex3f(-1.0f,-1.0f,0.0f);
      glVertex3f(1.0f,-1.0f,0.0f);
      glVertex3f(0.0f,1.0f,0.0f);
    glEnd();
}
