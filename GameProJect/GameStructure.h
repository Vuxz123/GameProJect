#pragma once
#include <vector>
#include "GameObject.h"
#include <string>
#include <map>
#include "TexOb.h"
#include "ButtonList.h"
#include "AbOb.h"
#include "MultiTexOb.h"
#include "TextInput.h"
#include "Util.cpp"
#include "GameManager.h"

class GameBase
{
public:

	float oldtime, newtime, delta;

	const std::string MENU = "scene1";
	const std::string GAME = "scene2";
	const std::string ENDGAME = "scene3";
	const std::string CONTINUE = "scene4";

	std::vector<GameObject*> s1, s2, s3, s4;

	TexOb mo = TexOb(), mbo = TexOb(), pbo = TexOb(), gbo = TexOb(), tob1 = TexOb(), tob2 = TexOb(), tob3 = TexOb(), spello = TexOb(), guesso = TexOb(), sellecto = TexOb(), yes_button = TexOb(), no_button = TexOb(), ctn_text_ob = TexOb(), end_ob = TexOb();
	
	MultiTexOb mto = MultiTexOb();
	
	ButtonList mbl = ButtonList(), ingamebuttonlist = ButtonList(), ctn_buttonlist = ButtonList();
	
	AbOb ao = AbOb(), baro = AbOb(), gmo = AbOb(), bg = AbOb();
	
	TextInput ao2 = TextInput();

	Texture* t = new Texture("Player.bmp");
	Texture* menu = new Texture("GameMenu.png"); //256 x 128
	Texture* mb = new Texture("GameMenuBackGroud.png"); //600 x 600
	Texture* pb = new Texture("PlayButton.png"); //100 x 50
	Texture* test = new Texture("PlayerHead1.png");
	Texture* gb = new Texture("GameBackground.png");
	Texture* test2 = new Texture("PlayerHead2.png");
	Texture* test3 = new Texture("PlayerHead3.png");
	Texture* test4 = new Texture("PlayerHead4.png");
	Texture* test5 = new Texture("PlayerHead5.png");
	Texture* test6 = new Texture("PlayerHead6.png");
	Texture* test7 = new Texture("PlayerHead7.png");
	Texture* test8 = new Texture("PlayerHead8.png");
	Texture* spellbutton = new Texture("spell.png");
	Texture* guessbutton = new Texture("guess.png");
	Texture* sellectbutton = new Texture("sellectchar.png");
	Texture* yes_texture = new Texture("Yes.png");
	Texture* no_texture = new Texture("No.png");

	Text tutor1, tutor2, tutor3, h_m_display, ctn_y_n_text;

	Text placeholder, selectedchar;

	Text endgame;

	GameManager manager = GameManager();
	
private:
	bool running = true;

	std::map<std::string, std::vector<GameObject*>> scene;
	std::string presentedscene;

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event Event;

	const std::string VERSION = "0.1.2";
	const std::string TITLE = "Hang Man";

public:
	void addScene(std::string name, std::vector<GameObject*> objects);

	void changeScene(std::string name);

	GameBase(){}

	void init();

	void render();

	void eventCheck(SDL_Event* Event);

	void tick();

	void quit();

	void run();

	~GameBase() {
		quit();
	}
};


