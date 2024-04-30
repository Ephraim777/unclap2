
#include <iostream>
#include <fstream>
#include <string>
class Address {

    std::string street;
    std::string city;
    int NumOfapartment;
    int NumOfHome;
public:
    Address() : city("unknown"), street("unknown"), NumOfHome(0), NumOfapartment(0) {}


    void
    SetParametrs(const std::string &city, const std::string &street, const int &NumOfHome, const int &NumOfapartment) {
        this->city = city;
        this->street = street;
        this->NumOfHome = NumOfHome;
        this->NumOfapartment = NumOfapartment;

    }

    std::string mix;

    void GetToString() {

        this->mix = this->city + ", " + this->street + ", " + std::to_string(this->NumOfHome) + ", " +
                    std::to_string(this->NumOfapartment);

    }
    std::string& ReturnCity(){
        return this->city;
    }


};


void sort(Address *ptr, int size) {

    for (int i = 0; i < size - 1; i++) {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (ptr[j].ReturnCity() < ptr[j + 1].ReturnCity()) {
                Address temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }

}
int main() {
    std::ifstream file("in.txt", std::ios::binary);
    if (!file.is_open()) {

        std::cout << "File not open" << std::endl;
        return 0;
    }
    int Calls;
    file >> Calls;
    Address *ptr;
    ptr = new Address[Calls];
    for (int i = 0; i < Calls; i++) {
        std::string city;
        file >> city;
        std::string street;
        file >> street;
        int NumOfHome;
        file >> NumOfHome;
        int NumOfapartment;
        file >> NumOfapartment;
        ptr[i].SetParametrs(city, street, NumOfHome, NumOfapartment);

    }
    file.close();
    std::ofstream file1("out.txt", std::ios::binary);
    if (!file1.is_open()) {
        std::cout << "File1 is not open\n";
        return 3;
    }
    file1 << Calls;
    file1 << std::endl;
sort(ptr,Calls);
    for (int i = Calls - 1; i >= 0; i--) {
        ptr[i].GetToString();
        file1 << ptr[i].mix;
        file1 << std::endl;
    }
    file1.close();
}



