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

}