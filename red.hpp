#ifndef RED_HPP
#define RED_HPP

class Red
{
public:

    void updateValue(int val) { value = val; }
    int get() const { return value; }

private:
    int value = 0;
};

#endif // RED_HPP
