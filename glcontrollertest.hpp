#ifndef GLCONTROLLERTEST_HPP
#define GLCONTROLLERTEST_HPP

#include <QMainWindow>

#include "red.hpp"
#include "green.hpp"
#include "blue.hpp"
#include "controller.hpp"
#include "slider.hpp"
#include "spinbox.hpp"

#include <memory>

namespace Ui {
class GLControllerTest;
}

class GLControllerTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit GLControllerTest(QWidget *parent = nullptr);
    ~GLControllerTest();

private slots:
    void on_redHSlider_valueChanged(int value);

    void on_greenHSlider_valueChanged(int value);

    void on_blueHSlider_valueChanged(int value);

    void on_redSBox_editingFinished();

    void on_greenSBox_editingFinished();

    void on_blueSBox_editingFinished();

private:
    Ui::GLControllerTest *ui;
    Red red;
    Green green;
    Blue blue;

    Slider *redSlider;
    Slider *greenSlider;
    Slider *blueSlider;

    SpinBox *redSpinBox;
    SpinBox *greenSpinBox;
    SpinBox *blueSpinBox;

    std::unique_ptr<Controller<Slider,SpinBox,Red>> redController;
    std::unique_ptr<Controller<Slider,SpinBox,Green>> greenController;
    std::unique_ptr<Controller<Slider,SpinBox,Blue>> blueController;
    std::unique_ptr<Controller<Red,Green,Blue>> colorController;

};

#endif // GLCONTROLLERTEST_HPP
