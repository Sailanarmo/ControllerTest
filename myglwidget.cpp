#include "myglwidget.hpp"

MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget (parent)
{

}

void MyGLWidget::initializeGL()
{
    //makeCurrent();
    initializeOpenGLFunctions();
    glGenBuffers(1,&vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data),g_vertex_buffer_data, GL_STATIC_DRAW);
}

void MyGLWidget::drawTriangle()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
    glVertexAttribPointer(
      0,
      3,
      GL_FLOAT,
      GL_FALSE,
      0,
      (void*)0
     );

    glDrawArrays(GL_TRIANGLES,0,3);
    glDisableVertexAttribArray(0);
}
