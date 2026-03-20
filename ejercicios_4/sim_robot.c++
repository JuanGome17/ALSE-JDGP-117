#include <iostream>
using namespace std;
class Robot {
private:
    int x, y;
    char direction; // N S O E
public:
    Robot(int x, int y, char direccion){
        this->x = x;
        this->y = y;
        this->direction = direccion;
    }
    void turnright(){
        if (direction == 'N') direction = 'E';
        else if (direction == 'E') direction = 'S';
        else if (direction == 'S') direction = 'O';
        else if (direction == 'O') direction = 'N';
    }
    void turnleft(){
        if (direction == 'N') direction = 'O';
        else if (direction == 'O') direction = 'S';
        else if (direction == 'S') direction = 'E';
        else if (direction == 'E') direction = 'N';
    }
    void move(){
        if (direction == 'N') y++;
        else if (direction == 'S') y--;
        else if (direction == 'E') x++;
        else if (direction == 'O') x--;
    }
    void execute(string commands){
        for (char command : commands){
            if (command == 'R') turnright();
            else if (command == 'L') turnleft();
            else if (command == 'A') move();
        }
    }
    void printPosition(){
        cout << "Posicion: {" << x << "," << y << "} ";
        cout << "Direccion: " << direction << endl;
    }
};
int main() {
    Robot robot(7, 3, 'N');
    robot.printPosition();
    robot.execute("RAALAL");
    robot.printPosition();
    return 0;
}