//
// Created by Acer on 7/7/2021.
//

#ifndef LEARNCPP_ALGORITHM_OOP2_H
#define LEARNCPP_ALGORITHM_OOP2_H
#include <string>
#include <iostream>

using namespace std;

class Animal{
private:
    string Name;
    string Sound;
public:
    Animal(const string &name, const string &sound) : Name(name), Sound(sound) {}

    Animal() {}

    const string &getName() const {
        return Name;
    }

    void setName(const string &name) {
        Name = name;
    }

    const string &getSound() const {
        return Sound;
    }

    void setSound(const string &sound) {
        Sound = sound;
    }
    void Animal_Details(){
        cout << "Animal Name: "<<Name<<endl;
        cout << "Animal Sound: " <<Sound<<endl;
    }
};

class Dog: public Animal{
private:
    string Family;
public:
    Dog(const string &name, const string &sound, const string &family) : Animal(name, sound), Family(family) {}
    Dog(const string &name, const string &sound) : Animal(name, sound){
        Family = "Carnivores";
    }
    Dog() {}

    void Dog_detail(){
        Animal_Details();
        cout << "Dog's Family: " + Family<<endl;
    }
};

class Sheep: public Animal{
private:
    string Color;
public:
    Sheep(const string &name, const string &sound, const string &color) : Animal(name, sound), Color(color) {}
    Sheep(const string &name, const string &sound) : Animal(name, sound){
        Color = "White";
    }
    Sheep() {}

    void Sheep_detail(){
        Animal_Details();
        cout << "Sheep Color:" + Color<<endl;
    }
};

#endif //LEARNCPP_ALGORITHM_OOP2_H
