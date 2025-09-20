#include <iostream>
using namespace std;


class rectangleType{
    private:
        double length;
        double width;

    public:
        rectangleType(){
            length = 0;
            width = 0;
        };
        rectangleType(double l, double w){
            setDimension(l, w);
        };
        double getLength()const{
            return length;
        } 

        void setDimension(double l, double w)
        {
            if (l >= 0)
                length = l;
            else
                length = 0;
            if (w >= 0)
                width = w;
            else
                width = 0;
        }
        void print()const{
            cout << "Length: " << length << "\n"
                << "Width: " << width;
        }

};

class boxType: public rectangleType{
    private:
        double length;
        double width;
        double height;

    public:
        boxType(){
            height = 0;
        }
        // boxType(double l, double w, double h){
        //     length = l;
        //     width = w;
        //     height = h;
        // }
        boxType(double l, double w, double h)
                :rectangleType(l, w){
                if (h >= 0)
                {
                    height = h;
                }else{
                    height = 0;
                }

        }
        void setDimensions(double l, double w, double h){
            rectangleType::setDimension(l, w);
            if(h >= 0 ){
                height = h;
            }else{
                height = 0;
            }
        }
        double getHeight()const{
            return height;
        }

        double getLength()const{
            return length;
        }
        double getWidth()const{
            return width;
        }

        void print()const {
            rectangleType::print();
            cout << "; Height: " << height;
        }
};

int main(){
    // rectangleType rect1(99.2, 100.2);
    boxType box1(10.1, 2.3, 1.0);
    
    // rect1.print();
    cout << "\n";
    box1.print();

    return 0;
}


