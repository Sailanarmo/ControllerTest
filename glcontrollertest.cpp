#include "glcontrollertest.hpp"
#include "ui_glcontrollertest.h"

GLControllerTest::GLControllerTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GLControllerTest)
{
    ui->setupUi(this);

    redSlider = ui->redHSlider;
    greenSlider = ui->greenHSlider;
    blueSlider = ui->blueHSlider;

    redSpinBox = ui->redSBox;
    greenSpinBox = ui->greenSBox;
    blueSpinBox = ui->blueSBox;

    redController = std::make_unique<Controller<Slider,SpinBox,Red>>(*redSlider,*redSpinBox,red);
    greenController = std::make_unique<Controller<Slider,SpinBox,Green>>(*greenSlider, *greenSpinBox,green);
    blueController = std::make_unique<Controller<Slider,SpinBox,Blue>>(*blueSlider,*blueSpinBox,blue);

    colorController = std::make_unique<Controller<Red,Green,Blue>>(red,green,blue);


}

GLControllerTest::~GLControllerTest()
{
    delete ui;
}

void GLControllerTest::on_redHSlider_valueChanged(int value)
{
    redController->setValues(value);
}

void GLControllerTest::on_greenHSlider_valueChanged(int value)
{
    greenController->setValues(value);
}

void GLControllerTest::on_blueHSlider_valueChanged(int value)
{
    blueController->setValues(value);
}

void GLControllerTest::on_redSBox_editingFinished()
{
    redController->setValues(redSpinBox->value());
}

void GLControllerTest::on_greenSBox_editingFinished()
{
    greenController->setValues(greenSpinBox->value());
}

void GLControllerTest::on_blueSBox_editingFinished()
{
    blueController->setValues(blueSpinBox->value());
}
