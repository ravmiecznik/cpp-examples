/*
    An example how to generate values in for:auto loop without allocating iterable object with defined elements.
*/

#include <iostream>

using namespace std;

class range_generator
{
    int cur_value;
    const int end_value;

public:
    range_generator(int end_value) : cur_value(0), end_value(end_value) {}

    // To make this class iterable:
    range_generator& begin() { return *this; }
    range_generator& end() { return *this; }

    // Define prefix and postfix increment operator
    range_generator& operator++()
    {
        // cout << "++G\n";
       ++cur_value;
       return *this;
    }
    range_generator operator++(int)
    {
        // cout << "G++\n";
       range_generator tmp(*this);
       ++(*this);
       return tmp;
    }

    // Define dereference operator
    int operator*() const { 
        // cout << "G*\n";
        return cur_value; 
        }

    // Define comparison operator
    bool operator!=(const range_generator& other) const
    {
        // cout << "!G\n";
        return cur_value != other.end_value;
    }
};

int main(){
    for(auto i: range_generator(10)){
        cout << i << " ";
    }
    cout << '\n';
}