#include <iostream>
using namespace std;
class ParkingSystem {
    private:
    int big;
    int medium;
    int small;
    public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    bool addCar(int carType) {
        if (carType == 1){
            if (big > 0){
                big = big -1;
                return true;
            }
            else{
                return false;
            }
        }
        if (carType == 2){
            if (medium > 0){
                medium = medium - 1;
                return true;
            }
            else{
                return false;
            }

        }
        if (carType == 3){
            if (small >0){
                small = small - 1;
                return true;
            }
            else{
                return false;
            }
        }
    return false;
    }
};
int main(){
        ParkingSystem parquadero(2,7,0);
        std ::cout << parquadero.addCar(1) << std::endl;
        std ::cout << parquadero.addCar(2) << std::endl;
        std ::cout << parquadero.addCar(3) << std::endl;
        std ::cout << parquadero.addCar(1) << std::endl;
        std ::cout << parquadero.addCar(2) << std::endl;
        std ::cout << parquadero.addCar(1) << std::endl;
        return 0;
}