#ifndef BLUE_HPP
#define BLUE_HPP

class Blue
{
public:

    void updateValue(int val) { value = val; }
    int get() const { return value; }

private:
    int value = 0;
};

#endif // BLUE_HPP
