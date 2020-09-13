#include<bangtal.h>

using namespace bangtal;

int main() {
	SoundPtr sound = Sound::create("Sounds/Horror.mp3");
	sound->play();

	ScenePtr scene1 = Scene::create("룸1", "Images/배경-3.png");
	ScenePtr scene2 = Scene::create("룸2", "Images/배경-2.png");

	ObjectPtr bone = Object::create("Images/해골.png", scene1, 100, 300, true);
	bone->setScale(0.3f);
	ObjectPtr soondae = Object::create("Images/순대국밥.png", scene1, 1100, 480, true);
	soondae->setScale(0.5f);
	ObjectPtr hero = Object::create("Images/슈퍼맨.png", scene1, 1110, 380, true);
	hero->setScale(0.2f);
	ObjectPtr hint = Object::create("Images/힌트.png", scene1, 700, 600, true);
	hint->setScale(0.3f);

	auto open1 = false, locked = true, first_enter = true;
	ObjectPtr door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 850, 280, true);
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (locked) {
			showMessage("문이 잠겨있습니다.");
		}
		else {
			if (open1) {
				scene2->enter();
			}
			else {
				door1->setImage("Images/문-오른쪽-열림.png");
				open1 = true;
			}
		}
		return true;
		});

	door1->setOnKeypadCallback([&](ObjectPtr object)->bool {
		locked = false;
		showMessage("삐빅 문이 열렸습니다.");
		return true;
		});

	auto keypad1 = Object::create("Images/키패드.png", scene1, 800, 450);
	keypad1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("SDGB", door1);
		return true;
		});


	auto post_it = Object::create("Images/포스트잇.png", scene1, 900, 400);
	post_it->setScale(0.04f);
	post_it->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showImageViewer("Images/포스트잇.png");
		return true;
		});
	
	auto lattice = Object::create("Images/감옥창.jpg", scene1, 200, 500);
	lattice->setScale(0.3f);
	lattice->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showImageViewer("Images/감옥창.jpg");
		return true;
		});

	auto d = Object::create("Images/디.png", scene1, 500, 200);
	d->setScale(0.2f);


	auto carpet = Object::create("Images/카펫.png", scene1, 500, 150);
	carpet->setScale(0.4f);
	carpet->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			carpet->locate(scene1, 430, 150);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			carpet->locate(scene1, 580, 150);
		}
		return true;
		});


	ObjectPtr door2 = Object::create("Images/문-왼쪽-열림.png", scene2, 320, 270, true);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
		});

	auto keybox_open = Object::create("Images/키박스-열림.png", scene2, 640, 460, false);
	keybox_open->setScale(0.2f);

	auto key = Object::create("Images/열쇠.png", scene2, 660, 500);
	key->setScale(0.2f);

	auto keybox_state = false;
	auto keybox_closed = Object::create("Images/키박스-닫힘.png", scene2, 630, 460);
	keybox_closed->setScale(0.2f);

	keybox_closed->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (!keybox_state) {
			showKeypad("UBD", keybox_closed);
		}
		else {
			keybox_closed->hide();
			keybox_open->show();
		}

		return true;
		});

	keybox_closed->setOnKeypadCallback([&](ObjectPtr object)->bool {
		keybox_state = true;
		showMessage("키박스가 열렸다.");
		return true;
		});

	key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		key->pick();
		return true;
		});


	auto locked3 = true, open3 = false;
	ObjectPtr door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 850, 280, true);
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (locked3) {
			if (key->isHanded()) {
				showMessage("철커덕");
				locked3 = false;
			}
			else {
				showMessage("열쇠가 필요합니다.");
			}
		}
		else {
			if (open3) {
				endGame();;
			}
			else {
				door3->setImage("Images/문-오른쪽-열림.png");
				open3 = true;
			}
		}
		return true;
		});

	ObjectPtr scary1 = Object::create("Images/공포배경-1.png", scene2, 650, 350, true);
	scary1->setScale(0.1f);
	scary1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scary1->setImage("Images/공포배경-2.png");
		return true;
		});

	ObjectPtr hint2 = Object::create("Images/쪽지.png", scene2, 400, 100, true);
	hint2->setScale(0.2f);
	hint2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showImageViewer("Images/힌트-2.png");
		return true;
		});

	ObjectPtr ubd = Object::create("Images/엄복동.jpg", scene2, 80, 300, true);
	ubd->setScale(0.2f);
	ubd->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showImageViewer("Images/엄복동.jpg");
		return true;
		});

	ObjectPtr furniture = Object::create("Images/가구.png", scene2, 80, 190, true);
	furniture->setScale(0.9f);
	furniture->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			furniture->locate(scene2, 100, 190);
		}
		else {
			showMessage("그 방향으로는 움직일 수 없다.");
		}
		return true;
		});

	ObjectPtr movie = Object::create("Images/영화.jpg", scene2,1050, 450, true);
	movie->setScale(0.3f);

	ObjectPtr bicycle = Object::create("Images/자전거.png", scene2, 650, 150, true);
	bicycle->setScale(0.4f);

	startGame(scene1);
	return 0;
}