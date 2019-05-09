#ifndef MYGLWIDGET_HPP
#define MYGLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <vector>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent = nullptr);
    void updateColors(const std::vector<int> &colors);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:

    void draw();
    void normalizeColors(float &r, float &g, float &b);
    float normalize_0_1(float val, float min, float max) const;

    const float RGB_MIN = 1.0f;
    const float RGB_MAX = 255.0f;

    float r = 150.0f;
    float g = 120.0f;
    float b = 32.0f;

};

#endif // MYGLWIDGET_HPP
