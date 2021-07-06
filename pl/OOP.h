//
// Created by Acer on 7/7/2021.
//

#ifndef LEARNCPP_ALGORITHM_OOP_H
#define LEARNCPP_ALGORITHM_OOP_H
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Vehicle{
    string speed;
    string model;
public:
    Vehicle(){
        speed = "";
        model = "";
    }
    Vehicle(string _speed, string _model):speed(std::move(_speed)),model(std::move(_model)){}

    string getSpeed(){
        return speed;
    }

    string  getModel(){
        return model;
    }

};

// Derived Class
class Car: public Vehicle{ // This line needs to be changed.

    string name; //  Name of a Car

public:
    Car():Vehicle() { // Default Constructor
        name = "";
    }
    Car(string _model, string _speed, string _name):Vehicle(_speed, _model){
        this -> name = _name;
    }

    // This function sets the name of the car
    void setDetails(string name) { // Setter Function
        this->name = name;
    }

    // This function calls the Base class functions and appends the result with the input
    string getDetails(string carName) {

        string details = "";

        // write your code here
        details = carName + ", " + getModel() + ", " + getSpeed();

        return details;
    }
};

#endif //LEARNCPP_ALGORITHM_OOP_H
