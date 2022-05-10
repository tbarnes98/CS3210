/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "x11context.h"
#include "shape.h"
#include "line.h"
#include "triangle.h"
#include "image.h"
using namespace std;

GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

vector<Shape*> boatScene;

void part1Test(){

	cout << "Part 1 Test" << endl;

	// Boat
	boatScene.push_back(new Line(250,500,550,500,GraphicsContext::YELLOW));
	boatScene.push_back(new Line(250,500,150,400,GraphicsContext::YELLOW));
	boatScene.push_back(new Line(150,400,650,400,GraphicsContext::YELLOW));
	boatScene.push_back(new Line(650,400,550,500,GraphicsContext::YELLOW));
	boatScene.push_back(new Line(400,400,400,100,GraphicsContext::YELLOW));
	
	// Sail
	boatScene.push_back(new Triangle(400,100,300,150,400,200,GraphicsContext::YELLOW));
	
	// Waves
	boatScene.push_back(new Line(0,550,100,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(100,450,100,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(100,550,200,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(200,450,200,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(200,550,300,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(300,450,300,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(300,550,400,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(400,450,400,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(400,550,500,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(500,450,500,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(500,550,600,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(600,450,600,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(600,550,700,450,GraphicsContext::BLUE));
	boatScene.push_back(new Line(700,450,700,550,GraphicsContext::BLUE));
	boatScene.push_back(new Line(700,550,800,450,GraphicsContext::BLUE));
	
	for(int i = 0; i < boatScene.size(); i++){
		boatScene[i]->draw(gc);
	}
}

// Run part 1 test first
void part2Test(){
	cout << "Part 2 Test" << endl;
	Image image1;
	Line L1(300,400,400,600,0x00FF00);
	image1.add(&L1);
	image1.draw(gc);
	image1.erase();
	sleep(3);
	gc->clear();
	Image boat;
	for(int i = 0; i < boatScene.size(); i++){
		boat.add(boatScene[i]);
	}
	Image boat2(boat);
	boat2.draw(gc);
	sleep(5);
	gc->clear();
	sleep(1);
	ofstream boatImage;
	boatImage.open("boat.txt");
	boat.out(boatImage);
	boatImage.close();
	Image image2;
	ifstream imageFile2("boat.txt", ifstream::in);
	image2.in(imageFile2);
	image2.draw(gc);
	boat2.erase();
	image2.erase();
	boat.erase();
	for(int i = 0; i < boatScene.size(); i++){
		delete boatScene[i];
	}
}

int main(void)
{	
	part1Test();
	sleep(5);
	gc->clear();

	part2Test();
	sleep(5);
	gc->clear();
	
	
	delete gc;
 
	return 0;
}

