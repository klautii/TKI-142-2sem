#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Color {
private:
    int r, g, b;

public:
    Color(const int r = 0, const int g = 0, const int b = 0);
    
    int GetR() const { return r; }
    int GetG() const { return g; }
    int GetB() const { return b; }
    
    void SetR(const int value);
    void SetG(const int value);
    void SetB(const int value);
    
    friend ostream& operator<<(ostream& os, const Color& color);
    friend istream& operator>>(istream& is, Color& color);
};
