#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include <QObject>
#include <QWidget>
#include <QSpinBox>

class SpinBox : public QSpinBox
{
    Q_OBJECT
public:
    SpinBox(QWidget *parent = nullptr);
    void updateValue(int value) { this->setValue(value);}
    int get() const { return this->value(); }

private:
    int val = 0;

};

#endif // SPINBOX_HPP
