#include<bangtal.h>
using namespace bangtal;
int main()
{
	//장면을 생성한다.
	auto scene1 = Scene::create("룸1", "RoomEscape_Images/배경-1.png");
	auto scene2 = Scene::create("룸2", "RoomEscape_Images/배경-2.png");

	//열쇠를 만든다.
	auto key = Object::create("RoomEscape_Images/열쇠.png", scene1, 1128, 133);
	key->setScale(0.2f);

	key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		key->pick();
		return true;
		});

	//박스를 만든다.
	auto box1_moved = false;
	auto box2_moved = false;
	auto box3_moved = false;
	auto box4_moved = false;
	auto box5_moved = false;
	auto box6_moved = false;
	auto box7_moved = false;

	auto box1 = Object::create("RoomEscape_Images/box.png", scene1, 330, 170);
	box1->setScale(0.01f);
	auto box2 = Object::create("RoomEscape_Images/box.png", scene1, 550, 30);
	box2->setScale(0.01f);
	auto box3 = Object::create("RoomEscape_Images/box.png", scene1, 1100, 130);
	box3->setScale(0.01f);
	auto box4 = Object::create("RoomEscape_Images/box.png", scene1, 790, 90);
	box4->setScale(0.01f);
	auto box5 = Object::create("RoomEscape_Images/box.png", scene1, 600, 190);
	box5->setScale(0.01f);
	auto box6 = Object::create("RoomEscape_Images/box.png", scene1, 200, 15);
	box6->setScale(0.01f);
	auto box7 = Object::create("RoomEscape_Images/box.png", scene1, 130, 190);
	box7->setScale(0.01f);
	
	//문을 만든다.
	auto open1 = false;
	auto open2 = false; 
	auto door1_2 = Object::create("RoomEscape_Images/문-오른쪽-닫힘.png", scene1, 800, 270);
	auto door2_1 = Object::create("RoomEscape_Images/문-왼쪽-열림.png", scene2, 320, 270);
	auto door2_2 = Object::create("RoomEscape_Images/문-오른쪽-열림.png", scene2, 910, 272, false);
	
	//버튼을 만든다.
	auto play_right = 0;
	auto la_sound = createSound("RoomEscape_Images/라.mp3");
	auto sol_sound = createSound("RoomEscape_Images/솔.mp3");
	auto fa_sound = createSound("RoomEscape_Images/파.mp3");

	auto red_button = Object::create("RoomEscape_Images/red_button.png", scene2, 820, 445); //라
	red_button->setScale(0.1f);
	auto blue_button = Object::create("RoomEscape_Images/blue_button.png", scene2, 860, 440); //솔
	blue_button->setScale(0.1f);
	auto green_button = Object::create("RoomEscape_Images/green_button.png", scene2, 835, 410); //파
	green_button->setScale(0.1f);

}