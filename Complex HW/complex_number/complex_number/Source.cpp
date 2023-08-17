#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include <typeinfo>

using namespace std;

class Complex {
protected:
    float rp;
    float ip;
public:
    Complex() {
        rp = 0;
        ip = 0;
        cout << "Complex" << endl;
    }
    Complex(float r) {
        this->rp = r;
        this->ip = 0;
    }
    Complex(float r, float i) {
        this->rp = r;
        this->ip = i;
    }
    Complex(const Complex& complex) {
        this->rp = complex.rp;
        this->ip = complex.ip;
    }
    Complex& operator =(const Complex& complex) {
        this->rp = complex.rp;
        this->ip = complex.ip;
        return *this;
    }
    Complex operator +(const Complex& complex) {
        Complex res;
        res.rp = this->rp + complex.rp;
        res.ip = this->ip + complex.ip;
        return res;
    }
    virtual void setReal(float r) {
        this->rp = r;
    }
    virtual void setImage(float i) {
        this->ip = i;
    }
    float getReal()const { 
        return rp; 
    }
    float getImag()const {
        return ip;
    }
    char* toString() const {
        int r,i;
        r = int(rp * 100);
        i = int(ip * 100);
        int rCount=0;
        int iCount=0;
        while (r) {
            rCount++;
            r /= 10;
        }
        if (rCount == 0) {
            rCount = 1;
        }
        while (i) {
            iCount++;
            i /= 10;
        }
        if (iCount == 0) {
            iCount = 1;
        }
        r = int(rp * 100);
        i = int(ip * 100);
        char* str = new char[rCount + iCount + 5];
        int* rArray = new int[rCount] {0};
        int* iArray = new int[iCount] {0};
        for (int j = 0; j < rCount; j++) {
            rArray[j] = r % 10;
            r /= 10;
        }
        for (int j = 0; j < iCount; j++) {
            iArray[j] = i % 10;
            i /= 10;
        }
        int counter = 0;
        for (int j = rCount - 1; j >= 0; j--) {
            if (j == 1) {
                str[counter] = '.';
                counter++;
                str[counter] = rArray[j]+'0';
                counter++;
            }
            else {
                str[counter] = rArray[j]+'0';
                counter++;
            }
        }
        str[counter] = '+';
        counter++;
        for (int j = iCount - 1; j >= 0; j--) {
            if (j == 1) {
                str[counter] = '.';
                counter++;
                str[counter] = iArray[j]+'0';
                counter++;
            }
            else {
                str[counter] = iArray[j]+'0';
                counter++;
            }
        }
        str[counter] = 'i';
        counter++;
        str[counter] = '\0';
        return str;
    }
    virtual ~Complex() {
        cout << "~Complxe died" << endl;
    }
};
class Number :public Complex {
protected:
    int x;
public:
    Number(){
        x = 10;
        cout << "Number" << endl;
    }
    void setReal(float r) {
        this->rp = x;
    }
    void setImage(float i) {
        this->ip = x;
    }
    ~Number() {
        cout << "~Number died" << endl;
    }
};

int main() {
    /*Complex a(3, 4);
    Complex d(2);
    Complex c;
    float x, y;
    cin >> x >> y;
    c.setReal(x);
    c.setImage(y);
    cout << a.toString() << "         " << d.toString() << endl;    //  prints:    3+4i                  2+0i
    c = a + d;
    cout << c.toString();  //  5 + 4i*/
    Complex* obj = new Complex;
    Complex* a = new Number;
    a->setImage(10);
    cout << typeid(a).name() << endl;
    delete obj;
    delete a;
}