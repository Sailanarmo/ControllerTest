#ifndef GREEN_HPP
#define GREEN_HPP

class Green
{
public:

    void updateValue(int val) { value = val; }
    int get() const { return value; }

private:
    int value = 0;
};

#endif // GREEN_HPP
