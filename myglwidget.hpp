#ifndef MYGLWIDGET_HPP
#define MYGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent = nullptr);
    void drawTriangle();

protected:
    void initializeGL() override;

private:
    const GLfloat g_vertex_buffer_data[9]{
        -1.0f,-1.0f,0.0f,
        1.0f,-1.0f,0.0f,
        0.0f,1.0f,0.0f,
    };

    GLuint vertexbuffer;

};

#endif // MYGLWIDGET_HPP
