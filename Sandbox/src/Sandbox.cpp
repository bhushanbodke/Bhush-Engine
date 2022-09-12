#include<iostream>
#include<Bhush.h>

class Sandbox :public bhush::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

bhush::Application* bhush::createApplication() {
	return new Sandbox();
}