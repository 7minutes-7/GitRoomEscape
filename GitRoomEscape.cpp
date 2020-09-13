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

	//힌트 표시.
	auto password = Object::create("RoomEscape_Images/hint.png", scene2, 400, 30, false);
	password->setScale(0.25f);
	auto sound_icon = Object::create("RoomEscape_Images/sound.png", scene2, 837, 475);
	sound_icon->setScale(0.07f);

	//스위치를 만든다.
	auto lighted = true;
	auto button = Object::create("RoomEscape_Images/green_switch.png", scene2, 430, 445);
	button->setScale(0.05f);
	button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (lighted) {			//켜진 상태
			scene2->setLight(0.2f);
			password->show();
			lighted = false;
		}
		else {					//꺼진 상태
			scene2->setLight(1.0f);
			password->hide();
			lighted = true;
		}
		return true;
		});
	//문을 클릭하면 이동한다.  
	door1_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open1 == true) {		
			scene2->enter();
		}
		else if (key->isHanded()) {					
			door1_2->setImage("RoomEscape_Images/문-오른쪽-열림.png");
			open1 = true;
		}
		else {
			showMessage("열쇠가 필요해!!!");
		}
		return true;
		});

	door2_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});
	door2_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});

	//박스 위아래로 드래그시 움직인다. 
	box1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box1_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box1->locate(scene1, 330, 240);
				box1_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box1->locate(scene1, 330, 170);
			box1_moved = false;
		}
		return true;
		});
	box2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box2_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box2->locate(scene1, 550, 100);
				box2_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box2->locate(scene1, 550, 30);
			box2_moved = false;
		}
		return true;
		});
	box3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box3_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box3->locate(scene1, 1100, 200);
				box3_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box3->locate(scene1, 1100, 130);
			box3_moved = false;
		}
		return true;
		});
	box4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box4_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box4->locate(scene1, 790, 160);
				box4_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box4->locate(scene1, 790, 90);
			box4_moved = false;
		}
		return true;
		});
	box5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box5_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box5->locate(scene1, 600, 260);
				box5_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box5->locate(scene1, 600, 190);
			box5_moved = false;
		}
		return true;
		});
	box6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box6_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box6->locate(scene1, 200, 85);
				box6_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box6->locate(scene1, 200, 15);
			box6_moved = false;
		}
		return true;
		});
	box7->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (box7_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				box7->locate(scene1, 130, 260);
				box7_moved = true;
			}
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			box7->locate(scene1, 130, 190);
			box7_moved = false;
		}
		return true;
		});

	//버튼 클릭하면 소리 발생
	red_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		playSound(la_sound);
		if (play_right == 0 || play_right == 4 || play_right == 5 || play_right == 6) {
			play_right++;
			if (play_right == 7 && open2 == false) {
				door2_2->show();
				showMessage("뾰로롱");
				open2 = true;
			}
		}
		else {
			play_right = 0;
		}
		return true;
		});

	blue_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		playSound(sol_sound);
		if (play_right == 1 || play_right == 3) {
			play_right++;
		}
		else {
			play_right = 0;
		}
		return true;
		});
	green_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		playSound(fa_sound);
		if (play_right == 2) {
			play_right++;
		}
		else {
			play_right = 0;
		}
		return true;
		});

}