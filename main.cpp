#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    //better way to declare: int getX() const { ...
    int getX() {
        return x;
    }

    void setX(int x) {
        Point::x = x;
    }

    int getY() {
        return y;
    }

    void setY(int y) {
        Point::y = y;
    }

    //also could be made const
    int getQuadrant(){
        if (x > 0){
            if (y > 0){
                return 1;
            } else if (y < 0) {
                return 4;
            }
        } else if (x < 0){
            if (y > 0){
                return 2;
            } else if (y < 0){
                return 3;
            }
        }
        return 0;
    }
};

/*
 * it is better to pass objects by reference or const reference
 * double getDistance(Point &point1, Point &point2) {..
 * double getDistance(const Point &point1, const Point &point2) {..
 * */
double getDistance(Point point1, Point point2) {

    int x1 = point1.getX();
    int x2 = point2.getX();
    int y1 = point1.getY();
    int y2 = point2.getY();

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void printPointInfo(Point point){
    cout<<"("<<point.getX()<<", "<<point.getY()<<")"<<" is in quadrant "<<point.getQuadrant()<<endl;
}

int main() {

    //creating objects:
    Point p1, p2;

    //setting data for x and y:
    p1.setX(12);
    p1.setY(13);

    p2.setX(2);
    p2.setY(-100);

    int tempX, tempY;

    //Asking the user to enter data for P1:
    cout<<"Enter X value for point P1:";
    cin>>tempX;
    p1.setX(tempX);
    cout<<"Enter Y value for point P1:";
    cin>>tempY;
    p1.setX(tempY);

    //Asking the user to enter data for P2:
    cout<<"Enter X value for point P2:";
    cin>>tempX;
    p2.setX(tempX);
    cout<<"Enter Y value for point P2:";
    cin>>tempY;
    p2.setX(tempY);

    cout<<"The distance between P1 ("<<p1.getX()<<", "<<p1.getY()<<")";
    cout<<" and P2 ("<<p2.getX()<<", "<<p2.getY()<<") is "<<getDistance(p1, p2)<<endl;
    cout<<"P1 is in quadrant number "<<p1.getQuadrant()<<endl;
    cout<<"P2 is in quadrant number "<<p2.getQuadrant()<<endl;

    Point points[4];

    //using enhanced for: for each Point (point) in points...
    for (Point point : points){
        cout<<"Enter X:";
        cin>>tempX;
        point.setX(tempX);
        cout<<"Enter Y:";
        cin>>tempY;
        point.setX(tempY);
    }

    for (Point p : points){
        printPointInfo(p);
    }

    return 0;
}
