#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Penalty
{
private:
    static int idCounter;
    int id;
    string text;
    string dateTime;
    int price;

public:
    Penalty() = default;
    Penalty(string _text, string _dateTime, int _price) : id(idCounter++), text(_text), dateTime(_dateTime), price(_price) {}

   
    int getId() const { return id; }
    string getText() const { return text; }
    string getDateTime() const { return dateTime; }
    int getPrice() const { return price; }



    friend ostream& operator<<(ostream& os, const Penalty& penalty);

};
ostream& operator<<(ostream& os, const Penalty& penalty)
{
    os << "ID: " << penalty.id << "\tText: " << penalty.text << "\tDateTime: " << penalty.dateTime << "\tPrice: " << penalty.price;
    return os;
}


int Penalty::idCounter = 1;

class Car
{
private:
    list<Penalty*> penal;
    string marka;
    string model;
    string serialnumber;

public:
    Car() = default;
    Car(const string _marka, const string _model, const string _serialnum) : marka(_marka), model(_model), serialnumber(_serialnum) {}

    void addPenalty(Penalty* penalty)
    {
        this->penal.push_back(penalty);
    }

   
    string getMarka() const { return marka; }
    string getModel() const { return model; }
    string getSerialNumber() const { return serialnumber; }

    
    friend ostream& operator<<(ostream& os, const Car& car);
 
};
 ostream& operator<<(ostream& os, const Car& car)
{
    os << "Car: " << car.marka << "\t" << car.model << "\t" << car.serialnumber << endl;

    if (!car.penal.empty())
    {
        os << "Penalty:" << endl;
        for (auto penalty : car.penal)
        {
            os << *penalty << endl;
        }
        os << "-----------------------------------";
    }
    else
    {
        os << "No penal" << endl;
    }

    return os;
}

int main()
{
    list<Car*> carList;

  
    Car* car1 = new Car("BMW", "X6", "10 AR 100");
    Car* car2 = new Car("Audi", "A4", "20 FG 200");
    Car* car3 = new Car("Vaz", "2107", "10 XX 110");
    Car* car4 = new Car("Ford", "Fusion", "66 AA 666");

    
    Penalty* penalty1 = new Penalty("Qosha xett", "2023-07-26", 100);
    Penalty* penalty2 = new Penalty("Qirmizi ishiq", "2023-07-25", 50);
    Penalty* penalty3 = new Penalty("Dayanma durma", "2023-07-24", 20);
    Penalty* penalty4 = new Penalty("Suret heddi", "2023-07-23", 75);

    car1->addPenalty(penalty1);
    car1->addPenalty(penalty2);
    car1->addPenalty(penalty3);

    car2->addPenalty(penalty4);
    car2->addPenalty(new Penalty("Suret heddi", "2023-07-22", 150));
    
    
    car3->addPenalty(new Penalty("Ceza ", "2023-07-22", 1));
    car3->addPenalty(new Penalty("Ceza", "2023-07-22", 2));
    car3->addPenalty(new Penalty("Ceza", "2023-07-22", 3));


    carList.push_back(car1);
    carList.push_back(car2);
    carList.push_back(car3);
    carList.push_back(car4);
  

    
    for_each(carList.begin(), carList.end(), [](Car* car) {cout << *car << endl;});
}


